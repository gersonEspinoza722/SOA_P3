#include "lista_enlazada.h"
#include <stdlib.h>

ListaEnlazada *crear_lista_enlazada() {
    ListaEnlazada *lista = malloc(sizeof(ListaEnlazada));
    lista->primerNodo = NULL;
    return lista;
}

NodoL *crear_nodo(int idDestino) {
    NodoL *nodo = malloc(sizeof(NodoL));
    nodo->idDestino = idDestino;
    nodo->siguienteNodo = NULL;
    return nodo;
}

void append(ListaEnlazada *lista, NodoL *nodo) {
    NodoL *siguienteNodo = lista->primerNodo;
    if (siguienteNodo == NULL) {
        lista->primerNodo = nodo;
        return;
    }
    while (siguienteNodo->siguienteNodo != NULL) {
        siguienteNodo = siguienteNodo->siguienteNodo;
    }
    siguienteNodo->siguienteNodo = nodo;
}

void push(ListaEnlazada *lista, NodoL *nodo) {
    nodo->siguienteNodo = lista->primerNodo;
    lista->primerNodo = nodo;
}

void pop(ListaEnlazada *lista) {
    NodoL *borrado = lista->primerNodo;
    lista->primerNodo = borrado->siguienteNodo;
    free(borrado);
}

ListaEnlazada *copiar_lista(ListaEnlazada *listaP) {
    ListaEnlazada *lista = crear_lista_enlazada();
    NodoL *siguienteNodo = listaP->primerNodo;
    while (siguienteNodo->siguienteNodo != NULL) {
        append(lista, crear_nodo(siguienteNodo->idDestino));
        siguienteNodo = siguienteNodo->siguienteNodo;
    }
    return lista;
}