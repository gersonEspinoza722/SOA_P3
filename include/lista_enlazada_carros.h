#ifndef LISTA_ENLAZADA_CARROS
#define LISTA_ENLAZADA_CARROS


typedef struct NodoData {
    float width;
    float height;
    int tipoImagen;
    char siguienteParada[20];
} NodoData;


typedef struct Nodo {
    int valor;
    struct Nodo *siguiente;
    struct NodoData *data;
} NodoT;


NodoT *iniciar_push(NodoT *head, int valor, struct NodoData *data);

NodoT *terminar_push(NodoT *head, int valor, struct NodoData *data);

int pop_lista(NodoT **head);

int remover_ultimo(NodoT *head);

int remover_por_indice(NodoT **head, int n);

NodoT *remover_por_valor(NodoT *head, int n);

void imprimir_lista(NodoT *head);

#endif /* LISTA_ENLAZADA_CARROS */
