#include "threadville_map.h"
#include "bridge_handlers.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/mman.h>
#include <interface.h>

extern pthread_mutex_t mutex_KMN;

extern ThreadvilleMap *map;

pthread_cond_t *get_conditional_mutex(BridgesType type) {
    extern pthread_cond_t *cond_larry;
    extern pthread_cond_t *cond_joe;
    extern pthread_cond_t *cond_curly;
    extern pthread_cond_t *cond_shemp;
    switch (type) {
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

pthread_mutex_t *get_bridge_mutex(BridgesType type) {
    extern pthread_mutex_t *mutex_larry;
    extern pthread_mutex_t *mutex_joe;
    extern pthread_mutex_t *mutex_curly;
    extern pthread_mutex_t *mutex_shemp;
    switch (type) {
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

void lock_bridge_semaphores(int starting_id, int ending_id) {
    for (int i = starting_id; i <= ending_id; i++) {
        priority_semaphore *current = lookup(map->map, i);
        if (current != NULL) {
            lock_priority_semaphore(0, current);
        }
    }
}

void unlock_bridge_semaphores(int starting_id, int ending_id) {
    for (int i = ending_id; i >= starting_id; i--) {
        priority_semaphore *current = lookup(map->map, i);
        if (current != NULL) {
            unlock_priority_semaphore(0, current);
        }
    }
}

bool can_chance(BridgesType type, bool direction) {
    extern int larry_cars_waitu;
    extern int joe_cars_waitu;
    extern int larry_cars_waitd;
    extern int joe_cars_waitd;

    if (type == LARRY && !direction && larry_cars_waitu > 0) {
        return true;
    } else if (type == LARRY && direction && larry_cars_waitd > 0) {
        return true;
    } else if (type == JOE && !direction && joe_cars_waitu > 0) {
        return true;
    } else if (type == JOE && direction && joe_cars_waitd > 0) {
        return true;
    }

    return false;
}

int get_k() {
    extern int K;
    int k_result;

    pthread_mutex_lock(&mutex_KMN);
    k_result = K;
    pthread_mutex_unlock(&mutex_KMN);
    return k_result;
}

int get_m() {
    extern int M;
    int m_result;

    pthread_mutex_lock(&mutex_KMN);
    m_result = M;
    pthread_mutex_unlock(&mutex_KMN);
    return m_result;
}

int get_n() {
    extern int N;
    int n_result;

    pthread_mutex_lock(&mutex_KMN);
    n_result = N;
    pthread_mutex_unlock(&mutex_KMN);
    return n_result;
}

_Noreturn
void *handleLarryJoe(void *arg) {
    // Get side of the bridge
    // Check if direction must change
    struct timespec time;
    int k_local;

    LarryJoeInformation *information = (LarryJoeInformation *) arg;
    pthread_cond_t *cond = get_conditional_mutex(information->type);
    pthread_mutex_t *mutex = get_bridge_mutex(information->type);
    priority_semaphore *currentSemaphore;
    int *oppositeSemaphore;
    images_enum bridge_image;
    // Keep count of the number of cars that has pass
    int local_counter = 0;
    // South direction
    if (information->direction) {
        oppositeSemaphore = information->north_side_range;
        currentSemaphore = lookup(map->map, information->south_side_range[0]);
        bridge_image = SEMAPHOREU;
    } else {
        oppositeSemaphore = information->south_side_range;
        currentSemaphore = lookup(map->map, information->north_side_range[0]);
        bridge_image = SEMAPHORED;
    }
    while (1) {
        k_local = get_k();
        pthread_mutex_lock(mutex);

        // See which side of the bridge should be available
        if (information->direction != *information->nextDirection) {
            // Sleep if is this side should not be available
            pthread_cond_wait(&cond[information->direction], mutex);
        }

        lock_bridge_semaphores(oppositeSemaphore[0], oppositeSemaphore[1]);
        edit_semaphore(information->type, bridge_image);
        pthread_mutex_lock(&currentSemaphore->mutex);

        while (local_counter < k_local) {
            timespec_get(&time, TIME_UTC);
            time.tv_sec += 5;

            const int res = pthread_cond_timedwait(&currentSemaphore->mutex_condition, &currentSemaphore->mutex,
                                                   &time);
            if (res) {
                if (can_chance(information->type, information->direction) == true) {
                    break;
                }
            } else {
                local_counter++;
            }
        }
        if (information->type == LARRY) {
            printf("\033[0;31mLarry change direction to: %s\033[0m\n", information->direction ? "South" : "North");
        } else {
            printf("\033[0;31mJoe change direction to: %s\033[0m\n", information->direction ? "South" : "North");
        }
        fflush(stdout);

        *information->nextDirection = !*information->nextDirection;
        local_counter = 0;

        pthread_mutex_unlock(&currentSemaphore->mutex);
        unlock_bridge_semaphores(oppositeSemaphore[0], oppositeSemaphore[1]);

        // weak up next thread
        pthread_cond_signal(&cond[*information->nextDirection]);
        pthread_mutex_unlock(mutex);
    }
}

_Noreturn
void *handleCurlyShemp(void *arg) {
    // Get side of the bridge
    int M_local = get_m();
    int N_local = get_n();
    CurlyShempInformation *information = (CurlyShempInformation *) arg;
    pthread_cond_t *cond = get_conditional_mutex(information->type);
    pthread_mutex_t *mutex = get_bridge_mutex(information->type);
    int *prioritySemaphore;
    images_enum bridge_image;
    int *seconds;
    // South direction
    if (information->direction) {
        prioritySemaphore = information->north_side_range;
        bridge_image = SEMAPHOREU;
    } else {
        prioritySemaphore = information->south_side_range;
        bridge_image = SEMAPHORED;
    }
    while (1) {
        //Update values in real time
        M_local = get_m();
        N_local = get_n();
        if (information->direction) {
            seconds = &M_local;
        } else {
            seconds = &N_local;
        }
        //Fin de update

        pthread_mutex_lock(mutex);
        // See which side of the bridge should be available
        if (information->direction != *information->nextDirection) {
            // Sleep if is this side should not be available
            pthread_cond_wait(&cond[information->direction], mutex);
        }

        lock_bridge_semaphores(prioritySemaphore[0], prioritySemaphore[1]);
        edit_semaphore(information->type, bridge_image);
        sleep(*seconds);
        unlock_bridge_semaphores(prioritySemaphore[0], prioritySemaphore[1]);
        if (information->type == CURLY) {
            printf("\033[0;31mCurly change direction to: %s\033[0m\n", information->direction ? "South" : "North");
        } else {
            printf("\033[0;31mShemp change direction to: %s\033[0m\n", information->direction ? "South" : "North");
        }
        *information->nextDirection = !*information->nextDirection;

        // weak up next thread
        pthread_cond_signal(&cond[*information->nextDirection]);
        pthread_mutex_unlock(mutex);
    }
}

CurlyShempInformation *createCurlyShempInfo(
        bool direction, BridgesType type, bool *nextDirection,
        int start_north_id, int end_north_id,
        int start_south_id, int end_south_id
) {
    CurlyShempInformation *info = malloc(sizeof(CurlyShempInformation));
    int *north_ids = calloc(2, sizeof(int));
    north_ids[0] = start_north_id;
    north_ids[1] = end_north_id;
    int *south_ids = calloc(2, sizeof(int));
    south_ids[0] = start_south_id;
    south_ids[1] = end_south_id;

    info->direction = direction;
    info->nextDirection = nextDirection;
    info->type = type;
    info->north_side_range = north_ids;
    info->south_side_range = south_ids;
    return info;
}

LarryJoeInformation *createLarryJoeInfo(
        bool direction, BridgesType type, bool *nextDirection,
        int start_north_id, int end_north_id,
        int start_south_id, int end_south_id
) {
    LarryJoeInformation *info = malloc(sizeof(LarryJoeInformation));
    int *north_ids = calloc(2, sizeof(int));
    north_ids[0] = start_north_id;
    north_ids[1] = end_north_id;
    int *south_ids = calloc(2, sizeof(int));
    south_ids[0] = start_south_id;
    south_ids[1] = end_south_id;

    info->direction = direction;
    info->nextDirection = nextDirection;
    info->type = type;
    info->north_side_range = north_ids;
    info->south_side_range = south_ids;
    return info;
}
