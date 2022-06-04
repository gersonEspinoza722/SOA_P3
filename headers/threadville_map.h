#ifndef PROYECTO3_THREADVILLE_MAP_H
#define PROYECTO3_THREADVILLE_MAP_H

#include "hash_table.h"
#include "hash_table_info_calle.h"
#include "utils.h"

typedef struct ThreadvilleMap {
    Table *mapa;
    TablaInfoCalle* tablaInfoCalle;
} ThreadvilleMap;

ThreadvilleMap *create_threadville_map();

void insert_highways(Table *, TablaInfoCalle *);

void insert_bridges(Table *, TablaInfoCalle *);

void insert_roundabouts(Table *, TablaInfoCalle *);

void insert_stops(Table *, TablaInfoCalle *);

void insert_streets(Table *, TablaInfoCalle *);

void insert_corners(Table *, TablaInfoCalle *);

void insert_street_info_highways(TablaInfoCalle *, HighwaysIds);

void insert_street_info_bridge(TablaInfoCalle *, BridgeIds);

void insert_street_info_bridge_up(TablaInfoCalle *t, BridgeIds id);

void insert_street_info_roundabouts(TablaInfoCalle *, RoundaboutIds);

void insert_street_info_stops(TablaInfoCalle *, StopIds);

void insert_street_info_streets(TablaInfoCalle *, StreetIds);

void insert_street_info_corners(TablaInfoCalle *, CornersIds);

#endif //PROYECTO3_THREADVILLE_MAP_H
