#include <stdio.h>
#include <stdlib.h>
#include "hash_table.h"

Table *create_table(int tamanio) {
    Table *t = (Table *) malloc(sizeof(Table));
    t->tamanio = tamanio;
    t->lista = (Node **) malloc(sizeof(Node *) * tamanio);
    int i;
    for (i = 0; i < tamanio; i++)
        t->lista[i] = NULL;
    return t;
}

int hash_code(Table *t, int llave) {
    if (llave < 0)
        return -(llave % t->tamanio);
    return llave % t->tamanio;
}

void insert(Table *t, int llave, priority_semaphore* valor) {
    int pos = hash_code(t, llave);
    Node *lista = t->lista[pos];
    Node *newNode = (Node *) malloc(sizeof(Node));
    Node *temp = lista;
    while (temp) {
        if (temp->llave == llave) {
            temp->valor = valor;
            return;
        }
        temp = temp->siguiente;
    }
    newNode->llave = llave;
    newNode->valor = valor;
    newNode->siguiente = lista;
    t->lista[pos] = newNode;
}

priority_semaphore * lookup(Table *t, int llave) {
    int pos = hash_code(t, llave);
    Node *lista = t->lista[pos];
    Node *temp = lista;
    while (temp) {
        if (temp->llave == llave) {
            return temp->valor;
        }
        temp = temp->siguiente;
    }
    return NULL;
}
