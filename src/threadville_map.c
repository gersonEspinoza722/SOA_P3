#include "threadville_map.h"
#include "utils.h"

ThreadvilleMap *create_threadville_map() {
    ThreadvilleMap *threadvilleMap = create_shared_memory(sizeof(ThreadvilleMap));
    threadvilleMap->mapa = create_table(984);
    threadvilleMap->tablaInfoCalle = create_table_street_info(984);

    insert_highways(threadvilleMap->mapa, threadvilleMap->tablaInfoCalle);
    insert_bridges(threadvilleMap->mapa, threadvilleMap->tablaInfoCalle);
    insert_roundabouts(threadvilleMap->mapa, threadvilleMap->tablaInfoCalle);
    insert_stops(threadvilleMap->mapa, threadvilleMap->tablaInfoCalle);
    insert_streets(threadvilleMap->mapa, threadvilleMap->tablaInfoCalle);
    insert_corners(threadvilleMap->mapa, threadvilleMap->tablaInfoCalle);
    return threadvilleMap;
}

void insert_highways(Table *table, TableStreetInfo *streetInfo) {
    for (int i = H001H; i <= H144H; ++i) {
        insert(table, i, get_priority_semaphore());
        insert_street_info_highways(streetInfo, i);
    }
}

void insert_bridges(Table *table, TableStreetInfo *streetInfo) {
    for (int i = B001B; i <= B030B; ++i) {
        insert(table, i, get_priority_semaphore());
        insert_street_info_bridge(streetInfo, i);
    }
    for (int i = BU01B; i <= BU30B; ++i) {
        insert(table, i, get_priority_semaphore());
        insert_street_info_bridge_up(streetInfo, i);
    }
}

void insert_roundabouts(Table *table, TableStreetInfo *streetInfo) {
    for (int i = Y001R; i <= Z006R; ++i) {
        insert(table, i, get_priority_semaphore());
        insert_street_info_roundabouts(streetInfo, i);
    }
}

void insert_stops(Table *table, TableStreetInfo *streetInfo) {
    for (int i = A001S; i <= R006S; ++i) {
        insert(table, i, get_priority_semaphore());
        insert_street_info_stops(streetInfo, i);
    }
}

void insert_streets(Table *table, TableStreetInfo *streetInfo) {
    for (int i = A001P; i <= R018P; ++i) {
        insert(table, i, get_priority_semaphore());
        insert_street_info_streets(streetInfo, i);
    }
}

void insert_corners(Table *table, TableStreetInfo *streetInfo) {
    for (int i = A001C; i <= X004C; ++i) {
        insert(table, i, get_priority_semaphore());
        insert_street_info_corners(streetInfo, i);
    }
}

void insert_street_info_highways(TableStreetInfo *t, HighwaysIds id) {
    switch (id) {
        case H072H:
            insert_street_info(t, id, create_street_info(0.143, 0.465, WEST_DIR));
            break;
        case H071H:
            insert_street_info(t, id, create_street_info(0.159, 0.465, WEST_DIR));
            break;
        case H070H:
            insert_street_info(t, id, create_street_info(0.175, 0.465, WEST_DIR));
            break;
        case H069H:
            insert_street_info(t, id, create_street_info(0.191, 0.465, WEST_DIR));
            break;
        case H068H:
            insert_street_info(t, id, create_street_info(0.2335, 0.465, WEST_DIR));
            break;
        case H067H:
            insert_street_info(t, id, create_street_info(0.2525, 0.465, WEST_DIR));
            break;
        case H066H:
            insert_street_info(t, id, create_street_info(0.2685, 0.465, WEST_DIR));
            break;
        case H065H:
            insert_street_info(t, id, create_street_info(0.2845, 0.465, WEST_DIR));
            break;
        case H064H:
            insert_street_info(t, id, create_street_info(0.3005, 0.465, WEST_DIR));
            break;
        case H063H:
            insert_street_info(t, id, create_street_info(0.3165, 0.465, WEST_DIR));
            break;
        case H062H:
            insert_street_info(t, id, create_street_info(0.3325, 0.465, WEST_DIR));
            break;
        case H061H:
            insert_street_info(t, id, create_street_info(0.375, 0.465, WEST_DIR));
            break;
        case H060H:
            insert_street_info(t, id, create_street_info(0.394, 0.465, WEST_DIR));
            break;
        case H059H:
            insert_street_info(t, id, create_street_info(0.410, 0.465, WEST_DIR));
            break;
        case H058H:
            insert_street_info(t, id, create_street_info(0.426, 0.465, WEST_DIR));
            break;
        case H057H:
            insert_street_info(t, id, create_street_info(0.442, 0.465, WEST_DIR));
            break;
        case H056H:
            insert_street_info(t, id, create_street_info(0.458, 0.465, WEST_DIR));
            break;
        case H055H:
            insert_street_info(t, id, create_street_info(0.474, 0.465, WEST_DIR));
            break;
        case H054H:
            insert_street_info(t, id, create_street_info(0.5135, 0.465, WEST_DIR));
            break;
        case H053H:
            insert_street_info(t, id, create_street_info(0.5325, 0.465, WEST_DIR));
            break;
        case H052H:
            insert_street_info(t, id, create_street_info(0.5485, 0.465, WEST_DIR));
            break;
        case H051H:
            insert_street_info(t, id, create_street_info(0.5645, 0.465, WEST_DIR));
            break;
        case H050H:
            insert_street_info(t, id, create_street_info(0.5805, 0.465, WEST_DIR));
            break;
        case H049H:
            insert_street_info(t, id, create_street_info(0.5965, 0.465, WEST_DIR));
            break;
        case H048H:
            insert_street_info(t, id, create_street_info(0.6125, 0.465, WEST_DIR));
            break;
        case H047H:
            insert_street_info(t, id, create_street_info(0.654, 0.465, WEST_DIR));
            break;
        case H046H:
            insert_street_info(t, id, create_street_info(0.673, 0.465, WEST_DIR));
            break;
        case H045H:
            insert_street_info(t, id, create_street_info(0.689, 0.465, WEST_DIR));
            break;
        case H044H:
            insert_street_info(t, id, create_street_info(0.705, 0.465, WEST_DIR));
            break;
        case H043H:
            insert_street_info(t, id, create_street_info(0.721, 0.465, WEST_DIR));
            break;
        case H042H:
            insert_street_info(t, id, create_street_info(0.737, 0.465, WEST_DIR));
            break;
        case H041H:
            insert_street_info(t, id, create_street_info(0.753, 0.465, WEST_DIR));
            break;
        case H040H:
            insert_street_info(t, id, create_street_info(0.795, 0.465, WEST_DIR));
            break;
        case H039H:
            insert_street_info(t, id, create_street_info(0.813, 0.465, WEST_DIR));
            break;
        case H038H:
            insert_street_info(t, id, create_street_info(0.829, 0.465, WEST_DIR));
            break;
        case H037H:
            insert_street_info(t, id, create_street_info(0.844, 0.465, WEST_DIR));
            break;
        case H036H:
            insert_street_info(t, id, create_street_info(0.143, 0.426, WEST_DIR));
            break;
        case H035H:
            insert_street_info(t, id, create_street_info(0.159, 0.426, WEST_DIR));
            break;
        case H034H:
            insert_street_info(t, id, create_street_info(0.175, 0.426, WEST_DIR));
            break;
        case H033H:
            insert_street_info(t, id, create_street_info(0.191, 0.426, WEST_DIR));
            break;
        case H032H:
            insert_street_info(t, id, create_street_info(0.2335, 0.426, WEST_DIR));
            break;
        case H031H:
            insert_street_info(t, id, create_street_info(0.2525, 0.426, WEST_DIR));
            break;
        case H030H:
            insert_street_info(t, id, create_street_info(0.2685, 0.426, WEST_DIR));
            break;
        case H029H:
            insert_street_info(t, id, create_street_info(0.2845, 0.426, WEST_DIR));
            break;
        case H028H:
            insert_street_info(t, id, create_street_info(0.3005, 0.426, WEST_DIR));
            break;
        case H027H:
            insert_street_info(t, id, create_street_info(0.3165, 0.426, WEST_DIR));
            break;
        case H026H:
            insert_street_info(t, id, create_street_info(0.3325, 0.426, WEST_DIR));
            break;
        case H025H:
            insert_street_info(t, id, create_street_info(0.375, 0.426, WEST_DIR));
            break;
        case H024H:
            insert_street_info(t, id, create_street_info(0.394, 0.426, WEST_DIR));
            break;
        case H023H:
            insert_street_info(t, id, create_street_info(0.410, 0.426, WEST_DIR));
            break;
        case H022H:
            insert_street_info(t, id, create_street_info(0.426, 0.426, WEST_DIR));
            break;
        case H021H:
            insert_street_info(t, id, create_street_info(0.442, 0.426, WEST_DIR));
            break;
        case H020H:
            insert_street_info(t, id, create_street_info(0.458, 0.426, WEST_DIR));
            break;
        case H019H:
            insert_street_info(t, id, create_street_info(0.474, 0.426, WEST_DIR));
            break;
        case H018H:
            insert_street_info(t, id, create_street_info(0.5135, 0.426, WEST_DIR));
            break;
        case H017H:
            insert_street_info(t, id, create_street_info(0.5325, 0.426, WEST_DIR));
            break;
        case H016H:
            insert_street_info(t, id, create_street_info(0.5485, 0.426, WEST_DIR));
            break;
        case H015H:
            insert_street_info(t, id, create_street_info(0.5645, 0.426, WEST_DIR));
            break;
        case H014H:
            insert_street_info(t, id, create_street_info(0.5805, 0.426, WEST_DIR));
            break;
        case H013H:
            insert_street_info(t, id, create_street_info(0.5965, 0.426, WEST_DIR));
            break;
        case H012H:
            insert_street_info(t, id, create_street_info(0.6125, 0.426, WEST_DIR));
            break;
        case H011H:
            insert_street_info(t, id, create_street_info(0.654, 0.426, WEST_DIR));
            break;
        case H010H:
            insert_street_info(t, id, create_street_info(0.673, 0.426, WEST_DIR));
            break;
        case H009H:
            insert_street_info(t, id, create_street_info(0.689, 0.426, WEST_DIR));
            break;
        case H008H:
            insert_street_info(t, id, create_street_info(0.705, 0.426, WEST_DIR));
            break;
        case H007H:
            insert_street_info(t, id, create_street_info(0.721, 0.426, WEST_DIR));
            break;
        case H006H:
            insert_street_info(t, id, create_street_info(0.737, 0.426, WEST_DIR));
            break;
        case H005H:
            insert_street_info(t, id, create_street_info(0.753, 0.426, WEST_DIR));
            break;
        case H004H:
            insert_street_info(t, id, create_street_info(0.795, 0.426, WEST_DIR));
            break;
        case H003H:
            insert_street_info(t, id, create_street_info(0.813, 0.426, WEST_DIR));
            break;
        case H002H:
            insert_street_info(t, id, create_street_info(0.829, 0.426, WEST_DIR));
            break;
        case H001H:
            insert_street_info(t, id, create_street_info(0.844, 0.426, WEST_DIR));
            break;
        case H073H:
            insert_street_info(t, id, create_street_info(0.143, 0.512, EAST_DIR));
            break;
        case H074H:
            insert_street_info(t, id, create_street_info(0.159, 0.512, EAST_DIR));
            break;
        case H075H:
            insert_street_info(t, id, create_street_info(0.175, 0.512, EAST_DIR));
            break;
        case H076H:
            insert_street_info(t, id, create_street_info(0.191, 0.512, EAST_DIR));
            break;
        case H077H:
            insert_street_info(t, id, create_street_info(0.2335, 0.512, EAST_DIR));
            break;
        case H078H:
            insert_street_info(t, id, create_street_info(0.2525, 0.512, EAST_DIR));
            break;
        case H079H:
            insert_street_info(t, id, create_street_info(0.2685, 0.512, EAST_DIR));
            break;
        case H080H:
            insert_street_info(t, id, create_street_info(0.2845, 0.512, EAST_DIR));
            break;
        case H081H:
            insert_street_info(t, id, create_street_info(0.3005, 0.512, EAST_DIR));
            break;
        case H082H:
            insert_street_info(t, id, create_street_info(0.3165, 0.512, EAST_DIR));
            break;
        case H083H:
            insert_street_info(t, id, create_street_info(0.3325, 0.512, EAST_DIR));
            break;
        case H084H:
            insert_street_info(t, id, create_street_info(0.375, 0.512, EAST_DIR));
            break;
        case H085H:
            insert_street_info(t, id, create_street_info(0.394, 0.512, EAST_DIR));
            break;
        case H086H:
            insert_street_info(t, id, create_street_info(0.410, 0.512, EAST_DIR));
            break;
        case H087H:
            insert_street_info(t, id, create_street_info(0.426, 0.512, EAST_DIR));
            break;
        case H088H:
            insert_street_info(t, id, create_street_info(0.442, 0.512, EAST_DIR));
            break;
        case H089H:
            insert_street_info(t, id, create_street_info(0.458, 0.512, EAST_DIR));
            break;
        case H090H:
            insert_street_info(t, id, create_street_info(0.474, 0.512, EAST_DIR));
            break;
        case H091H:
            insert_street_info(t, id, create_street_info(0.5135, 0.512, EAST_DIR));
            break;
        case H092H:
            insert_street_info(t, id, create_street_info(0.5325, 0.512, EAST_DIR));
            break;
        case H093H:
            insert_street_info(t, id, create_street_info(0.5485, 0.512, EAST_DIR));
            break;
        case H094H:
            insert_street_info(t, id, create_street_info(0.5645, 0.512, EAST_DIR));
            break;
        case H095H:
            insert_street_info(t, id, create_street_info(0.5805, 0.512, EAST_DIR));
            break;
        case H096H:
            insert_street_info(t, id, create_street_info(0.5965, 0.512, EAST_DIR));
            break;
        case H097H:
            insert_street_info(t, id, create_street_info(0.6125, 0.512, EAST_DIR));
            break;
        case H098H:
            insert_street_info(t, id, create_street_info(0.654, 0.512, EAST_DIR));
            break;
        case H099H:
            insert_street_info(t, id, create_street_info(0.673, 0.512, EAST_DIR));
            break;
        case H100H:
            insert_street_info(t, id, create_street_info(0.689, 0.512, EAST_DIR));
            break;
        case H101H:
            insert_street_info(t, id, create_street_info(0.705, 0.512, EAST_DIR));
            break;
        case H102H:
            insert_street_info(t, id, create_street_info(0.721, 0.512, EAST_DIR));
            break;
        case H103H:
            insert_street_info(t, id, create_street_info(0.737, 0.512, EAST_DIR));
            break;
        case H104H:
            insert_street_info(t, id, create_street_info(0.753, 0.512, EAST_DIR));
            break;
        case H105H:
            insert_street_info(t, id, create_street_info(0.795, 0.512, EAST_DIR));
            break;
        case H106H:
            insert_street_info(t, id, create_street_info(0.813, 0.512, EAST_DIR));
            break;
        case H107H:
            insert_street_info(t, id, create_street_info(0.829, 0.512, EAST_DIR));
            break;
        case H108H:
            insert_street_info(t, id, create_street_info(0.844, 0.512, EAST_DIR));
            break;
        case H109H:
            insert_street_info(t, id, create_street_info(0.143, 0.55, EAST_DIR));
            break;
        case H110H:
            insert_street_info(t, id, create_street_info(0.159, 0.55, EAST_DIR));
            break;
        case H111H:
            insert_street_info(t, id, create_street_info(0.175, 0.55, EAST_DIR));
            break;
        case H112H:
            insert_street_info(t, id, create_street_info(0.191, 0.55, EAST_DIR));
            break;
        case H113H:
            insert_street_info(t, id, create_street_info(0.2335, 0.55, EAST_DIR));
            break;
        case H114H:
            insert_street_info(t, id, create_street_info(0.2525, 0.55, EAST_DIR));
            break;
        case H115H:
            insert_street_info(t, id, create_street_info(0.2685, 0.55, EAST_DIR));
            break;
        case H116H:
            insert_street_info(t, id, create_street_info(0.2845, 0.55, EAST_DIR));
            break;
        case H117H:
            insert_street_info(t, id, create_street_info(0.3005, 0.55, EAST_DIR));
            break;
        case H118H:
            insert_street_info(t, id, create_street_info(0.3165, 0.55, EAST_DIR));
            break;
        case H119H:
            insert_street_info(t, id, create_street_info(0.3325, 0.55, EAST_DIR));
            break;
        case H120H:
            insert_street_info(t, id, create_street_info(0.375, 0.55, EAST_DIR));
            break;
        case H121H:
            insert_street_info(t, id, create_street_info(0.394, 0.55, EAST_DIR));
            break;
        case H122H:
            insert_street_info(t, id, create_street_info(0.410, 0.55, EAST_DIR));
            break;
        case H123H:
            insert_street_info(t, id, create_street_info(0.426, 0.55, EAST_DIR));
            break;
        case H124H:
            insert_street_info(t, id, create_street_info(0.442, 0.55, EAST_DIR));
            break;
        case H125H:
            insert_street_info(t, id, create_street_info(0.458, 0.55, EAST_DIR));
            break;
        case H126H:
            insert_street_info(t, id, create_street_info(0.474, 0.55, EAST_DIR));
            break;
        case H127H:
            insert_street_info(t, id, create_street_info(0.5135, 0.55, EAST_DIR));
            break;
        case H128H:
            insert_street_info(t, id, create_street_info(0.5325, 0.55, EAST_DIR));
            break;
        case H129H:
            insert_street_info(t, id, create_street_info(0.5485, 0.55, EAST_DIR));
            break;
        case H130H:
            insert_street_info(t, id, create_street_info(0.5645, 0.55, EAST_DIR));
            break;
        case H131H:
            insert_street_info(t, id, create_street_info(0.5805, 0.55, EAST_DIR));
            break;
        case H132H:
            insert_street_info(t, id, create_street_info(0.5965, 0.55, EAST_DIR));
            break;
        case H133H:
            insert_street_info(t, id, create_street_info(0.6125, 0.55, EAST_DIR));
            break;
        case H134H:
            insert_street_info(t, id, create_street_info(0.654, 0.55, EAST_DIR));
            break;
        case H135H:
            insert_street_info(t, id, create_street_info(0.673, 0.55, EAST_DIR));
            break;
        case H136H:
            insert_street_info(t, id, create_street_info(0.689, 0.55, EAST_DIR));
            break;
        case H137H:
            insert_street_info(t, id, create_street_info(0.705, 0.55, EAST_DIR));
            break;
        case H138H:
            insert_street_info(t, id, create_street_info(0.721, 0.55, EAST_DIR));
            break;
        case H139H:
            insert_street_info(t, id, create_street_info(0.737, 0.55, EAST_DIR));
            break;
        case H140H:
            insert_street_info(t, id, create_street_info(0.753, 0.55, EAST_DIR));
            break;
        case H141H:
            insert_street_info(t, id, create_street_info(0.795, 0.55, EAST_DIR));
            break;
        case H142H:
            insert_street_info(t, id, create_street_info(0.813, 0.55, EAST_DIR));
            break;
        case H143H:
            insert_street_info(t, id, create_street_info(0.829, 0.55, EAST_DIR));
            break;
        case H144H:
            insert_street_info(t, id, create_street_info(0.844, 0.55, EAST_DIR));
            break;
        default:
            break;
    }
}

