#ifndef SEMAFORO_PRIORIDAD
#define SEMAFORO_PRIORIDAD
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct SemaforoPrioridad {
    int prioridad[10];
    bool enUso;
    pthread_mutex_t mutex;
    pthread_mutexattr_t mutexAtributos;
    pthread_cond_t mutexCondicion; 
    pthread_condattr_t mutexCondicionAtributos;
} SemaforoPrioridad;  


void lock_semaforo_prioridad(int nivelPrioridad, SemaforoPrioridad * semaforoPrioridad);
void unlock_semaforo_prioridad(int nivelPrioridad, SemaforoPrioridad * semaforoPrioridad);
SemaforoPrioridad * get_semaforo_prioridad();

#endif /* SEMAFORO_PRIORIDAD */