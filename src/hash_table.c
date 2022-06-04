#include <stdio.h>
#include <stdlib.h>
#include "hash_table.h"

Tabla *crear_tabla(int tamanio) {
    Tabla *tabla = (Tabla *) malloc(sizeof(Tabla));
    tabla->tamanio = tamanio;
    tabla->lista = (NodoH **) malloc(sizeof(NodoH *) * tamanio);
    int i;
    for (i = 0; i < tamanio; i++)
        tabla->lista[i] = NULL;
    return tabla;
}

int hash_code(Tabla *tabla, int llave) {
    if (llave < 0)
        return -(llave % tabla->tamanio);
    return llave % tabla->tamanio;
}

void insertar(Tabla *tabla, int llave, SemaforoPrioridad* valor) {
    int posicion = hash_code(tabla, llave);
    NodoH *lista = tabla->lista[posicion];
    NodoH *nuevoNodo = (NodoH *) malloc(sizeof(NodoH));
    NodoH *temporal = lista;
    while (temporal) {
        if (temporal->llave == llave) {
            temporal->valor = valor;
            return;
        }
        temporal = temporal->siguiente;
    }
    nuevoNodo->llave = llave;
    nuevoNodo->valor = valor;
    nuevoNodo->siguiente = lista;
    tabla->lista[posicion] = nuevoNodo;
}

SemaforoPrioridad * lookup(Tabla *tabla, int llave) {
    int posicion = hash_code(tabla, llave);
    NodoH *lista = tabla->lista[posicion];
    NodoH *temporal = lista;
    while (temporal) {
        if (temporal->llave == llave) {
            return temporal->valor;
        }
        temporal = temporal->siguiente;
    }
    return NULL;
}
