#ifndef PROYECTO_3_BRIDGE_HANDLERS_H
#define PROYECTO_3_BRIDGE_HANDLERS_H

#include <stdbool.h>

#define NORTH_DIR_BRIDGE false
#define SOUTH_DIR_BRIDGE true

typedef enum BridgesType {
    LARRY = 0,
    CURLY = 1,
    MOE = 2,
    SHEMP = 3,
    JOE = 4
} BridgesType;

typedef struct CurlyShempInformation {
    int *north_side_range;
    int *south_side_range;
    BridgesType type;
    bool direction;
    bool *nextDirection;
} CurlyShempInformation;

typedef struct LarryJoeInformation {
    int *north_side_range;
    int *south_side_range;
    BridgesType type;
    bool direction;
    bool *nextDirection;
} LarryJoeInformation;

void *handleLarryJoe(void *arg);

void *handleCurlyShemp(void *arg);

CurlyShempInformation *createCurlyShempInfo(
        bool direction, BridgesType type, bool *nextDirection,
        int start_north_id, int end_north_id,
        int start_south_id, int end_south_id
);

LarryJoeInformation *createLarryJoeInfo(
        bool direction, BridgesType type, bool *nextDirection,
        int start_north_id, int end_north_id,
        int start_south_id, int end_south_id
);

#endif //PROYECTO_3_BRIDGE_HANDLERS_H
