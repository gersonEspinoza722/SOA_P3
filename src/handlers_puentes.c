#include "threadville_map.h"
#include "handlers_puentes.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/mman.h>
#include <interface.h>

extern pthread_mutex_t mutex_KMN;

extern ThreadvilleMap *mapa;

pthread_cond_t *get_mutex_condicional(TipoPuentes tipo) {
    extern pthread_cond_t *cond_larry;
    extern pthread_cond_t *cond_joe;
    extern pthread_cond_t *cond_curly;
    extern pthread_cond_t *cond_shemp;
    switch (tipo) {
        case LARRY:
            return cond_larry;
        case JOE:
            return cond_joe;
        case CURLY:
            return cond_curly;
        case SHEMP:
            return cond_shemp;
        case MOE:
        default:
            return NULL;
    }
}

pthread_mutex_t *get_mutex_puente(TipoPuentes tipo) {
    extern pthread_mutex_t *mutex_larry;
    extern pthread_mutex_t *mutex_joe;
    extern pthread_mutex_t *mutex_curly;
    extern pthread_mutex_t *mutex_shemp;
    switch (tipo) {
        case LARRY:
            return mutex_larry;
        case JOE:
            return mutex_joe;
        case CURLY:
            return mutex_curly;
        case SHEMP:
            return mutex_shemp;
        case MOE:
        default:
            return NULL;
    }
}

void lock_semaforos_puente(int idInicial, int idFinal) {
    for (int i = idInicial; i <= idFinal; i++) {
        priority_semaphore *actual = lookup(mapa->mapa, i);
        if (actual != NULL) {
            lock_priority_semaphore(0, actual);
        }
    }
}

void unlock_semaforos_puente(int idInicial, int idFinal) {
    for (int i = idFinal; i >= idInicial; i--) {
        priority_semaphore *actual = lookup(mapa->mapa, i);
        if (actual != NULL) {
            unlock_priority_semaphore(0, actual);
        }
    }
}

bool tiene_oportunidad(TipoPuentes tipo, bool direccion) {
    extern int larry_espera_carros_arriba;
    extern int joe_espera_carros_arriba;
    extern int larry_espera_carros_abajo;
    extern int joe_espera_carros_abajo;

    if (tipo == LARRY && !direccion && larry_espera_carros_arriba > 0) {
        return true;
    } else if (tipo == LARRY && direccion && larry_espera_carros_abajo > 0) {
        return true;
    } else if (tipo == JOE && !direccion && joe_espera_carros_arriba > 0) {
        return true;
    } else if (tipo == JOE && direccion && joe_espera_carros_abajo > 0) {
        return true;
    }

    return false;
}

int get_k() {
    extern int K;
    int kResultado;

    pthread_mutex_lock(&mutex_KMN);
    kResultado = K;
    pthread_mutex_unlock(&mutex_KMN);
    return kResultado;
}

int get_m() {
    extern int M;
    int mResultado;

    pthread_mutex_lock(&mutex_KMN);
    mResultado = M;
    pthread_mutex_unlock(&mutex_KMN);
    return mResultado;
}

int get_n() {
    extern int N;
    int nResultado;

    pthread_mutex_lock(&mutex_KMN);
    nResultado = N;
    pthread_mutex_unlock(&mutex_KMN);
    return nResultado;
}

_Noreturn
void *handleLarryJoe(void *arg) {
    // Obtener el lado del puente, chequear si la direccion debe cambiar
    struct timespec tiempo;
    int kLocal;

    LarryJoeInformacion *informacion = (LarryJoeInformacion *) arg;
    pthread_cond_t *cond = get_mutex_condicional(informacion->tipo);
    pthread_mutex_t *mutex = get_mutex_puente(informacion->tipo);
    priority_semaphore *semaforoActual;
    int *semaforoOpuesto;
    images_enum imagenPuente;
    //Mantener contador de los carros que deben de pasar
    int contadorLocal = 0;
    //Sur
    if (informacion->direccion) {
        semaforoOpuesto = informacion->rango_lado_norte;
        semaforoActual = lookup(mapa->mapa, informacion->rango_lado_sur[0]);
        imagenPuente = SEMAPHOREU;
    } else {
        semaforoOpuesto = informacion->rango_lado_sur;
        semaforoActual = lookup(mapa->mapa, informacion->rango_lado_norte[0]);
        imagenPuente = SEMAPHORED;
    }
    while (1) {
        kLocal = get_k();
        pthread_mutex_lock(mutex);

        //Chequear que lado del puente esta disponible
        if (informacion->direccion != *informacion->siguienteDireccion) {
            //Dormir si este lado no debe estar disponible
            pthread_cond_wait(&cond[informacion->direccion], mutex);
        }

        lock_semaforos_puente(semaforoOpuesto[0], semaforoOpuesto[1]);
        edit_semaphore(informacion->tipo, imagenPuente);
        pthread_mutex_lock(&semaforoActual->mutex);

        while (contadorLocal < kLocal) {
            timespec_get(&tiempo, TIME_UTC);
            tiempo.tv_sec += 5;

            const int resultado = pthread_cond_timedwait(&semaforoActual->mutex_condition, &semaforoActual->mutex,
                                                   &tiempo);
            if (resultado) {
                if (tiene_oportunidad(informacion->tipo, informacion->direccion) == true) {
                    break;
                }
            } else {
                contadorLocal++;
            }
        }
        if (informacion->tipo == LARRY) {
            printf("\033[0;31mLarry cambio de direccion a: %s\033[0m\n", informacion->direccion ? "Sur" : "Norte");
        } else {
            printf("\033[0;31mJoe cambio de direccion a: %s\033[0m\n", informacion->direccion ? "Sur" : "Norte");
        }
        fflush(stdout);

        *informacion->siguienteDireccion = !*informacion->siguienteDireccion;
        contadorLocal = 0;

        pthread_mutex_unlock(&semaforoActual->mutex);
        unlock_semaforos_puente(semaforoOpuesto[0], semaforoOpuesto[1]);

        // despertar siguiente hilo
        pthread_cond_signal(&cond[*informacion->siguienteDireccion]);
        pthread_mutex_unlock(mutex);
    }
}

