#ifndef PROYECTO3_LINKED_LIST_H
#define PROYECTO3_LINKED_LIST_H

typedef struct NodeL {
    struct NodeL *next_node;
    int destination_id;
} NodeL;

typedef struct LinkedList {
    NodeL* first_node;
} LinkedList;

LinkedList *create_linked_list();

NodeL *create_node(int);

void append(LinkedList *, NodeL *);

void push(LinkedList *, NodeL *);

void pop(LinkedList *);

LinkedList *copy_list(LinkedList *);

#endif //PROYECTO3_LINKED_LIST_H
