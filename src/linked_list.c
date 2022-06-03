#include "linked_list.h"
#include <stdlib.h>

LinkedList *create_linked_list() {
    LinkedList *list = malloc(sizeof(LinkedList));
    list->primer_nodo = NULL;
    return list;
}

NodeL *create_node(int id_destino) {
    NodeL *node = malloc(sizeof(NodeL));
    node->id_destino = id_destino;
    node->next_node = NULL;
    return node;
}

void append(LinkedList *list, NodeL *node) {
    NodeL *nextNode = list->primer_nodo;
    if (nextNode == NULL) {
        list->primer_nodo = node;
        return;
    }
    while (nextNode->next_node != NULL) {
        nextNode = nextNode->next_node;
    }
    nextNode->next_node = node;
}

void push(LinkedList *list, NodeL *node) {
    node->next_node = list->primer_nodo;
    list->primer_nodo = node;
}

void pop(LinkedList *list) {
    NodeL *deleted = list->primer_nodo;
    list->primer_nodo = deleted->next_node;
    free(deleted);
}

LinkedList *copy_list(LinkedList *l) {
    LinkedList *list = create_linked_list();
    NodeL *nextNode = l->primer_nodo;
    while (nextNode->next_node != NULL) {
        append(list, create_node(nextNode->id_destino));
        nextNode = nextNode->next_node;
    }
    return list;
}