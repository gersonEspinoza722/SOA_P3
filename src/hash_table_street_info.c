#include "hash_table_street_info.h"
#include <stdlib.h>

TableStreetInfo *create_table_street_info(int size) {
    TableStreetInfo *t = (TableStreetInfo *) malloc(sizeof(TableStreetInfo));
    t->size = size;
    t->list = (NodeStreetInfo **) malloc(sizeof(NodeStreetInfo *) * size);
    int i;
    for (i = 0; i < size; i++)
        t->list[i] = NULL;
    return t;
}

StreetInfo *create_street_info(double x, double y, StreetDir dir) {
    StreetInfo *i = (StreetInfo *) malloc(sizeof(StreetInfo));
    i->x = (float) x;
    i->y = (float) y;
    i->dir = dir;
    return i;
}

int hash_code_street_info(TableStreetInfo *t, int key) {
    if (key < 0)
        return -(key % t->size);
    return key % t->size;
}

void insert_street_info(TableStreetInfo *t, int key, StreetInfo* val) {
    int pos = hash_code_street_info(t, key);
    NodeStreetInfo *list = t->list[pos];
    NodeStreetInfo *newNode = (NodeStreetInfo *) malloc(sizeof(NodeStreetInfo));
    NodeStreetInfo *temp = list;
    while (temp) {
        if (temp->key == key) {
            temp->val = val;
            return;
        }
        temp = temp->next;
    }
    newNode->key = key;
    newNode->val = val;
    newNode->next = list;
    t->list[pos] = newNode;
}

StreetInfo* lookup_street_info(TableStreetInfo *t, int key) {
    int pos = hash_code_street_info(t, key);
    NodeStreetInfo *list = t->list[pos];
    NodeStreetInfo *temp = list;
    while (temp) {
        if (temp->key == key) {
            return temp->val;
        }
        temp = temp->next;
    }
    return NULL;
}