void insert_street_info_stops(TableStreetInfo *t, StopIds id) {
    switch (id) {
        case A001S:
            insert_street_info(t, id, create_street_info(0.117, 0.040, NORTH_DIR));
            break;
        case A002S:
            insert_street_info(t, id, create_street_info(0.165, 0.040, NORTH_DIR));
            break;
        case A003S:
            insert_street_info(t, id, create_street_info(0.181, 0.067, NORTH_DIR));
            break;
        case A004S:
            insert_street_info(t, id, create_street_info(0.181, 0.135, NORTH_DIR));
            break;
        case A005S:
            insert_street_info(t, id, create_street_info(0.165, 0.162, NORTH_DIR));
            break;
        case A006S:
            insert_street_info(t, id, create_street_info(0.117, 0.162, NORTH_DIR));
            break;
        case A007S:
            insert_street_info(t, id, create_street_info(0.104, 0.135, NORTH_DIR));
            break;
        case A008S:
            insert_street_info(t, id, create_street_info(0.104, 0.067, NORTH_DIR));
            break;

        case B001S:
            insert_street_info(t, id, create_street_info(0.2585, 0.040, NORTH_DIR));
            break;
        case B002S:
            insert_street_info(t, id, create_street_info(0.3065, 0.040, NORTH_DIR));
            break;
        case B003S:
            insert_street_info(t, id, create_street_info(0.3215, 0.067, NORTH_DIR));
            break;
        case B004S:
            insert_street_info(t, id, create_street_info(0.3215, 0.135, NORTH_DIR));
            break;
        case B005S:
            insert_street_info(t, id, create_street_info(0.3065, 0.162, NORTH_DIR));
            break;
        case B006S:
            insert_street_info(t, id, create_street_info(0.2585, 0.162, NORTH_DIR));
            break;
        case B007S:
            insert_street_info(t, id, create_street_info(0.2455, 0.135, NORTH_DIR));
            break;
        case B008S:
            insert_street_info(t, id, create_street_info(0.2455, 0.067, NORTH_DIR));
            break;

        case C001S:
            insert_street_info(t, id, create_street_info(0.400, 0.040, NORTH_DIR));
            break;
        case C002S:
            insert_street_info(t, id, create_street_info(0.448, 0.040, NORTH_DIR));
            break;
        case C003S:
            insert_street_info(t, id, create_street_info(0.462, 0.067, NORTH_DIR));
            break;
        case C004S:
            insert_street_info(t, id, create_street_info(0.462, 0.135, NORTH_DIR));
            break;
        case C005S:
            insert_street_info(t, id, create_street_info(0.448, 0.162, NORTH_DIR));
            break;
        case C006S:
            insert_street_info(t, id, create_street_info(0.400, 0.162, NORTH_DIR));
            break;
        case C007S:
            insert_street_info(t, id, create_street_info(0.386, 0.135, NORTH_DIR));
            break;
        case C008S:
            insert_street_info(t, id, create_street_info(0.386, 0.067, NORTH_DIR));
            break;

        case D001S:
            insert_street_info(t, id, create_street_info(0.5385, 0.040, NORTH_DIR));
            break;
        case D002S:
            insert_street_info(t, id, create_street_info(0.5865, 0.040, NORTH_DIR));
            break;
        case D003S:
            insert_street_info(t, id, create_street_info(0.6025, 0.066, NORTH_DIR));
            break;
        case D004S:
            insert_street_info(t, id, create_street_info(0.6025, 0.134, NORTH_DIR));
            break;
        case D005S:
            insert_street_info(t, id, create_street_info(0.5865, 0.162, NORTH_DIR));
            break;
        case D006S:
            insert_street_info(t, id, create_street_info(0.5385, 0.162, NORTH_DIR));
            break;
        case D007S:
            insert_street_info(t, id, create_street_info(0.5255, 0.135, NORTH_DIR));
            break;
        case D008S:
            insert_street_info(t, id, create_street_info(0.5255, 0.067, NORTH_DIR));
            break;

        case E001S:
            insert_street_info(t, id, create_street_info(0.679, 0.040, NORTH_DIR));
            break;
        case E002S:
            insert_street_info(t, id, create_street_info(0.727, 0.040, NORTH_DIR));
            break;
        case E003S:
            insert_street_info(t, id, create_street_info(0.743, 0.067, NORTH_DIR));
            break;
        case E004S:
            insert_street_info(t, id, create_street_info(0.743, 0.135, NORTH_DIR));
            break;
        case E005S:
            insert_street_info(t, id, create_street_info(0.727, 0.162, NORTH_DIR));
            break;
        case E006S:
            insert_street_info(t, id, create_street_info(0.679, 0.162, NORTH_DIR));
            break;
        case E007S:
            insert_street_info(t, id, create_street_info(0.666, 0.135, NORTH_DIR));
            break;
        case E008S:
            insert_street_info(t, id, create_street_info(0.666, 0.067, NORTH_DIR));
            break;

        case F001S:
            insert_street_info(t, id, create_street_info(0.819, 0.040, NORTH_DIR));
            break;
        case F002S:
            insert_street_info(t, id, create_street_info(0.867, 0.040, NORTH_DIR));
            break;
        case F003S:
            insert_street_info(t, id, create_street_info(0.883, 0.067, NORTH_DIR));
            break;
        case F004S:
            insert_street_info(t, id, create_street_info(0.883, 0.135, NORTH_DIR));
            break;
        case F005S:
            insert_street_info(t, id, create_street_info(0.867, 0.162, NORTH_DIR));
            break;
        case F006S:
            insert_street_info(t, id, create_street_info(0.819, 0.162, NORTH_DIR));
            break;
        case F007S:
            insert_street_info(t, id, create_street_info(0.806, 0.135, NORTH_DIR));
            break;
        case F008S:
            insert_street_info(t, id, create_street_info(0.806, 0.067, NORTH_DIR));
            break;

        case G001S:
            insert_street_info(t, id, create_street_info(0.117, 0.226, NORTH_DIR));
            break;
        case G002S:
            insert_street_info(t, id, create_street_info(0.165, 0.226, NORTH_DIR));
            break;
        case G003S:
            insert_street_info(t, id, create_street_info(0.181, 0.253, NORTH_DIR));
            break;
        case G004S:
            insert_street_info(t, id, create_street_info(0.181, 0.321, NORTH_DIR));
            break;
        case G005S:
            insert_street_info(t, id, create_street_info(0.104, 0.321, NORTH_DIR));
            break;
        case G006S:
            insert_street_info(t, id, create_street_info(0.104, 0.253, NORTH_DIR));
            break;

        case H001S:
            insert_street_info(t, id, create_street_info(0.2585, 0.226, NORTH_DIR));
            break;
        case H002S:
            insert_street_info(t, id, create_street_info(0.3065, 0.226, NORTH_DIR));
            break;
        case H003S:
            insert_street_info(t, id, create_street_info(0.3215, 0.253, NORTH_DIR));
            break;
        case H004S:
            insert_street_info(t, id, create_street_info(0.3215, 0.321, NORTH_DIR));
            break;
        case H005S:
            insert_street_info(t, id, create_street_info(0.2455, 0.321, NORTH_DIR));
            break;
        case H006S:
            insert_street_info(t, id, create_street_info(0.2455, 0.253, NORTH_DIR));
            break;

        case I001S:
            insert_street_info(t, id, create_street_info(0.400, 0.226, NORTH_DIR));
            break;
        case I002S:
            insert_street_info(t, id, create_street_info(0.448, 0.226, NORTH_DIR));
            break;
        case I003S:
            insert_street_info(t, id, create_street_info(0.462, 0.253, NORTH_DIR));
            break;
        case I004S:
            insert_street_info(t, id, create_street_info(0.462, 0.321, NORTH_DIR));
            break;
        case I005S:
            insert_street_info(t, id, create_street_info(0.386, 0.321, NORTH_DIR));
            break;
        case I006S:
            insert_street_info(t, id, create_street_info(0.386, 0.253, NORTH_DIR));
            break;

        case J001S:
            insert_street_info(t, id, create_street_info(0.5385, 0.226, NORTH_DIR));
            break;
        case J002S:
            insert_street_info(t, id, create_street_info(0.5865, 0.226, NORTH_DIR));
            break;
        case J003S:
            insert_street_info(t, id, create_street_info(0.6025, 0.252, NORTH_DIR));
            break;
        case J004S:
            insert_street_info(t, id, create_street_info(0.6025, 0.32, NORTH_DIR));
            break;
        case J005S:
            insert_street_info(t, id, create_street_info(0.5255, 0.321, NORTH_DIR));
            break;
        case J006S:
            insert_street_info(t, id, create_street_info(0.5255, 0.253, NORTH_DIR));
            break;

        case K001S:
            insert_street_info(t, id, create_street_info(0.679, 0.226, NORTH_DIR));
            break;
        case K002S:
            insert_street_info(t, id, create_street_info(0.727, 0.226, NORTH_DIR));
            break;
        case K003S:
            insert_street_info(t, id, create_street_info(0.743, 0.253, NORTH_DIR));
            break;
        case K004S:
            insert_street_info(t, id, create_street_info(0.743, 0.321, NORTH_DIR));
            break;
        case K005S:
            insert_street_info(t, id, create_street_info(0.666, 0.321, NORTH_DIR));
            break;
        case K006S:
            insert_street_info(t, id, create_street_info(0.666, 0.253, NORTH_DIR));
            break;

        case L001S:
            insert_street_info(t, id, create_street_info(0.819, 0.226, NORTH_DIR));
            break;
        case L002S:
            insert_street_info(t, id, create_street_info(0.867, 0.226, NORTH_DIR));
            break;
        case L003S:
            insert_street_info(t, id, create_street_info(0.883, 0.253, NORTH_DIR));
            break;
        case L004S:
            insert_street_info(t, id, create_street_info(0.883, 0.321, NORTH_DIR));
            break;
        case L005S:
            insert_street_info(t, id, create_street_info(0.806, 0.321, NORTH_DIR));
            break;
        case L006S:
            insert_street_info(t, id, create_street_info(0.806, 0.253, NORTH_DIR));
            break;

        case M002S:
            insert_street_info(t, id, create_street_info(0.181, 0.655, NORTH_DIR));
            break;
        case M003S:
            insert_street_info(t, id, create_street_info(0.181, 0.723, NORTH_DIR));
            break;
        case M004S:
            insert_street_info(t, id, create_street_info(0.165, 0.75, NORTH_DIR));
            break;
        case M005S:
            insert_street_info(t, id, create_street_info(0.117, 0.75, NORTH_DIR));
            break;
        case M006S:
            insert_street_info(t, id, create_street_info(0.104, 0.723, NORTH_DIR));
            break;
        case M001S:
            insert_street_info(t, id, create_street_info(0.104, 0.655, NORTH_DIR));
            break;

        case N002S:
            insert_street_info(t, id, create_street_info(0.3215, 0.655, NORTH_DIR));
            break;
        case N003S:
            insert_street_info(t, id, create_street_info(0.3215, 0.723, NORTH_DIR));
            break;
        case N004S:
            insert_street_info(t, id, create_street_info(0.3065, 0.75, NORTH_DIR));
            break;
        case N005S:
            insert_street_info(t, id, create_street_info(0.2585, 0.75, NORTH_DIR));
            break;
        case N006S:
            insert_street_info(t, id, create_street_info(0.2455, 0.723, NORTH_DIR));
            break;
        case N001S:
            insert_street_info(t, id, create_street_info(0.2455, 0.655, NORTH_DIR));
            break;

        case O002S:
            insert_street_info(t, id, create_street_info(0.462, 0.655, NORTH_DIR));
            break;
        case O003S:
            insert_street_info(t, id, create_street_info(0.462, 0.723, NORTH_DIR));
            break;
        case O004S:
            insert_street_info(t, id, create_street_info(0.448, 0.75, NORTH_DIR));
            break;
        case O005S:
            insert_street_info(t, id, create_street_info(0.400, 0.75, NORTH_DIR));
            break;
        case O006S:
            insert_street_info(t, id, create_street_info(0.386, 0.723, NORTH_DIR));
            break;
        case O001S:
            insert_street_info(t, id, create_street_info(0.386, 0.655, NORTH_DIR));
            break;

        case P002S:
            insert_street_info(t, id, create_street_info(0.6025, 0.654, NORTH_DIR));
            break;
        case P003S:
            insert_street_info(t, id, create_street_info(0.6025, 0.722, NORTH_DIR));
            break;
        case P004S:
            insert_street_info(t, id, create_street_info(0.5865, 0.75, NORTH_DIR));
            break;
        case P005S:
            insert_street_info(t, id, create_street_info(0.5385, 0.75, NORTH_DIR));
            break;
        case P006S:
            insert_street_info(t, id, create_street_info(0.5255, 0.723, NORTH_DIR));
            break;
        case P001S:
            insert_street_info(t, id, create_street_info(0.5255, 0.655, NORTH_DIR));
            break;

        case Q002S:
            insert_street_info(t, id, create_street_info(0.743, 0.655, NORTH_DIR));
            break;
        case Q003S:
            insert_street_info(t, id, create_street_info(0.743, 0.723, NORTH_DIR));
            break;
        case Q004S:
            insert_street_info(t, id, create_street_info(0.727, 0.75, NORTH_DIR));
            break;
        case Q005S:
            insert_street_info(t, id, create_street_info(0.679, 0.75, NORTH_DIR));
            break;
        case Q006S:
            insert_street_info(t, id, create_street_info(0.666, 0.723, NORTH_DIR));
            break;
        case Q001S:
            insert_street_info(t, id, create_street_info(0.666, 0.655, NORTH_DIR));
            break;

        case R002S:
            insert_street_info(t, id, create_street_info(0.883, 0.655, NORTH_DIR));
            break;
        case R003S:
            insert_street_info(t, id, create_street_info(0.883, 0.723, NORTH_DIR));
            break;
        case R004S:
            insert_street_info(t, id, create_street_info(0.867, 0.75, NORTH_DIR));
            break;
        case R005S:
            insert_street_info(t, id, create_street_info(0.819, 0.75, NORTH_DIR));
            break;
        case R006S:
            insert_street_info(t, id, create_street_info(0.806, 0.723, NORTH_DIR));
            break;
        case R001S:
            insert_street_info(t, id, create_street_info(0.806, 0.655, NORTH_DIR));
            break;

        case S001S:
            insert_street_info(t, id, create_street_info(0.117, 0.815, NORTH_DIR));
            break;
        case S002S:
            insert_street_info(t, id, create_street_info(0.165, 0.815, NORTH_DIR));
            break;
        case S003S:
            insert_street_info(t, id, create_street_info(0.181, 0.842, NORTH_DIR));
            break;
        case S004S:
            insert_street_info(t, id, create_street_info(0.181, 0.907, NORTH_DIR));
            break;
        case S005S:
            insert_street_info(t, id, create_street_info(0.165, 0.935, NORTH_DIR));
            break;
        case S006S:
            insert_street_info(t, id, create_street_info(0.117, 0.935, NORTH_DIR));
            break;
        case S007S:
            insert_street_info(t, id, create_street_info(0.104, 0.907, NORTH_DIR));
            break;
        case S008S:
            insert_street_info(t, id, create_street_info(0.104, 0.842, NORTH_DIR));
            break;

        case T001S:
            insert_street_info(t, id, create_street_info(0.2585, 0.815, NORTH_DIR));
            break;
        case T002S:
            insert_street_info(t, id, create_street_info(0.3065, 0.815, NORTH_DIR));
            break;
        case T003S:
            insert_street_info(t, id, create_street_info(0.3215, 0.842, NORTH_DIR));
            break;
        case T004S:
            insert_street_info(t, id, create_street_info(0.3215, 0.907, NORTH_DIR));
            break;
        case T005S:
            insert_street_info(t, id, create_street_info(0.3065, 0.935, NORTH_DIR));
            break;
        case T006S:
            insert_street_info(t, id, create_street_info(0.2585, 0.935, NORTH_DIR));
            break;
        case T007S:
            insert_street_info(t, id, create_street_info(0.2455, 0.907, NORTH_DIR));
            break;
        case T008S:
            insert_street_info(t, id, create_street_info(0.2455, 0.842, NORTH_DIR));
            break;

        case U001S:
            insert_street_info(t, id, create_street_info(0.400, 0.815, NORTH_DIR));
            break;
        case U002S:
            insert_street_info(t, id, create_street_info(0.448, 0.815, NORTH_DIR));
            break;
        case U003S:
            insert_street_info(t, id, create_street_info(0.462, 0.842, NORTH_DIR));
            break;
        case U004S:
            insert_street_info(t, id, create_street_info(0.462, 0.907, NORTH_DIR));
            break;
        case U005S:
            insert_street_info(t, id, create_street_info(0.448, 0.935, NORTH_DIR));
            break;
        case U006S:
            insert_street_info(t, id, create_street_info(0.400, 0.935, NORTH_DIR));
            break;
        case U007S:
            insert_street_info(t, id, create_street_info(0.386, 0.907, NORTH_DIR));
            break;
        case U008S:
            insert_street_info(t, id, create_street_info(0.386, 0.842, NORTH_DIR));
            break;

        case V001S:
            insert_street_info(t, id, create_street_info(0.5385, 0.815, NORTH_DIR));
            break;
        case V002S:
            insert_street_info(t, id, create_street_info(0.5865, 0.815, NORTH_DIR));
            break;
        case V003S:
            insert_street_info(t, id, create_street_info(0.6025, 0.841, NORTH_DIR));
            break;
        case V004S:
            insert_street_info(t, id, create_street_info(0.6025, 0.909, NORTH_DIR));
            break;
        case V005S:
            insert_street_info(t, id, create_street_info(0.5865, 0.935, NORTH_DIR));
            break;
        case V006S:
            insert_street_info(t, id, create_street_info(0.5385, 0.935, NORTH_DIR));
            break;
        case V007S:
            insert_street_info(t, id, create_street_info(0.5255, 0.907, NORTH_DIR));
            break;
        case V008S:
            insert_street_info(t, id, create_street_info(0.5255, 0.842, NORTH_DIR));
            break;

        case W001S:
            insert_street_info(t, id, create_street_info(0.679, 0.815, NORTH_DIR));
            break;
        case W002S:
            insert_street_info(t, id, create_street_info(0.727, 0.815, NORTH_DIR));
            break;
        case W003S:
            insert_street_info(t, id, create_street_info(0.743, 0.842, NORTH_DIR));
            break;
        case W004S:
            insert_street_info(t, id, create_street_info(0.743, 0.907, NORTH_DIR));
            break;
        case W005S:
            insert_street_info(t, id, create_street_info(0.727, 0.935, NORTH_DIR));
            break;
        case W006S:
            insert_street_info(t, id, create_street_info(0.679, 0.935, NORTH_DIR));
            break;
        case W007S:
            insert_street_info(t, id, create_street_info(0.666, 0.907, NORTH_DIR));
            break;
        case W008S:
            insert_street_info(t, id, create_street_info(0.666, 0.842, NORTH_DIR));
            break;

        case X001S:
            insert_street_info(t, id, create_street_info(0.819, 0.815, NORTH_DIR));
            break;
        case X002S:
            insert_street_info(t, id, create_street_info(0.867, 0.815, NORTH_DIR));
            break;
        case X003S:
            insert_street_info(t, id, create_street_info(0.883, 0.842, NORTH_DIR));
            break;
        case X004S:
            insert_street_info(t, id, create_street_info(0.883, 0.907, NORTH_DIR));
            break;
        case X005S:
            insert_street_info(t, id, create_street_info(0.867, 0.935, NORTH_DIR));
            break;
        case X006S:
            insert_street_info(t, id, create_street_info(0.819, 0.935, NORTH_DIR));
            break;
        case X007S:
            insert_street_info(t, id, create_street_info(0.806, 0.907, NORTH_DIR));
            break;
        case X008S:
            insert_street_info(t, id, create_street_info(0.806, 0.842, NORTH_DIR));
            break;
        default:
            break;
    }
}

