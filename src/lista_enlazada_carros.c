#include"lista_enlazada_carros.h"
#include <stdio.h>
#include <stdlib.h>

NodoT *terminar_push(NodoT *head, int valor, struct NodoData *data) {
    NodoT *actual = head;
    while (actual->siguiente != NULL) {
        actual = actual->siguiente;
    }

    actual->siguiente = (NodoT *) malloc(sizeof(NodoT));
    actual->siguiente->valor = valor;
    actual->siguiente->data = data;
    actual->siguiente->siguiente = NULL;
    return actual->siguiente;
}

NodoT *iniciar_push(NodoT *head, int valor, struct NodoData *data) {
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

int remover_ultimo(NodoT *head) {
    int retval = 0;
    //Si solo hay un item, entonces remuevalo
    if (head->siguiente == NULL) {
        return -1;
    }

    //Moverse al segundo elemento
    NodoT *actual = head;
    while (actual->siguiente->siguiente != NULL) {
        actual = actual->siguiente;
    }

    //Removerlo ahora que ya se movio el puntero
    retval = actual->siguiente->valor;
    if (actual->siguiente->data != NULL) {
        free(actual->siguiente->data);
    }
    free(actual->siguiente);
    actual->siguiente = NULL;
    return retval;

}

int remover_por_indice(NodoT **head, int n) {
    int i = 0;
    int retval = -1;
    NodoT *actual = *head;
    NodoT *nodoTemporal = NULL;

    if (n == 0) {
        return pop_lista(head);
    }

    for (i = 0; i < n - 1; i++) {
        if (actual->siguiente == NULL) {
            return -1;
        }
        actual = actual->siguiente;
    }

    nodoTemporal = actual->siguiente;
    retval = nodoTemporal->valor;
    actual->siguiente = nodoTemporal->siguiente;

    if (nodoTemporal->data != NULL) {
        free(nodoTemporal->data);
    }
    free(nodoTemporal);
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

void imprimir_lista(NodoT *head) {
    NodoT *actual = head;

    while (actual != NULL) {
        printf("%d %f %f\n", actual->valor, actual->data->width, actual->data->height);
        actual = actual->siguiente;
    }
}