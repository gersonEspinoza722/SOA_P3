#include"linked_list_cars.h"
#include <stdio.h>
#include <stdlib.h>

node_t *push_end(node_t *head, int val, struct data_node *data) {
    node_t *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    /* now we can add a new variable */
    current->next = (node_t *) malloc(sizeof(node_t));
    current->next->val = val;
    current->next->data = data;
    current->next->next = NULL;
    return current->next;
}

node_t *push_begin(node_t *head, int val, struct data_node *data) {
    node_t *new_node;
    new_node = (node_t *) malloc(sizeof(node_t));

    new_node->val = val;
    new_node->data = data;
    new_node->next = head;
    return new_node;
}

int pop_list(node_t **head) {
    int retval = -1;
    node_t *next_node = NULL;

    if (*head == NULL || (*head)->next == NULL) {
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->val;
    if ((*head)->data != NULL) {
        free((*head)->data);
    }
    free(*head);
    *head = next_node;

    if ((*head)->next == NULL) {
        return -1;
    }

    return retval;
}

int remove_last(node_t *head) {
    int retval = 0;
    /* if there is only one item in the list, remove it */
    if (head->next == NULL) {
        return -1;
    }

    /* get to the second to last node in the list */
    node_t *current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    /* now current points to the second to last item of the list, so let's remove current->next */
    retval = current->next->val;
    if (current->next->data != NULL) {
        free(current->next->data);
    }
    free(current->next);
    current->next = NULL;
    return retval;

}

int remove_by_index(node_t **head, int n) {
    int i = 0;
    int retval = -1;
    node_t *current = *head;
    node_t *temp_node = NULL;

    if (n == 0) {
        return pop_list(head);
    }

    for (i = 0; i < n - 1; i++) {
        if (current->next == NULL) {
            return -1;
        }
        current = current->next;
    }

    temp_node = current->next;
    retval = temp_node->val;
    current->next = temp_node->next;

    if (temp_node->data != NULL) {
        free(temp_node->data);
    }
    free(temp_node);
    return retval;

}

node_t *delete_node_aux(node_t *current) {
    node_t *tmp = current;
    current = tmp->next;
    if (tmp->data != NULL) {
        free(tmp->data);
    }
    free(tmp);
    return current;
}

node_t *remove_by_val(node_t *head, int n) {
    node_t *current = head;

    if (current->val == n) {
        return delete_node_aux(current);
    }
    while (current->next != NULL) {
        if (current->next->val == n) {
            current->next = delete_node_aux(current->next);
            break;
        }
        current = current->next;
    }
    return head;
}

void print_list(node_t *head) {
    node_t *current = head;

    while (current != NULL) {
        printf("%d %f %f\n", current->val, current->data->width, current->data->height);
        current = current->next;
    }
}