void insert_street_info_roundabouts(TableStreetInfo *t, RoundaboutIds id) {
    switch (id) {
        case Y001R:
            insert_street_info(t, id, create_street_info(0.111, 0.45, NORTH_DIR));
            break;
        case Y002R:
            insert_street_info(t, id, create_street_info(0.111, 0.53, NORTH_DIR));
            break;
        case Y003R:
            insert_street_info(t, id, create_street_info(0.059, 0.59, NORTH_DIR));
            break;
        case Y004R:
            insert_street_info(t, id, create_street_info(0.009, 0.53, NORTH_DIR));
            break;
        case Y005R:
            insert_street_info(t, id, create_street_info(0.009, 0.45, NORTH_DIR));
            break;
        case Y006R:
            insert_street_info(t, id, create_street_info(0.059, 0.39, NORTH_DIR));
            break;
        case Z001R:
            insert_street_info(t, id, create_street_info(0.874, 0.45, NORTH_DIR));
            break;
        case Z002R:
            insert_street_info(t, id, create_street_info(0.874, 0.53, NORTH_DIR));
            break;
        case Z003R:
            insert_street_info(t, id, create_street_info(0.924, 0.59, NORTH_DIR));
            break;
        case Z004R:
            insert_street_info(t, id, create_street_info(0.976, 0.53, NORTH_DIR));
            break;
        case Z005R:
            insert_street_info(t, id, create_street_info(0.976, 0.45, NORTH_DIR));
            break;
        case Z006R:
            insert_street_info(t, id, create_street_info(0.924, 0.39, NORTH_DIR));
            break;
        default:
            break;
    }
}

