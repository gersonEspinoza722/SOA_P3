#include "threadville_map.h"
#include "utils.h"

ThreadvilleMap *create_threadville_map() {
    ThreadvilleMap *threadvilleMap = create_shared_memory(sizeof(ThreadvilleMap));
    threadvilleMap->mapa = crear_tabla(984);
    threadvilleMap->tablaInfoCalle = crear_tabla_info_calle(984);

    insert_highways(threadvilleMap->mapa, threadvilleMap->tablaInfoCalle);
    insert_bridges(threadvilleMap->mapa, threadvilleMap->tablaInfoCalle);
    insert_roundabouts(threadvilleMap->mapa, threadvilleMap->tablaInfoCalle);
    insert_stops(threadvilleMap->mapa, threadvilleMap->tablaInfoCalle);
    insert_streets(threadvilleMap->mapa, threadvilleMap->tablaInfoCalle);
    insert_corners(threadvilleMap->mapa, threadvilleMap->tablaInfoCalle);
    return threadvilleMap;
}

void insert_highways(Tabla *table, TablaInfoCalle *infoCalle) {
    for (int i = H001H; i <= H144H; ++i) {
        insertar(table, i, get_semaforo_prioridad());
        insert_street_info_highways(infoCalle, i);
    }
}

void insert_bridges(Tabla *table, TablaInfoCalle *infoCalle) {
    for (int i = B001B; i <= B030B; ++i) {
        insertar(table, i, get_semaforo_prioridad());
        insert_street_info_bridge(infoCalle, i);
    }
    for (int i = BU01B; i <= BU30B; ++i) {
        insertar(table, i, get_semaforo_prioridad());
        insert_street_info_bridge_up(infoCalle, i);
    }
}

void insert_roundabouts(Tabla *table, TablaInfoCalle *infoCalle) {
    for (int i = Y001R; i <= Z006R; ++i) {
        insertar(table, i, get_semaforo_prioridad());
        insert_street_info_roundabouts(infoCalle, i);
    }
}

void insert_stops(Tabla *table, TablaInfoCalle *infoCalle) {
    for (int i = A001S; i <= R006S; ++i) {
        insertar(table, i, get_semaforo_prioridad());
        insert_street_info_stops(infoCalle, i);
    }
}

void insert_streets(Tabla *table, TablaInfoCalle *infoCalle) {
    for (int i = A001P; i <= R018P; ++i) {
        insertar(table, i, get_semaforo_prioridad());
        insert_street_info_streets(infoCalle, i);
    }
}

void insert_corners(Tabla *table, TablaInfoCalle *infoCalle) {
    for (int i = A001C; i <= X004C; ++i) {
        insertar(table, i, get_semaforo_prioridad());
        insert_street_info_corners(infoCalle, i);
    }
}

void insert_street_info_highways(TablaInfoCalle *t, HighwaysIds id) {
    switch (id) {
        case H072H:
            insertar_info_calle(t, id, crear_info_calle(0.143, 0.465, DIR_OESTE));
            break;
        case H071H:
            insertar_info_calle(t, id, crear_info_calle(0.159, 0.465, DIR_OESTE));
            break;
        case H070H:
            insertar_info_calle(t, id, crear_info_calle(0.175, 0.465, DIR_OESTE));
            break;
        case H069H:
            insertar_info_calle(t, id, crear_info_calle(0.191, 0.465, DIR_OESTE));
            break;
        case H068H:
            insertar_info_calle(t, id, crear_info_calle(0.2335, 0.465, DIR_OESTE));
            break;
        case H067H:
            insertar_info_calle(t, id, crear_info_calle(0.2525, 0.465, DIR_OESTE));
            break;
        case H066H:
            insertar_info_calle(t, id, crear_info_calle(0.2685, 0.465, DIR_OESTE));
            break;
        case H065H:
            insertar_info_calle(t, id, crear_info_calle(0.2845, 0.465, DIR_OESTE));
            break;
        case H064H:
            insertar_info_calle(t, id, crear_info_calle(0.3005, 0.465, DIR_OESTE));
            break;
        case H063H:
            insertar_info_calle(t, id, crear_info_calle(0.3165, 0.465, DIR_OESTE));
            break;
        case H062H:
            insertar_info_calle(t, id, crear_info_calle(0.3325, 0.465, DIR_OESTE));
            break;
        case H061H:
            insertar_info_calle(t, id, crear_info_calle(0.375, 0.465, DIR_OESTE));
            break;
        case H060H:
            insertar_info_calle(t, id, crear_info_calle(0.394, 0.465, DIR_OESTE));
            break;
        case H059H:
            insertar_info_calle(t, id, crear_info_calle(0.410, 0.465, DIR_OESTE));
            break;
        case H058H:
            insertar_info_calle(t, id, crear_info_calle(0.426, 0.465, DIR_OESTE));
            break;
        case H057H:
            insertar_info_calle(t, id, crear_info_calle(0.442, 0.465, DIR_OESTE));
            break;
        case H056H:
            insertar_info_calle(t, id, crear_info_calle(0.458, 0.465, DIR_OESTE));
            break;
        case H055H:
            insertar_info_calle(t, id, crear_info_calle(0.474, 0.465, DIR_OESTE));
            break;
        case H054H:
            insertar_info_calle(t, id, crear_info_calle(0.5135, 0.465, DIR_OESTE));
            break;
        case H053H:
            insertar_info_calle(t, id, crear_info_calle(0.5325, 0.465, DIR_OESTE));
            break;
        case H052H:
            insertar_info_calle(t, id, crear_info_calle(0.5485, 0.465, DIR_OESTE));
            break;
        case H051H:
            insertar_info_calle(t, id, crear_info_calle(0.5645, 0.465, DIR_OESTE));
            break;
        case H050H:
            insertar_info_calle(t, id, crear_info_calle(0.5805, 0.465, DIR_OESTE));
            break;
        case H049H:
            insertar_info_calle(t, id, crear_info_calle(0.5965, 0.465, DIR_OESTE));
            break;
        case H048H:
            insertar_info_calle(t, id, crear_info_calle(0.6125, 0.465, DIR_OESTE));
            break;
        case H047H:
            insertar_info_calle(t, id, crear_info_calle(0.654, 0.465, DIR_OESTE));
            break;
        case H046H:
            insertar_info_calle(t, id, crear_info_calle(0.673, 0.465, DIR_OESTE));
            break;
        case H045H:
            insertar_info_calle(t, id, crear_info_calle(0.689, 0.465, DIR_OESTE));
            break;
        case H044H:
            insertar_info_calle(t, id, crear_info_calle(0.705, 0.465, DIR_OESTE));
            break;
        case H043H:
            insertar_info_calle(t, id, crear_info_calle(0.721, 0.465, DIR_OESTE));
            break;
        case H042H:
            insertar_info_calle(t, id, crear_info_calle(0.737, 0.465, DIR_OESTE));
            break;
        case H041H:
            insertar_info_calle(t, id, crear_info_calle(0.753, 0.465, DIR_OESTE));
            break;
        case H040H:
            insertar_info_calle(t, id, crear_info_calle(0.795, 0.465, DIR_OESTE));
            break;
        case H039H:
            insertar_info_calle(t, id, crear_info_calle(0.813, 0.465, DIR_OESTE));
            break;
        case H038H:
            insertar_info_calle(t, id, crear_info_calle(0.829, 0.465, DIR_OESTE));
            break;
        case H037H:
            insertar_info_calle(t, id, crear_info_calle(0.844, 0.465, DIR_OESTE));
            break;
        case H036H:
            insertar_info_calle(t, id, crear_info_calle(0.143, 0.426, DIR_OESTE));
            break;
        case H035H:
            insertar_info_calle(t, id, crear_info_calle(0.159, 0.426, DIR_OESTE));
            break;
        case H034H:
            insertar_info_calle(t, id, crear_info_calle(0.175, 0.426, DIR_OESTE));
            break;
        case H033H:
            insertar_info_calle(t, id, crear_info_calle(0.191, 0.426, DIR_OESTE));
            break;
        case H032H:
            insertar_info_calle(t, id, crear_info_calle(0.2335, 0.426, DIR_OESTE));
            break;
        case H031H:
            insertar_info_calle(t, id, crear_info_calle(0.2525, 0.426, DIR_OESTE));
            break;
        case H030H:
            insertar_info_calle(t, id, crear_info_calle(0.2685, 0.426, DIR_OESTE));
            break;
        case H029H:
            insertar_info_calle(t, id, crear_info_calle(0.2845, 0.426, DIR_OESTE));
            break;
        case H028H:
            insertar_info_calle(t, id, crear_info_calle(0.3005, 0.426, DIR_OESTE));
            break;
        case H027H:
            insertar_info_calle(t, id, crear_info_calle(0.3165, 0.426, DIR_OESTE));
            break;
        case H026H:
            insertar_info_calle(t, id, crear_info_calle(0.3325, 0.426, DIR_OESTE));
            break;
        case H025H:
            insertar_info_calle(t, id, crear_info_calle(0.375, 0.426, DIR_OESTE));
            break;
        case H024H:
            insertar_info_calle(t, id, crear_info_calle(0.394, 0.426, DIR_OESTE));
            break;
        case H023H:
            insertar_info_calle(t, id, crear_info_calle(0.410, 0.426, DIR_OESTE));
            break;
        case H022H:
            insertar_info_calle(t, id, crear_info_calle(0.426, 0.426, DIR_OESTE));
            break;
        case H021H:
            insertar_info_calle(t, id, crear_info_calle(0.442, 0.426, DIR_OESTE));
            break;
        case H020H:
            insertar_info_calle(t, id, crear_info_calle(0.458, 0.426, DIR_OESTE));
            break;
        case H019H:
            insertar_info_calle(t, id, crear_info_calle(0.474, 0.426, DIR_OESTE));
            break;
        case H018H:
            insertar_info_calle(t, id, crear_info_calle(0.5135, 0.426, DIR_OESTE));
            break;
        case H017H:
            insertar_info_calle(t, id, crear_info_calle(0.5325, 0.426, DIR_OESTE));
            break;
        case H016H:
            insertar_info_calle(t, id, crear_info_calle(0.5485, 0.426, DIR_OESTE));
            break;
        case H015H:
            insertar_info_calle(t, id, crear_info_calle(0.5645, 0.426, DIR_OESTE));
            break;
        case H014H:
            insertar_info_calle(t, id, crear_info_calle(0.5805, 0.426, DIR_OESTE));
            break;
        case H013H:
            insertar_info_calle(t, id, crear_info_calle(0.5965, 0.426, DIR_OESTE));
            break;
        case H012H:
            insertar_info_calle(t, id, crear_info_calle(0.6125, 0.426, DIR_OESTE));
            break;
        case H011H:
            insertar_info_calle(t, id, crear_info_calle(0.654, 0.426, DIR_OESTE));
            break;
        case H010H:
            insertar_info_calle(t, id, crear_info_calle(0.673, 0.426, DIR_OESTE));
            break;
        case H009H:
            insertar_info_calle(t, id, crear_info_calle(0.689, 0.426, DIR_OESTE));
            break;
        case H008H:
            insertar_info_calle(t, id, crear_info_calle(0.705, 0.426, DIR_OESTE));
            break;
        case H007H:
            insertar_info_calle(t, id, crear_info_calle(0.721, 0.426, DIR_OESTE));
            break;
        case H006H:
            insertar_info_calle(t, id, crear_info_calle(0.737, 0.426, DIR_OESTE));
            break;
        case H005H:
            insertar_info_calle(t, id, crear_info_calle(0.753, 0.426, DIR_OESTE));
            break;
        case H004H:
            insertar_info_calle(t, id, crear_info_calle(0.795, 0.426, DIR_OESTE));
            break;
        case H003H:
            insertar_info_calle(t, id, crear_info_calle(0.813, 0.426, DIR_OESTE));
            break;
        case H002H:
            insertar_info_calle(t, id, crear_info_calle(0.829, 0.426, DIR_OESTE));
            break;
        case H001H:
            insertar_info_calle(t, id, crear_info_calle(0.844, 0.426, DIR_OESTE));
            break;
        case H073H:
            insertar_info_calle(t, id, crear_info_calle(0.143, 0.512, DIR_ESTE));
            break;
        case H074H:
            insertar_info_calle(t, id, crear_info_calle(0.159, 0.512, DIR_ESTE));
            break;
        case H075H:
            insertar_info_calle(t, id, crear_info_calle(0.175, 0.512, DIR_ESTE));
            break;
        case H076H:
            insertar_info_calle(t, id, crear_info_calle(0.191, 0.512, DIR_ESTE));
            break;
        case H077H:
            insertar_info_calle(t, id, crear_info_calle(0.2335, 0.512, DIR_ESTE));
            break;
        case H078H:
            insertar_info_calle(t, id, crear_info_calle(0.2525, 0.512, DIR_ESTE));
            break;
        case H079H:
            insertar_info_calle(t, id, crear_info_calle(0.2685, 0.512, DIR_ESTE));
            break;
        case H080H:
            insertar_info_calle(t, id, crear_info_calle(0.2845, 0.512, DIR_ESTE));
            break;
        case H081H:
            insertar_info_calle(t, id, crear_info_calle(0.3005, 0.512, DIR_ESTE));
            break;
        case H082H:
            insertar_info_calle(t, id, crear_info_calle(0.3165, 0.512, DIR_ESTE));
            break;
        case H083H:
            insertar_info_calle(t, id, crear_info_calle(0.3325, 0.512, DIR_ESTE));
            break;
        case H084H:
            insertar_info_calle(t, id, crear_info_calle(0.375, 0.512, DIR_ESTE));
            break;
        case H085H:
            insertar_info_calle(t, id, crear_info_calle(0.394, 0.512, DIR_ESTE));
            break;
        case H086H:
            insertar_info_calle(t, id, crear_info_calle(0.410, 0.512, DIR_ESTE));
            break;
        case H087H:
            insertar_info_calle(t, id, crear_info_calle(0.426, 0.512, DIR_ESTE));
            break;
        case H088H:
            insertar_info_calle(t, id, crear_info_calle(0.442, 0.512, DIR_ESTE));
            break;
        case H089H:
            insertar_info_calle(t, id, crear_info_calle(0.458, 0.512, DIR_ESTE));
            break;
        case H090H:
            insertar_info_calle(t, id, crear_info_calle(0.474, 0.512, DIR_ESTE));
            break;
        case H091H:
            insertar_info_calle(t, id, crear_info_calle(0.5135, 0.512, DIR_ESTE));
            break;
        case H092H:
            insertar_info_calle(t, id, crear_info_calle(0.5325, 0.512, DIR_ESTE));
            break;
        case H093H:
            insertar_info_calle(t, id, crear_info_calle(0.5485, 0.512, DIR_ESTE));
            break;
        case H094H:
            insertar_info_calle(t, id, crear_info_calle(0.5645, 0.512, DIR_ESTE));
            break;
        case H095H:
            insertar_info_calle(t, id, crear_info_calle(0.5805, 0.512, DIR_ESTE));
            break;
        case H096H:
            insertar_info_calle(t, id, crear_info_calle(0.5965, 0.512, DIR_ESTE));
            break;
        case H097H:
            insertar_info_calle(t, id, crear_info_calle(0.6125, 0.512, DIR_ESTE));
            break;
        case H098H:
            insertar_info_calle(t, id, crear_info_calle(0.654, 0.512, DIR_ESTE));
            break;
        case H099H:
            insertar_info_calle(t, id, crear_info_calle(0.673, 0.512, DIR_ESTE));
            break;
        case H100H:
            insertar_info_calle(t, id, crear_info_calle(0.689, 0.512, DIR_ESTE));
            break;
        case H101H:
            insertar_info_calle(t, id, crear_info_calle(0.705, 0.512, DIR_ESTE));
            break;
        case H102H:
            insertar_info_calle(t, id, crear_info_calle(0.721, 0.512, DIR_ESTE));
            break;
        case H103H:
            insertar_info_calle(t, id, crear_info_calle(0.737, 0.512, DIR_ESTE));
            break;
        case H104H:
            insertar_info_calle(t, id, crear_info_calle(0.753, 0.512, DIR_ESTE));
            break;
        case H105H:
            insertar_info_calle(t, id, crear_info_calle(0.795, 0.512, DIR_ESTE));
            break;
        case H106H:
            insertar_info_calle(t, id, crear_info_calle(0.813, 0.512, DIR_ESTE));
            break;
        case H107H:
            insertar_info_calle(t, id, crear_info_calle(0.829, 0.512, DIR_ESTE));
            break;
        case H108H:
            insertar_info_calle(t, id, crear_info_calle(0.844, 0.512, DIR_ESTE));
            break;
        case H109H:
            insertar_info_calle(t, id, crear_info_calle(0.143, 0.55, DIR_ESTE));
            break;
        case H110H:
            insertar_info_calle(t, id, crear_info_calle(0.159, 0.55, DIR_ESTE));
            break;
        case H111H:
            insertar_info_calle(t, id, crear_info_calle(0.175, 0.55, DIR_ESTE));
            break;
        case H112H:
            insertar_info_calle(t, id, crear_info_calle(0.191, 0.55, DIR_ESTE));
            break;
        case H113H:
            insertar_info_calle(t, id, crear_info_calle(0.2335, 0.55, DIR_ESTE));
            break;
        case H114H:
            insertar_info_calle(t, id, crear_info_calle(0.2525, 0.55, DIR_ESTE));
            break;
        case H115H:
            insertar_info_calle(t, id, crear_info_calle(0.2685, 0.55, DIR_ESTE));
            break;
        case H116H:
            insertar_info_calle(t, id, crear_info_calle(0.2845, 0.55, DIR_ESTE));
            break;
        case H117H:
            insertar_info_calle(t, id, crear_info_calle(0.3005, 0.55, DIR_ESTE));
            break;
        case H118H:
            insertar_info_calle(t, id, crear_info_calle(0.3165, 0.55, DIR_ESTE));
            break;
        case H119H:
            insertar_info_calle(t, id, crear_info_calle(0.3325, 0.55, DIR_ESTE));
            break;
        case H120H:
            insertar_info_calle(t, id, crear_info_calle(0.375, 0.55, DIR_ESTE));
            break;
        case H121H:
            insertar_info_calle(t, id, crear_info_calle(0.394, 0.55, DIR_ESTE));
            break;
        case H122H:
            insertar_info_calle(t, id, crear_info_calle(0.410, 0.55, DIR_ESTE));
            break;
        case H123H:
            insertar_info_calle(t, id, crear_info_calle(0.426, 0.55, DIR_ESTE));
            break;
        case H124H:
            insertar_info_calle(t, id, crear_info_calle(0.442, 0.55, DIR_ESTE));
            break;
        case H125H:
            insertar_info_calle(t, id, crear_info_calle(0.458, 0.55, DIR_ESTE));
            break;
        case H126H:
            insertar_info_calle(t, id, crear_info_calle(0.474, 0.55, DIR_ESTE));
            break;
        case H127H:
            insertar_info_calle(t, id, crear_info_calle(0.5135, 0.55, DIR_ESTE));
            break;
        case H128H:
            insertar_info_calle(t, id, crear_info_calle(0.5325, 0.55, DIR_ESTE));
            break;
        case H129H:
            insertar_info_calle(t, id, crear_info_calle(0.5485, 0.55, DIR_ESTE));
            break;
        case H130H:
            insertar_info_calle(t, id, crear_info_calle(0.5645, 0.55, DIR_ESTE));
            break;
        case H131H:
            insertar_info_calle(t, id, crear_info_calle(0.5805, 0.55, DIR_ESTE));
            break;
        case H132H:
            insertar_info_calle(t, id, crear_info_calle(0.5965, 0.55, DIR_ESTE));
            break;
        case H133H:
            insertar_info_calle(t, id, crear_info_calle(0.6125, 0.55, DIR_ESTE));
            break;
        case H134H:
            insertar_info_calle(t, id, crear_info_calle(0.654, 0.55, DIR_ESTE));
            break;
        case H135H:
            insertar_info_calle(t, id, crear_info_calle(0.673, 0.55, DIR_ESTE));
            break;
        case H136H:
            insertar_info_calle(t, id, crear_info_calle(0.689, 0.55, DIR_ESTE));
            break;
        case H137H:
            insertar_info_calle(t, id, crear_info_calle(0.705, 0.55, DIR_ESTE));
            break;
        case H138H:
            insertar_info_calle(t, id, crear_info_calle(0.721, 0.55, DIR_ESTE));
            break;
        case H139H:
            insertar_info_calle(t, id, crear_info_calle(0.737, 0.55, DIR_ESTE));
            break;
        case H140H:
            insertar_info_calle(t, id, crear_info_calle(0.753, 0.55, DIR_ESTE));
            break;
        case H141H:
            insertar_info_calle(t, id, crear_info_calle(0.795, 0.55, DIR_ESTE));
            break;
        case H142H:
            insertar_info_calle(t, id, crear_info_calle(0.813, 0.55, DIR_ESTE));
            break;
        case H143H:
            insertar_info_calle(t, id, crear_info_calle(0.829, 0.55, DIR_ESTE));
            break;
        case H144H:
            insertar_info_calle(t, id, crear_info_calle(0.844, 0.55, DIR_ESTE));
            break;
        default:
            break;
    }
}

