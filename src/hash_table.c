#include <stdio.h>
#include <stdlib.h>
#include "hash_table.h"

Table *create_table(int size) {
    Table *t = (Table *) malloc(sizeof(Table));
    t->size = size;
    t->list = (Node **) malloc(sizeof(Node *) * size);
    int i;
    for (i = 0; i < size; i++)
        t->list[i] = NULL;
    return t;
}

int hash_code(Table *t, int key) {
    if (key < 0)
        return -(key % t->size);
    return key % t->size;
}

void insert(Table *t, int key, priority_semaphore* valor) {
    int pos = hash_code(t, key);
    Node *list = t->list[pos];
    Node *newNode = (Node *) malloc(sizeof(Node));
    Node *temp = list;
    while (temp) {
        if (temp->key == key) {
            temp->valor = valor;
            return;
        }
        temp = temp->siguiente;
    }
    newNode->key = key;
    newNode->valor = valor;
    newNode->siguiente = list;
    t->list[pos] = newNode;
}

priority_semaphore * lookup(Table *t, int key) {
    int pos = hash_code(t, key);
    Node *list = t->list[pos];
    Node *temp = list;
    while (temp) {
        if (temp->key == key) {
            return temp->valor;
        }
        temp = temp->siguiente;
    }
    return NULL;
}
