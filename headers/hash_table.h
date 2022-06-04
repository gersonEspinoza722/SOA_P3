#ifndef PROYECTO3_HASH_TABLE_H
#define PROYECTO3_HASH_TABLE_H

#include <pthread.h>
#include "priority_semaphore.h"

typedef struct Node {
    int llave;
    priority_semaphore *valor;
    struct Node *siguiente;
} Node;

typedef struct Table {
    int tamanio;
    Node **lista;
} Table;

Table *create_table(int tamanio);

int hash_code(Table*, int);

void insert(Table*, int, priority_semaphore*);

priority_semaphore *lookup(Table *t, int);

#endif //PROYECTO3_HASH_TABLE_H
