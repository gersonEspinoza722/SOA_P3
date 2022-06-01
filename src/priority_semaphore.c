#include "priority_semaphore.h"
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


priority_semaphore * get_priority_semaphore(){
	priority_semaphore * semaphore_p = NULL;
	semaphore_p = (struct priority_semaphore*) malloc(sizeof(struct priority_semaphore));

    pthread_cond_init(&semaphore_p->mutex_condition, NULL);
    pthread_cond_init(&semaphore_p->mutex_condition, &semaphore_p->mutex_condition_attr); 
    
    pthread_mutexattr_init(&semaphore_p->mutex_attr);
    pthread_mutexattr_settype(&semaphore_p->mutex_attr, PTHREAD_PROCESS_SHARED); 
    pthread_mutex_init(&semaphore_p->mutex, &semaphore_p->mutex_attr);

    semaphore_p->in_use = false;

    memset(semaphore_p->priority, 0, 10*sizeof(int));
    return semaphore_p;
}

void lock_priority_semaphore(int priority_level, priority_semaphore * semaphore_p){
    pthread_mutex_lock(&semaphore_p->mutex);
    semaphore_p->priority[priority_level]+=1;
    pthread_mutex_unlock(&semaphore_p->mutex);

    pthread_mutex_lock(&semaphore_p->mutex);
    bool flat = true;
    while(flat==true){
        flat = false;
        if(semaphore_p->in_use==false){
            for (int i = 0; i < priority_level; ++i)
            {
                if(semaphore_p->priority[i]>0){
                    flat=true;
                }
            }
        }else{
            flat=true;
        }

        if(flat==true){
            pthread_cond_wait(&semaphore_p->mutex_condition, &semaphore_p->mutex);
        }
    }
    semaphore_p->in_use = true;
    pthread_mutex_unlock(&semaphore_p->mutex);
}

void unlock_priority_semaphore(int priority_level, priority_semaphore * semaphore_p){
    pthread_mutex_lock(&semaphore_p->mutex);
    semaphore_p->priority[priority_level]-=1;
    semaphore_p->in_use = false;
    pthread_cond_broadcast(&semaphore_p->mutex_condition);
    pthread_mutex_unlock(&semaphore_p->mutex);
}
