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


NodoT *push_lista(NodoT *head, int valor, struct NodoData *data);

int pop_lista(NodoT **head);

NodoT *remover_por_valor(NodoT *head, int n);


#endif /* LISTA_ENLAZADA_CARROS */