void insert_street_info_bridge_up(TableStreetInfo *t, BridgeIds id) {
    switch (id) {
        case BU06B:
            insert_street_info(t, id, create_street_info(0.213, 0.420, NORTH_DIR));
            break;
        case BU05B:
            insert_street_info(t, id, create_street_info(0.213, 0.447, NORTH_DIR));
            break;
        case BU04B:
            insert_street_info(t, id, create_street_info(0.213, 0.475, NORTH_DIR));
            break;
        case BU03B:
            insert_street_info(t, id, create_street_info(0.213, 0.501, NORTH_DIR));
            break;
        case BU02B:
            insert_street_info(t, id, create_street_info(0.213, 0.528, NORTH_DIR));
            break;
        case BU01B:
            insert_street_info(t, id, create_street_info(0.213, 0.555, NORTH_DIR));
            break;

        case BU12B:
            insert_street_info(t, id, create_street_info(0.353, 0.420, NORTH_DIR));
            break;
        case BU11B:
            insert_street_info(t, id, create_street_info(0.353, 0.447, NORTH_DIR));
            break;
        case BU10B:
            insert_street_info(t, id, create_street_info(0.353, 0.475, NORTH_DIR));
            break;
        case BU09B:
            insert_street_info(t, id, create_street_info(0.353, 0.501, NORTH_DIR));
            break;
        case BU08B:
            insert_street_info(t, id, create_street_info(0.353, 0.528, NORTH_DIR));
            break;
        case BU07B:
            insert_street_info(t, id, create_street_info(0.353, 0.555, NORTH_DIR));
            break;

        case BU18B:
            insert_street_info(t, id, create_street_info(0.493, 0.420, NORTH_DIR));
            break;
        case BU17B:
            insert_street_info(t, id, create_street_info(0.493, 0.447, NORTH_DIR));
            break;
        case BU16B:
            insert_street_info(t, id, create_street_info(0.493, 0.475, NORTH_DIR));
            break;
        case BU15B:
            insert_street_info(t, id, create_street_info(0.493, 0.501, NORTH_DIR));
            break;
        case BU14B:
            insert_street_info(t, id, create_street_info(0.493, 0.528, NORTH_DIR));
            break;
        case BU13B:
            insert_street_info(t, id, create_street_info(0.493, 0.555, NORTH_DIR));
            break;

        case BU24B:
            insert_street_info(t, id, create_street_info(0.634, 0.420, NORTH_DIR));
            break;
        case BU23B:
            insert_street_info(t, id, create_street_info(0.634, 0.447, NORTH_DIR));
            break;
        case BU22B:
            insert_street_info(t, id, create_street_info(0.634, 0.475, NORTH_DIR));
            break;
        case BU21B:
            insert_street_info(t, id, create_street_info(0.634, 0.501, NORTH_DIR));
            break;
        case BU20B:
            insert_street_info(t, id, create_street_info(0.634, 0.528, NORTH_DIR));
            break;
        case BU19B:
            insert_street_info(t, id, create_street_info(0.634, 0.555, NORTH_DIR));
            break;

        case BU30B:
            insert_street_info(t, id, create_street_info(0.775, 0.420, NORTH_DIR));
            break;
        case BU29B:
            insert_street_info(t, id, create_street_info(0.775, 0.447, NORTH_DIR));
            break;
        case BU28B:
            insert_street_info(t, id, create_street_info(0.775, 0.475, NORTH_DIR));
            break;
        case BU27B:
            insert_street_info(t, id, create_street_info(0.775, 0.501, NORTH_DIR));
            break;
        case BU26B:
            insert_street_info(t, id, create_street_info(0.775, 0.528, NORTH_DIR));
            break;
        case BU25B:
            insert_street_info(t, id, create_street_info(0.775, 0.555, NORTH_DIR));
            break;
        default:
            break;
    }
}

void insert_street_info_bridge(TableStreetInfo *t, BridgeIds id) {
    switch (id) {
        case B001B:
            insert_street_info(t, id, create_street_info(0.213, 0.420, SOUTH_DIR));
            break;
        case B002B:
            insert_street_info(t, id, create_street_info(0.213, 0.447, SOUTH_DIR));
            break;
        case B003B:
            insert_street_info(t, id, create_street_info(0.213, 0.475, SOUTH_DIR));
            break;
        case B004B:
            insert_street_info(t, id, create_street_info(0.213, 0.501, SOUTH_DIR));
            break;
        case B005B:
            insert_street_info(t, id, create_street_info(0.213, 0.528, SOUTH_DIR));
            break;
        case B006B:
            insert_street_info(t, id, create_street_info(0.213, 0.555, SOUTH_DIR));
            break;

        case B007B:
            insert_street_info(t, id, create_street_info(0.353, 0.420, SOUTH_DIR));
            break;
        case B008B:
            insert_street_info(t, id, create_street_info(0.353, 0.447, SOUTH_DIR));
            break;
        case B009B:
            insert_street_info(t, id, create_street_info(0.353, 0.475, SOUTH_DIR));
            break;
        case B010B:
            insert_street_info(t, id, create_street_info(0.353, 0.501, SOUTH_DIR));
            break;
        case B011B:
            insert_street_info(t, id, create_street_info(0.353, 0.528, SOUTH_DIR));
            break;
        case B012B:
            insert_street_info(t, id, create_street_info(0.353, 0.555, SOUTH_DIR));
            break;

        case B013B:
            insert_street_info(t, id, create_street_info(0.493, 0.420, SOUTH_DIR));
            break;
        case B014B:
            insert_street_info(t, id, create_street_info(0.493, 0.447, SOUTH_DIR));
            break;
        case B015B:
            insert_street_info(t, id, create_street_info(0.493, 0.475, SOUTH_DIR));
            break;
        case B016B:
            insert_street_info(t, id, create_street_info(0.493, 0.501, SOUTH_DIR));
            break;
        case B017B:
            insert_street_info(t, id, create_street_info(0.493, 0.528, SOUTH_DIR));
            break;
        case B018B:
            insert_street_info(t, id, create_street_info(0.493, 0.555, SOUTH_DIR));
            break;

        case B019B:
            insert_street_info(t, id, create_street_info(0.634, 0.420, SOUTH_DIR));
            break;
        case B020B:
            insert_street_info(t, id, create_street_info(0.634, 0.447, SOUTH_DIR));
            break;
        case B021B:
            insert_street_info(t, id, create_street_info(0.634, 0.475, SOUTH_DIR));
            break;
        case B022B:
            insert_street_info(t, id, create_street_info(0.634, 0.501, SOUTH_DIR));
            break;
        case B023B:
            insert_street_info(t, id, create_street_info(0.634, 0.528, SOUTH_DIR));
            break;
        case B024B:
            insert_street_info(t, id, create_street_info(0.634, 0.555, SOUTH_DIR));
            break;

        case B025B:
            insert_street_info(t, id, create_street_info(0.775, 0.420, SOUTH_DIR));
            break;
        case B026B:
            insert_street_info(t, id, create_street_info(0.775, 0.447, SOUTH_DIR));
            break;
        case B027B:
            insert_street_info(t, id, create_street_info(0.775, 0.475, SOUTH_DIR));
            break;
        case B028B:
            insert_street_info(t, id, create_street_info(0.775, 0.501, SOUTH_DIR));
            break;
        case B029B:
            insert_street_info(t, id, create_street_info(0.775, 0.528, SOUTH_DIR));
            break;
        case B030B:
            insert_street_info(t, id, create_street_info(0.775, 0.555, SOUTH_DIR));
            break;
        default:
            break;
    }
}

