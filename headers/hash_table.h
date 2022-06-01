#ifndef PROYECTO3_HASH_TABLE_H
#define PROYECTO3_HASH_TABLE_H

#include <pthread.h>
#include "priority_semaphore.h"

typedef struct Node {
    int key;
    priority_semaphore *val;
    struct Node *next;
} Node;

typedef struct Table {
    int size;
    Node **list;
} Table;

Table *create_table(int size);

int hash_code(Table*, int);

void insert(Table*, int, priority_semaphore*);

priority_semaphore *lookup(Table *t, int);

#endif //PROYECTO3_HASH_TABLE_H