void insert_street_info_stops(TablaInfoCalle *t, StopIds id) {
    switch (id) {
        case A001S:
            insertar_info_calle(t, id, crear_info_calle(0.117, 0.040, DIR_NORTE));
            break;
        case A002S:
            insertar_info_calle(t, id, crear_info_calle(0.165, 0.040, DIR_NORTE));
            break;
        case A003S:
            insertar_info_calle(t, id, crear_info_calle(0.181, 0.067, DIR_NORTE));
            break;
        case A004S:
            insertar_info_calle(t, id, crear_info_calle(0.181, 0.135, DIR_NORTE));
            break;
        case A005S:
            insertar_info_calle(t, id, crear_info_calle(0.165, 0.162, DIR_NORTE));
            break;
        case A006S:
            insertar_info_calle(t, id, crear_info_calle(0.117, 0.162, DIR_NORTE));
            break;
        case A007S:
            insertar_info_calle(t, id, crear_info_calle(0.104, 0.135, DIR_NORTE));
            break;
        case A008S:
            insertar_info_calle(t, id, crear_info_calle(0.104, 0.067, DIR_NORTE));
            break;

        case B001S:
            insertar_info_calle(t, id, crear_info_calle(0.2585, 0.040, DIR_NORTE));
            break;
        case B002S:
            insertar_info_calle(t, id, crear_info_calle(0.3065, 0.040, DIR_NORTE));
            break;
        case B003S:
            insertar_info_calle(t, id, crear_info_calle(0.3215, 0.067, DIR_NORTE));
            break;
        case B004S:
            insertar_info_calle(t, id, crear_info_calle(0.3215, 0.135, DIR_NORTE));
            break;
        case B005S:
            insertar_info_calle(t, id, crear_info_calle(0.3065, 0.162, DIR_NORTE));
            break;
        case B006S:
            insertar_info_calle(t, id, crear_info_calle(0.2585, 0.162, DIR_NORTE));
            break;
        case B007S:
            insertar_info_calle(t, id, crear_info_calle(0.2455, 0.135, DIR_NORTE));
            break;
        case B008S:
            insertar_info_calle(t, id, crear_info_calle(0.2455, 0.067, DIR_NORTE));
            break;

        case C001S:
            insertar_info_calle(t, id, crear_info_calle(0.400, 0.040, DIR_NORTE));
            break;
        case C002S:
            insertar_info_calle(t, id, crear_info_calle(0.448, 0.040, DIR_NORTE));
            break;
        case C003S:
            insertar_info_calle(t, id, crear_info_calle(0.462, 0.067, DIR_NORTE));
            break;
        case C004S:
            insertar_info_calle(t, id, crear_info_calle(0.462, 0.135, DIR_NORTE));
            break;
        case C005S:
            insertar_info_calle(t, id, crear_info_calle(0.448, 0.162, DIR_NORTE));
            break;
        case C006S:
            insertar_info_calle(t, id, crear_info_calle(0.400, 0.162, DIR_NORTE));
            break;
        case C007S:
            insertar_info_calle(t, id, crear_info_calle(0.386, 0.135, DIR_NORTE));
            break;
        case C008S:
            insertar_info_calle(t, id, crear_info_calle(0.386, 0.067, DIR_NORTE));
            break;

        case D001S:
            insertar_info_calle(t, id, crear_info_calle(0.5385, 0.040, DIR_NORTE));
            break;
        case D002S:
            insertar_info_calle(t, id, crear_info_calle(0.5865, 0.040, DIR_NORTE));
            break;
        case D003S:
            insertar_info_calle(t, id, crear_info_calle(0.6025, 0.066, DIR_NORTE));
            break;
        case D004S:
            insertar_info_calle(t, id, crear_info_calle(0.6025, 0.134, DIR_NORTE));
            break;
        case D005S:
            insertar_info_calle(t, id, crear_info_calle(0.5865, 0.162, DIR_NORTE));
            break;
        case D006S:
            insertar_info_calle(t, id, crear_info_calle(0.5385, 0.162, DIR_NORTE));
            break;
        case D007S:
            insertar_info_calle(t, id, crear_info_calle(0.5255, 0.135, DIR_NORTE));
            break;
        case D008S:
            insertar_info_calle(t, id, crear_info_calle(0.5255, 0.067, DIR_NORTE));
            break;

        case E001S:
            insertar_info_calle(t, id, crear_info_calle(0.679, 0.040, DIR_NORTE));
            break;
        case E002S:
            insertar_info_calle(t, id, crear_info_calle(0.727, 0.040, DIR_NORTE));
            break;
        case E003S:
            insertar_info_calle(t, id, crear_info_calle(0.743, 0.067, DIR_NORTE));
            break;
        case E004S:
            insertar_info_calle(t, id, crear_info_calle(0.743, 0.135, DIR_NORTE));
            break;
        case E005S:
            insertar_info_calle(t, id, crear_info_calle(0.727, 0.162, DIR_NORTE));
            break;
        case E006S:
            insertar_info_calle(t, id, crear_info_calle(0.679, 0.162, DIR_NORTE));
            break;
        case E007S:
            insertar_info_calle(t, id, crear_info_calle(0.666, 0.135, DIR_NORTE));
            break;
        case E008S:
            insertar_info_calle(t, id, crear_info_calle(0.666, 0.067, DIR_NORTE));
            break;

        case F001S:
            insertar_info_calle(t, id, crear_info_calle(0.819, 0.040, DIR_NORTE));
            break;
        case F002S:
            insertar_info_calle(t, id, crear_info_calle(0.867, 0.040, DIR_NORTE));
            break;
        case F003S:
            insertar_info_calle(t, id, crear_info_calle(0.883, 0.067, DIR_NORTE));
            break;
        case F004S:
            insertar_info_calle(t, id, crear_info_calle(0.883, 0.135, DIR_NORTE));
            break;
        case F005S:
            insertar_info_calle(t, id, crear_info_calle(0.867, 0.162, DIR_NORTE));
            break;
        case F006S:
            insertar_info_calle(t, id, crear_info_calle(0.819, 0.162, DIR_NORTE));
            break;
        case F007S:
            insertar_info_calle(t, id, crear_info_calle(0.806, 0.135, DIR_NORTE));
            break;
        case F008S:
            insertar_info_calle(t, id, crear_info_calle(0.806, 0.067, DIR_NORTE));
            break;

        case G001S:
            insertar_info_calle(t, id, crear_info_calle(0.117, 0.226, DIR_NORTE));
            break;
        case G002S:
            insertar_info_calle(t, id, crear_info_calle(0.165, 0.226, DIR_NORTE));
            break;
        case G003S:
            insertar_info_calle(t, id, crear_info_calle(0.181, 0.253, DIR_NORTE));
            break;
        case G004S:
            insertar_info_calle(t, id, crear_info_calle(0.181, 0.321, DIR_NORTE));
            break;
        case G005S:
            insertar_info_calle(t, id, crear_info_calle(0.104, 0.321, DIR_NORTE));
            break;
        case G006S:
            insertar_info_calle(t, id, crear_info_calle(0.104, 0.253, DIR_NORTE));
            break;

        case H001S:
            insertar_info_calle(t, id, crear_info_calle(0.2585, 0.226, DIR_NORTE));
            break;
        case H002S:
            insertar_info_calle(t, id, crear_info_calle(0.3065, 0.226, DIR_NORTE));
            break;
        case H003S:
            insertar_info_calle(t, id, crear_info_calle(0.3215, 0.253, DIR_NORTE));
            break;
        case H004S:
            insertar_info_calle(t, id, crear_info_calle(0.3215, 0.321, DIR_NORTE));
            break;
        case H005S:
            insertar_info_calle(t, id, crear_info_calle(0.2455, 0.321, DIR_NORTE));
            break;
        case H006S:
            insertar_info_calle(t, id, crear_info_calle(0.2455, 0.253, DIR_NORTE));
            break;

        case I001S:
            insertar_info_calle(t, id, crear_info_calle(0.400, 0.226, DIR_NORTE));
            break;
        case I002S:
            insertar_info_calle(t, id, crear_info_calle(0.448, 0.226, DIR_NORTE));
            break;
        case I003S:
            insertar_info_calle(t, id, crear_info_calle(0.462, 0.253, DIR_NORTE));
            break;
        case I004S:
            insertar_info_calle(t, id, crear_info_calle(0.462, 0.321, DIR_NORTE));
            break;
        case I005S:
            insertar_info_calle(t, id, crear_info_calle(0.386, 0.321, DIR_NORTE));
            break;
        case I006S:
            insertar_info_calle(t, id, crear_info_calle(0.386, 0.253, DIR_NORTE));
            break;

        case J001S:
            insertar_info_calle(t, id, crear_info_calle(0.5385, 0.226, DIR_NORTE));
            break;
        case J002S:
            insertar_info_calle(t, id, crear_info_calle(0.5865, 0.226, DIR_NORTE));
            break;
        case J003S:
            insertar_info_calle(t, id, crear_info_calle(0.6025, 0.252, DIR_NORTE));
            break;
        case J004S:
            insertar_info_calle(t, id, crear_info_calle(0.6025, 0.32, DIR_NORTE));
            break;
        case J005S:
            insertar_info_calle(t, id, crear_info_calle(0.5255, 0.321, DIR_NORTE));
            break;
        case J006S:
            insertar_info_calle(t, id, crear_info_calle(0.5255, 0.253, DIR_NORTE));
            break;

        case K001S:
            insertar_info_calle(t, id, crear_info_calle(0.679, 0.226, DIR_NORTE));
            break;
        case K002S:
            insertar_info_calle(t, id, crear_info_calle(0.727, 0.226, DIR_NORTE));
            break;
        case K003S:
            insertar_info_calle(t, id, crear_info_calle(0.743, 0.253, DIR_NORTE));
            break;
        case K004S:
            insertar_info_calle(t, id, crear_info_calle(0.743, 0.321, DIR_NORTE));
            break;
        case K005S:
            insertar_info_calle(t, id, crear_info_calle(0.666, 0.321, DIR_NORTE));
            break;
        case K006S:
            insertar_info_calle(t, id, crear_info_calle(0.666, 0.253, DIR_NORTE));
            break;

        case L001S:
            insertar_info_calle(t, id, crear_info_calle(0.819, 0.226, DIR_NORTE));
            break;
        case L002S:
            insertar_info_calle(t, id, crear_info_calle(0.867, 0.226, DIR_NORTE));
            break;
        case L003S:
            insertar_info_calle(t, id, crear_info_calle(0.883, 0.253, DIR_NORTE));
            break;
        case L004S:
            insertar_info_calle(t, id, crear_info_calle(0.883, 0.321, DIR_NORTE));
            break;
        case L005S:
            insertar_info_calle(t, id, crear_info_calle(0.806, 0.321, DIR_NORTE));
            break;
        case L006S:
            insertar_info_calle(t, id, crear_info_calle(0.806, 0.253, DIR_NORTE));
            break;

        case M002S:
            insertar_info_calle(t, id, crear_info_calle(0.181, 0.655, DIR_NORTE));
            break;
        case M003S:
            insertar_info_calle(t, id, crear_info_calle(0.181, 0.723, DIR_NORTE));
            break;
        case M004S:
            insertar_info_calle(t, id, crear_info_calle(0.165, 0.75, DIR_NORTE));
            break;
        case M005S:
            insertar_info_calle(t, id, crear_info_calle(0.117, 0.75, DIR_NORTE));
            break;
        case M006S:
            insertar_info_calle(t, id, crear_info_calle(0.104, 0.723, DIR_NORTE));
            break;
        case M001S:
            insertar_info_calle(t, id, crear_info_calle(0.104, 0.655, DIR_NORTE));
            break;

        case N002S:
            insertar_info_calle(t, id, crear_info_calle(0.3215, 0.655, DIR_NORTE));
            break;
        case N003S:
            insertar_info_calle(t, id, crear_info_calle(0.3215, 0.723, DIR_NORTE));
            break;
        case N004S:
            insertar_info_calle(t, id, crear_info_calle(0.3065, 0.75, DIR_NORTE));
            break;
        case N005S:
            insertar_info_calle(t, id, crear_info_calle(0.2585, 0.75, DIR_NORTE));
            break;
        case N006S:
            insertar_info_calle(t, id, crear_info_calle(0.2455, 0.723, DIR_NORTE));
            break;
        case N001S:
            insertar_info_calle(t, id, crear_info_calle(0.2455, 0.655, DIR_NORTE));
            break;

        case O002S:
            insertar_info_calle(t, id, crear_info_calle(0.462, 0.655, DIR_NORTE));
            break;
        case O003S:
            insertar_info_calle(t, id, crear_info_calle(0.462, 0.723, DIR_NORTE));
            break;
        case O004S:
            insertar_info_calle(t, id, crear_info_calle(0.448, 0.75, DIR_NORTE));
            break;
        case O005S:
            insertar_info_calle(t, id, crear_info_calle(0.400, 0.75, DIR_NORTE));
            break;
        case O006S:
            insertar_info_calle(t, id, crear_info_calle(0.386, 0.723, DIR_NORTE));
            break;
        case O001S:
            insertar_info_calle(t, id, crear_info_calle(0.386, 0.655, DIR_NORTE));
            break;

        case P002S:
            insertar_info_calle(t, id, crear_info_calle(0.6025, 0.654, DIR_NORTE));
            break;
        case P003S:
            insertar_info_calle(t, id, crear_info_calle(0.6025, 0.722, DIR_NORTE));
            break;
        case P004S:
            insertar_info_calle(t, id, crear_info_calle(0.5865, 0.75, DIR_NORTE));
            break;
        case P005S:
            insertar_info_calle(t, id, crear_info_calle(0.5385, 0.75, DIR_NORTE));
            break;
        case P006S:
            insertar_info_calle(t, id, crear_info_calle(0.5255, 0.723, DIR_NORTE));
            break;
        case P001S:
            insertar_info_calle(t, id, crear_info_calle(0.5255, 0.655, DIR_NORTE));
            break;

        case Q002S:
            insertar_info_calle(t, id, crear_info_calle(0.743, 0.655, DIR_NORTE));
            break;
        case Q003S:
            insertar_info_calle(t, id, crear_info_calle(0.743, 0.723, DIR_NORTE));
            break;
        case Q004S:
            insertar_info_calle(t, id, crear_info_calle(0.727, 0.75, DIR_NORTE));
            break;
        case Q005S:
            insertar_info_calle(t, id, crear_info_calle(0.679, 0.75, DIR_NORTE));
            break;
        case Q006S:
            insertar_info_calle(t, id, crear_info_calle(0.666, 0.723, DIR_NORTE));
            break;
        case Q001S:
            insertar_info_calle(t, id, crear_info_calle(0.666, 0.655, DIR_NORTE));
            break;

        case R002S:
            insertar_info_calle(t, id, crear_info_calle(0.883, 0.655, DIR_NORTE));
            break;
        case R003S:
            insertar_info_calle(t, id, crear_info_calle(0.883, 0.723, DIR_NORTE));
            break;
        case R004S:
            insertar_info_calle(t, id, crear_info_calle(0.867, 0.75, DIR_NORTE));
            break;
        case R005S:
            insertar_info_calle(t, id, crear_info_calle(0.819, 0.75, DIR_NORTE));
            break;
        case R006S:
            insertar_info_calle(t, id, crear_info_calle(0.806, 0.723, DIR_NORTE));
            break;
        case R001S:
            insertar_info_calle(t, id, crear_info_calle(0.806, 0.655, DIR_NORTE));
            break;

        case S001S:
            insertar_info_calle(t, id, crear_info_calle(0.117, 0.815, DIR_NORTE));
            break;
        case S002S:
            insertar_info_calle(t, id, crear_info_calle(0.165, 0.815, DIR_NORTE));
            break;
        case S003S:
            insertar_info_calle(t, id, crear_info_calle(0.181, 0.842, DIR_NORTE));
            break;
        case S004S:
            insertar_info_calle(t, id, crear_info_calle(0.181, 0.907, DIR_NORTE));
            break;
        case S005S:
            insertar_info_calle(t, id, crear_info_calle(0.165, 0.935, DIR_NORTE));
            break;
        case S006S:
            insertar_info_calle(t, id, crear_info_calle(0.117, 0.935, DIR_NORTE));
            break;
        case S007S:
            insertar_info_calle(t, id, crear_info_calle(0.104, 0.907, DIR_NORTE));
            break;
        case S008S:
            insertar_info_calle(t, id, crear_info_calle(0.104, 0.842, DIR_NORTE));
            break;

        case T001S:
            insertar_info_calle(t, id, crear_info_calle(0.2585, 0.815, DIR_NORTE));
            break;
        case T002S:
            insertar_info_calle(t, id, crear_info_calle(0.3065, 0.815, DIR_NORTE));
            break;
        case T003S:
            insertar_info_calle(t, id, crear_info_calle(0.3215, 0.842, DIR_NORTE));
            break;
        case T004S:
            insertar_info_calle(t, id, crear_info_calle(0.3215, 0.907, DIR_NORTE));
            break;
        case T005S:
            insertar_info_calle(t, id, crear_info_calle(0.3065, 0.935, DIR_NORTE));
            break;
        case T006S:
            insertar_info_calle(t, id, crear_info_calle(0.2585, 0.935, DIR_NORTE));
            break;
        case T007S:
            insertar_info_calle(t, id, crear_info_calle(0.2455, 0.907, DIR_NORTE));
            break;
        case T008S:
            insertar_info_calle(t, id, crear_info_calle(0.2455, 0.842, DIR_NORTE));
            break;

        case U001S:
            insertar_info_calle(t, id, crear_info_calle(0.400, 0.815, DIR_NORTE));
            break;
        case U002S:
            insertar_info_calle(t, id, crear_info_calle(0.448, 0.815, DIR_NORTE));
            break;
        case U003S:
            insertar_info_calle(t, id, crear_info_calle(0.462, 0.842, DIR_NORTE));
            break;
        case U004S:
            insertar_info_calle(t, id, crear_info_calle(0.462, 0.907, DIR_NORTE));
            break;
        case U005S:
            insertar_info_calle(t, id, crear_info_calle(0.448, 0.935, DIR_NORTE));
            break;
        case U006S:
            insertar_info_calle(t, id, crear_info_calle(0.400, 0.935, DIR_NORTE));
            break;
        case U007S:
            insertar_info_calle(t, id, crear_info_calle(0.386, 0.907, DIR_NORTE));
            break;
        case U008S:
            insertar_info_calle(t, id, crear_info_calle(0.386, 0.842, DIR_NORTE));
            break;

        case V001S:
            insertar_info_calle(t, id, crear_info_calle(0.5385, 0.815, DIR_NORTE));
            break;
        case V002S:
            insertar_info_calle(t, id, crear_info_calle(0.5865, 0.815, DIR_NORTE));
            break;
        case V003S:
            insertar_info_calle(t, id, crear_info_calle(0.6025, 0.841, DIR_NORTE));
            break;
        case V004S:
            insertar_info_calle(t, id, crear_info_calle(0.6025, 0.909, DIR_NORTE));
            break;
        case V005S:
            insertar_info_calle(t, id, crear_info_calle(0.5865, 0.935, DIR_NORTE));
            break;
        case V006S:
            insertar_info_calle(t, id, crear_info_calle(0.5385, 0.935, DIR_NORTE));
            break;
        case V007S:
            insertar_info_calle(t, id, crear_info_calle(0.5255, 0.907, DIR_NORTE));
            break;
        case V008S:
            insertar_info_calle(t, id, crear_info_calle(0.5255, 0.842, DIR_NORTE));
            break;

        case W001S:
            insertar_info_calle(t, id, crear_info_calle(0.679, 0.815, DIR_NORTE));
            break;
        case W002S:
            insertar_info_calle(t, id, crear_info_calle(0.727, 0.815, DIR_NORTE));
            break;
        case W003S:
            insertar_info_calle(t, id, crear_info_calle(0.743, 0.842, DIR_NORTE));
            break;
        case W004S:
            insertar_info_calle(t, id, crear_info_calle(0.743, 0.907, DIR_NORTE));
            break;
        case W005S:
            insertar_info_calle(t, id, crear_info_calle(0.727, 0.935, DIR_NORTE));
            break;
        case W006S:
            insertar_info_calle(t, id, crear_info_calle(0.679, 0.935, DIR_NORTE));
            break;
        case W007S:
            insertar_info_calle(t, id, crear_info_calle(0.666, 0.907, DIR_NORTE));
            break;
        case W008S:
            insertar_info_calle(t, id, crear_info_calle(0.666, 0.842, DIR_NORTE));
            break;

        case X001S:
            insertar_info_calle(t, id, crear_info_calle(0.819, 0.815, DIR_NORTE));
            break;
        case X002S:
            insertar_info_calle(t, id, crear_info_calle(0.867, 0.815, DIR_NORTE));
            break;
        case X003S:
            insertar_info_calle(t, id, crear_info_calle(0.883, 0.842, DIR_NORTE));
            break;
        case X004S:
            insertar_info_calle(t, id, crear_info_calle(0.883, 0.907, DIR_NORTE));
            break;
        case X005S:
            insertar_info_calle(t, id, crear_info_calle(0.867, 0.935, DIR_NORTE));
            break;
        case X006S:
            insertar_info_calle(t, id, crear_info_calle(0.819, 0.935, DIR_NORTE));
            break;
        case X007S:
            insertar_info_calle(t, id, crear_info_calle(0.806, 0.907, DIR_NORTE));
            break;
        case X008S:
            insertar_info_calle(t, id, crear_info_calle(0.806, 0.842, DIR_NORTE));
            break;
        default:
            break;
    }
}

