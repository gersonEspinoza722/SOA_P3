#ifndef LIKED_LIST_CARS
#define LIKED_LIST_CARS


typedef struct data_node {
    float width;
    float height;
    int type_image;
    char next_stop[20];
} data_node;


typedef struct node {
    int val;
    struct node *next;
    struct data_node *data;
} node_t;


node_t *push_begin(node_t *head, int val, struct data_node *data);

node_t *push_end(node_t *head, int val, struct data_node *data);

int pop_list(node_t **head);

int remove_last(node_t *head);

int remove_by_index(node_t **head, int n);

node_t *remove_by_val(node_t *head, int n);

void print_list(node_t *head);

#endif /* LIKED_LIST_CARS */
