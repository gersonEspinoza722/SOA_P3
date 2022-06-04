#include "hash_table_info_calle.h"
#include <stdlib.h>

TablaInfoCalle *crear_tabla_info_calle(int tamanio) {
    TablaInfoCalle *tabla = (TablaInfoCalle *) malloc(sizeof(TablaInfoCalle));
    tabla->tamanio = tamanio;
    tabla->lista = (NodoInfoCalle **) malloc(sizeof(NodoInfoCalle *) * tamanio);
    int i;
    for (i = 0; i < tamanio; i++)
        tabla->lista[i] = NULL;
    return tabla;
}

InfoCalle *crear_info_calle(double x, double y, DireccionCalle direccion) {
    InfoCalle *info = (InfoCalle *) malloc(sizeof(InfoCalle));
    info->x = (float) x;
    info->y = (float) y;
    info->direccion = direccion;
    return info;
}

int hash_code_info_calle(TablaInfoCalle *tabla, int llave) {
    if (llave < 0)
        return -(llave % tabla->tamanio);
    return llave % tabla->tamanio;
}

void insertar_info_calle(TablaInfoCalle *tabla, int llave, InfoCalle* valor) {
    int posicion = hash_code_info_calle(tabla, llave);
    NodoInfoCalle *lista = tabla->lista[posicion];
    NodoInfoCalle *nuevoNodo = (NodoInfoCalle *) malloc(sizeof(NodoInfoCalle));
    NodoInfoCalle *temporal = lista;
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

InfoCalle* lookup_info_calle(TablaInfoCalle *tabla, int llave) {
    int posicion = hash_code_info_calle(tabla, llave);
    NodoInfoCalle *lista = tabla->lista[posicion];
    NodoInfoCalle *temporal = lista;
    while (temporal) {
        if (temporal->llave == llave) {
            return temporal->valor;
        }
        temporal = temporal->siguiente;
    }
    return NULL;
}