void insert_street_info_roundabouts(TablaInfoCalle *t, RoundaboutIds id) {
    switch (id) {
        case Y001R:
            insertar_info_calle(t, id, crear_info_calle(0.111, 0.45, DIR_NORTE));
            break;
        case Y002R:
            insertar_info_calle(t, id, crear_info_calle(0.111, 0.53, DIR_NORTE));
            break;
        case Y003R:
            insertar_info_calle(t, id, crear_info_calle(0.059, 0.59, DIR_NORTE));
            break;
        case Y004R:
            insertar_info_calle(t, id, crear_info_calle(0.009, 0.53, DIR_NORTE));
            break;
        case Y005R:
            insertar_info_calle(t, id, crear_info_calle(0.009, 0.45, DIR_NORTE));
            break;
        case Y006R:
            insertar_info_calle(t, id, crear_info_calle(0.059, 0.39, DIR_NORTE));
            break;
        case Z001R:
            insertar_info_calle(t, id, crear_info_calle(0.874, 0.45, DIR_NORTE));
            break;
        case Z002R:
            insertar_info_calle(t, id, crear_info_calle(0.874, 0.53, DIR_NORTE));
            break;
        case Z003R:
            insertar_info_calle(t, id, crear_info_calle(0.924, 0.59, DIR_NORTE));
            break;
        case Z004R:
            insertar_info_calle(t, id, crear_info_calle(0.976, 0.53, DIR_NORTE));
            break;
        case Z005R:
            insertar_info_calle(t, id, crear_info_calle(0.976, 0.45, DIR_NORTE));
            break;
        case Z006R:
            insertar_info_calle(t, id, crear_info_calle(0.924, 0.39, DIR_NORTE));
            break;
        default:
            break;
    }
}