_Noreturn
void *handleCurlyShemp(void *arg) {
    //Obtener el lado del puente
    int M_local = get_m();
    int N_local = get_n();
    CurlyShempInformacion *informacion = (CurlyShempInformacion *) arg;
    pthread_cond_t *cond = get_mutex_condicional(informacion->tipo);
    pthread_mutex_t *mutex = get_mutex_puente(informacion->tipo);
    int *prioridadSemaforo;
    images_enum imagenPuente;
    int *segundos;
    //Sur
    if (informacion->direccion) {
        prioridadSemaforo = informacion->rango_lado_norte;
        imagenPuente = SEMAPHOREU;
    } else {
        prioridadSemaforo = informacion->rango_lado_sur;
        imagenPuente = SEMAPHORED;
    }
    while (1) {
        //Actualizar valores en tiempo real
        M_local = get_m();
        N_local = get_n();
        if (informacion->direccion) {
            segundos = &M_local;
        } else {
            segundos = &N_local;
        }
        //Fin de actualizacion

        pthread_mutex_lock(mutex);
        //Chequear que lado del puente esta disponible
        if (informacion->direccion != *informacion->siguienteDireccion) {
            //Dormir si este lado no debe estar disponible
            pthread_cond_wait(&cond[informacion->direccion], mutex);
        }

        lock_semaforos_puente(prioridadSemaforo[0], prioridadSemaforo[1]);
        edit_semaphore(informacion->tipo, imagenPuente);
        sleep(*segundos);
        unlock_semaforos_puente(prioridadSemaforo[0], prioridadSemaforo[1]);
        if (informacion->tipo == CURLY) {
            printf("\033[0;31mCurly cambio de direccion a: %s\033[0m\n", informacion->direccion ? "Sur" : "Norte");
        } else {
            printf("\033[0;31mShemp cambio de direccion a: %s\033[0m\n", informacion->direccion ? "Sur" : "Norte");
        }
        *informacion->siguienteDireccion = !*informacion->siguienteDireccion;

        // despertar siguiente hilo
        pthread_cond_signal(&cond[*informacion->siguienteDireccion]);
        pthread_mutex_unlock(mutex);
    }
}

CurlyShempInformacion *crearCurlyShempInfo(bool direccion, TipoPuentes tipo, bool *siguienteDireccion,
        int idInicioNorte, int idFinNorte, int idInicioSur, int idFinSur) {
    CurlyShempInformacion *info = malloc(sizeof(CurlyShempInformacion));
    int *idsNorte = calloc(2, sizeof(int));
    idsNorte[0] = idInicioNorte;
    idsNorte[1] = idFinNorte;
    int *idsSur = calloc(2, sizeof(int));
    idsSur[0] = idInicioSur;
    idsSur[1] = idFinSur;

    info->direccion = direccion;
    info->siguienteDireccion = siguienteDireccion;
    info->tipo = tipo;
    info->rango_lado_norte = idsNorte;
    info->rango_lado_sur = idsSur;
    return info;
}

LarryJoeInformacion *crearLarryJoeInfo(
        bool direccion, TipoPuentes tipo, bool *siguienteDireccion,
        int idInicioNorte, int idFinNorte,
        int idInicioSur, int idFinSur
) {
    LarryJoeInformacion *info = malloc(sizeof(LarryJoeInformacion));
    int *idsNorte = calloc(2, sizeof(int));
    idsNorte[0] = idInicioNorte;
    idsNorte[1] = idFinNorte;
    int *idsSur = calloc(2, sizeof(int));
    idsSur[0] = idInicioSur;
    idsSur[1] = idFinSur;

    info->direccion = direccion;
    info->siguienteDireccion = siguienteDireccion;
    info->tipo = tipo;
    info->rango_lado_norte = idsNorte;
    info->rango_lado_sur = idsSur;
    return info;
}
