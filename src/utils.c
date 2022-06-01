#include "utils.h"
#include <sys/mman.h>
#include <pthread.h>

void *create_shared_memory(size_t size) {
    int protection = PROT_READ | PROT_WRITE;
    int flags = MAP_SHARED | MAP_ANONYMOUS | MAP_SYNC;

    return mmap(NULL, size, protection, flags, -1, 0);
}

pthread_condattr_t get_conditional_attribute() {
    pthread_condattr_t *cattr = (pthread_condattr_t*) malloc(sizeof(pthread_condattr_t));
    pthread_condattr_init(cattr);
    pthread_condattr_setpshared(cattr, PTHREAD_PROCESS_SHARED);
    return *cattr;
}

pthread_mutexattr_t *get_mutex_attributes() {
    pthread_mutexattr_t *mattr = (pthread_mutexattr_t*) malloc(sizeof(pthread_mutexattr_t));;
    pthread_mutexattr_init(mattr);
    pthread_mutexattr_setpshared(mattr, PTHREAD_PROCESS_SHARED);
    return mattr;
}

pthread_mutex_t *get_mutex(pthread_mutexattr_t *mattr) {
    pthread_mutex_t *mutex = create_shared_memory(sizeof(pthread_mutex_t));
    pthread_mutex_init(mutex, mattr);
    return mutex;
}