void insert_street_info_bridge_up(TablaInfoCalle *t, BridgeIds id) {
    switch (id) {
        case BU06B:
            insertar_info_calle(t, id, crear_info_calle(0.213, 0.420, DIR_NORTE));
            break;
        case BU05B:
            insertar_info_calle(t, id, crear_info_calle(0.213, 0.447, DIR_NORTE));
            break;
        case BU04B:
            insertar_info_calle(t, id, crear_info_calle(0.213, 0.475, DIR_NORTE));
            break;
        case BU03B:
            insertar_info_calle(t, id, crear_info_calle(0.213, 0.501, DIR_NORTE));
            break;
        case BU02B:
            insertar_info_calle(t, id, crear_info_calle(0.213, 0.528, DIR_NORTE));
            break;
        case BU01B:
            insertar_info_calle(t, id, crear_info_calle(0.213, 0.555, DIR_NORTE));
            break;

        case BU12B:
            insertar_info_calle(t, id, crear_info_calle(0.353, 0.420, DIR_NORTE));
            break;
        case BU11B:
            insertar_info_calle(t, id, crear_info_calle(0.353, 0.447, DIR_NORTE));
            break;
        case BU10B:
            insertar_info_calle(t, id, crear_info_calle(0.353, 0.475, DIR_NORTE));
            break;
        case BU09B:
            insertar_info_calle(t, id, crear_info_calle(0.353, 0.501, DIR_NORTE));
            break;
        case BU08B:
            insertar_info_calle(t, id, crear_info_calle(0.353, 0.528, DIR_NORTE));
            break;
        case BU07B:
            insertar_info_calle(t, id, crear_info_calle(0.353, 0.555, DIR_NORTE));
            break;

        case BU18B:
            insertar_info_calle(t, id, crear_info_calle(0.493, 0.420, DIR_NORTE));
            break;
        case BU17B:
            insertar_info_calle(t, id, crear_info_calle(0.493, 0.447, DIR_NORTE));
            break;
        case BU16B:
            insertar_info_calle(t, id, crear_info_calle(0.493, 0.475, DIR_NORTE));
            break;
        case BU15B:
            insertar_info_calle(t, id, crear_info_calle(0.493, 0.501, DIR_NORTE));
            break;
        case BU14B:
            insertar_info_calle(t, id, crear_info_calle(0.493, 0.528, DIR_NORTE));
            break;
        case BU13B:
            insertar_info_calle(t, id, crear_info_calle(0.493, 0.555, DIR_NORTE));
            break;

        case BU24B:
            insertar_info_calle(t, id, crear_info_calle(0.634, 0.420, DIR_NORTE));
            break;
        case BU23B:
            insertar_info_calle(t, id, crear_info_calle(0.634, 0.447, DIR_NORTE));
            break;
        case BU22B:
            insertar_info_calle(t, id, crear_info_calle(0.634, 0.475, DIR_NORTE));
            break;
        case BU21B:
            insertar_info_calle(t, id, crear_info_calle(0.634, 0.501, DIR_NORTE));
            break;
        case BU20B:
            insertar_info_calle(t, id, crear_info_calle(0.634, 0.528, DIR_NORTE));
            break;
        case BU19B:
            insertar_info_calle(t, id, crear_info_calle(0.634, 0.555, DIR_NORTE));
            break;

        case BU30B:
            insertar_info_calle(t, id, crear_info_calle(0.775, 0.420, DIR_NORTE));
            break;
        case BU29B:
            insertar_info_calle(t, id, crear_info_calle(0.775, 0.447, DIR_NORTE));
            break;
        case BU28B:
            insertar_info_calle(t, id, crear_info_calle(0.775, 0.475, DIR_NORTE));
            break;
        case BU27B:
            insertar_info_calle(t, id, crear_info_calle(0.775, 0.501, DIR_NORTE));
            break;
        case BU26B:
            insertar_info_calle(t, id, crear_info_calle(0.775, 0.528, DIR_NORTE));
            break;
        case BU25B:
            insertar_info_calle(t, id, crear_info_calle(0.775, 0.555, DIR_NORTE));
            break;
        default:
            break;
    }
}

void insert_street_info_bridge(TablaInfoCalle *t, BridgeIds id) {
    switch (id) {
        case B001B:
            insertar_info_calle(t, id, crear_info_calle(0.213, 0.420, DIR_SUR));
            break;
        case B002B:
            insertar_info_calle(t, id, crear_info_calle(0.213, 0.447, DIR_SUR));
            break;
        case B003B:
            insertar_info_calle(t, id, crear_info_calle(0.213, 0.475, DIR_SUR));
            break;
        case B004B:
            insertar_info_calle(t, id, crear_info_calle(0.213, 0.501, DIR_SUR));
            break;
        case B005B:
            insertar_info_calle(t, id, crear_info_calle(0.213, 0.528, DIR_SUR));
            break;
        case B006B:
            insertar_info_calle(t, id, crear_info_calle(0.213, 0.555, DIR_SUR));
            break;

        case B007B:
            insertar_info_calle(t, id, crear_info_calle(0.353, 0.420, DIR_SUR));
            break;
        case B008B:
            insertar_info_calle(t, id, crear_info_calle(0.353, 0.447, DIR_SUR));
            break;
        case B009B:
            insertar_info_calle(t, id, crear_info_calle(0.353, 0.475, DIR_SUR));
            break;
        case B010B:
            insertar_info_calle(t, id, crear_info_calle(0.353, 0.501, DIR_SUR));
            break;
        case B011B:
            insertar_info_calle(t, id, crear_info_calle(0.353, 0.528, DIR_SUR));
            break;
        case B012B:
            insertar_info_calle(t, id, crear_info_calle(0.353, 0.555, DIR_SUR));
            break;

        case B013B:
            insertar_info_calle(t, id, crear_info_calle(0.493, 0.420, DIR_SUR));
            break;
        case B014B:
            insertar_info_calle(t, id, crear_info_calle(0.493, 0.447, DIR_SUR));
            break;
        case B015B:
            insertar_info_calle(t, id, crear_info_calle(0.493, 0.475, DIR_SUR));
            break;
        case B016B:
            insertar_info_calle(t, id, crear_info_calle(0.493, 0.501, DIR_SUR));
            break;
        case B017B:
            insertar_info_calle(t, id, crear_info_calle(0.493, 0.528, DIR_SUR));
            break;
        case B018B:
            insertar_info_calle(t, id, crear_info_calle(0.493, 0.555, DIR_SUR));
            break;

        case B019B:
            insertar_info_calle(t, id, crear_info_calle(0.634, 0.420, DIR_SUR));
            break;
        case B020B:
            insertar_info_calle(t, id, crear_info_calle(0.634, 0.447, DIR_SUR));
            break;
        case B021B:
            insertar_info_calle(t, id, crear_info_calle(0.634, 0.475, DIR_SUR));
            break;
        case B022B:
            insertar_info_calle(t, id, crear_info_calle(0.634, 0.501, DIR_SUR));
            break;
        case B023B:
            insertar_info_calle(t, id, crear_info_calle(0.634, 0.528, DIR_SUR));
            break;
        case B024B:
            insertar_info_calle(t, id, crear_info_calle(0.634, 0.555, DIR_SUR));
            break;

        case B025B:
            insertar_info_calle(t, id, crear_info_calle(0.775, 0.420, DIR_SUR));
            break;
        case B026B:
            insertar_info_calle(t, id, crear_info_calle(0.775, 0.447, DIR_SUR));
            break;
        case B027B:
            insertar_info_calle(t, id, crear_info_calle(0.775, 0.475, DIR_SUR));
            break;
        case B028B:
            insertar_info_calle(t, id, crear_info_calle(0.775, 0.501, DIR_SUR));
            break;
        case B029B:
            insertar_info_calle(t, id, crear_info_calle(0.775, 0.528, DIR_SUR));
            break;
        case B030B:
            insertar_info_calle(t, id, crear_info_calle(0.775, 0.555, DIR_SUR));
            break;
        default:
            break;
    }
}

