#include "threadville_mantenimiento.h"
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include "utils.h"
#include "interface.h"
#include "globales.h"
#include<time.h> 

double ran_expo() {
    srand(time(0));
    double u;
    u = rand() / (RAND_MAX + 1.0);
    // Media de 40 -> lambda = 0.025
    return -log(1 - u) / 0.025;
}

int threadville_id_aleatorio() {
    return rand() % (MAX_ID_NUMBER + 1);
}

_Noreturn void* hacer_mantenimiento(void *arg) {
    int tiempoMantenimiento;
    int threadvilleId;
    double tiempoEsperaActual;

    time_t tiempo;
    srand((unsigned) time(&tiempo));
    pthread_t tId = pthread_self();
    tiempoEsperaActual = ran_expo();
    while (1) {
        sleep(tiempoEsperaActual);

        threadvilleId = threadville_id_aleatorio();
        InfoCalle *infoCalle = NULL;
        while(infoCalle == NULL){
            threadvilleId = threadville_id_aleatorio();
            infoCalle = lookup_info_calle(mapa->tablaInfoCalle, threadvilleId);
        }
        
        SemaforoPrioridad *mutex = lookup(mapa->mapa, threadvilleId);
        lock_semaforo_prioridad(3, mutex);
        create_object(tId, REPAIR, infoCalle->x, infoCalle->y, "");
        tiempoMantenimiento = ((rand() % 4) + 1) * 5;
        sleep(tiempoMantenimiento);
        unlock_semaforo_prioridad(3, mutex);
        delete_object(tId);
        tiempoEsperaActual = ran_expo();
    }
}