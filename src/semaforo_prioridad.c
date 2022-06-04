#include "semaforo_prioridad.h"
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

SemaforoPrioridad * get_semaforo_prioridad(){
	SemaforoPrioridad * semaforoPrioridad = NULL;
	semaforoPrioridad = (struct SemaforoPrioridad*) malloc(sizeof(struct SemaforoPrioridad));

    pthread_cond_init(&semaforoPrioridad->mutexCondicion, NULL);
    pthread_cond_init(&semaforoPrioridad->mutexCondicion, &semaforoPrioridad->mutexCondicionAtributos); 
    
    pthread_mutexattr_init(&semaforoPrioridad->mutexAtributos);
    pthread_mutexattr_settype(&semaforoPrioridad->mutexAtributos, PTHREAD_PROCESS_SHARED); 
    pthread_mutex_init(&semaforoPrioridad->mutex, &semaforoPrioridad->mutexAtributos);

    semaforoPrioridad->enUso = false;

    memset(semaforoPrioridad->prioridad, 0, 10 * sizeof(int));
    return semaforoPrioridad;
}

void lock_semaforo_prioridad(int nivelPrioridad, SemaforoPrioridad * semaforoPrioridad){
    pthread_mutex_lock(&semaforoPrioridad->mutex);
    semaforoPrioridad->prioridad[nivelPrioridad] += 1;
    pthread_mutex_unlock(&semaforoPrioridad->mutex);

    pthread_mutex_lock(&semaforoPrioridad->mutex);
    bool flat = true;
    while(flat == true){
        flat = false;
        if(semaforoPrioridad->enUso == false) {
            for (int i = 0; i < nivelPrioridad; ++i){
                if(semaforoPrioridad->prioridad[i] > 0) {
                    flat = true;
                }
            }
        } else {
            flat=true;
        }

        if(flat == true) {
            pthread_cond_wait(&semaforoPrioridad->mutexCondicion, &semaforoPrioridad->mutex);
        }
    }
    semaforoPrioridad->enUso = true;
    pthread_mutex_unlock(&semaforoPrioridad->mutex);
}

void unlock_semaforo_prioridad(int nivelPrioridad, SemaforoPrioridad * semaforoPrioridad){
    pthread_mutex_lock(&semaforoPrioridad->mutex);
    semaforoPrioridad->prioridad[nivelPrioridad] -= 1;
    semaforoPrioridad->enUso = false;
    pthread_cond_broadcast(&semaforoPrioridad->mutexCondicion);
    pthread_mutex_unlock(&semaforoPrioridad->mutex);
}
