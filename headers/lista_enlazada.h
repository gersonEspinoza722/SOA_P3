#ifndef PROYECTO3_LISTA_ENLAZADA_H
#define PROYECTO3_LISTA_ENLAZADA_H

typedef struct NodoL {
    struct NodoL *siguienteNodo;
    int idDestino;
} NodoL;

typedef struct ListaEnlazada {
    NodoL* primerNodo;
} ListaEnlazada;

ListaEnlazada *crear_lista_enlazada();

NodoL *crear_nodo(int);

void append(ListaEnlazada *, NodoL *);

void push(ListaEnlazada *, NodoL *);

void pop(ListaEnlazada *);

ListaEnlazada *copiar_lista(ListaEnlazada *);

#endif //PROYECTO3_LISTA_ENLAZADA_H