void insert_street_info_streets(TableStreetInfo *t, StreetIds id) {
    switch (id) {
        //++Fila0
//Segmento 0

        case A001P:
            insert_street_info(t, id, create_street_info(0.101, 0.007, EAST_DIR));
            break;
        case A002P:
            insert_street_info(t, id, create_street_info(0.117, 0.007, EAST_DIR));
            break;
        case A003P:
            insert_street_info(t, id, create_street_info(0.133, 0.007, EAST_DIR));
            break;
        case A004P:
            insert_street_info(t, id, create_street_info(0.149, 0.007, EAST_DIR));
            break;
        case A005P:
            insert_street_info(t, id, create_street_info(0.165, 0.007, EAST_DIR));
            break;
        case A006P:
            insert_street_info(t, id, create_street_info(0.181, 0.007, EAST_DIR));
            break;
//Segmento 1
        case B001P:
            insert_street_info(t, id, create_street_info(0.2425, 0.007, EAST_DIR));
            break;
        case B002P:
            insert_street_info(t, id, create_street_info(0.2585, 0.007, EAST_DIR));
            break;
        case B003P:
            insert_street_info(t, id, create_street_info(0.2745, 0.007, EAST_DIR));
            break;
        case B004P:
            insert_street_info(t, id, create_street_info(0.2905, 0.007, EAST_DIR));
            break;
        case B005P:
            insert_street_info(t, id, create_street_info(0.3065, 0.007, EAST_DIR));
            break;
        case B006P:
            insert_street_info(t, id, create_street_info(0.3225, 0.007, EAST_DIR));
            break;
//Segmento 2
        case C001P:
            insert_street_info(t, id, create_street_info(0.384, 0.007, EAST_DIR));
            break;
        case C002P:
            insert_street_info(t, id, create_street_info(0.400, 0.007, EAST_DIR));
            break;
        case C003P:
            insert_street_info(t, id, create_street_info(0.416, 0.007, EAST_DIR));
            break;
        case C004P:
            insert_street_info(t, id, create_street_info(0.432, 0.007, EAST_DIR));
            break;
        case C005P:
            insert_street_info(t, id, create_street_info(0.448, 0.007, EAST_DIR));
            break;
        case C006P:
            insert_street_info(t, id, create_street_info(0.464, 0.007, EAST_DIR));
            break;
//Segmento 3
        case D001P:
            insert_street_info(t, id, create_street_info(0.5225, 0.007, EAST_DIR));
            break;
        case D002P:
            insert_street_info(t, id, create_street_info(0.5385, 0.007, EAST_DIR));
            break;
        case D003P:
            insert_street_info(t, id, create_street_info(0.5545, 0.007, EAST_DIR));
            break;
        case D004P:
            insert_street_info(t, id, create_street_info(0.5705, 0.007, EAST_DIR));
            break;
        case D005P:
            insert_street_info(t, id, create_street_info(0.5865, 0.007, EAST_DIR));
            break;
        case D006P:
            insert_street_info(t, id, create_street_info(0.6025, 0.007, EAST_DIR));
            break;
//Segmento 4
        case E001P:
            insert_street_info(t, id, create_street_info(0.663, 0.007, EAST_DIR));
            break;
        case E002P:
            insert_street_info(t, id, create_street_info(0.679, 0.007, EAST_DIR));
            break;
        case E003P:
            insert_street_info(t, id, create_street_info(0.695, 0.007, EAST_DIR));
            break;
        case E004P:
            insert_street_info(t, id, create_street_info(0.711, 0.007, EAST_DIR));
            break;
        case E005P:
            insert_street_info(t, id, create_street_info(0.727, 0.007, EAST_DIR));
            break;
        case E006P:
            insert_street_info(t, id, create_street_info(0.743, 0.007, EAST_DIR));
            break;
//Segmento 5
        case F001P:
            insert_street_info(t, id, create_street_info(0.803, 0.007, EAST_DIR));
            break;
        case F002P:
            insert_street_info(t, id, create_street_info(0.819, 0.007, EAST_DIR));
            break;
        case F003P:
            insert_street_info(t, id, create_street_info(0.834, 0.007, EAST_DIR));
            break;
        case F004P:
            insert_street_info(t, id, create_street_info(0.851, 0.007, EAST_DIR));
            break;
        case F005P:
            insert_street_info(t, id, create_street_info(0.867, 0.007, EAST_DIR));
            break;
        case F006P:
            insert_street_info(t, id, create_street_info(0.883, 0.007, EAST_DIR));
            break;

//++Fila1
//Segmento 0
        case A018P: // && G006P
            insert_street_info(t, id, create_street_info(0.101, 0.194, WEST_DIR));
            break;
        case A017P: // && G005P
            insert_street_info(t, id, create_street_info(0.117, 0.194, WEST_DIR));
            break;
        case A016P: // && G004P
            insert_street_info(t, id, create_street_info(0.133, 0.194, WEST_DIR));
            break;
        case A015P: // && G003P
            insert_street_info(t, id, create_street_info(0.149, 0.194, WEST_DIR));
            break;
        case A014P: // && G002P
            insert_street_info(t, id, create_street_info(0.165, 0.194, WEST_DIR));
            break;
        case A013P: // && G001P
            insert_street_info(t, id, create_street_info(0.181, 0.194, WEST_DIR));
            break;
//Segmento 1
        case B018P: // && H006P
            insert_street_info(t, id, create_street_info(0.2425, 0.194, WEST_DIR));
            break;
        case B017P: // && H005P
            insert_street_info(t, id, create_street_info(0.2585, 0.194, WEST_DIR));
            break;
        case B016P: // && H004P
            insert_street_info(t, id, create_street_info(0.2745, 0.194, WEST_DIR));
            break;
        case B015P: // && H003P
            insert_street_info(t, id, create_street_info(0.2905, 0.194, WEST_DIR));
            break;
        case B014P: // && H002P
            insert_street_info(t, id, create_street_info(0.3065, 0.194, WEST_DIR));
            break;
        case B013P: // && H001P
            insert_street_info(t, id, create_street_info(0.3225, 0.194, WEST_DIR));
            break;
//Segmento 2
        case C018P: // && I006P
            insert_street_info(t, id, create_street_info(0.384, 0.194, WEST_DIR));
            break;
        case C017P: // && I005P
            insert_street_info(t, id, create_street_info(0.400, 0.194, WEST_DIR));
            break;
        case C016P: // && I004P
            insert_street_info(t, id, create_street_info(0.416, 0.194, WEST_DIR));
            break;
        case C015P: // && I003P
            insert_street_info(t, id, create_street_info(0.432, 0.194, WEST_DIR));
            break;
        case C014P: // && I002P
            insert_street_info(t, id, create_street_info(0.448, 0.194, WEST_DIR));
            break;
        case C013P: // && I001P
            insert_street_info(t, id, create_street_info(0.464, 0.194, WEST_DIR));
            break;

//Segmento 3
        case D018P: // && J006P
            insert_street_info(t, id, create_street_info(0.5225, 0.194, WEST_DIR));
            break;
        case D017P: // && J005P
            insert_street_info(t, id, create_street_info(0.5385, 0.194, WEST_DIR));
            break;
        case D016P: // && J004P
            insert_street_info(t, id, create_street_info(0.5545, 0.194, WEST_DIR));
            break;
        case D015P: // && J003P
            insert_street_info(t, id, create_street_info(0.5705, 0.194, WEST_DIR));
            break;
        case D014P: // && J002P
            insert_street_info(t, id, create_street_info(0.5865, 0.194, WEST_DIR));
            break;
        case D013P: // && J001P
            insert_street_info(t, id, create_street_info(0.6025, 0.194, WEST_DIR));
            break;
//Segmento 4
        case E018P: // && K006P
            insert_street_info(t, id, create_street_info(0.663, 0.194, WEST_DIR));
            break;
        case E017P: // && K005P
            insert_street_info(t, id, create_street_info(0.679, 0.194, WEST_DIR));
            break;
        case E016P: // && K004P
            insert_street_info(t, id, create_street_info(0.695, 0.194, WEST_DIR));
            break;
        case E015P: // && K003P
            insert_street_info(t, id, create_street_info(0.711, 0.194, WEST_DIR));
            break;
        case E014P: // && K002P
            insert_street_info(t, id, create_street_info(0.727, 0.194, WEST_DIR));
            break;
        case E013P: // && K001P
            insert_street_info(t, id, create_street_info(0.743, 0.194, WEST_DIR));
            break;
//Segmento 5
        case F018P: // && L006P
            insert_street_info(t, id, create_street_info(0.803, 0.194, WEST_DIR));
            break;
        case F017P: // && L005P
            insert_street_info(t, id, create_street_info(0.819, 0.194, WEST_DIR));
            break;
        case F016P: // && L004P
            insert_street_info(t, id, create_street_info(0.834, 0.194, WEST_DIR));
            break;
        case F015P: // && L003P
            insert_street_info(t, id, create_street_info(0.851, 0.194, WEST_DIR));
            break;
        case F014P: // && L002P
            insert_street_info(t, id, create_street_info(0.867, 0.194, WEST_DIR));
            break;
        case F013P: // && L001P
            insert_street_info(t, id, create_street_info(0.883, 0.194, WEST_DIR));
            break;

//++Fila2
//Segmento 0
        case M012P: // && S001P
            insert_street_info(t, id, create_street_info(0.101, 0.778, EAST_DIR));
            break;
        case M011P: // && S002P
            insert_street_info(t, id, create_street_info(0.117, 0.778, EAST_DIR));
            break;
        case M010P: // && S003P
            insert_street_info(t, id, create_street_info(0.133, 0.778, EAST_DIR));
            break;
        case M009P: // && S004P
            insert_street_info(t, id, create_street_info(0.149, 0.778, EAST_DIR));
            break;
        case M008P: // && S005P
            insert_street_info(t, id, create_street_info(0.165, 0.778, EAST_DIR));
            break;
        case M007P: // && S006P
            insert_street_info(t, id, create_street_info(0.181, 0.778, EAST_DIR));
            break;
//Segmento 1
        case N012P: // && T001P
            insert_street_info(t, id, create_street_info(0.2425, 0.778, EAST_DIR));
            break;
        case N011P: // && T002P
            insert_street_info(t, id, create_street_info(0.2585, 0.778, EAST_DIR));
            break;
        case N010P: // && T003P
            insert_street_info(t, id, create_street_info(0.2745, 0.778, EAST_DIR));
            break;
        case N009P: // && T004P
            insert_street_info(t, id, create_street_info(0.2905, 0.778, EAST_DIR));
            break;
        case N008P: // && T005P
            insert_street_info(t, id, create_street_info(0.3065, 0.778, EAST_DIR));
            break;
        case N007P: // && T006P
            insert_street_info(t, id, create_street_info(0.3225, 0.778, EAST_DIR));
            break;
//Segmento 2
        case O012P: // && U001P
            insert_street_info(t, id, create_street_info(0.384, 0.778, EAST_DIR));
            break;
        case O011P: // && U002P
            insert_street_info(t, id, create_street_info(0.400, 0.778, EAST_DIR));
            break;
        case O010P: // && U003P
            insert_street_info(t, id, create_street_info(0.416, 0.778, EAST_DIR));
            break;
        case O009P: // && U004P
            insert_street_info(t, id, create_street_info(0.432, 0.778, EAST_DIR));
            break;
        case O008P: // && U005P
            insert_street_info(t, id, create_street_info(0.448, 0.778, EAST_DIR));
            break;
        case O007P: // && U006P
            insert_street_info(t, id, create_street_info(0.464, 0.778, EAST_DIR));
            break;

//Segmento 3
        case P012P: // && P007P
            insert_street_info(t, id, create_street_info(0.5225, 0.778, EAST_DIR));
            break;
        case P011P: // && P008P
            insert_street_info(t, id, create_street_info(0.5385, 0.778, EAST_DIR));
            break;
        case P010P: // && P009P
            insert_street_info(t, id, create_street_info(0.5545, 0.778, EAST_DIR));
            break;
        case P009P: // && P010P
            insert_street_info(t, id, create_street_info(0.5705, 0.778, EAST_DIR));
            break;
        case P008P: // && P011P
            insert_street_info(t, id, create_street_info(0.5865, 0.778, EAST_DIR));
            break;
        case P007P: // && P012P
            insert_street_info(t, id, create_street_info(0.6025, 0.778, EAST_DIR));
            break;
//Segmento 4
        case Q012P: // && W001P
            insert_street_info(t, id, create_street_info(0.663, 0.778, EAST_DIR));
            break;
        case Q011P: // && W002P
            insert_street_info(t, id, create_street_info(0.679, 0.778, EAST_DIR));
            break;
        case Q010P: // && W003P
            insert_street_info(t, id, create_street_info(0.695, 0.778, EAST_DIR));
            break;
        case Q009P: // && W004P
            insert_street_info(t, id, create_street_info(0.711, 0.778, EAST_DIR));
            break;
        case Q008P: // && W005P
            insert_street_info(t, id, create_street_info(0.727, 0.778, EAST_DIR));
            break;
        case Q007P: // && W006P
            insert_street_info(t, id, create_street_info(0.743, 0.778, EAST_DIR));
            break;
//Segmento 5
        case R012P: // && X001P
            insert_street_info(t, id, create_street_info(0.803, 0.778, EAST_DIR));
            break;
        case R011P: // && X002P
            insert_street_info(t, id, create_street_info(0.819, 0.778, EAST_DIR));
            break;
        case R010P: // && X003P
            insert_street_info(t, id, create_street_info(0.834, 0.778, EAST_DIR));
            break;
        case R009P: // && X004P
            insert_street_info(t, id, create_street_info(0.851, 0.778, EAST_DIR));
            break;
        case R008P: // && X005P
            insert_street_info(t, id, create_street_info(0.867, 0.778, EAST_DIR));
            break;
        case R007P: // && X006P
            insert_street_info(t, id, create_street_info(0.883, 0.778, EAST_DIR));
            break;
//++Fila3
//Segmento 0
        case S018P:
            insert_street_info(t, id, create_street_info(0.101, 0.965, WEST_DIR));
            break;
        case S017P:
            insert_street_info(t, id, create_street_info(0.117, 0.965, WEST_DIR));
            break;
        case S016P:
            insert_street_info(t, id, create_street_info(0.133, 0.965, WEST_DIR));
            break;
        case S015P:
            insert_street_info(t, id, create_street_info(0.149, 0.965, WEST_DIR));
            break;
        case S014P:
            insert_street_info(t, id, create_street_info(0.165, 0.965, WEST_DIR));
            break;
        case S013P:
            insert_street_info(t, id, create_street_info(0.181, 0.965, WEST_DIR));
            break;
//Segmento 1
        case T018P:
            insert_street_info(t, id, create_street_info(0.2425, 0.965, WEST_DIR));
            break;
        case T017P:
            insert_street_info(t, id, create_street_info(0.2585, 0.965, WEST_DIR));
            break;
        case T016P:
            insert_street_info(t, id, create_street_info(0.2745, 0.965, WEST_DIR));
            break;
        case T015P:
            insert_street_info(t, id, create_street_info(0.2905, 0.965, WEST_DIR));
            break;
        case T014P:
            insert_street_info(t, id, create_street_info(0.3065, 0.965, WEST_DIR));
            break;
        case T013P:
            insert_street_info(t, id, create_street_info(0.3225, 0.965, WEST_DIR));
            break;
//Segmento 2
        case U018P:
            insert_street_info(t, id, create_street_info(0.384, 0.965, WEST_DIR));
            break;
        case U017P:
            insert_street_info(t, id, create_street_info(0.400, 0.965, WEST_DIR));
            break;
        case U016P:
            insert_street_info(t, id, create_street_info(0.416, 0.965, WEST_DIR));
            break;
        case U015P:
            insert_street_info(t, id, create_street_info(0.432, 0.965, WEST_DIR));
            break;
        case U014P:
            insert_street_info(t, id, create_street_info(0.448, 0.965, WEST_DIR));
            break;
        case U013P:
            insert_street_info(t, id, create_street_info(0.464, 0.965, WEST_DIR));
            break;
//Segmento 3
        case V018P:
            insert_street_info(t, id, create_street_info(0.5225, 0.965, WEST_DIR));
            break;
        case V017P:
            insert_street_info(t, id, create_street_info(0.5385, 0.965, WEST_DIR));
            break;
        case V016P:
            insert_street_info(t, id, create_street_info(0.5545, 0.965, WEST_DIR));
            break;
        case V015P:
            insert_street_info(t, id, create_street_info(0.5705, 0.965, WEST_DIR));
            break;
        case V014P:
            insert_street_info(t, id, create_street_info(0.5865, 0.965, WEST_DIR));
            break;
        case V013P:
            insert_street_info(t, id, create_street_info(0.6025, 0.965, WEST_DIR));
            break;
//Segmento 4
        case W018P:
            insert_street_info(t, id, create_street_info(0.663, 0.965, WEST_DIR));
            break;
        case W017P:
            insert_street_info(t, id, create_street_info(0.679, 0.965, WEST_DIR));
            break;
        case W016P:
            insert_street_info(t, id, create_street_info(0.695, 0.965, WEST_DIR));
            break;
        case W015P:
            insert_street_info(t, id, create_street_info(0.711, 0.965, WEST_DIR));
            break;
        case W014P:
            insert_street_info(t, id, create_street_info(0.727, 0.965, WEST_DIR));
            break;
        case W013P:
            insert_street_info(t, id, create_street_info(0.743, 0.965, WEST_DIR));
            break;
//Segmento 5
        case X018P:
            insert_street_info(t, id, create_street_info(0.803, 0.965, WEST_DIR));
            break;
        case X017P:
            insert_street_info(t, id, create_street_info(0.819, 0.965, WEST_DIR));
            break;
        case X016P:
            insert_street_info(t, id, create_street_info(0.834, 0.965, WEST_DIR));
            break;
        case X015P:
            insert_street_info(t, id, create_street_info(0.851, 0.965, WEST_DIR));
            break;
        case X014P:
            insert_street_info(t, id, create_street_info(0.867, 0.965, WEST_DIR));
            break;
        case X013P:
            insert_street_info(t, id, create_street_info(0.883, 0.965, WEST_DIR));
            break;
//Parte superior
//Columna 0
        case A024P:
            insert_street_info(t, id, create_street_info(0.085, 0.040, NORTH_DIR));
            break;
        case A023P:
            insert_street_info(t, id, create_street_info(0.085, 0.065, NORTH_DIR));
            break;
        case A022P:
            insert_street_info(t, id, create_street_info(0.085, 0.090, NORTH_DIR));
            break;
        case A021P:
            insert_street_info(t, id, create_street_info(0.085, 0.115, NORTH_DIR));
            break;
        case A020P:
            insert_street_info(t, id, create_street_info(0.085, 0.138, NORTH_DIR));
            break;
        case A019P:
            insert_street_info(t, id, create_street_info(0.085, 0.163, NORTH_DIR));
            break;
        case G018P:
            insert_street_info(t, id, create_street_info(0.085, 0.226, NORTH_DIR));
            break;
        case G017P:
            insert_street_info(t, id, create_street_info(0.085, 0.251, NORTH_DIR));
            break;
        case G016P:
            insert_street_info(t, id, create_street_info(0.085, 0.275, NORTH_DIR));
            break;
        case G015P:
            insert_street_info(t, id, create_street_info(0.085, 0.300, NORTH_DIR));
            break;
        case G014P:
            insert_street_info(t, id, create_street_info(0.085, 0.323, NORTH_DIR));
            break;
        case G013P:
            insert_street_info(t, id, create_street_info(0.085, 0.345, NORTH_DIR));
            break;
//Columna 1
        case A007P:
            insert_street_info(t, id, create_street_info(0.200, 0.040, SOUTH_DIR));
            break;
        case A008P:
            insert_street_info(t, id, create_street_info(0.200, 0.065, SOUTH_DIR));
            break;
        case A009P:
            insert_street_info(t, id, create_street_info(0.200, 0.090, SOUTH_DIR));
            break;
        case A010P:
            insert_street_info(t, id, create_street_info(0.200, 0.115, SOUTH_DIR));
            break;
        case A011P:
            insert_street_info(t, id, create_street_info(0.200, 0.138, SOUTH_DIR));
            break;
        case A012P:
            insert_street_info(t, id, create_street_info(0.200, 0.163, SOUTH_DIR));
            break;
        case G007P:
            insert_street_info(t, id, create_street_info(0.200, 0.226, SOUTH_DIR));
            break;
        case G008P:
            insert_street_info(t, id, create_street_info(0.200, 0.251, SOUTH_DIR));
            break;
        case G009P:
            insert_street_info(t, id, create_street_info(0.200, 0.275, SOUTH_DIR));
            break;
        case G010P:
            insert_street_info(t, id, create_street_info(0.200, 0.300, SOUTH_DIR));
            break;
        case G011P:
            insert_street_info(t, id, create_street_info(0.200, 0.323, SOUTH_DIR));
            break;
        case G012P:
            insert_street_info(t, id, create_street_info(0.200, 0.345, SOUTH_DIR));
            break;
//Columna 2
        case B024P:
            insert_street_info(t, id, create_street_info(0.2235, 0.040, NORTH_DIR));
            break;
        case B023P:
            insert_street_info(t, id, create_street_info(0.2235, 0.065, NORTH_DIR));
            break;
        case B022P:
            insert_street_info(t, id, create_street_info(0.2235, 0.090, NORTH_DIR));
            break;
        case B021P:
            insert_street_info(t, id, create_street_info(0.2235, 0.115, NORTH_DIR));
            break;
        case B020P:
            insert_street_info(t, id, create_street_info(0.2235, 0.138, NORTH_DIR));
            break;
        case B019P:
            insert_street_info(t, id, create_street_info(0.2235, 0.163, NORTH_DIR));
            break;
        case H018P:
            insert_street_info(t, id, create_street_info(0.2235, 0.226, NORTH_DIR));
            break;
        case H017P:
            insert_street_info(t, id, create_street_info(0.2235, 0.251, NORTH_DIR));
            break;
        case H016P:
            insert_street_info(t, id, create_street_info(0.2235, 0.275, NORTH_DIR));
            break;
        case H015P:
            insert_street_info(t, id, create_street_info(0.2235, 0.300, NORTH_DIR));
            break;
        case H014P:
            insert_street_info(t, id, create_street_info(0.2235, 0.323, NORTH_DIR));
            break;
        case H013P:
            insert_street_info(t, id, create_street_info(0.2235, 0.345, NORTH_DIR));
            break;
//Columna 3
        case B007P:
            insert_street_info(t, id, create_street_info(0.3415, 0.040, SOUTH_DIR));
            break;
        case B008P:
            insert_street_info(t, id, create_street_info(0.3415, 0.065, SOUTH_DIR));
            break;
        case B009P:
            insert_street_info(t, id, create_street_info(0.3415, 0.090, SOUTH_DIR));
            break;
        case B010P:
            insert_street_info(t, id, create_street_info(0.3415, 0.115, SOUTH_DIR));
            break;
        case B011P:
            insert_street_info(t, id, create_street_info(0.3415, 0.138, SOUTH_DIR));
            break;
        case B012P:
            insert_street_info(t, id, create_street_info(0.3415, 0.163, SOUTH_DIR));
            break;
        case H007P:
            insert_street_info(t, id, create_street_info(0.3415, 0.226, SOUTH_DIR));
            break;
        case H008P:
            insert_street_info(t, id, create_street_info(0.3415, 0.251, SOUTH_DIR));
            break;
        case H009P:
            insert_street_info(t, id, create_street_info(0.3415, 0.275, SOUTH_DIR));
            break;
        case H010P:
            insert_street_info(t, id, create_street_info(0.3415, 0.300, SOUTH_DIR));
            break;
        case H011P:
            insert_street_info(t, id, create_street_info(0.3415, 0.323, SOUTH_DIR));
            break;
        case H012P:
            insert_street_info(t, id, create_street_info(0.3415, 0.345, SOUTH_DIR));
            break;
//Columna 4
        case C024P:
            insert_street_info(t, id, create_street_info(0.365, 0.040, NORTH_DIR));
            break;
        case C023P:
            insert_street_info(t, id, create_street_info(0.365, 0.065, NORTH_DIR));
            break;
        case C022P:
            insert_street_info(t, id, create_street_info(0.365, 0.090, NORTH_DIR));
            break;
        case C021P:
            insert_street_info(t, id, create_street_info(0.365, 0.115, NORTH_DIR));
            break;
        case C020P:
            insert_street_info(t, id, create_street_info(0.365, 0.138, NORTH_DIR));
            break;
        case C019P:
            insert_street_info(t, id, create_street_info(0.365, 0.163, NORTH_DIR));
            break;
        case I018P:
            insert_street_info(t, id, create_street_info(0.365, 0.226, NORTH_DIR));
            break;
        case I017P:
            insert_street_info(t, id, create_street_info(0.365, 0.251, NORTH_DIR));
            break;
        case I016P:
            insert_street_info(t, id, create_street_info(0.365, 0.275, NORTH_DIR));
            break;
        case I015P:
            insert_street_info(t, id, create_street_info(0.365, 0.300, NORTH_DIR));
            break;
        case I014P:
            insert_street_info(t, id, create_street_info(0.365, 0.323, NORTH_DIR));
            break;
        case I013P:
            insert_street_info(t, id, create_street_info(0.365, 0.345, NORTH_DIR));
            break;
//Columna 5
        case C007P:
            insert_street_info(t, id, create_street_info(0.483, 0.040, SOUTH_DIR));
            break;
        case C008P:
            insert_street_info(t, id, create_street_info(0.483, 0.065, SOUTH_DIR));
            break;
        case C009P:
            insert_street_info(t, id, create_street_info(0.483, 0.090, SOUTH_DIR));
            break;
        case C010P:
            insert_street_info(t, id, create_street_info(0.483, 0.115, SOUTH_DIR));
            break;
        case C011P:
            insert_street_info(t, id, create_street_info(0.483, 0.138, SOUTH_DIR));
            break;
        case C012P:
            insert_street_info(t, id, create_street_info(0.483, 0.163, SOUTH_DIR));
            break;
        case I007P:
            insert_street_info(t, id, create_street_info(0.483, 0.226, SOUTH_DIR));
            break;
        case I008P:
            insert_street_info(t, id, create_street_info(0.483, 0.251, SOUTH_DIR));
            break;
        case I009P:
            insert_street_info(t, id, create_street_info(0.483, 0.275, SOUTH_DIR));
            break;
        case I010P:
            insert_street_info(t, id, create_street_info(0.483, 0.300, SOUTH_DIR));
            break;
        case I011P:
            insert_street_info(t, id, create_street_info(0.483, 0.323, SOUTH_DIR));
            break;
        case I012P:
            insert_street_info(t, id, create_street_info(0.483, 0.345, SOUTH_DIR));
            break;
//Columna 6
        case D024P:
            insert_street_info(t, id, create_street_info(0.5035, 0.040, NORTH_DIR));
            break;
        case D023P:
            insert_street_info(t, id, create_street_info(0.5035, 0.065, NORTH_DIR));
            break;
        case D022P:
            insert_street_info(t, id, create_street_info(0.5035, 0.090, NORTH_DIR));
            break;
        case D021P:
            insert_street_info(t, id, create_street_info(0.5035, 0.115, NORTH_DIR));
            break;
        case D020P:
            insert_street_info(t, id, create_street_info(0.5035, 0.138, NORTH_DIR));
            break;
        case D019P:
            insert_street_info(t, id, create_street_info(0.5035, 0.163, NORTH_DIR));
            break;
        case J018P:
            insert_street_info(t, id, create_street_info(0.5035, 0.226, NORTH_DIR));
            break;
        case J017P:
            insert_street_info(t, id, create_street_info(0.5035, 0.251, NORTH_DIR));
            break;
        case J016P:
            insert_street_info(t, id, create_street_info(0.5035, 0.275, NORTH_DIR));
            break;
        case J015P:
            insert_street_info(t, id, create_street_info(0.5035, 0.300, NORTH_DIR));
            break;
        case J014P:
            insert_street_info(t, id, create_street_info(0.5035, 0.323, NORTH_DIR));
            break;
        case J013P:
            insert_street_info(t, id, create_street_info(0.5035, 0.345, NORTH_DIR));
            break;
//Columna 7
        case D007P:
            insert_street_info(t, id, create_street_info(0.6215, 0.040, SOUTH_DIR));
            break;
        case D008P:
            insert_street_info(t, id, create_street_info(0.6215, 0.065, SOUTH_DIR));
            break;
        case D009P:
            insert_street_info(t, id, create_street_info(0.6215, 0.090, SOUTH_DIR));
            break;
        case D010P:
            insert_street_info(t, id, create_street_info(0.6215, 0.115, SOUTH_DIR));
            break;
        case D011P:
            insert_street_info(t, id, create_street_info(0.6215, 0.138, SOUTH_DIR));
            break;
        case D012P:
            insert_street_info(t, id, create_street_info(0.6215, 0.163, SOUTH_DIR));
            break;
        case J007P:
            insert_street_info(t, id, create_street_info(0.6215, 0.226, SOUTH_DIR));
            break;
        case J008P:
            insert_street_info(t, id, create_street_info(0.6215, 0.251, SOUTH_DIR));
            break;
        case J009P:
            insert_street_info(t, id, create_street_info(0.6215, 0.275, SOUTH_DIR));
            break;
        case J010P:
            insert_street_info(t, id, create_street_info(0.6215, 0.300, SOUTH_DIR));
            break;
        case J011P:
            insert_street_info(t, id, create_street_info(0.6215, 0.323, SOUTH_DIR));
            break;
        case J012P:
            insert_street_info(t, id, create_street_info(0.6215, 0.345, SOUTH_DIR));
            break;
//Columna 8
        case E024P:
            insert_street_info(t, id, create_street_info(0.644, 0.040, NORTH_DIR));
            break;
        case E023P:
            insert_street_info(t, id, create_street_info(0.644, 0.065, NORTH_DIR));
            break;
        case E022P:
            insert_street_info(t, id, create_street_info(0.644, 0.090, NORTH_DIR));
            break;
        case E021P:
            insert_street_info(t, id, create_street_info(0.644, 0.115, NORTH_DIR));
            break;
        case E020P:
            insert_street_info(t, id, create_street_info(0.644, 0.138, NORTH_DIR));
            break;
        case E019P:
            insert_street_info(t, id, create_street_info(0.644, 0.163, NORTH_DIR));
            break;
        case K018P:
            insert_street_info(t, id, create_street_info(0.644, 0.226, NORTH_DIR));
            break;
        case K017P:
            insert_street_info(t, id, create_street_info(0.644, 0.251, NORTH_DIR));
            break;
        case K016P:
            insert_street_info(t, id, create_street_info(0.644, 0.275, NORTH_DIR));
            break;
        case K015P:
            insert_street_info(t, id, create_street_info(0.644, 0.300, NORTH_DIR));
            break;
        case K014P:
            insert_street_info(t, id, create_street_info(0.644, 0.323, NORTH_DIR));
            break;
        case K013P:
            insert_street_info(t, id, create_street_info(0.644, 0.345, NORTH_DIR));
            break;
//Columna 9
        case E007P:
            insert_street_info(t, id, create_street_info(0.762, 0.040, SOUTH_DIR));
            break;
        case E008P:
            insert_street_info(t, id, create_street_info(0.762, 0.065, SOUTH_DIR));
            break;
        case E009P:
            insert_street_info(t, id, create_street_info(0.762, 0.090, SOUTH_DIR));
            break;
        case E010P:
            insert_street_info(t, id, create_street_info(0.762, 0.115, SOUTH_DIR));
            break;
        case E011P:
            insert_street_info(t, id, create_street_info(0.762, 0.138, SOUTH_DIR));
            break;
        case E012P:
            insert_street_info(t, id, create_street_info(0.762, 0.163, SOUTH_DIR));
            break;
        case K007P:
            insert_street_info(t, id, create_street_info(0.762, 0.226, SOUTH_DIR));
            break;
        case K008P:
            insert_street_info(t, id, create_street_info(0.762, 0.251, SOUTH_DIR));
            break;
        case K009P:
            insert_street_info(t, id, create_street_info(0.762, 0.275, SOUTH_DIR));
            break;
        case K010P:
            insert_street_info(t, id, create_street_info(0.762, 0.300, SOUTH_DIR));
            break;
        case K011P:
            insert_street_info(t, id, create_street_info(0.762, 0.323, SOUTH_DIR));
            break;
        case K012P:
            insert_street_info(t, id, create_street_info(0.762, 0.345, SOUTH_DIR));
            break;
//Columna 10
        case F024P:
            insert_street_info(t, id, create_street_info(0.785, 0.040, NORTH_DIR));
            break;
        case F023P:
            insert_street_info(t, id, create_street_info(0.785, 0.065, NORTH_DIR));
            break;
        case F022P:
            insert_street_info(t, id, create_street_info(0.785, 0.090, NORTH_DIR));
            break;
        case F021P:
            insert_street_info(t, id, create_street_info(0.785, 0.115, NORTH_DIR));
            break;
        case F020P:
            insert_street_info(t, id, create_street_info(0.785, 0.138, NORTH_DIR));
            break;
        case F019P:
            insert_street_info(t, id, create_street_info(0.785, 0.163, NORTH_DIR));
            break;
        case L018P:
            insert_street_info(t, id, create_street_info(0.785, 0.226, NORTH_DIR));
            break;
        case L017P:
            insert_street_info(t, id, create_street_info(0.785, 0.251, NORTH_DIR));
            break;
        case L016P:
            insert_street_info(t, id, create_street_info(0.785, 0.275, NORTH_DIR));
            break;
        case L015P:
            insert_street_info(t, id, create_street_info(0.785, 0.300, NORTH_DIR));
            break;
        case L014P:
            insert_street_info(t, id, create_street_info(0.785, 0.323, NORTH_DIR));
            break;
        case L013P:
            insert_street_info(t, id, create_street_info(0.785, 0.345, NORTH_DIR));
            break;
//Columna 11
        case F007P:
            insert_street_info(t, id, create_street_info(0.900, 0.040, SOUTH_DIR));
            break;
        case F008P:
            insert_street_info(t, id, create_street_info(0.900, 0.065, SOUTH_DIR));
            break;
        case F009P:
            insert_street_info(t, id, create_street_info(0.900, 0.090, SOUTH_DIR));
            break;
        case F010P:
            insert_street_info(t, id, create_street_info(0.900, 0.115, SOUTH_DIR));
            break;
        case F011P:
            insert_street_info(t, id, create_street_info(0.900, 0.138, SOUTH_DIR));
            break;
        case F012P:
            insert_street_info(t, id, create_street_info(0.900, 0.163, SOUTH_DIR));
            break;
        case L007P:
            insert_street_info(t, id, create_street_info(0.900, 0.226, SOUTH_DIR));
            break;
        case L008P:
            insert_street_info(t, id, create_street_info(0.900, 0.251, SOUTH_DIR));
            break;
        case L009P:
            insert_street_info(t, id, create_street_info(0.900, 0.275, SOUTH_DIR));
            break;
        case L010P:
            insert_street_info(t, id, create_street_info(0.900, 0.300, SOUTH_DIR));
            break;
        case L011P:
            insert_street_info(t, id, create_street_info(0.900, 0.323, SOUTH_DIR));
            break;
        case L012P:
            insert_street_info(t, id, create_street_info(0.900, 0.345, SOUTH_DIR));
            break;

//Parte inferior
//Columna 0
        case M018P:
            insert_street_info(t, id, create_street_info(0.085, 0.629, NORTH_DIR));
            break;
        case M017P:
            insert_street_info(t, id, create_street_info(0.085, 0.654, NORTH_DIR));
            break;
        case M016P:
            insert_street_info(t, id, create_street_info(0.085, 0.676, NORTH_DIR));
            break;
        case M015P:
            insert_street_info(t, id, create_street_info(0.085, 0.700, NORTH_DIR));
            break;
        case M014P:
            insert_street_info(t, id, create_street_info(0.085, 0.723, NORTH_DIR));
            break;
        case M013P:
            insert_street_info(t, id, create_street_info(0.085, 0.750, NORTH_DIR));
            break;
        case S024P:
            insert_street_info(t, id, create_street_info(0.085, 0.812, NORTH_DIR));
            break;
        case S023P:
            insert_street_info(t, id, create_street_info(0.085, 0.839, NORTH_DIR));
            break;
        case S022P:
            insert_street_info(t, id, create_street_info(0.085, 0.861, NORTH_DIR));
            break;
        case S021P:
            insert_street_info(t, id, create_street_info(0.085, 0.882, NORTH_DIR));
            break;
        case S020P:
            insert_street_info(t, id, create_street_info(0.085, 0.907, NORTH_DIR));
            break;
        case S019P:
            insert_street_info(t, id, create_street_info(0.085, 0.933, NORTH_DIR));
            break;
//Columna 1
        case M001P:
            insert_street_info(t, id, create_street_info(0.200, 0.629, SOUTH_DIR));
            break;
        case M002P:
            insert_street_info(t, id, create_street_info(0.200, 0.654, SOUTH_DIR));
            break;
        case M003P:
            insert_street_info(t, id, create_street_info(0.200, 0.676, SOUTH_DIR));
            break;
        case M004P:
            insert_street_info(t, id, create_street_info(0.200, 0.700, SOUTH_DIR));
            break;
        case M005P:
            insert_street_info(t, id, create_street_info(0.200, 0.723, SOUTH_DIR));
            break;
        case M006P:
            insert_street_info(t, id, create_street_info(0.200, 0.750, SOUTH_DIR));
            break;
        case S007P:
            insert_street_info(t, id, create_street_info(0.200, 0.812, SOUTH_DIR));
            break;
        case S008P:
            insert_street_info(t, id, create_street_info(0.200, 0.839, SOUTH_DIR));
            break;
        case S009P:
            insert_street_info(t, id, create_street_info(0.200, 0.861, SOUTH_DIR));
            break;
        case S010P:
            insert_street_info(t, id, create_street_info(0.200, 0.882, SOUTH_DIR));
            break;
        case S011P:
            insert_street_info(t, id, create_street_info(0.200, 0.907, SOUTH_DIR));
            break;
        case S012P:
            insert_street_info(t, id, create_street_info(0.200, 0.933, SOUTH_DIR));
            break;
//Columna 2
        case N018P:
            insert_street_info(t, id, create_street_info(0.2235, 0.629, NORTH_DIR));
            break;
        case N017P:
            insert_street_info(t, id, create_street_info(0.2235, 0.654, NORTH_DIR));
            break;
        case N016P:
            insert_street_info(t, id, create_street_info(0.2235, 0.676, NORTH_DIR));
            break;
        case N015P:
            insert_street_info(t, id, create_street_info(0.2235, 0.700, NORTH_DIR));
            break;
        case N014P:
            insert_street_info(t, id, create_street_info(0.2235, 0.723, NORTH_DIR));
            break;
        case N013P:
            insert_street_info(t, id, create_street_info(0.2235, 0.750, NORTH_DIR));
            break;
        case T024P:
            insert_street_info(t, id, create_street_info(0.2235, 0.812, NORTH_DIR));
            break;
        case T023P:
            insert_street_info(t, id, create_street_info(0.2235, 0.839, NORTH_DIR));
            break;
        case T022P:
            insert_street_info(t, id, create_street_info(0.2235, 0.861, NORTH_DIR));
            break;
        case T021P:
            insert_street_info(t, id, create_street_info(0.2235, 0.882, NORTH_DIR));
            break;
        case T020P:
            insert_street_info(t, id, create_street_info(0.2235, 0.907, NORTH_DIR));
            break;
        case T019P:
            insert_street_info(t, id, create_street_info(0.2235, 0.933, NORTH_DIR));
            break;
//Columna 3
        case N001P:
            insert_street_info(t, id, create_street_info(0.3415, 0.629, SOUTH_DIR));
            break;
        case N002P:
            insert_street_info(t, id, create_street_info(0.3415, 0.654, SOUTH_DIR));
            break;
        case N003P:
            insert_street_info(t, id, create_street_info(0.3415, 0.676, SOUTH_DIR));
            break;
        case N004P:
            insert_street_info(t, id, create_street_info(0.3415, 0.700, SOUTH_DIR));
            break;
        case N005P:
            insert_street_info(t, id, create_street_info(0.3415, 0.723, SOUTH_DIR));
            break;
        case N006P:
            insert_street_info(t, id, create_street_info(0.3415, 0.750, SOUTH_DIR));
            break;
        case T007P:
            insert_street_info(t, id, create_street_info(0.3415, 0.812, SOUTH_DIR));
            break;
        case T008P:
            insert_street_info(t, id, create_street_info(0.3415, 0.839, SOUTH_DIR));
            break;
        case T009P:
            insert_street_info(t, id, create_street_info(0.3415, 0.861, SOUTH_DIR));
            break;
        case T010P:
            insert_street_info(t, id, create_street_info(0.3415, 0.882, SOUTH_DIR));
            break;
        case T011P:
            insert_street_info(t, id, create_street_info(0.3415, 0.907, SOUTH_DIR));
            break;
        case T012P:
            insert_street_info(t, id, create_street_info(0.3415, 0.933, SOUTH_DIR));
            break;
//Columna 4
        case O018P:
            insert_street_info(t, id, create_street_info(0.365, 0.629, NORTH_DIR));
            break;
        case O017P:
            insert_street_info(t, id, create_street_info(0.365, 0.654, NORTH_DIR));
            break;
        case O016P:
            insert_street_info(t, id, create_street_info(0.365, 0.676, NORTH_DIR));
            break;
        case O015P:
            insert_street_info(t, id, create_street_info(0.365, 0.700, NORTH_DIR));
            break;
        case O014P:
            insert_street_info(t, id, create_street_info(0.365, 0.723, NORTH_DIR));
            break;
        case O013P:
            insert_street_info(t, id, create_street_info(0.365, 0.750, NORTH_DIR));
            break;
        case U024P:
            insert_street_info(t, id, create_street_info(0.365, 0.812, NORTH_DIR));
            break;
        case U023P:
            insert_street_info(t, id, create_street_info(0.365, 0.839, NORTH_DIR));
            break;
        case U022P:
            insert_street_info(t, id, create_street_info(0.365, 0.861, NORTH_DIR));
            break;
        case U021P:
            insert_street_info(t, id, create_street_info(0.365, 0.882, NORTH_DIR));
            break;
        case U020P:
            insert_street_info(t, id, create_street_info(0.365, 0.907, NORTH_DIR));
            break;
        case U019P:
            insert_street_info(t, id, create_street_info(0.365, 0.933, NORTH_DIR));
            break;
//Columna 5
        case O001P:
            insert_street_info(t, id, create_street_info(0.483, 0.629, SOUTH_DIR));
            break;
        case O002P:
            insert_street_info(t, id, create_street_info(0.483, 0.654, SOUTH_DIR));
            break;
        case O003P:
            insert_street_info(t, id, create_street_info(0.483, 0.676, SOUTH_DIR));
            break;
        case O004P:
            insert_street_info(t, id, create_street_info(0.483, 0.700, SOUTH_DIR));
            break;
        case O005P:
            insert_street_info(t, id, create_street_info(0.483, 0.723, SOUTH_DIR));
            break;
        case O006P:
            insert_street_info(t, id, create_street_info(0.483, 0.750, SOUTH_DIR));
            break;
        case U007P:
            insert_street_info(t, id, create_street_info(0.483, 0.812, SOUTH_DIR));
            break;
        case U008P:
            insert_street_info(t, id, create_street_info(0.483, 0.839, SOUTH_DIR));
            break;
        case U009P:
            insert_street_info(t, id, create_street_info(0.483, 0.861, SOUTH_DIR));
            break;
        case U010P:
            insert_street_info(t, id, create_street_info(0.483, 0.882, SOUTH_DIR));
            break;
        case U011P:
            insert_street_info(t, id, create_street_info(0.483, 0.907, SOUTH_DIR));
            break;
        case U012P:
            insert_street_info(t, id, create_street_info(0.483, 0.933, SOUTH_DIR));
            break;
//Columna 6
        case P018P:
            insert_street_info(t, id, create_street_info(0.5035, 0.629, NORTH_DIR));
            break;
        case P017P:
            insert_street_info(t, id, create_street_info(0.5035, 0.654, NORTH_DIR));
            break;
        case P016P:
            insert_street_info(t, id, create_street_info(0.5035, 0.676, NORTH_DIR));
            break;
        case P015P:
            insert_street_info(t, id, create_street_info(0.5035, 0.700, NORTH_DIR));
            break;
        case P014P:
            insert_street_info(t, id, create_street_info(0.5035, 0.723, NORTH_DIR));
            break;
        case P013P:
            insert_street_info(t, id, create_street_info(0.5035, 0.750, NORTH_DIR));
            break;
        case V024P:
            insert_street_info(t, id, create_street_info(0.5035, 0.812, NORTH_DIR));
            break;
        case V023P:
            insert_street_info(t, id, create_street_info(0.5035, 0.839, NORTH_DIR));
            break;
        case V022P:
            insert_street_info(t, id, create_street_info(0.5035, 0.861, NORTH_DIR));
            break;
        case V021P:
            insert_street_info(t, id, create_street_info(0.5035, 0.882, NORTH_DIR));
            break;
        case V020P:
            insert_street_info(t, id, create_street_info(0.5035, 0.907, NORTH_DIR));
            break;
        case V019P:
            insert_street_info(t, id, create_street_info(0.5035, 0.933, NORTH_DIR));
            break;
//Columna 7
        case P001P:
            insert_street_info(t, id, create_street_info(0.6215, 0.629, SOUTH_DIR));
            break;
        case P002P:
            insert_street_info(t, id, create_street_info(0.6215, 0.654, SOUTH_DIR));
            break;
        case P003P:
            insert_street_info(t, id, create_street_info(0.6215, 0.676, SOUTH_DIR));
            break;
        case P004P:
            insert_street_info(t, id, create_street_info(0.6215, 0.700, SOUTH_DIR));
            break;
        case P005P:
            insert_street_info(t, id, create_street_info(0.6215, 0.723, SOUTH_DIR));
            break;
        case P006P:
            insert_street_info(t, id, create_street_info(0.6215, 0.750, SOUTH_DIR));
            break;
        case V007P:
            insert_street_info(t, id, create_street_info(0.6215, 0.812, SOUTH_DIR));
            break;
        case V008P:
            insert_street_info(t, id, create_street_info(0.6215, 0.839, SOUTH_DIR));
            break;
        case V009P:
            insert_street_info(t, id, create_street_info(0.6215, 0.861, SOUTH_DIR));
            break;
        case V010P:
            insert_street_info(t, id, create_street_info(0.6215, 0.882, SOUTH_DIR));
            break;
        case V011P:
            insert_street_info(t, id, create_street_info(0.6215, 0.907, SOUTH_DIR));
            break;
        case V012P:
            insert_street_info(t, id, create_street_info(0.6215, 0.933, SOUTH_DIR));
            break;
//Columna 8
        case Q018P:
            insert_street_info(t, id, create_street_info(0.644, 0.629, NORTH_DIR));
            break;
        case Q017P:
            insert_street_info(t, id, create_street_info(0.644, 0.654, NORTH_DIR));
            break;
        case Q016P:
            insert_street_info(t, id, create_street_info(0.644, 0.676, NORTH_DIR));
            break;
        case Q015P:
            insert_street_info(t, id, create_street_info(0.644, 0.700, NORTH_DIR));
            break;
        case Q014P:
            insert_street_info(t, id, create_street_info(0.644, 0.723, NORTH_DIR));
            break;
        case Q013P:
            insert_street_info(t, id, create_street_info(0.644, 0.750, NORTH_DIR));
            break;
        case W024P:
            insert_street_info(t, id, create_street_info(0.644, 0.812, NORTH_DIR));
            break;
        case W023P:
            insert_street_info(t, id, create_street_info(0.644, 0.839, NORTH_DIR));
            break;
        case W022P:
            insert_street_info(t, id, create_street_info(0.644, 0.861, NORTH_DIR));
            break;
        case W021P:
            insert_street_info(t, id, create_street_info(0.644, 0.882, NORTH_DIR));
            break;
        case W020P:
            insert_street_info(t, id, create_street_info(0.644, 0.907, NORTH_DIR));
            break;
        case W019P:
            insert_street_info(t, id, create_street_info(0.644, 0.933, NORTH_DIR));
            break;
//Columna 9
        case Q001P:
            insert_street_info(t, id, create_street_info(0.762, 0.629, SOUTH_DIR));
            break;
        case Q002P:
            insert_street_info(t, id, create_street_info(0.762, 0.654, SOUTH_DIR));
            break;
        case Q003P:
            insert_street_info(t, id, create_street_info(0.762, 0.676, SOUTH_DIR));
            break;
        case Q004P:
            insert_street_info(t, id, create_street_info(0.762, 0.700, SOUTH_DIR));
            break;
        case Q005P:
            insert_street_info(t, id, create_street_info(0.762, 0.723, SOUTH_DIR));
            break;
        case Q006P:
            insert_street_info(t, id, create_street_info(0.762, 0.750, SOUTH_DIR));
            break;
        case W007P:
            insert_street_info(t, id, create_street_info(0.762, 0.812, SOUTH_DIR));
            break;
        case W008P:
            insert_street_info(t, id, create_street_info(0.762, 0.839, SOUTH_DIR));
            break;
        case W009P:
            insert_street_info(t, id, create_street_info(0.762, 0.861, SOUTH_DIR));
            break;
        case W010P:
            insert_street_info(t, id, create_street_info(0.762, 0.882, SOUTH_DIR));
            break;
        case W011P:
            insert_street_info(t, id, create_street_info(0.762, 0.907, SOUTH_DIR));
            break;
        case W012P:
            insert_street_info(t, id, create_street_info(0.762, 0.933, SOUTH_DIR));
            break;
//Columna 10
        case R018P:
            insert_street_info(t, id, create_street_info(0.785, 0.629, NORTH_DIR));
            break;
        case R017P:
            insert_street_info(t, id, create_street_info(0.785, 0.654, NORTH_DIR));
            break;
        case R016P:
            insert_street_info(t, id, create_street_info(0.785, 0.676, NORTH_DIR));
            break;
        case R015P:
            insert_street_info(t, id, create_street_info(0.785, 0.700, NORTH_DIR));
            break;
        case R014P:
            insert_street_info(t, id, create_street_info(0.785, 0.723, NORTH_DIR));
            break;
        case R013P:
            insert_street_info(t, id, create_street_info(0.785, 0.750, NORTH_DIR));
            break;
        case X024P:
            insert_street_info(t, id, create_street_info(0.785, 0.812, NORTH_DIR));
            break;
        case X023P:
            insert_street_info(t, id, create_street_info(0.785, 0.839, NORTH_DIR));
            break;
        case X022P:
            insert_street_info(t, id, create_street_info(0.785, 0.861, NORTH_DIR));
            break;
        case X021P:
            insert_street_info(t, id, create_street_info(0.785, 0.882, NORTH_DIR));
            break;
        case X020P:
            insert_street_info(t, id, create_street_info(0.785, 0.907, NORTH_DIR));
            break;
        case X019P:
            insert_street_info(t, id, create_street_info(0.785, 0.933, NORTH_DIR));
            break;

//Columna 11
        case R001P:
            insert_street_info(t, id, create_street_info(0.900, 0.629, SOUTH_DIR));
            break;
        case R002P:
            insert_street_info(t, id, create_street_info(0.900, 0.654, SOUTH_DIR));
            break;
        case R003P:
            insert_street_info(t, id, create_street_info(0.900, 0.676, SOUTH_DIR));
            break;
        case R004P:
            insert_street_info(t, id, create_street_info(0.900, 0.700, SOUTH_DIR));
            break;
        case R005P:
            insert_street_info(t, id, create_street_info(0.900, 0.723, SOUTH_DIR));
            break;
        case R006P:
            insert_street_info(t, id, create_street_info(0.900, 0.750, SOUTH_DIR));
            break;
        case X007P:
            insert_street_info(t, id, create_street_info(0.900, 0.812, SOUTH_DIR));
            break;
        case X008P:
            insert_street_info(t, id, create_street_info(0.900, 0.839, SOUTH_DIR));
            break;
        case X009P:
            insert_street_info(t, id, create_street_info(0.900, 0.861, SOUTH_DIR));
            break;
        case X010P:
            insert_street_info(t, id, create_street_info(0.900, 0.882, SOUTH_DIR));
            break;
        case X011P:
            insert_street_info(t, id, create_street_info(0.900, 0.907, SOUTH_DIR));
            break;
        case X012P:
            insert_street_info(t, id, create_street_info(0.900, 0.933, SOUTH_DIR));
            break;
        default:
            break;
    }
}

