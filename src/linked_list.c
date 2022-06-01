#include "linked_list.h"
#include <stdlib.h>

LinkedList *create_linked_list() {
    LinkedList *list = malloc(sizeof(LinkedList));
    list->first_node = NULL;
    return list;
}

NodeL *create_node(int destination_id) {
    NodeL *node = malloc(sizeof(NodeL));
    node->destination_id = destination_id;
    node->next_node = NULL;
    return node;
}

void append(LinkedList *list, NodeL *node) {
    NodeL *nextNode = list->first_node;
    if (nextNode == NULL) {
        list->first_node = node;
        return;
    }
    while (nextNode->next_node != NULL) {
        nextNode = nextNode->next_node;
    }
    nextNode->next_node = node;
}

void push(LinkedList *list, NodeL *node) {
    node->next_node = list->first_node;
    list->first_node = node;
}

void pop(LinkedList *list) {
    NodeL *deleted = list->first_node;
    list->first_node = deleted->next_node;
    free(deleted);
}

LinkedList *copy_list(LinkedList *l) {
    LinkedList *list = create_linked_list();
    NodeL *nextNode = l->first_node;
    while (nextNode->next_node != NULL) {
        append(list, create_node(nextNode->destination_id));
        nextNode = nextNode->next_node;
    }
    return list;
}