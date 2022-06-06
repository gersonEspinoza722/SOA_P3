#ifndef PROYECTO3_HASH_TABLE_INFO_CALLE_H
#define PROYECTO3_HASH_TABLE_INFO_CALLE_H

typedef enum DireccionCalle {
    DIR_NORTE,
    DIR_SUR,
    DIR_OESTE,
    DIR_ESTE
} DireccionCalle;

typedef struct InfoCalle {
    float x;
    float y;
    DireccionCalle direccion;
} InfoCalle;

typedef struct NodoInfoCalle {
    int llave;
    InfoCalle *valor;
    struct NodoInfoCalle *siguiente;
} NodoInfoCalle;

typedef struct TablaInfoCalle {
    int tamanio;
    NodoInfoCalle **lista;
} TablaInfoCalle;

TablaInfoCalle *crear_tabla_info_calle(int tamanio);

InfoCalle *crear_info_calle(double, double, DireccionCalle);

int hash_code_info_calle(TablaInfoCalle *, int);

void insertar_info_calle(TablaInfoCalle *, int, InfoCalle *);

InfoCalle *lookup_info_calle(TablaInfoCalle *t, int);

#endif //PROYECTO3_HASH_TABLE_INFO_CALLE_H