void insert_street_info_corners(TableStreetInfo *t, CornersIds id) {
    switch (id) {
        case X004C:
            insert_street_info(t, id, create_street_info(0.785, 0.965, WEST_DIR));
            break;
        case X002C: // && R001C
            insert_street_info(t, id, create_street_info(0.900, 0.778, SOUTH_DIR));
            break;
        case X003C:
            insert_street_info(t, id, create_street_info(0.900, 0.965, WEST_DIR));
            break;
        case G001C: // && A004C
            insert_street_info(t, id, create_street_info(0.085, 0.194, NORTH_DIR));
            break;
        case A001C:
            insert_street_info(t, id, create_street_info(0.085, 0.007, EAST_DIR));
            break;
        case X001C: // && R002C
            insert_street_info(t, id, create_street_info(0.785, 0.778, EAST_DIR));
            break;
        case V002C: // && P001C
            insert_street_info(t, id, create_street_info(0.6215, 0.778, EAST_DIR));
            break;
        case V003C:
            insert_street_info(t, id, create_street_info(0.6215, 0.965, WEST_DIR));
            break;
        case W001C: // && Q002C
            insert_street_info(t, id, create_street_info(0.644, 0.778, EAST_DIR));
            break;
        case W004C:
            insert_street_info(t, id, create_street_info(0.644, 0.965, WEST_DIR));
            break;
        case W002C: // && Q001C
            insert_street_info(t, id, create_street_info(0.762, 0.778, EAST_DIR));
            break;
        case W003C:
            insert_street_info(t, id, create_street_info(0.762, 0.965, WEST_DIR));
            break;
        case S002C: // &&  M001C
            insert_street_info(t, id, create_street_info(0.200, 0.778, EAST_DIR));
            break;
        case S004C:
            insert_street_info(t, id, create_street_info(0.085, 0.965, WEST_DIR));
            break;
        case S001C: // && M002C
            insert_street_info(t, id, create_street_info(0.085, 0.778, NORTH_DIR));
            break;
        case S003C:
            insert_street_info(t, id, create_street_info(0.200, 0.965, WEST_DIR));
            break;
        case T001C: // && N002C
            insert_street_info(t, id, create_street_info(0.2235, 0.778, EAST_DIR));
            break;
        case T004C:
            insert_street_info(t, id, create_street_info(0.2235, 0.965, WEST_DIR));
            break;
        case T002C: // && N001C
            insert_street_info(t, id, create_street_info(0.3415, 0.778, EAST_DIR));
            break;
        case T003C:
            insert_street_info(t, id, create_street_info(0.3415, 0.965, WEST_DIR));
            break;
        case U001C: // && O002C
            insert_street_info(t, id, create_street_info(0.365, 0.778, EAST_DIR));
            break;
        case U004C:
            insert_street_info(t, id, create_street_info(0.365, 0.965, WEST_DIR));
            break;
        case U002C: // && O001C
            insert_street_info(t, id, create_street_info(0.483, 0.778, EAST_DIR));
            break;
        case U003C:
            insert_street_info(t, id, create_street_info(0.483, 0.965, WEST_DIR));
            break;
        case D001C:
            insert_street_info(t, id, create_street_info(0.5035, 0.007, EAST_DIR));
            break;
        case J001C: // && D004C
            insert_street_info(t, id, create_street_info(0.5035, 0.194, WEST_DIR));
            break;
        case D002C:
            insert_street_info(t, id, create_street_info(0.6215, 0.007, EAST_DIR));
            break;
        case J002C: // && D003C
            insert_street_info(t, id, create_street_info(0.6215, 0.194, WEST_DIR));
            break;
        case E001C:
            insert_street_info(t, id, create_street_info(0.644, 0.007, EAST_DIR));
            break;
        case K001C: // && E004C
            insert_street_info(t, id, create_street_info(0.644, 0.194, WEST_DIR));
            break;
        case E002C:
            insert_street_info(t, id, create_street_info(0.762, 0.007, EAST_DIR));
            break;
        case K002C: // && E003C
            insert_street_info(t, id, create_street_info(0.762, 0.194, WEST_DIR));
            break;
        case F001C:
            insert_street_info(t, id, create_street_info(0.785, 0.007, EAST_DIR));
            break;
        case L001C: // && F004C
            insert_street_info(t, id, create_street_info(0.785, 0.194, WEST_DIR));
            break;
        case F002C:
            insert_street_info(t, id, create_street_info(0.900, 0.007, SOUTH_DIR));
            break;
        case L002C: // && F003C
            insert_street_info(t, id, create_street_info(0.900, 0.194, SOUTH_DIR));
            break;
        case A002C:
            insert_street_info(t, id, create_street_info(0.200, 0.007, EAST_DIR));
            break;
        case G002C: // && A003C
            insert_street_info(t, id, create_street_info(0.200, 0.194, WEST_DIR));
            break;
        case B001C:
            insert_street_info(t, id, create_street_info(0.2235, 0.007, EAST_DIR));
            break;
        case H001C: // && B004C
            insert_street_info(t, id, create_street_info(0.2235, 0.194, WEST_DIR));
            break;
        case B002C:
            insert_street_info(t, id, create_street_info(0.3415, 0.007, EAST_DIR));
            break;
        case H002C: // && B003C
            insert_street_info(t, id, create_street_info(0.3415, 0.194, WEST_DIR));
            break;
        case C001C:
            insert_street_info(t, id, create_street_info(0.365, 0.007, EAST_DIR));
            break;
        case I001C: // && C004C
            insert_street_info(t, id, create_street_info(0.365, 0.194, WEST_DIR));
            break;
        case C002C:
            insert_street_info(t, id, create_street_info(0.483, 0.007, EAST_DIR));
            break;
        case I002C: // && C003C
            insert_street_info(t, id, create_street_info(0.483, 0.194, WEST_DIR));
            break;
        case P002C: // && V001C
            insert_street_info(t, id, create_street_info(0.5035, 0.778, EAST_DIR));
            break;
        case V004C:
            insert_street_info(t, id, create_street_info(0.5035, 0.965, WEST_DIR));
            break;
        default:
            break;
    }
}
