#include "threadville_maintenance.h"
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include "utils.h"
#include "interface.h"
#include "globals.h"
#include<time.h> 

double ran_expo() {
    srand(time(0));
    double u;
    u = rand() / (RAND_MAX + 1.0);
    // Mean value of 40 -> lambda = 0.025
    return -log(1 - u) / 0.025;
}

int random_threadville_id() {
    return rand() % (MAX_ID_NUMBER + 1);
}

_Noreturn void* run_maintenance(void *arg) {
    int maintenance_time;
    int threadville_id;
    double current_waiting_time;

    time_t t;
    srand((unsigned) time(&t));
    pthread_t tid = pthread_self();
    current_waiting_time = ran_expo();
    while (1) {
        sleep(current_waiting_time);

        threadville_id = random_threadville_id();
        StreetInfo *streetInfo = NULL;
        while(streetInfo==NULL){
            threadville_id = random_threadville_id();
            streetInfo = lookup_street_info(map->streetInfoTable, threadville_id);
        }
        
        priority_semaphore *mutex = lookup(map->map, threadville_id);
        lock_priority_semaphore(3, mutex);
        create_object(
                tid,
                REPAIR,
                streetInfo->x,
                streetInfo->y,
                ""
        );
        maintenance_time = ((rand() % 4) + 1) * 5;
        sleep(maintenance_time);
        unlock_priority_semaphore(3, mutex);
        delete_object(tid);
        current_waiting_time = ran_expo();
    }
}
