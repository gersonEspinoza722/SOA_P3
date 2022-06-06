#ifndef PROYECTO3_HASH_TABLE_H
#define PROYECTO3_HASH_TABLE_H

#include <pthread.h>
#include "semaforo_prioridad.h"

typedef struct NodoH {
    int llave;
    SemaforoPrioridad *valor;
    struct NodoH *siguiente;
} NodoH;

typedef struct Tabla {
    int tamanio;
    NodoH **lista;
} Tabla;

Tabla *crear_tabla(int tamanio);

int hash_code(Tabla*, int);

void insertar(Tabla*, int, SemaforoPrioridad*);

SemaforoPrioridad *lookup(Tabla *t, int);

#endif 
