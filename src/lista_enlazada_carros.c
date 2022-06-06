#include"lista_enlazada_carros.h"
#include <stdio.h>
#include <stdlib.h>

NodoT *push_lista(NodoT *head, int valor, struct NodoData *data) {
    NodoT *nuevoNodo;
    nuevoNodo = (NodoT *) malloc(sizeof(NodoT));

    nuevoNodo->valor = valor;
    nuevoNodo->data = data;
    nuevoNodo->siguiente = head;
    return nuevoNodo;
}

int pop_lista(NodoT **head) {
    int retval = -1;
    NodoT *siguienteNodo = NULL;

    if (*head == NULL || (*head)->siguiente == NULL) {
        return -1;
    }

    siguienteNodo = (*head)->siguiente;
    retval = (*head)->valor;
    if ((*head)->data != NULL) {
        free((*head)->data);
    }
    free(*head);
    *head = siguienteNodo;

    if ((*head)->siguiente == NULL) {
        return -1;
    }

    return retval;
}

NodoT *borrar_nodo_auxiliar(NodoT *actual) {
    NodoT *temporal = actual;
    actual = temporal->siguiente;
    if (temporal->data != NULL) {
        free(temporal->data);
    }
    free(temporal);
    return actual;
}

NodoT *remover_por_valor(NodoT *head, int n) {
    NodoT *actual = head;

    if (actual->valor == n) {
        return borrar_nodo_auxiliar(actual);
    }
    while (actual->siguiente != NULL) {
        if (actual->siguiente->valor == n) {
            actual->siguiente = borrar_nodo_auxiliar(actual->siguiente);
            break;
        }
        actual = actual->siguiente;
    }
    return head;
}

