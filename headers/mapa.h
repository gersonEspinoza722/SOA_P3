#ifndef PROYECTO3_THREADVILLE_MAPA_H
#define PROYECTO3_THREADVILLE_MAPA_H

#include "hash_table.h"
#include "hash_table_info_calle.h"
#include "utils.h"

typedef struct ThreadvilleMapa {
    Tabla *mapa;
    TablaInfoCalle* tablaInfoCalle;
} ThreadvilleMapa;

ThreadvilleMapa *crear_threadville_mapa();

void insertar_carreteras(Tabla *, TablaInfoCalle *);

void insertar_puentes(Tabla *, TablaInfoCalle *);

void insertar_rotondas(Tabla *, TablaInfoCalle *);

void insertar_paradas(Tabla *, TablaInfoCalle *);

void insertar_calles(Tabla *, TablaInfoCalle *);

void insertar_esquinas(Tabla *, TablaInfoCalle *);

void insertar_info_calle_carreteras(TablaInfoCalle *, IdsCarreteras);

void insertar_info_calle_puente(TablaInfoCalle *, IdsPuentes);

void insertar_info_calle_puente_arriba(TablaInfoCalle *t, IdsPuentes id);

void insertar_info_calle_rotondas(TablaInfoCalle *, IdsRotondas);

void insertar_info_calle_paradas(TablaInfoCalle *, IdsParadas);

void insertar_info_calle_calles(TablaInfoCalle *, IdsCalles);

void insertar_info_calle_esquinas(TablaInfoCalle *, IdsEsquinas);

#endif //PROYECTO3_THREADVILLE_MAPA_H
