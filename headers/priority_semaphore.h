#ifndef PRIORITY_SEMAPHORE
#define PRIORITY_SEMAPHORE
#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct priority_semaphore {
    int priority[10];
    bool in_use;
    pthread_mutex_t mutex;
    pthread_mutexattr_t mutex_attr;
    pthread_cond_t mutex_condition; 
    pthread_condattr_t mutex_condition_attr;
} priority_semaphore;  


void lock_priority_semaphore(int priority_level, priority_semaphore * semaphore_p);
void unlock_priority_semaphore(int priority_level, priority_semaphore * semaphore_p);
priority_semaphore * get_priority_semaphore();



#endif /* PRIORITY_SEMAPHORE */