void insert_street_info_streets(TablaInfoCalle *t, StreetIds id) {
    switch (id) {
        //++Fila0
//Segmento 0

        case A001P:
            insertar_info_calle(t, id, crear_info_calle(0.101, 0.007, DIR_ESTE));
            break;
        case A002P:
            insertar_info_calle(t, id, crear_info_calle(0.117, 0.007, DIR_ESTE));
            break;
        case A003P:
            insertar_info_calle(t, id, crear_info_calle(0.133, 0.007, DIR_ESTE));
            break;
        case A004P:
            insertar_info_calle(t, id, crear_info_calle(0.149, 0.007, DIR_ESTE));
            break;
        case A005P:
            insertar_info_calle(t, id, crear_info_calle(0.165, 0.007, DIR_ESTE));
            break;
        case A006P:
            insertar_info_calle(t, id, crear_info_calle(0.181, 0.007, DIR_ESTE));
            break;
//Segmento 1
        case B001P:
            insertar_info_calle(t, id, crear_info_calle(0.2425, 0.007, DIR_ESTE));
            break;
        case B002P:
            insertar_info_calle(t, id, crear_info_calle(0.2585, 0.007, DIR_ESTE));
            break;
        case B003P:
            insertar_info_calle(t, id, crear_info_calle(0.2745, 0.007, DIR_ESTE));
            break;
        case B004P:
            insertar_info_calle(t, id, crear_info_calle(0.2905, 0.007, DIR_ESTE));
            break;
        case B005P:
            insertar_info_calle(t, id, crear_info_calle(0.3065, 0.007, DIR_ESTE));
            break;
        case B006P:
            insertar_info_calle(t, id, crear_info_calle(0.3225, 0.007, DIR_ESTE));
            break;
//Segmento 2
        case C001P:
            insertar_info_calle(t, id, crear_info_calle(0.384, 0.007, DIR_ESTE));
            break;
        case C002P:
            insertar_info_calle(t, id, crear_info_calle(0.400, 0.007, DIR_ESTE));
            break;
        case C003P:
            insertar_info_calle(t, id, crear_info_calle(0.416, 0.007, DIR_ESTE));
            break;
        case C004P:
            insertar_info_calle(t, id, crear_info_calle(0.432, 0.007, DIR_ESTE));
            break;
        case C005P:
            insertar_info_calle(t, id, crear_info_calle(0.448, 0.007, DIR_ESTE));
            break;
        case C006P:
            insertar_info_calle(t, id, crear_info_calle(0.464, 0.007, DIR_ESTE));
            break;
//Segmento 3
        case D001P:
            insertar_info_calle(t, id, crear_info_calle(0.5225, 0.007, DIR_ESTE));
            break;
        case D002P:
            insertar_info_calle(t, id, crear_info_calle(0.5385, 0.007, DIR_ESTE));
            break;
        case D003P:
            insertar_info_calle(t, id, crear_info_calle(0.5545, 0.007, DIR_ESTE));
            break;
        case D004P:
            insertar_info_calle(t, id, crear_info_calle(0.5705, 0.007, DIR_ESTE));
            break;
        case D005P:
            insertar_info_calle(t, id, crear_info_calle(0.5865, 0.007, DIR_ESTE));
            break;
        case D006P:
            insertar_info_calle(t, id, crear_info_calle(0.6025, 0.007, DIR_ESTE));
            break;
//Segmento 4
        case E001P:
            insertar_info_calle(t, id, crear_info_calle(0.663, 0.007, DIR_ESTE));
            break;
        case E002P:
            insertar_info_calle(t, id, crear_info_calle(0.679, 0.007, DIR_ESTE));
            break;
        case E003P:
            insertar_info_calle(t, id, crear_info_calle(0.695, 0.007, DIR_ESTE));
            break;
        case E004P:
            insertar_info_calle(t, id, crear_info_calle(0.711, 0.007, DIR_ESTE));
            break;
        case E005P:
            insertar_info_calle(t, id, crear_info_calle(0.727, 0.007, DIR_ESTE));
            break;
        case E006P:
            insertar_info_calle(t, id, crear_info_calle(0.743, 0.007, DIR_ESTE));
            break;
//Segmento 5
        case F001P:
            insertar_info_calle(t, id, crear_info_calle(0.803, 0.007, DIR_ESTE));
            break;
        case F002P:
            insertar_info_calle(t, id, crear_info_calle(0.819, 0.007, DIR_ESTE));
            break;
        case F003P:
            insertar_info_calle(t, id, crear_info_calle(0.834, 0.007, DIR_ESTE));
            break;
        case F004P:
            insertar_info_calle(t, id, crear_info_calle(0.851, 0.007, DIR_ESTE));
            break;
        case F005P:
            insertar_info_calle(t, id, crear_info_calle(0.867, 0.007, DIR_ESTE));
            break;
        case F006P:
            insertar_info_calle(t, id, crear_info_calle(0.883, 0.007, DIR_ESTE));
            break;

//++Fila1
//Segmento 0
        case A018P: // && G006P
            insertar_info_calle(t, id, crear_info_calle(0.101, 0.194, DIR_OESTE));
            break;
        case A017P: // && G005P
            insertar_info_calle(t, id, crear_info_calle(0.117, 0.194, DIR_OESTE));
            break;
        case A016P: // && G004P
            insertar_info_calle(t, id, crear_info_calle(0.133, 0.194, DIR_OESTE));
            break;
        case A015P: // && G003P
            insertar_info_calle(t, id, crear_info_calle(0.149, 0.194, DIR_OESTE));
            break;
        case A014P: // && G002P
            insertar_info_calle(t, id, crear_info_calle(0.165, 0.194, DIR_OESTE));
            break;
        case A013P: // && G001P
            insertar_info_calle(t, id, crear_info_calle(0.181, 0.194, DIR_OESTE));
            break;
//Segmento 1
        case B018P: // && H006P
            insertar_info_calle(t, id, crear_info_calle(0.2425, 0.194, DIR_OESTE));
            break;
        case B017P: // && H005P
            insertar_info_calle(t, id, crear_info_calle(0.2585, 0.194, DIR_OESTE));
            break;
        case B016P: // && H004P
            insertar_info_calle(t, id, crear_info_calle(0.2745, 0.194, DIR_OESTE));
            break;
        case B015P: // && H003P
            insertar_info_calle(t, id, crear_info_calle(0.2905, 0.194, DIR_OESTE));
            break;
        case B014P: // && H002P
            insertar_info_calle(t, id, crear_info_calle(0.3065, 0.194, DIR_OESTE));
            break;
        case B013P: // && H001P
            insertar_info_calle(t, id, crear_info_calle(0.3225, 0.194, DIR_OESTE));
            break;
//Segmento 2
        case C018P: // && I006P
            insertar_info_calle(t, id, crear_info_calle(0.384, 0.194, DIR_OESTE));
            break;
        case C017P: // && I005P
            insertar_info_calle(t, id, crear_info_calle(0.400, 0.194, DIR_OESTE));
            break;
        case C016P: // && I004P
            insertar_info_calle(t, id, crear_info_calle(0.416, 0.194, DIR_OESTE));
            break;
        case C015P: // && I003P
            insertar_info_calle(t, id, crear_info_calle(0.432, 0.194, DIR_OESTE));
            break;
        case C014P: // && I002P
            insertar_info_calle(t, id, crear_info_calle(0.448, 0.194, DIR_OESTE));
            break;
        case C013P: // && I001P
            insertar_info_calle(t, id, crear_info_calle(0.464, 0.194, DIR_OESTE));
            break;

//Segmento 3
        case D018P: // && J006P
            insertar_info_calle(t, id, crear_info_calle(0.5225, 0.194, DIR_OESTE));
            break;
        case D017P: // && J005P
            insertar_info_calle(t, id, crear_info_calle(0.5385, 0.194, DIR_OESTE));
            break;
        case D016P: // && J004P
            insertar_info_calle(t, id, crear_info_calle(0.5545, 0.194, DIR_OESTE));
            break;
        case D015P: // && J003P
            insertar_info_calle(t, id, crear_info_calle(0.5705, 0.194, DIR_OESTE));
            break;
        case D014P: // && J002P
            insertar_info_calle(t, id, crear_info_calle(0.5865, 0.194, DIR_OESTE));
            break;
        case D013P: // && J001P
            insertar_info_calle(t, id, crear_info_calle(0.6025, 0.194, DIR_OESTE));
            break;
//Segmento 4
        case E018P: // && K006P
            insertar_info_calle(t, id, crear_info_calle(0.663, 0.194, DIR_OESTE));
            break;
        case E017P: // && K005P
            insertar_info_calle(t, id, crear_info_calle(0.679, 0.194, DIR_OESTE));
            break;
        case E016P: // && K004P
            insertar_info_calle(t, id, crear_info_calle(0.695, 0.194, DIR_OESTE));
            break;
        case E015P: // && K003P
            insertar_info_calle(t, id, crear_info_calle(0.711, 0.194, DIR_OESTE));
            break;
        case E014P: // && K002P
            insertar_info_calle(t, id, crear_info_calle(0.727, 0.194, DIR_OESTE));
            break;
        case E013P: // && K001P
            insertar_info_calle(t, id, crear_info_calle(0.743, 0.194, DIR_OESTE));
            break;
//Segmento 5
        case F018P: // && L006P
            insertar_info_calle(t, id, crear_info_calle(0.803, 0.194, DIR_OESTE));
            break;
        case F017P: // && L005P
            insertar_info_calle(t, id, crear_info_calle(0.819, 0.194, DIR_OESTE));
            break;
        case F016P: // && L004P
            insertar_info_calle(t, id, crear_info_calle(0.834, 0.194, DIR_OESTE));
            break;
        case F015P: // && L003P
            insertar_info_calle(t, id, crear_info_calle(0.851, 0.194, DIR_OESTE));
            break;
        case F014P: // && L002P
            insertar_info_calle(t, id, crear_info_calle(0.867, 0.194, DIR_OESTE));
            break;
        case F013P: // && L001P
            insertar_info_calle(t, id, crear_info_calle(0.883, 0.194, DIR_OESTE));
            break;

//++Fila2
//Segmento 0
        case M012P: // && S001P
            insertar_info_calle(t, id, crear_info_calle(0.101, 0.778, DIR_ESTE));
            break;
        case M011P: // && S002P
            insertar_info_calle(t, id, crear_info_calle(0.117, 0.778, DIR_ESTE));
            break;
        case M010P: // && S003P
            insertar_info_calle(t, id, crear_info_calle(0.133, 0.778, DIR_ESTE));
            break;
        case M009P: // && S004P
            insertar_info_calle(t, id, crear_info_calle(0.149, 0.778, DIR_ESTE));
            break;
        case M008P: // && S005P
            insertar_info_calle(t, id, crear_info_calle(0.165, 0.778, DIR_ESTE));
            break;
        case M007P: // && S006P
            insertar_info_calle(t, id, crear_info_calle(0.181, 0.778, DIR_ESTE));
            break;
//Segmento 1
        case N012P: // && T001P
            insertar_info_calle(t, id, crear_info_calle(0.2425, 0.778, DIR_ESTE));
            break;
        case N011P: // && T002P
            insertar_info_calle(t, id, crear_info_calle(0.2585, 0.778, DIR_ESTE));
            break;
        case N010P: // && T003P
            insertar_info_calle(t, id, crear_info_calle(0.2745, 0.778, DIR_ESTE));
            break;
        case N009P: // && T004P
            insertar_info_calle(t, id, crear_info_calle(0.2905, 0.778, DIR_ESTE));
            break;
        case N008P: // && T005P
            insertar_info_calle(t, id, crear_info_calle(0.3065, 0.778, DIR_ESTE));
            break;
        case N007P: // && T006P
            insertar_info_calle(t, id, crear_info_calle(0.3225, 0.778, DIR_ESTE));
            break;
//Segmento 2
        case O012P: // && U001P
            insertar_info_calle(t, id, crear_info_calle(0.384, 0.778, DIR_ESTE));
            break;
        case O011P: // && U002P
            insertar_info_calle(t, id, crear_info_calle(0.400, 0.778, DIR_ESTE));
            break;
        case O010P: // && U003P
            insertar_info_calle(t, id, crear_info_calle(0.416, 0.778, DIR_ESTE));
            break;
        case O009P: // && U004P
            insertar_info_calle(t, id, crear_info_calle(0.432, 0.778, DIR_ESTE));
            break;
        case O008P: // && U005P
            insertar_info_calle(t, id, crear_info_calle(0.448, 0.778, DIR_ESTE));
            break;
        case O007P: // && U006P
            insertar_info_calle(t, id, crear_info_calle(0.464, 0.778, DIR_ESTE));
            break;

//Segmento 3
        case P012P: // && P007P
            insertar_info_calle(t, id, crear_info_calle(0.5225, 0.778, DIR_ESTE));
            break;
        case P011P: // && P008P
            insertar_info_calle(t, id, crear_info_calle(0.5385, 0.778, DIR_ESTE));
            break;
        case P010P: // && P009P
            insertar_info_calle(t, id, crear_info_calle(0.5545, 0.778, DIR_ESTE));
            break;
        case P009P: // && P010P
            insertar_info_calle(t, id, crear_info_calle(0.5705, 0.778, DIR_ESTE));
            break;
        case P008P: // && P011P
            insertar_info_calle(t, id, crear_info_calle(0.5865, 0.778, DIR_ESTE));
            break;
        case P007P: // && P012P
            insertar_info_calle(t, id, crear_info_calle(0.6025, 0.778, DIR_ESTE));
            break;
//Segmento 4
        case Q012P: // && W001P
            insertar_info_calle(t, id, crear_info_calle(0.663, 0.778, DIR_ESTE));
            break;
        case Q011P: // && W002P
            insertar_info_calle(t, id, crear_info_calle(0.679, 0.778, DIR_ESTE));
            break;
        case Q010P: // && W003P
            insertar_info_calle(t, id, crear_info_calle(0.695, 0.778, DIR_ESTE));
            break;
        case Q009P: // && W004P
            insertar_info_calle(t, id, crear_info_calle(0.711, 0.778, DIR_ESTE));
            break;
        case Q008P: // && W005P
            insertar_info_calle(t, id, crear_info_calle(0.727, 0.778, DIR_ESTE));
            break;
        case Q007P: // && W006P
            insertar_info_calle(t, id, crear_info_calle(0.743, 0.778, DIR_ESTE));
            break;
//Segmento 5
        case R012P: // && X001P
            insertar_info_calle(t, id, crear_info_calle(0.803, 0.778, DIR_ESTE));
            break;
        case R011P: // && X002P
            insertar_info_calle(t, id, crear_info_calle(0.819, 0.778, DIR_ESTE));
            break;
        case R010P: // && X003P
            insertar_info_calle(t, id, crear_info_calle(0.834, 0.778, DIR_ESTE));
            break;
        case R009P: // && X004P
            insertar_info_calle(t, id, crear_info_calle(0.851, 0.778, DIR_ESTE));
            break;
        case R008P: // && X005P
            insertar_info_calle(t, id, crear_info_calle(0.867, 0.778, DIR_ESTE));
            break;
        case R007P: // && X006P
            insertar_info_calle(t, id, crear_info_calle(0.883, 0.778, DIR_ESTE));
            break;
//++Fila3
//Segmento 0
        case S018P:
            insertar_info_calle(t, id, crear_info_calle(0.101, 0.965, DIR_OESTE));
            break;
        case S017P:
            insertar_info_calle(t, id, crear_info_calle(0.117, 0.965, DIR_OESTE));
            break;
        case S016P:
            insertar_info_calle(t, id, crear_info_calle(0.133, 0.965, DIR_OESTE));
            break;
        case S015P:
            insertar_info_calle(t, id, crear_info_calle(0.149, 0.965, DIR_OESTE));
            break;
        case S014P:
            insertar_info_calle(t, id, crear_info_calle(0.165, 0.965, DIR_OESTE));
            break;
        case S013P:
            insertar_info_calle(t, id, crear_info_calle(0.181, 0.965, DIR_OESTE));
            break;
//Segmento 1
        case T018P:
            insertar_info_calle(t, id, crear_info_calle(0.2425, 0.965, DIR_OESTE));
            break;
        case T017P:
            insertar_info_calle(t, id, crear_info_calle(0.2585, 0.965, DIR_OESTE));
            break;
        case T016P:
            insertar_info_calle(t, id, crear_info_calle(0.2745, 0.965, DIR_OESTE));
            break;
        case T015P:
            insertar_info_calle(t, id, crear_info_calle(0.2905, 0.965, DIR_OESTE));
            break;
        case T014P:
            insertar_info_calle(t, id, crear_info_calle(0.3065, 0.965, DIR_OESTE));
            break;
        case T013P:
            insertar_info_calle(t, id, crear_info_calle(0.3225, 0.965, DIR_OESTE));
            break;
//Segmento 2
        case U018P:
            insertar_info_calle(t, id, crear_info_calle(0.384, 0.965, DIR_OESTE));
            break;
        case U017P:
            insertar_info_calle(t, id, crear_info_calle(0.400, 0.965, DIR_OESTE));
            break;
        case U016P:
            insertar_info_calle(t, id, crear_info_calle(0.416, 0.965, DIR_OESTE));
            break;
        case U015P:
            insertar_info_calle(t, id, crear_info_calle(0.432, 0.965, DIR_OESTE));
            break;
        case U014P:
            insertar_info_calle(t, id, crear_info_calle(0.448, 0.965, DIR_OESTE));
            break;
        case U013P:
            insertar_info_calle(t, id, crear_info_calle(0.464, 0.965, DIR_OESTE));
            break;
//Segmento 3
        case V018P:
            insertar_info_calle(t, id, crear_info_calle(0.5225, 0.965, DIR_OESTE));
            break;
        case V017P:
            insertar_info_calle(t, id, crear_info_calle(0.5385, 0.965, DIR_OESTE));
            break;
        case V016P:
            insertar_info_calle(t, id, crear_info_calle(0.5545, 0.965, DIR_OESTE));
            break;
        case V015P:
            insertar_info_calle(t, id, crear_info_calle(0.5705, 0.965, DIR_OESTE));
            break;
        case V014P:
            insertar_info_calle(t, id, crear_info_calle(0.5865, 0.965, DIR_OESTE));
            break;
        case V013P:
            insertar_info_calle(t, id, crear_info_calle(0.6025, 0.965, DIR_OESTE));
            break;
//Segmento 4
        case W018P:
            insertar_info_calle(t, id, crear_info_calle(0.663, 0.965, DIR_OESTE));
            break;
        case W017P:
            insertar_info_calle(t, id, crear_info_calle(0.679, 0.965, DIR_OESTE));
            break;
        case W016P:
            insertar_info_calle(t, id, crear_info_calle(0.695, 0.965, DIR_OESTE));
            break;
        case W015P:
            insertar_info_calle(t, id, crear_info_calle(0.711, 0.965, DIR_OESTE));
            break;
        case W014P:
            insertar_info_calle(t, id, crear_info_calle(0.727, 0.965, DIR_OESTE));
            break;
        case W013P:
            insertar_info_calle(t, id, crear_info_calle(0.743, 0.965, DIR_OESTE));
            break;
//Segmento 5
        case X018P:
            insertar_info_calle(t, id, crear_info_calle(0.803, 0.965, DIR_OESTE));
            break;
        case X017P:
            insertar_info_calle(t, id, crear_info_calle(0.819, 0.965, DIR_OESTE));
            break;
        case X016P:
            insertar_info_calle(t, id, crear_info_calle(0.834, 0.965, DIR_OESTE));
            break;
        case X015P:
            insertar_info_calle(t, id, crear_info_calle(0.851, 0.965, DIR_OESTE));
            break;
        case X014P:
            insertar_info_calle(t, id, crear_info_calle(0.867, 0.965, DIR_OESTE));
            break;
        case X013P:
            insertar_info_calle(t, id, crear_info_calle(0.883, 0.965, DIR_OESTE));
            break;
//Parte superior
//Columna 0
        case A024P:
            insertar_info_calle(t, id, crear_info_calle(0.085, 0.040, DIR_NORTE));
            break;
        case A023P:
            insertar_info_calle(t, id, crear_info_calle(0.085, 0.065, DIR_NORTE));
            break;
        case A022P:
            insertar_info_calle(t, id, crear_info_calle(0.085, 0.090, DIR_NORTE));
            break;
        case A021P:
            insertar_info_calle(t, id, crear_info_calle(0.085, 0.115, DIR_NORTE));
            break;
        case A020P:
            insertar_info_calle(t, id, crear_info_calle(0.085, 0.138, DIR_NORTE));
            break;
        case A019P:
            insertar_info_calle(t, id, crear_info_calle(0.085, 0.163, DIR_NORTE));
            break;
        case G018P:
            insertar_info_calle(t, id, crear_info_calle(0.085, 0.226, DIR_NORTE));
            break;
        case G017P:
            insertar_info_calle(t, id, crear_info_calle(0.085, 0.251, DIR_NORTE));
            break;
        case G016P:
            insertar_info_calle(t, id, crear_info_calle(0.085, 0.275, DIR_NORTE));
            break;
        case G015P:
            insertar_info_calle(t, id, crear_info_calle(0.085, 0.300, DIR_NORTE));
            break;
        case G014P:
            insertar_info_calle(t, id, crear_info_calle(0.085, 0.323, DIR_NORTE));
            break;
        case G013P:
            insertar_info_calle(t, id, crear_info_calle(0.085, 0.345, DIR_NORTE));
            break;
//Columna 1
        case A007P:
            insertar_info_calle(t, id, crear_info_calle(0.200, 0.040, DIR_SUR));
            break;
        case A008P:
            insertar_info_calle(t, id, crear_info_calle(0.200, 0.065, DIR_SUR));
            break;
        case A009P:
            insertar_info_calle(t, id, crear_info_calle(0.200, 0.090, DIR_SUR));
            break;
        case A010P:
            insertar_info_calle(t, id, crear_info_calle(0.200, 0.115, DIR_SUR));
            break;
        case A011P:
            insertar_info_calle(t, id, crear_info_calle(0.200, 0.138, DIR_SUR));
            break;
        case A012P:
            insertar_info_calle(t, id, crear_info_calle(0.200, 0.163, DIR_SUR));
            break;
        case G007P:
            insertar_info_calle(t, id, crear_info_calle(0.200, 0.226, DIR_SUR));
            break;
        case G008P:
            insertar_info_calle(t, id, crear_info_calle(0.200, 0.251, DIR_SUR));
            break;
        case G009P:
            insertar_info_calle(t, id, crear_info_calle(0.200, 0.275, DIR_SUR));
            break;
        case G010P:
            insertar_info_calle(t, id, crear_info_calle(0.200, 0.300, DIR_SUR));
            break;
        case G011P:
            insertar_info_calle(t, id, crear_info_calle(0.200, 0.323, DIR_SUR));
            break;
        case G012P:
            insertar_info_calle(t, id, crear_info_calle(0.200, 0.345, DIR_SUR));
            break;
//Columna 2
        case B024P:
            insertar_info_calle(t, id, crear_info_calle(0.2235, 0.040, DIR_NORTE));
            break;
        case B023P:
            insertar_info_calle(t, id, crear_info_calle(0.2235, 0.065, DIR_NORTE));
            break;
        case B022P:
            insertar_info_calle(t, id, crear_info_calle(0.2235, 0.090, DIR_NORTE));
            break;
        case B021P:
            insertar_info_calle(t, id, crear_info_calle(0.2235, 0.115, DIR_NORTE));
            break;
        case B020P:
            insertar_info_calle(t, id, crear_info_calle(0.2235, 0.138, DIR_NORTE));
            break;
        case B019P:
            insertar_info_calle(t, id, crear_info_calle(0.2235, 0.163, DIR_NORTE));
            break;
        case H018P:
            insertar_info_calle(t, id, crear_info_calle(0.2235, 0.226, DIR_NORTE));
            break;
        case H017P:
            insertar_info_calle(t, id, crear_info_calle(0.2235, 0.251, DIR_NORTE));
            break;
        case H016P:
            insertar_info_calle(t, id, crear_info_calle(0.2235, 0.275, DIR_NORTE));
            break;
        case H015P:
            insertar_info_calle(t, id, crear_info_calle(0.2235, 0.300, DIR_NORTE));
            break;
        case H014P:
            insertar_info_calle(t, id, crear_info_calle(0.2235, 0.323, DIR_NORTE));
            break;
        case H013P:
            insertar_info_calle(t, id, crear_info_calle(0.2235, 0.345, DIR_NORTE));
            break;
//Columna 3
        case B007P:
            insertar_info_calle(t, id, crear_info_calle(0.3415, 0.040, DIR_SUR));
            break;
        case B008P:
            insertar_info_calle(t, id, crear_info_calle(0.3415, 0.065, DIR_SUR));
            break;
        case B009P:
            insertar_info_calle(t, id, crear_info_calle(0.3415, 0.090, DIR_SUR));
            break;
        case B010P:
            insertar_info_calle(t, id, crear_info_calle(0.3415, 0.115, DIR_SUR));
            break;
        case B011P:
            insertar_info_calle(t, id, crear_info_calle(0.3415, 0.138, DIR_SUR));
            break;
        case B012P:
            insertar_info_calle(t, id, crear_info_calle(0.3415, 0.163, DIR_SUR));
            break;
        case H007P:
            insertar_info_calle(t, id, crear_info_calle(0.3415, 0.226, DIR_SUR));
            break;
        case H008P:
            insertar_info_calle(t, id, crear_info_calle(0.3415, 0.251, DIR_SUR));
            break;
        case H009P:
            insertar_info_calle(t, id, crear_info_calle(0.3415, 0.275, DIR_SUR));
            break;
        case H010P:
            insertar_info_calle(t, id, crear_info_calle(0.3415, 0.300, DIR_SUR));
            break;
        case H011P:
            insertar_info_calle(t, id, crear_info_calle(0.3415, 0.323, DIR_SUR));
            break;
        case H012P:
            insertar_info_calle(t, id, crear_info_calle(0.3415, 0.345, DIR_SUR));
            break;
//Columna 4
        case C024P:
            insertar_info_calle(t, id, crear_info_calle(0.365, 0.040, DIR_NORTE));
            break;
        case C023P:
            insertar_info_calle(t, id, crear_info_calle(0.365, 0.065, DIR_NORTE));
            break;
        case C022P:
            insertar_info_calle(t, id, crear_info_calle(0.365, 0.090, DIR_NORTE));
            break;
        case C021P:
            insertar_info_calle(t, id, crear_info_calle(0.365, 0.115, DIR_NORTE));
            break;
        case C020P:
            insertar_info_calle(t, id, crear_info_calle(0.365, 0.138, DIR_NORTE));
            break;
        case C019P:
            insertar_info_calle(t, id, crear_info_calle(0.365, 0.163, DIR_NORTE));
            break;
        case I018P:
            insertar_info_calle(t, id, crear_info_calle(0.365, 0.226, DIR_NORTE));
            break;
        case I017P:
            insertar_info_calle(t, id, crear_info_calle(0.365, 0.251, DIR_NORTE));
            break;
        case I016P:
            insertar_info_calle(t, id, crear_info_calle(0.365, 0.275, DIR_NORTE));
            break;
        case I015P:
            insertar_info_calle(t, id, crear_info_calle(0.365, 0.300, DIR_NORTE));
            break;
        case I014P:
            insertar_info_calle(t, id, crear_info_calle(0.365, 0.323, DIR_NORTE));
            break;
        case I013P:
            insertar_info_calle(t, id, crear_info_calle(0.365, 0.345, DIR_NORTE));
            break;
//Columna 5
        case C007P:
            insertar_info_calle(t, id, crear_info_calle(0.483, 0.040, DIR_SUR));
            break;
        case C008P:
            insertar_info_calle(t, id, crear_info_calle(0.483, 0.065, DIR_SUR));
            break;
        case C009P:
            insertar_info_calle(t, id, crear_info_calle(0.483, 0.090, DIR_SUR));
            break;
        case C010P:
            insertar_info_calle(t, id, crear_info_calle(0.483, 0.115, DIR_SUR));
            break;
        case C011P:
            insertar_info_calle(t, id, crear_info_calle(0.483, 0.138, DIR_SUR));
            break;
        case C012P:
            insertar_info_calle(t, id, crear_info_calle(0.483, 0.163, DIR_SUR));
            break;
        case I007P:
            insertar_info_calle(t, id, crear_info_calle(0.483, 0.226, DIR_SUR));
            break;
        case I008P:
            insertar_info_calle(t, id, crear_info_calle(0.483, 0.251, DIR_SUR));
            break;
        case I009P:
            insertar_info_calle(t, id, crear_info_calle(0.483, 0.275, DIR_SUR));
            break;
        case I010P:
            insertar_info_calle(t, id, crear_info_calle(0.483, 0.300, DIR_SUR));
            break;
        case I011P:
            insertar_info_calle(t, id, crear_info_calle(0.483, 0.323, DIR_SUR));
            break;
        case I012P:
            insertar_info_calle(t, id, crear_info_calle(0.483, 0.345, DIR_SUR));
            break;
//Columna 6
        case D024P:
            insertar_info_calle(t, id, crear_info_calle(0.5035, 0.040, DIR_NORTE));
            break;
        case D023P:
            insertar_info_calle(t, id, crear_info_calle(0.5035, 0.065, DIR_NORTE));
            break;
        case D022P:
            insertar_info_calle(t, id, crear_info_calle(0.5035, 0.090, DIR_NORTE));
            break;
        case D021P:
            insertar_info_calle(t, id, crear_info_calle(0.5035, 0.115, DIR_NORTE));
            break;
        case D020P:
            insertar_info_calle(t, id, crear_info_calle(0.5035, 0.138, DIR_NORTE));
            break;
        case D019P:
            insertar_info_calle(t, id, crear_info_calle(0.5035, 0.163, DIR_NORTE));
            break;
        case J018P:
            insertar_info_calle(t, id, crear_info_calle(0.5035, 0.226, DIR_NORTE));
            break;
        case J017P:
            insertar_info_calle(t, id, crear_info_calle(0.5035, 0.251, DIR_NORTE));
            break;
        case J016P:
            insertar_info_calle(t, id, crear_info_calle(0.5035, 0.275, DIR_NORTE));
            break;
        case J015P:
            insertar_info_calle(t, id, crear_info_calle(0.5035, 0.300, DIR_NORTE));
            break;
        case J014P:
            insertar_info_calle(t, id, crear_info_calle(0.5035, 0.323, DIR_NORTE));
            break;
        case J013P:
            insertar_info_calle(t, id, crear_info_calle(0.5035, 0.345, DIR_NORTE));
            break;
//Columna 7
        case D007P:
            insertar_info_calle(t, id, crear_info_calle(0.6215, 0.040, DIR_SUR));
            break;
        case D008P:
            insertar_info_calle(t, id, crear_info_calle(0.6215, 0.065, DIR_SUR));
            break;
        case D009P:
            insertar_info_calle(t, id, crear_info_calle(0.6215, 0.090, DIR_SUR));
            break;
        case D010P:
            insertar_info_calle(t, id, crear_info_calle(0.6215, 0.115, DIR_SUR));
            break;
        case D011P:
            insertar_info_calle(t, id, crear_info_calle(0.6215, 0.138, DIR_SUR));
            break;
        case D012P:
            insertar_info_calle(t, id, crear_info_calle(0.6215, 0.163, DIR_SUR));
            break;
        case J007P:
            insertar_info_calle(t, id, crear_info_calle(0.6215, 0.226, DIR_SUR));
            break;
        case J008P:
            insertar_info_calle(t, id, crear_info_calle(0.6215, 0.251, DIR_SUR));
            break;
        case J009P:
            insertar_info_calle(t, id, crear_info_calle(0.6215, 0.275, DIR_SUR));
            break;
        case J010P:
            insertar_info_calle(t, id, crear_info_calle(0.6215, 0.300, DIR_SUR));
            break;
        case J011P:
            insertar_info_calle(t, id, crear_info_calle(0.6215, 0.323, DIR_SUR));
            break;
        case J012P:
            insertar_info_calle(t, id, crear_info_calle(0.6215, 0.345, DIR_SUR));
            break;
//Columna 8
        case E024P:
            insertar_info_calle(t, id, crear_info_calle(0.644, 0.040, DIR_NORTE));
            break;
        case E023P:
            insertar_info_calle(t, id, crear_info_calle(0.644, 0.065, DIR_NORTE));
            break;
        case E022P:
            insertar_info_calle(t, id, crear_info_calle(0.644, 0.090, DIR_NORTE));
            break;
        case E021P:
            insertar_info_calle(t, id, crear_info_calle(0.644, 0.115, DIR_NORTE));
            break;
        case E020P:
            insertar_info_calle(t, id, crear_info_calle(0.644, 0.138, DIR_NORTE));
            break;
        case E019P:
            insertar_info_calle(t, id, crear_info_calle(0.644, 0.163, DIR_NORTE));
            break;
        case K018P:
            insertar_info_calle(t, id, crear_info_calle(0.644, 0.226, DIR_NORTE));
            break;
        case K017P:
            insertar_info_calle(t, id, crear_info_calle(0.644, 0.251, DIR_NORTE));
            break;
        case K016P:
            insertar_info_calle(t, id, crear_info_calle(0.644, 0.275, DIR_NORTE));
            break;
        case K015P:
            insertar_info_calle(t, id, crear_info_calle(0.644, 0.300, DIR_NORTE));
            break;
        case K014P:
            insertar_info_calle(t, id, crear_info_calle(0.644, 0.323, DIR_NORTE));
            break;
        case K013P:
            insertar_info_calle(t, id, crear_info_calle(0.644, 0.345, DIR_NORTE));
            break;
//Columna 9
        case E007P:
            insertar_info_calle(t, id, crear_info_calle(0.762, 0.040, DIR_SUR));
            break;
        case E008P:
            insertar_info_calle(t, id, crear_info_calle(0.762, 0.065, DIR_SUR));
            break;
        case E009P:
            insertar_info_calle(t, id, crear_info_calle(0.762, 0.090, DIR_SUR));
            break;
        case E010P:
            insertar_info_calle(t, id, crear_info_calle(0.762, 0.115, DIR_SUR));
            break;
        case E011P:
            insertar_info_calle(t, id, crear_info_calle(0.762, 0.138, DIR_SUR));
            break;
        case E012P:
            insertar_info_calle(t, id, crear_info_calle(0.762, 0.163, DIR_SUR));
            break;
        case K007P:
            insertar_info_calle(t, id, crear_info_calle(0.762, 0.226, DIR_SUR));
            break;
        case K008P:
            insertar_info_calle(t, id, crear_info_calle(0.762, 0.251, DIR_SUR));
            break;
        case K009P:
            insertar_info_calle(t, id, crear_info_calle(0.762, 0.275, DIR_SUR));
            break;
        case K010P:
            insertar_info_calle(t, id, crear_info_calle(0.762, 0.300, DIR_SUR));
            break;
        case K011P:
            insertar_info_calle(t, id, crear_info_calle(0.762, 0.323, DIR_SUR));
            break;
        case K012P:
            insertar_info_calle(t, id, crear_info_calle(0.762, 0.345, DIR_SUR));
            break;
//Columna 10
        case F024P:
            insertar_info_calle(t, id, crear_info_calle(0.785, 0.040, DIR_NORTE));
            break;
        case F023P:
            insertar_info_calle(t, id, crear_info_calle(0.785, 0.065, DIR_NORTE));
            break;
        case F022P:
            insertar_info_calle(t, id, crear_info_calle(0.785, 0.090, DIR_NORTE));
            break;
        case F021P:
            insertar_info_calle(t, id, crear_info_calle(0.785, 0.115, DIR_NORTE));
            break;
        case F020P:
            insertar_info_calle(t, id, crear_info_calle(0.785, 0.138, DIR_NORTE));
            break;
        case F019P:
            insertar_info_calle(t, id, crear_info_calle(0.785, 0.163, DIR_NORTE));
            break;
        case L018P:
            insertar_info_calle(t, id, crear_info_calle(0.785, 0.226, DIR_NORTE));
            break;
        case L017P:
            insertar_info_calle(t, id, crear_info_calle(0.785, 0.251, DIR_NORTE));
            break;
        case L016P:
            insertar_info_calle(t, id, crear_info_calle(0.785, 0.275, DIR_NORTE));
            break;
        case L015P:
            insertar_info_calle(t, id, crear_info_calle(0.785, 0.300, DIR_NORTE));
            break;
        case L014P:
            insertar_info_calle(t, id, crear_info_calle(0.785, 0.323, DIR_NORTE));
            break;
        case L013P:
            insertar_info_calle(t, id, crear_info_calle(0.785, 0.345, DIR_NORTE));
            break;
//Columna 11
        case F007P:
            insertar_info_calle(t, id, crear_info_calle(0.900, 0.040, DIR_SUR));
            break;
        case F008P:
            insertar_info_calle(t, id, crear_info_calle(0.900, 0.065, DIR_SUR));
            break;
        case F009P:
            insertar_info_calle(t, id, crear_info_calle(0.900, 0.090, DIR_SUR));
            break;
        case F010P:
            insertar_info_calle(t, id, crear_info_calle(0.900, 0.115, DIR_SUR));
            break;
        case F011P:
            insertar_info_calle(t, id, crear_info_calle(0.900, 0.138, DIR_SUR));
            break;
        case F012P:
            insertar_info_calle(t, id, crear_info_calle(0.900, 0.163, DIR_SUR));
            break;
        case L007P:
            insertar_info_calle(t, id, crear_info_calle(0.900, 0.226, DIR_SUR));
            break;
        case L008P:
            insertar_info_calle(t, id, crear_info_calle(0.900, 0.251, DIR_SUR));
            break;
        case L009P:
            insertar_info_calle(t, id, crear_info_calle(0.900, 0.275, DIR_SUR));
            break;
        case L010P:
            insertar_info_calle(t, id, crear_info_calle(0.900, 0.300, DIR_SUR));
            break;
        case L011P:
            insertar_info_calle(t, id, crear_info_calle(0.900, 0.323, DIR_SUR));
            break;
        case L012P:
            insertar_info_calle(t, id, crear_info_calle(0.900, 0.345, DIR_SUR));
            break;

//Parte inferior
//Columna 0
        case M018P:
            insertar_info_calle(t, id, crear_info_calle(0.085, 0.629, DIR_NORTE));
            break;
        case M017P:
            insertar_info_calle(t, id, crear_info_calle(0.085, 0.654, DIR_NORTE));
            break;
        case M016P:
            insertar_info_calle(t, id, crear_info_calle(0.085, 0.676, DIR_NORTE));
            break;
        case M015P:
            insertar_info_calle(t, id, crear_info_calle(0.085, 0.700, DIR_NORTE));
            break;
        case M014P:
            insertar_info_calle(t, id, crear_info_calle(0.085, 0.723, DIR_NORTE));
            break;
        case M013P:
            insertar_info_calle(t, id, crear_info_calle(0.085, 0.750, DIR_NORTE));
            break;
        case S024P:
            insertar_info_calle(t, id, crear_info_calle(0.085, 0.812, DIR_NORTE));
            break;
        case S023P:
            insertar_info_calle(t, id, crear_info_calle(0.085, 0.839, DIR_NORTE));
            break;
        case S022P:
            insertar_info_calle(t, id, crear_info_calle(0.085, 0.861, DIR_NORTE));
            break;
        case S021P:
            insertar_info_calle(t, id, crear_info_calle(0.085, 0.882, DIR_NORTE));
            break;
        case S020P:
            insertar_info_calle(t, id, crear_info_calle(0.085, 0.907, DIR_NORTE));
            break;
        case S019P:
            insertar_info_calle(t, id, crear_info_calle(0.085, 0.933, DIR_NORTE));
            break;
//Columna 1
        case M001P:
            insertar_info_calle(t, id, crear_info_calle(0.200, 0.629, DIR_SUR));
            break;
        case M002P:
            insertar_info_calle(t, id, crear_info_calle(0.200, 0.654, DIR_SUR));
            break;
        case M003P:
            insertar_info_calle(t, id, crear_info_calle(0.200, 0.676, DIR_SUR));
            break;
        case M004P:
            insertar_info_calle(t, id, crear_info_calle(0.200, 0.700, DIR_SUR));
            break;
        case M005P:
            insertar_info_calle(t, id, crear_info_calle(0.200, 0.723, DIR_SUR));
            break;
        case M006P:
            insertar_info_calle(t, id, crear_info_calle(0.200, 0.750, DIR_SUR));
            break;
        case S007P:
            insertar_info_calle(t, id, crear_info_calle(0.200, 0.812, DIR_SUR));
            break;
        case S008P:
            insertar_info_calle(t, id, crear_info_calle(0.200, 0.839, DIR_SUR));
            break;
        case S009P:
            insertar_info_calle(t, id, crear_info_calle(0.200, 0.861, DIR_SUR));
            break;
        case S010P:
            insertar_info_calle(t, id, crear_info_calle(0.200, 0.882, DIR_SUR));
            break;
        case S011P:
            insertar_info_calle(t, id, crear_info_calle(0.200, 0.907, DIR_SUR));
            break;
        case S012P:
            insertar_info_calle(t, id, crear_info_calle(0.200, 0.933, DIR_SUR));
            break;
//Columna 2
        case N018P:
            insertar_info_calle(t, id, crear_info_calle(0.2235, 0.629, DIR_NORTE));
            break;
        case N017P:
            insertar_info_calle(t, id, crear_info_calle(0.2235, 0.654, DIR_NORTE));
            break;
        case N016P:
            insertar_info_calle(t, id, crear_info_calle(0.2235, 0.676, DIR_NORTE));
            break;
        case N015P:
            insertar_info_calle(t, id, crear_info_calle(0.2235, 0.700, DIR_NORTE));
            break;
        case N014P:
            insertar_info_calle(t, id, crear_info_calle(0.2235, 0.723, DIR_NORTE));
            break;
        case N013P:
            insertar_info_calle(t, id, crear_info_calle(0.2235, 0.750, DIR_NORTE));
            break;
        case T024P:
            insertar_info_calle(t, id, crear_info_calle(0.2235, 0.812, DIR_NORTE));
            break;
        case T023P:
            insertar_info_calle(t, id, crear_info_calle(0.2235, 0.839, DIR_NORTE));
            break;
        case T022P:
            insertar_info_calle(t, id, crear_info_calle(0.2235, 0.861, DIR_NORTE));
            break;
        case T021P:
            insertar_info_calle(t, id, crear_info_calle(0.2235, 0.882, DIR_NORTE));
            break;
        case T020P:
            insertar_info_calle(t, id, crear_info_calle(0.2235, 0.907, DIR_NORTE));
            break;
        case T019P:
            insertar_info_calle(t, id, crear_info_calle(0.2235, 0.933, DIR_NORTE));
            break;
//Columna 3
        case N001P:
            insertar_info_calle(t, id, crear_info_calle(0.3415, 0.629, DIR_SUR));
            break;
        case N002P:
            insertar_info_calle(t, id, crear_info_calle(0.3415, 0.654, DIR_SUR));
            break;
        case N003P:
            insertar_info_calle(t, id, crear_info_calle(0.3415, 0.676, DIR_SUR));
            break;
        case N004P:
            insertar_info_calle(t, id, crear_info_calle(0.3415, 0.700, DIR_SUR));
            break;
        case N005P:
            insertar_info_calle(t, id, crear_info_calle(0.3415, 0.723, DIR_SUR));
            break;
        case N006P:
            insertar_info_calle(t, id, crear_info_calle(0.3415, 0.750, DIR_SUR));
            break;
        case T007P:
            insertar_info_calle(t, id, crear_info_calle(0.3415, 0.812, DIR_SUR));
            break;
        case T008P:
            insertar_info_calle(t, id, crear_info_calle(0.3415, 0.839, DIR_SUR));
            break;
        case T009P:
            insertar_info_calle(t, id, crear_info_calle(0.3415, 0.861, DIR_SUR));
            break;
        case T010P:
            insertar_info_calle(t, id, crear_info_calle(0.3415, 0.882, DIR_SUR));
            break;
        case T011P:
            insertar_info_calle(t, id, crear_info_calle(0.3415, 0.907, DIR_SUR));
            break;
        case T012P:
            insertar_info_calle(t, id, crear_info_calle(0.3415, 0.933, DIR_SUR));
            break;
//Columna 4
        case O018P:
            insertar_info_calle(t, id, crear_info_calle(0.365, 0.629, DIR_NORTE));
            break;
        case O017P:
            insertar_info_calle(t, id, crear_info_calle(0.365, 0.654, DIR_NORTE));
            break;
        case O016P:
            insertar_info_calle(t, id, crear_info_calle(0.365, 0.676, DIR_NORTE));
            break;
        case O015P:
            insertar_info_calle(t, id, crear_info_calle(0.365, 0.700, DIR_NORTE));
            break;
        case O014P:
            insertar_info_calle(t, id, crear_info_calle(0.365, 0.723, DIR_NORTE));
            break;
        case O013P:
            insertar_info_calle(t, id, crear_info_calle(0.365, 0.750, DIR_NORTE));
            break;
        case U024P:
            insertar_info_calle(t, id, crear_info_calle(0.365, 0.812, DIR_NORTE));
            break;
        case U023P:
            insertar_info_calle(t, id, crear_info_calle(0.365, 0.839, DIR_NORTE));
            break;
        case U022P:
            insertar_info_calle(t, id, crear_info_calle(0.365, 0.861, DIR_NORTE));
            break;
        case U021P:
            insertar_info_calle(t, id, crear_info_calle(0.365, 0.882, DIR_NORTE));
            break;
        case U020P:
            insertar_info_calle(t, id, crear_info_calle(0.365, 0.907, DIR_NORTE));
            break;
        case U019P:
            insertar_info_calle(t, id, crear_info_calle(0.365, 0.933, DIR_NORTE));
            break;
//Columna 5
        case O001P:
            insertar_info_calle(t, id, crear_info_calle(0.483, 0.629, DIR_SUR));
            break;
        case O002P:
            insertar_info_calle(t, id, crear_info_calle(0.483, 0.654, DIR_SUR));
            break;
        case O003P:
            insertar_info_calle(t, id, crear_info_calle(0.483, 0.676, DIR_SUR));
            break;
        case O004P:
            insertar_info_calle(t, id, crear_info_calle(0.483, 0.700, DIR_SUR));
            break;
        case O005P:
            insertar_info_calle(t, id, crear_info_calle(0.483, 0.723, DIR_SUR));
            break;
        case O006P:
            insertar_info_calle(t, id, crear_info_calle(0.483, 0.750, DIR_SUR));
            break;
        case U007P:
            insertar_info_calle(t, id, crear_info_calle(0.483, 0.812, DIR_SUR));
            break;
        case U008P:
            insertar_info_calle(t, id, crear_info_calle(0.483, 0.839, DIR_SUR));
            break;
        case U009P:
            insertar_info_calle(t, id, crear_info_calle(0.483, 0.861, DIR_SUR));
            break;
        case U010P:
            insertar_info_calle(t, id, crear_info_calle(0.483, 0.882, DIR_SUR));
            break;
        case U011P:
            insertar_info_calle(t, id, crear_info_calle(0.483, 0.907, DIR_SUR));
            break;
        case U012P:
            insertar_info_calle(t, id, crear_info_calle(0.483, 0.933, DIR_SUR));
            break;
//Columna 6
        case P018P:
            insertar_info_calle(t, id, crear_info_calle(0.5035, 0.629, DIR_NORTE));
            break;
        case P017P:
            insertar_info_calle(t, id, crear_info_calle(0.5035, 0.654, DIR_NORTE));
            break;
        case P016P:
            insertar_info_calle(t, id, crear_info_calle(0.5035, 0.676, DIR_NORTE));
            break;
        case P015P:
            insertar_info_calle(t, id, crear_info_calle(0.5035, 0.700, DIR_NORTE));
            break;
        case P014P:
            insertar_info_calle(t, id, crear_info_calle(0.5035, 0.723, DIR_NORTE));
            break;
        case P013P:
            insertar_info_calle(t, id, crear_info_calle(0.5035, 0.750, DIR_NORTE));
            break;
        case V024P:
            insertar_info_calle(t, id, crear_info_calle(0.5035, 0.812, DIR_NORTE));
            break;
        case V023P:
            insertar_info_calle(t, id, crear_info_calle(0.5035, 0.839, DIR_NORTE));
            break;
        case V022P:
            insertar_info_calle(t, id, crear_info_calle(0.5035, 0.861, DIR_NORTE));
            break;
        case V021P:
            insertar_info_calle(t, id, crear_info_calle(0.5035, 0.882, DIR_NORTE));
            break;
        case V020P:
            insertar_info_calle(t, id, crear_info_calle(0.5035, 0.907, DIR_NORTE));
            break;
        case V019P:
            insertar_info_calle(t, id, crear_info_calle(0.5035, 0.933, DIR_NORTE));
            break;
//Columna 7
        case P001P:
            insertar_info_calle(t, id, crear_info_calle(0.6215, 0.629, DIR_SUR));
            break;
        case P002P:
            insertar_info_calle(t, id, crear_info_calle(0.6215, 0.654, DIR_SUR));
            break;
        case P003P:
            insertar_info_calle(t, id, crear_info_calle(0.6215, 0.676, DIR_SUR));
            break;
        case P004P:
            insertar_info_calle(t, id, crear_info_calle(0.6215, 0.700, DIR_SUR));
            break;
        case P005P:
            insertar_info_calle(t, id, crear_info_calle(0.6215, 0.723, DIR_SUR));
            break;
        case P006P:
            insertar_info_calle(t, id, crear_info_calle(0.6215, 0.750, DIR_SUR));
            break;
        case V007P:
            insertar_info_calle(t, id, crear_info_calle(0.6215, 0.812, DIR_SUR));
            break;
        case V008P:
            insertar_info_calle(t, id, crear_info_calle(0.6215, 0.839, DIR_SUR));
            break;
        case V009P:
            insertar_info_calle(t, id, crear_info_calle(0.6215, 0.861, DIR_SUR));
            break;
        case V010P:
            insertar_info_calle(t, id, crear_info_calle(0.6215, 0.882, DIR_SUR));
            break;
        case V011P:
            insertar_info_calle(t, id, crear_info_calle(0.6215, 0.907, DIR_SUR));
            break;
        case V012P:
            insertar_info_calle(t, id, crear_info_calle(0.6215, 0.933, DIR_SUR));
            break;
//Columna 8
        case Q018P:
            insertar_info_calle(t, id, crear_info_calle(0.644, 0.629, DIR_NORTE));
            break;
        case Q017P:
            insertar_info_calle(t, id, crear_info_calle(0.644, 0.654, DIR_NORTE));
            break;
        case Q016P:
            insertar_info_calle(t, id, crear_info_calle(0.644, 0.676, DIR_NORTE));
            break;
        case Q015P:
            insertar_info_calle(t, id, crear_info_calle(0.644, 0.700, DIR_NORTE));
            break;
        case Q014P:
            insertar_info_calle(t, id, crear_info_calle(0.644, 0.723, DIR_NORTE));
            break;
        case Q013P:
            insertar_info_calle(t, id, crear_info_calle(0.644, 0.750, DIR_NORTE));
            break;
        case W024P:
            insertar_info_calle(t, id, crear_info_calle(0.644, 0.812, DIR_NORTE));
            break;
        case W023P:
            insertar_info_calle(t, id, crear_info_calle(0.644, 0.839, DIR_NORTE));
            break;
        case W022P:
            insertar_info_calle(t, id, crear_info_calle(0.644, 0.861, DIR_NORTE));
            break;
        case W021P:
            insertar_info_calle(t, id, crear_info_calle(0.644, 0.882, DIR_NORTE));
            break;
        case W020P:
            insertar_info_calle(t, id, crear_info_calle(0.644, 0.907, DIR_NORTE));
            break;
        case W019P:
            insertar_info_calle(t, id, crear_info_calle(0.644, 0.933, DIR_NORTE));
            break;
//Columna 9
        case Q001P:
            insertar_info_calle(t, id, crear_info_calle(0.762, 0.629, DIR_SUR));
            break;
        case Q002P:
            insertar_info_calle(t, id, crear_info_calle(0.762, 0.654, DIR_SUR));
            break;
        case Q003P:
            insertar_info_calle(t, id, crear_info_calle(0.762, 0.676, DIR_SUR));
            break;
        case Q004P:
            insertar_info_calle(t, id, crear_info_calle(0.762, 0.700, DIR_SUR));
            break;
        case Q005P:
            insertar_info_calle(t, id, crear_info_calle(0.762, 0.723, DIR_SUR));
            break;
        case Q006P:
            insertar_info_calle(t, id, crear_info_calle(0.762, 0.750, DIR_SUR));
            break;
        case W007P:
            insertar_info_calle(t, id, crear_info_calle(0.762, 0.812, DIR_SUR));
            break;
        case W008P:
            insertar_info_calle(t, id, crear_info_calle(0.762, 0.839, DIR_SUR));
            break;
        case W009P:
            insertar_info_calle(t, id, crear_info_calle(0.762, 0.861, DIR_SUR));
            break;
        case W010P:
            insertar_info_calle(t, id, crear_info_calle(0.762, 0.882, DIR_SUR));
            break;
        case W011P:
            insertar_info_calle(t, id, crear_info_calle(0.762, 0.907, DIR_SUR));
            break;
        case W012P:
            insertar_info_calle(t, id, crear_info_calle(0.762, 0.933, DIR_SUR));
            break;
//Columna 10
        case R018P:
            insertar_info_calle(t, id, crear_info_calle(0.785, 0.629, DIR_NORTE));
            break;
        case R017P:
            insertar_info_calle(t, id, crear_info_calle(0.785, 0.654, DIR_NORTE));
            break;
        case R016P:
            insertar_info_calle(t, id, crear_info_calle(0.785, 0.676, DIR_NORTE));
            break;
        case R015P:
            insertar_info_calle(t, id, crear_info_calle(0.785, 0.700, DIR_NORTE));
            break;
        case R014P:
            insertar_info_calle(t, id, crear_info_calle(0.785, 0.723, DIR_NORTE));
            break;
        case R013P:
            insertar_info_calle(t, id, crear_info_calle(0.785, 0.750, DIR_NORTE));
            break;
        case X024P:
            insertar_info_calle(t, id, crear_info_calle(0.785, 0.812, DIR_NORTE));
            break;
        case X023P:
            insertar_info_calle(t, id, crear_info_calle(0.785, 0.839, DIR_NORTE));
            break;
        case X022P:
            insertar_info_calle(t, id, crear_info_calle(0.785, 0.861, DIR_NORTE));
            break;
        case X021P:
            insertar_info_calle(t, id, crear_info_calle(0.785, 0.882, DIR_NORTE));
            break;
        case X020P:
            insertar_info_calle(t, id, crear_info_calle(0.785, 0.907, DIR_NORTE));
            break;
        case X019P:
            insertar_info_calle(t, id, crear_info_calle(0.785, 0.933, DIR_NORTE));
            break;

//Columna 11
        case R001P:
            insertar_info_calle(t, id, crear_info_calle(0.900, 0.629, DIR_SUR));
            break;
        case R002P:
            insertar_info_calle(t, id, crear_info_calle(0.900, 0.654, DIR_SUR));
            break;
        case R003P:
            insertar_info_calle(t, id, crear_info_calle(0.900, 0.676, DIR_SUR));
            break;
        case R004P:
            insertar_info_calle(t, id, crear_info_calle(0.900, 0.700, DIR_SUR));
            break;
        case R005P:
            insertar_info_calle(t, id, crear_info_calle(0.900, 0.723, DIR_SUR));
            break;
        case R006P:
            insertar_info_calle(t, id, crear_info_calle(0.900, 0.750, DIR_SUR));
            break;
        case X007P:
            insertar_info_calle(t, id, crear_info_calle(0.900, 0.812, DIR_SUR));
            break;
        case X008P:
            insertar_info_calle(t, id, crear_info_calle(0.900, 0.839, DIR_SUR));
            break;
        case X009P:
            insertar_info_calle(t, id, crear_info_calle(0.900, 0.861, DIR_SUR));
            break;
        case X010P:
            insertar_info_calle(t, id, crear_info_calle(0.900, 0.882, DIR_SUR));
            break;
        case X011P:
            insertar_info_calle(t, id, crear_info_calle(0.900, 0.907, DIR_SUR));
            break;
        case X012P:
            insertar_info_calle(t, id, crear_info_calle(0.900, 0.933, DIR_SUR));
            break;
        default:
            break;
    }
}

void insert_street_info_corners(TablaInfoCalle *t, CornersIds id) {
    switch (id) {
        case X004C:
            insertar_info_calle(t, id, crear_info_calle(0.785, 0.965, DIR_OESTE));
            break;
        case X002C: // && R001C
            insertar_info_calle(t, id, crear_info_calle(0.900, 0.778, DIR_SUR));
            break;
        case X003C:
            insertar_info_calle(t, id, crear_info_calle(0.900, 0.965, DIR_OESTE));
            break;
        case G001C: // && A004C
            insertar_info_calle(t, id, crear_info_calle(0.085, 0.194, DIR_NORTE));
            break;
        case A001C:
            insertar_info_calle(t, id, crear_info_calle(0.085, 0.007, DIR_ESTE));
            break;
        case X001C: // && R002C
            insertar_info_calle(t, id, crear_info_calle(0.785, 0.778, DIR_ESTE));
            break;
        case V002C: // && P001C
            insertar_info_calle(t, id, crear_info_calle(0.6215, 0.778, DIR_ESTE));
            break;
        case V003C:
            insertar_info_calle(t, id, crear_info_calle(0.6215, 0.965, DIR_OESTE));
            break;
        case W001C: // && Q002C
            insertar_info_calle(t, id, crear_info_calle(0.644, 0.778, DIR_ESTE));
            break;
        case W004C:
            insertar_info_calle(t, id, crear_info_calle(0.644, 0.965, DIR_OESTE));
            break;
        case W002C: // && Q001C
            insertar_info_calle(t, id, crear_info_calle(0.762, 0.778, DIR_ESTE));
            break;
        case W003C:
            insertar_info_calle(t, id, crear_info_calle(0.762, 0.965, DIR_OESTE));
            break;
        case S002C: // &&  M001C
            insertar_info_calle(t, id, crear_info_calle(0.200, 0.778, DIR_ESTE));
            break;
        case S004C:
            insertar_info_calle(t, id, crear_info_calle(0.085, 0.965, DIR_OESTE));
            break;
        case S001C: // && M002C
            insertar_info_calle(t, id, crear_info_calle(0.085, 0.778, DIR_NORTE));
            break;
        case S003C:
            insertar_info_calle(t, id, crear_info_calle(0.200, 0.965, DIR_OESTE));
            break;
        case T001C: // && N002C
            insertar_info_calle(t, id, crear_info_calle(0.2235, 0.778, DIR_ESTE));
            break;
        case T004C:
            insertar_info_calle(t, id, crear_info_calle(0.2235, 0.965, DIR_OESTE));
            break;
        case T002C: // && N001C
            insertar_info_calle(t, id, crear_info_calle(0.3415, 0.778, DIR_ESTE));
            break;
        case T003C:
            insertar_info_calle(t, id, crear_info_calle(0.3415, 0.965, DIR_OESTE));
            break;
        case U001C: // && O002C
            insertar_info_calle(t, id, crear_info_calle(0.365, 0.778, DIR_ESTE));
            break;
        case U004C:
            insertar_info_calle(t, id, crear_info_calle(0.365, 0.965, DIR_OESTE));
            break;
        case U002C: // && O001C
            insertar_info_calle(t, id, crear_info_calle(0.483, 0.778, DIR_ESTE));
            break;
        case U003C:
            insertar_info_calle(t, id, crear_info_calle(0.483, 0.965, DIR_OESTE));
            break;
        case D001C:
            insertar_info_calle(t, id, crear_info_calle(0.5035, 0.007, DIR_ESTE));
            break;
        case J001C: // && D004C
            insertar_info_calle(t, id, crear_info_calle(0.5035, 0.194, DIR_OESTE));
            break;
        case D002C:
            insertar_info_calle(t, id, crear_info_calle(0.6215, 0.007, DIR_ESTE));
            break;
        case J002C: // && D003C
            insertar_info_calle(t, id, crear_info_calle(0.6215, 0.194, DIR_OESTE));
            break;
        case E001C:
            insertar_info_calle(t, id, crear_info_calle(0.644, 0.007, DIR_ESTE));
            break;
        case K001C: // && E004C
            insertar_info_calle(t, id, crear_info_calle(0.644, 0.194, DIR_OESTE));
            break;
        case E002C:
            insertar_info_calle(t, id, crear_info_calle(0.762, 0.007, DIR_ESTE));
            break;
        case K002C: // && E003C
            insertar_info_calle(t, id, crear_info_calle(0.762, 0.194, DIR_OESTE));
            break;
        case F001C:
            insertar_info_calle(t, id, crear_info_calle(0.785, 0.007, DIR_ESTE));
            break;
        case L001C: // && F004C
            insertar_info_calle(t, id, crear_info_calle(0.785, 0.194, DIR_OESTE));
            break;
        case F002C:
            insertar_info_calle(t, id, crear_info_calle(0.900, 0.007, DIR_SUR));
            break;
        case L002C: // && F003C
            insertar_info_calle(t, id, crear_info_calle(0.900, 0.194, DIR_SUR));
            break;
        case A002C:
            insertar_info_calle(t, id, crear_info_calle(0.200, 0.007, DIR_ESTE));
            break;
        case G002C: // && A003C
            insertar_info_calle(t, id, crear_info_calle(0.200, 0.194, DIR_OESTE));
            break;
        case B001C:
            insertar_info_calle(t, id, crear_info_calle(0.2235, 0.007, DIR_ESTE));
            break;
        case H001C: // && B004C
            insertar_info_calle(t, id, crear_info_calle(0.2235, 0.194, DIR_OESTE));
            break;
        case B002C:
            insertar_info_calle(t, id, crear_info_calle(0.3415, 0.007, DIR_ESTE));
            break;
        case H002C: // && B003C
            insertar_info_calle(t, id, crear_info_calle(0.3415, 0.194, DIR_OESTE));
            break;
        case C001C:
            insertar_info_calle(t, id, crear_info_calle(0.365, 0.007, DIR_ESTE));
            break;
        case I001C: // && C004C
            insertar_info_calle(t, id, crear_info_calle(0.365, 0.194, DIR_OESTE));
            break;
        case C002C:
            insertar_info_calle(t, id, crear_info_calle(0.483, 0.007, DIR_ESTE));
            break;
        case I002C: // && C003C
            insertar_info_calle(t, id, crear_info_calle(0.483, 0.194, DIR_OESTE));
            break;
        case P002C: // && V001C
            insertar_info_calle(t, id, crear_info_calle(0.5035, 0.778, DIR_ESTE));
            break;
        case V004C:
            insertar_info_calle(t, id, crear_info_calle(0.5035, 0.965, DIR_OESTE));
            break;
        default:
            break;
    }
}
