#include "vehicle.h"
#include <stdlib.h>
#include <unistd.h>
#include "utils.h"
#include "hash_table.h"
#include "interface.h"
#include "floyd.h"
#include "bus.h"
#include <stdbool.h>
#include<time.h>

#define AF_DISTANCE 48.0 // distance from A1 to F2

extern bool isa_bred;
extern bool isa_bgreen;
extern bool isa_borange;
extern bool isa_bblue;
extern bool isa_bgray;
extern bool isa_bpink;
extern bool isa_blblue;
extern bool isa_bwhite;
extern bool isa_bblack;

extern ThreadvilleMap *map;
extern GtkBuilder *builder;


extern int moe_direction; // 0 libre, 1 arriba, -1 abajo
extern pthread_mutex_t mutex_moe;
extern int moe_cars;
extern pthread_mutex_t check_mutex_moe;


extern pthread_mutex_t mutex_larry_con;
extern pthread_mutex_t mutex_joe_con;

extern int larry_cars_waitu;
extern int joe_cars_waitu;
extern int larry_cars_waitd;
extern int joe_cars_waitd;


extern pthread_mutex_t mutex_bus_active;

static int global_id = 0;

pthread_mutex_t mutex_global_id = PTHREAD_MUTEX_INITIALIZER;

int get_global_id() {
    int result = 0;
    pthread_mutex_lock(&mutex_global_id);
    result = global_id;
    global_id += 1;
    pthread_mutex_unlock(&mutex_global_id);
    return result;
}

int random_stop_id() {
    srand(time(0));
    return (rand() % (R006S - A001S + 1)) + A001S;
}

int random_car_id() {
    srand(time(0));
    return (rand() % (YELLOW_CAR - RED_CAR + 1)) + RED_CAR;
}

char *get_stop_id(int stop, int destinations_left) {
    char *res = calloc(6, sizeof(char));
    switch (stop) {
        case A001S:
            sprintf(res, "%s-%d", "A1", destinations_left);
            break;
        case A002S:
            sprintf(res, "%s-%d", "A2", destinations_left);
            break;
        case A003S:
            sprintf(res, "%s-%d", "A3", destinations_left);
            break;
        case A004S:
            sprintf(res, "%s-%d", "A4", destinations_left);
            break;
        case A005S:
            sprintf(res, "%s-%d", "A5", destinations_left);
            break;
        case A006S:
            sprintf(res, "%s-%d", "A6", destinations_left);
            break;
        case A007S:
            sprintf(res, "%s-%d", "A7", destinations_left);
            break;
        case A008S:
            sprintf(res, "%s-%d", "A8", destinations_left);
            break;
        case B001S:
            sprintf(res, "%s-%d", "B1", destinations_left);
            break;
        case B002S:
            sprintf(res, "%s-%d", "B2", destinations_left);
            break;
        case B003S:
            sprintf(res, "%s-%d", "B3", destinations_left);
            break;
        case B004S:
            sprintf(res, "%s-%d", "B4", destinations_left);
            break;
        case B005S:
            sprintf(res, "%s-%d", "B5", destinations_left);
            break;
        case B006S:
            sprintf(res, "%s-%d", "B6", destinations_left);
            break;
        case B007S:
            sprintf(res, "%s-%d", "B7", destinations_left);
            break;
        case B008S:
            sprintf(res, "%s-%d", "B8", destinations_left);
            break;
        case C001S:
            sprintf(res, "%s-%d", "C1", destinations_left);
            break;
        case C002S:
            sprintf(res, "%s-%d", "C2", destinations_left);
            break;
        case C003S:
            sprintf(res, "%s-%d", "C3", destinations_left);
            break;
        case C004S:
            sprintf(res, "%s-%d", "C4", destinations_left);
            break;
        case C005S:
            sprintf(res, "%s-%d", "C5", destinations_left);
            break;
        case C006S:
            sprintf(res, "%s-%d", "C6", destinations_left);
            break;
        case C007S:
            sprintf(res, "%s-%d", "C7", destinations_left);
            break;
        case C008S:
            sprintf(res, "%s-%d", "C8", destinations_left);
            break;
        case D001S:
            sprintf(res, "%s-%d", "D1", destinations_left);
            break;
        case D002S:
            sprintf(res, "%s-%d", "D2", destinations_left);
            break;
        case D003S:
            sprintf(res, "%s-%d", "D3", destinations_left);
            break;
        case D004S:
            sprintf(res, "%s-%d", "D4", destinations_left);
            break;
        case D005S:
            sprintf(res, "%s-%d", "D5", destinations_left);
            break;
        case D006S:
            sprintf(res, "%s-%d", "D6", destinations_left);
            break;
        case D007S:
            sprintf(res, "%s-%d", "D7", destinations_left);
            break;
        case D008S:
            sprintf(res, "%s-%d", "D8", destinations_left);
            break;
        case E001S:
            sprintf(res, "%s-%d", "E1", destinations_left);
            break;
        case E002S:
            sprintf(res, "%s-%d", "E2", destinations_left);
            break;
        case E003S:
            sprintf(res, "%s-%d", "E3", destinations_left);
            break;
        case E004S:
            sprintf(res, "%s-%d", "E4", destinations_left);
            break;
        case E005S:
            sprintf(res, "%s-%d", "E5", destinations_left);
            break;
        case E006S:
            sprintf(res, "%s-%d", "E6", destinations_left);
            break;
        case E007S:
            sprintf(res, "%s-%d", "E7", destinations_left);
            break;
        case E008S:
            sprintf(res, "%s-%d", "E8", destinations_left);
            break;
        case F001S:
            sprintf(res, "%s-%d", "F1", destinations_left);
            break;
        case F002S:
            sprintf(res, "%s-%d", "F2", destinations_left);
            break;
        case F003S:
            sprintf(res, "%s-%d", "F3", destinations_left);
            break;
        case F004S:
            sprintf(res, "%s-%d", "F4", destinations_left);
            break;
        case F005S:
            sprintf(res, "%s-%d", "F5", destinations_left);
            break;
        case F006S:
            sprintf(res, "%s-%d", "F6", destinations_left);
            break;
        case F007S:
            sprintf(res, "%s-%d", "F7", destinations_left);
            break;
        case F008S:
            sprintf(res, "%s-%d", "F8", destinations_left);
            break;
        case S001S:
            sprintf(res, "%s-%d", "S1", destinations_left);
            break;
        case S002S:
            sprintf(res, "%s-%d", "S2", destinations_left);
            break;
        case S003S:
            sprintf(res, "%s-%d", "S3", destinations_left);
            break;
        case S004S:
            sprintf(res, "%s-%d", "S4", destinations_left);
            break;
        case S005S:
            sprintf(res, "%s-%d", "S5", destinations_left);
            break;
        case S006S:
            sprintf(res, "%s-%d", "S6", destinations_left);
            break;
        case S007S:
            sprintf(res, "%s-%d", "S7", destinations_left);
            break;
        case S008S:
            sprintf(res, "%s-%d", "S8", destinations_left);
            break;
        case T001S:
            sprintf(res, "%s-%d", "T1", destinations_left);
            break;
        case T002S:
            sprintf(res, "%s-%d", "T2", destinations_left);
            break;
        case T003S:
            sprintf(res, "%s-%d", "T3", destinations_left);
            break;
        case T004S:
            sprintf(res, "%s-%d", "T4", destinations_left);
            break;
        case T005S:
            sprintf(res, "%s-%d", "T5", destinations_left);
            break;
        case T006S:
            sprintf(res, "%s-%d", "T6", destinations_left);
            break;
        case T007S:
            sprintf(res, "%s-%d", "T7", destinations_left);
            break;
        case T008S:
            sprintf(res, "%s-%d", "T8", destinations_left);
            break;
        case U001S:
            sprintf(res, "%s-%d", "U1", destinations_left);
            break;
        case U002S:
            sprintf(res, "%s-%d", "U2", destinations_left);
            break;
        case U003S:
            sprintf(res, "%s-%d", "U3", destinations_left);
            break;
        case U004S:
            sprintf(res, "%s-%d", "U4", destinations_left);
            break;
        case U005S:
            sprintf(res, "%s-%d", "U5", destinations_left);
            break;
        case U006S:
            sprintf(res, "%s-%d", "U6", destinations_left);
            break;
        case U007S:
            sprintf(res, "%s-%d", "U7", destinations_left);
            break;
        case U008S:
            sprintf(res, "%s-%d", "U8", destinations_left);
            break;
        case V001S:
            sprintf(res, "%s-%d", "V1", destinations_left);
            break;
        case V002S:
            sprintf(res, "%s-%d", "V2", destinations_left);
            break;
        case V003S:
            sprintf(res, "%s-%d", "V3", destinations_left);
            break;
        case V004S:
            sprintf(res, "%s-%d", "V4", destinations_left);
            break;
        case V005S:
            sprintf(res, "%s-%d", "V5", destinations_left);
            break;
        case V006S:
            sprintf(res, "%s-%d", "V6", destinations_left);
            break;
        case V007S:
            sprintf(res, "%s-%d", "V7", destinations_left);
            break;
        case V008S:
            sprintf(res, "%s-%d", "V8", destinations_left);
            break;
        case W001S:
            sprintf(res, "%s-%d", "W1", destinations_left);
            break;
        case W002S:
            sprintf(res, "%s-%d", "W2", destinations_left);
            break;
        case W003S:
            sprintf(res, "%s-%d", "W3", destinations_left);
            break;
        case W004S:
            sprintf(res, "%s-%d", "W4", destinations_left);
            break;
        case W005S:
            sprintf(res, "%s-%d", "W5", destinations_left);
            break;
        case W006S:
            sprintf(res, "%s-%d", "W6", destinations_left);
            break;
        case W007S:
            sprintf(res, "%s-%d", "W7", destinations_left);
            break;
        case W008S:
            sprintf(res, "%s-%d", "W8", destinations_left);
            break;
        case X001S:
            sprintf(res, "%s-%d", "X1", destinations_left);
            break;
        case X002S:
            sprintf(res, "%s-%d", "X2", destinations_left);
            break;
        case X003S:
            sprintf(res, "%s-%d", "X3", destinations_left);
            break;
        case X004S:
            sprintf(res, "%s-%d", "X4", destinations_left);
            break;
        case X005S:
            sprintf(res, "%s-%d", "X5", destinations_left);
            break;
        case X006S:
            sprintf(res, "%s-%d", "X6", destinations_left);
            break;
        case X007S:
            sprintf(res, "%s-%d", "X7", destinations_left);
            break;
        case X008S:
            sprintf(res, "%s-%d", "X8", destinations_left);
            break;
        case G001S:
            sprintf(res, "%s-%d", "G1", destinations_left);
            break;
        case G002S:
            sprintf(res, "%s-%d", "G2", destinations_left);
            break;
        case G003S:
            sprintf(res, "%s-%d", "G3", destinations_left);
            break;
        case G004S:
            sprintf(res, "%s-%d", "G4", destinations_left);
            break;
        case G005S:
            sprintf(res, "%s-%d", "G5", destinations_left);
            break;
        case G006S:
            sprintf(res, "%s-%d", "G6", destinations_left);
            break;
        case H001S:
            sprintf(res, "%s-%d", "H1", destinations_left);
            break;
        case H002S:
            sprintf(res, "%s-%d", "H2", destinations_left);
            break;
        case H003S:
            sprintf(res, "%s-%d", "H3", destinations_left);
            break;
        case H004S:
            sprintf(res, "%s-%d", "H4", destinations_left);
            break;
        case H005S:
            sprintf(res, "%s-%d", "H5", destinations_left);
            break;
        case H006S:
            sprintf(res, "%s-%d", "H6", destinations_left);
            break;
        case I001S:
            sprintf(res, "%s-%d", "I1", destinations_left);
            break;
        case I002S:
            sprintf(res, "%s-%d", "I2", destinations_left);
            break;
        case I003S:
            sprintf(res, "%s-%d", "I3", destinations_left);
            break;
        case I004S:
            sprintf(res, "%s-%d", "I4", destinations_left);
            break;
        case I005S:
            sprintf(res, "%s-%d", "I5", destinations_left);
            break;
        case I006S:
            sprintf(res, "%s-%d", "I6", destinations_left);
            break;
        case J001S:
            sprintf(res, "%s-%d", "J1", destinations_left);
            break;
        case J002S:
            sprintf(res, "%s-%d", "J2", destinations_left);
            break;
        case J003S:
            sprintf(res, "%s-%d", "J3", destinations_left);
            break;
        case J004S:
            sprintf(res, "%s-%d", "J4", destinations_left);
            break;
        case J005S:
            sprintf(res, "%s-%d", "J5", destinations_left);
            break;
        case J006S:
            sprintf(res, "%s-%d", "J6", destinations_left);
            break;
        case K001S:
            sprintf(res, "%s-%d", "K1", destinations_left);
            break;
        case K002S:
            sprintf(res, "%s-%d", "K2", destinations_left);
            break;
        case K003S:
            sprintf(res, "%s-%d", "K3", destinations_left);
            break;
        case K004S:
            sprintf(res, "%s-%d", "K4", destinations_left);
            break;
        case K005S:
            sprintf(res, "%s-%d", "K5", destinations_left);
            break;
        case K006S:
            sprintf(res, "%s-%d", "K6", destinations_left);
            break;
        case L001S:
            sprintf(res, "%s-%d", "L1", destinations_left);
            break;
        case L002S:
            sprintf(res, "%s-%d", "L2", destinations_left);
            break;
        case L003S:
            sprintf(res, "%s-%d", "L3", destinations_left);
            break;
        case L004S:
            sprintf(res, "%s-%d", "L4", destinations_left);
            break;
        case L005S:
            sprintf(res, "%s-%d", "L5", destinations_left);
            break;
        case L006S:
            sprintf(res, "%s-%d", "L6", destinations_left);
            break;
        case M001S:
            sprintf(res, "%s-%d", "M1", destinations_left);
            break;
        case M002S:
            sprintf(res, "%s-%d", "M2", destinations_left);
            break;
        case M003S:
            sprintf(res, "%s-%d", "M3", destinations_left);
            break;
        case M004S:
            sprintf(res, "%s-%d", "M4", destinations_left);
            break;
        case M005S:
            sprintf(res, "%s-%d", "M5", destinations_left);
            break;
        case M006S:
            sprintf(res, "%s-%d", "M6", destinations_left);
            break;
        case N001S:
            sprintf(res, "%s-%d", "N1", destinations_left);
            break;
        case N002S:
            sprintf(res, "%s-%d", "N2", destinations_left);
            break;
        case N003S:
            sprintf(res, "%s-%d", "N3", destinations_left);
            break;
        case N004S:
            sprintf(res, "%s-%d", "N4", destinations_left);
            break;
        case N005S:
            sprintf(res, "%s-%d", "N5", destinations_left);
            break;
        case N006S:
            sprintf(res, "%s-%d", "N6", destinations_left);
            break;
        case O001S:
            sprintf(res, "%s-%d", "O1", destinations_left);
            break;
        case O002S:
            sprintf(res, "%s-%d", "O2", destinations_left);
            break;
        case O003S:
            sprintf(res, "%s-%d", "O3", destinations_left);
            break;
        case O004S:
            sprintf(res, "%s-%d", "O4", destinations_left);
            break;
        case O005S:
            sprintf(res, "%s-%d", "O5", destinations_left);
            break;
        case O006S:
            sprintf(res, "%s-%d", "O6", destinations_left);
            break;
        case P001S:
            sprintf(res, "%s-%d", "P1", destinations_left);
            break;
        case P002S:
            sprintf(res, "%s-%d", "P2", destinations_left);
            break;
        case P003S:
            sprintf(res, "%s-%d", "P3", destinations_left);
            break;
        case P004S:
            sprintf(res, "%s-%d", "P4", destinations_left);
            break;
        case P005S:
            sprintf(res, "%s-%d", "P5", destinations_left);
            break;
        case P006S:
            sprintf(res, "%s-%d", "P6", destinations_left);
            break;
        case Q001S:
            sprintf(res, "%s-%d", "Q1", destinations_left);
            break;
        case Q002S:
            sprintf(res, "%s-%d", "Q2", destinations_left);
            break;
        case Q003S:
            sprintf(res, "%s-%d", "Q3", destinations_left);
            break;
        case Q004S:
            sprintf(res, "%s-%d", "Q4", destinations_left);
            break;
        case Q005S:
            sprintf(res, "%s-%d", "Q5", destinations_left);
            break;
        case Q006S:
            sprintf(res, "%s-%d", "Q6", destinations_left);
            break;
        case R001S:
            sprintf(res, "%s-%d", "R1", destinations_left);
            break;
        case R002S:
            sprintf(res, "%s-%d", "R2", destinations_left);
            break;
        case R003S:
            sprintf(res, "%s-%d", "R3", destinations_left);
            break;
        case R004S:
            sprintf(res, "%s-%d", "R4", destinations_left);
            break;
        case R005S:
            sprintf(res, "%s-%d", "R5", destinations_left);
            break;
        case R006S:
            sprintf(res, "%s-%d", "R6", destinations_left);
            break;
        case Z006R:
            sprintf(res, "%s-%d", "Z6", destinations_left);
            break;
        case Y006R:
            sprintf(res, "%s-%d", "Y6", destinations_left);
            break;
        default:
            return "";
            break;
    }
    return res;
}

char *get_active_button(VehicleType type) {
    switch (type) {
        case RED_BUS:
            return "btn_cbr";
        case GREEN_BUS:
            return "btn_cbgr";
        case BLUE_BUS:
            return "btn_cbb";
        case WHITE_BUS:
            return "btn_cbw";
        case GRAY_BUS:
            return "btn_cbg";
        case BLACK_BUS:
            return "btn_cbbl";
        case PINK_BUS:
            return "btn_cbp";
        case LIGHT_BLUE_BUS:
            return "btn_cblb";
        case ORANGE_BUS:
            return "btn_cbo";
        default:
            return "";
    }
}

bool get_actual_variable(VehicleType type) {

    pthread_mutex_lock(&mutex_bus_active);
    switch (type) {
        case RED_BUS:
            pthread_mutex_unlock(&mutex_bus_active);
            return isa_bred;
        case GREEN_BUS:
            pthread_mutex_unlock(&mutex_bus_active);
            return isa_bgreen;
        case BLUE_BUS:
            pthread_mutex_unlock(&mutex_bus_active);
            return isa_bblue;
        case WHITE_BUS:
            pthread_mutex_unlock(&mutex_bus_active);
            return isa_bwhite;
        case GRAY_BUS:
            pthread_mutex_unlock(&mutex_bus_active);
            return isa_bgray;
        case BLACK_BUS:
            pthread_mutex_unlock(&mutex_bus_active);
            return isa_bblack;
        case PINK_BUS:
            pthread_mutex_unlock(&mutex_bus_active);
            return isa_bpink;
        case LIGHT_BLUE_BUS:
            pthread_mutex_unlock(&mutex_bus_active);
            return isa_blblue;
        case ORANGE_BUS:
            pthread_mutex_unlock(&mutex_bus_active);
            return isa_borange;
        default:
            pthread_mutex_unlock(&mutex_bus_active);
            return false;
    }
}

LinkedList *create_route(int start_point, int end_point) {
    LinkedList *l = create_linked_list();
    int *path = floyd_path(start_point, end_point);
    printf("%s", "CREATE ROUTEE//////////////////////////////////////////");
    for (int i = path[0]; i >= 1; --i) {
        printf("%d", i);

        push(l, create_node(path[i]));
    }
    free(path);
    return l;
}

LinkedList *create_route_aux(int start_point, int end_point) {
    LinkedList *l = create_linked_list();
    int *path = floyd_path(start_point, end_point);
    for (int i = path[0]; i > 1; --i) {
        push(l, create_node(path[i]));
    }
    free(path);
    return l;
}

void create_bus_route(Vehicle *vehicle) {
    switch (vehicle->vehicleType) {
        case RED_BUS:
            create_route_red(vehicle);
            break;
        case GREEN_BUS:
            create_route_green(vehicle);
            break;
        case BLUE_BUS:
            create_route_blue(vehicle);
            break;
        case WHITE_BUS:
            create_route_white(vehicle);
            break;
        case GRAY_BUS:
            create_route_gray(vehicle);
            break;
        case BLACK_BUS:
            create_route_black(vehicle);
            break;
        case PINK_BUS:
            create_route_pink(vehicle);
            break;
        case LIGHT_BLUE_BUS:
            create_route_light_blue(vehicle);
            break;
        case ORANGE_BUS:
            create_route_orange(vehicle);
            break;
        default:
            break;
    }
}

float getVehicleSpeed(VehicleType type) {
    // Speed given in "spots" per second
    float speed;
    switch (type) {
        case ORANGE_BUS:
            speed = 7.0 / AF_DISTANCE;
            break;
        case AMBULANCE:
            speed = 0.5 / AF_DISTANCE;
            break;
        case RED_CAR:
            speed = 1.0 / AF_DISTANCE;
            break;
        case BLUE_CAR:
            speed = 2.0 / AF_DISTANCE;
            break;
        case PINK_BUS:
        case LIGHT_BLUE_BUS:
        case GREEN_CAR:
            speed = 3.0 / AF_DISTANCE;
            break;
        case WHITE_BUS:
        case GRAY_BUS:
        case BLACK_BUS:
        case BLACK_CAR:
            speed = 4.0 / AF_DISTANCE;
            break;
        case RED_BUS:
        case GREEN_BUS:
        case BLUE_BUS:
        case WHITE_CAR:
            speed = 5.0 / AF_DISTANCE;
            break;
        case YELLOW_CAR:
            speed = 6.0 / AF_DISTANCE;
            break;
        default:
            speed = -1;
            break;
    }
    return speed;
}

Vehicle *create_bus(VehicleType type, VehicleDir dir) {
    int actual_id = get_global_id();
    Vehicle *v = malloc(sizeof(Vehicle));
    float speed = getVehicleSpeed(type);
    if (speed < 0) {
        return NULL;
    }
    v->speed = speed;
    v->vehicleType = type;
    v->vehicleDir = dir;

    create_bus_route(v);

    // Starting point is always Y006R
    StreetInfo *info = lookup_street_info(
            map->streetInfoTable,
            v->current_route->first_node->destination_id
    );
    node_t *ui_info = create_object(
            actual_id,
            from_vehicle_type(type, info->dir),
            info->x, info->y,
            get_stop_id(
                    v->current_route->first_node->destination_id,
                    get_destinations_size(v->destinations)
            )
    );
    v->ui_info = ui_info;
    v->vehicle_id = actual_id;
    return v;
}

Vehicle *create_vehicle(VehicleType type, VehicleDir dir, int *destinations) {
    int actual_id = get_global_id();
    Vehicle *v = malloc(sizeof(Vehicle));
    float speed = getVehicleSpeed(type);
    if (speed < 0) {
        return NULL;
    }
    v->speed = speed;
    v->vehicleType = type;
    v->vehicleDir = dir;
    v->destinations = destinations;
    v->current_route = create_route(Y006R, destinations[0]);

    // Starting point is always Y006R
    StreetInfo *info = lookup_street_info(
            map->streetInfoTable,
            v->current_route->first_node->destination_id
    );
    node_t *ui_info = create_object(
            actual_id,
            from_vehicle_type(type, info->dir),
            info->x, info->y,
            get_stop_id(
                    v->current_route->first_node->destination_id,
                    get_destinations_size(v->destinations)
            )
    );
    v->ui_info = ui_info;
    v->vehicle_id = actual_id;
    return v;
}

VehicleThreadInfo *create_vehicle_thread_info(Vehicle *vehicle) {
    VehicleThreadInfo *info = malloc(sizeof(VehicleThreadInfo));
    info->vehicle = vehicle;
    return info;
}

int highway_multiplier(int street_id) {
    return street_id >= 1 && street_id <= 144 ? 2 : 1;
}

int get_destinations_size(const int *destinations) {
    int index = 0;
    while (destinations[index] != -1) index++;
    return index - 2;
}

void handle_normal_vehicle(Vehicle *vehicle, int priority_value) {
    int startDestination;
    int nextDestination = 0;
    priority_semaphore *currentStreet = NULL;
    priority_semaphore *beforeStreet = NULL;
    NodeL *currentNode;

    while (1) {

        while (vehicle->current_route->first_node != NULL) {
            currentNode = vehicle->current_route->first_node;
            beforeStreet = currentStreet;
            currentStreet = lookup(map->map, currentNode->destination_id);

            //Incio de Larry y Joe
            //Larry
            if (currentNode->destination_id == N018P) { // Larry u
                pthread_mutex_lock(&mutex_larry_con);
                larry_cars_waitu += 1;
                pthread_mutex_unlock(&mutex_larry_con);

            } else if (currentNode->destination_id == G012P) { // Larry d
                pthread_mutex_lock(&mutex_larry_con);
                larry_cars_waitd += 1;
                pthread_mutex_unlock(&mutex_larry_con);

            } else if (currentNode->destination_id == BU02B) {// Larry u get
                pthread_mutex_lock(&mutex_larry_con);
                larry_cars_waitu -= 1;
                pthread_mutex_unlock(&mutex_larry_con);

            } else if (currentNode->destination_id == B002B) {// Larry d get
                pthread_mutex_lock(&mutex_larry_con);
                larry_cars_waitd -= 1;
                pthread_mutex_unlock(&mutex_larry_con);
            }

            //Joe
            if (currentNode->destination_id == R018P) { // Joe u

                pthread_mutex_lock(&mutex_joe_con);
                joe_cars_waitu += 1;
                pthread_mutex_unlock(&mutex_joe_con);

            } else if (currentNode->destination_id == K012P) { // Joe d
                pthread_mutex_lock(&mutex_joe_con);
                joe_cars_waitd += 1;
                pthread_mutex_unlock(&mutex_joe_con);

            } else if (currentNode->destination_id == BU26B) {// Joe u get
                pthread_mutex_lock(&mutex_joe_con);
                joe_cars_waitu -= 1;
                pthread_mutex_unlock(&mutex_joe_con);

            } else if (currentNode->destination_id == B026B) {// Joe d get
                pthread_mutex_lock(&mutex_joe_con);
                joe_cars_waitd -= 1;
                pthread_mutex_unlock(&mutex_joe_con);
            }

            //Fin de Larry y Joe

            //Inicio de puente central
            //Bloqueo de llegada
            if (currentNode->destination_id == B013B) { // Para abajo
                pthread_mutex_lock(&check_mutex_moe);
                if (moe_direction == 0 || moe_direction == 1) {
                    pthread_mutex_unlock(&check_mutex_moe);
                    pthread_mutex_lock(&mutex_moe);
                    moe_direction = -1;
                    printf("\033[0;31m%s\033[0m\n", "Moe change direction to: South");
                    edit_semaphore(2, SEMAPHORED);

                    pthread_mutex_lock(&check_mutex_moe);
                    moe_cars += 1;
                    pthread_mutex_unlock(&check_mutex_moe);

                } else {
                    moe_cars += 1;
                    pthread_mutex_unlock(&check_mutex_moe);
                }


            } else if (currentNode->destination_id == BU13B) {//Para arriba
                pthread_mutex_lock(&check_mutex_moe);
                if (moe_direction == 0 || moe_direction == -1) {
                    pthread_mutex_unlock(&check_mutex_moe);
                    pthread_mutex_lock(&mutex_moe);
                    moe_direction = 1;
                    printf("\033[0;31m%s\033[0m\n", "Moe change direction to: North");
                    edit_semaphore(2, SEMAPHOREU);

                    pthread_mutex_lock(&check_mutex_moe);
                    moe_cars += 1;
                    pthread_mutex_unlock(&check_mutex_moe);

                } else {
                    moe_cars += 1;
                    pthread_mutex_unlock(&check_mutex_moe);
                }


            }

            //Bloqueo de salida
            if (currentNode->destination_id == B018B || currentNode->destination_id == BU18B) {// Para abajo
                pthread_mutex_lock(&check_mutex_moe);
                moe_cars -= 1;
                if (moe_cars == 0) {
                    pthread_mutex_unlock(&mutex_moe);
                }
                pthread_mutex_unlock(&check_mutex_moe);
            }

            //Fin de puente central
            lock_priority_semaphore(priority_value, currentStreet);

            if (beforeStreet != NULL) {
                unlock_priority_semaphore(priority_value, beforeStreet);
            }

            //Se pinte luego de obtener el semaforo
            StreetInfo *streetInfo = lookup_street_info(map->streetInfoTable, currentNode->destination_id);
            edit_object_with_node(
                    vehicle->ui_info,
                    from_vehicle_type(vehicle->vehicleType, streetInfo->dir),
                    streetInfo->x, streetInfo->y,
                    get_stop_id(vehicle->destinations[nextDestination], 3 - nextDestination)
            );

            //Duerma el tiempo que necesite para pasar la calle
            usleep((vehicle->speed * 1000000) / highway_multiplier(currentNode->destination_id));


            if (vehicle->current_route->first_node->next_node == NULL) {
                startDestination = vehicle->current_route->first_node->destination_id;
            }

            pop(vehicle->current_route);
        }
        nextDestination++;
        if (vehicle->destinations[nextDestination] != -1) {
            sleep(3);
            vehicle->current_route = create_route_aux(startDestination, vehicle->destinations[nextDestination]);
        } else {
            break;
        }
    }

    unlock_priority_semaphore(priority_value, currentStreet);
}

StreetDir best_dirc(StreetDir currentDir_p, StreetDir previousDir_p, StreetDir previousprevious_p) {
    if (currentDir_p == previousDir_p) {
        return currentDir_p;
    } else if (previousDir_p == previousprevious_p) {
        return previousDir_p;
    } else if (currentDir_p == previousprevious_p) {
        return currentDir_p;
    } else {
        return currentDir_p;
    }
}

void handle_bus(Vehicle *vehicle) {
    priority_semaphore *currentStreet = NULL;
    priority_semaphore *previousStreet = NULL;
    priority_semaphore *previouspreviousStreet = NULL;
    NodeL *currentNode;
    int currentDestination = 0;
    StreetInfo *streetInfo;
    LinkedList *busRouteCopy = copy_list(vehicle->current_route);

    StreetDir currentDir = 0;
    StreetDir previousDir = 0;
    StreetDir previousprevious = 0;

    float currentX;
    float currentY;
    float previousX;
    float previousY;

    float useX;
    float useY;


    // TODO MECANISMO PARA DETENER EL BUS
    while (get_actual_variable(vehicle->vehicleType)) {
        while (vehicle->current_route->first_node != NULL && get_actual_variable(vehicle->vehicleType)) {
            currentNode = vehicle->current_route->first_node;
            previouspreviousStreet = previousStreet;
            previousStreet = currentStreet;
            currentStreet = lookup(map->map, currentNode->destination_id);

            //Incio de Larry y Joe
            //Larry
            if (currentNode->destination_id == N018P) { // Larry u
                pthread_mutex_lock(&mutex_larry_con);
                larry_cars_waitu += 1;
                pthread_mutex_unlock(&mutex_larry_con);

            } else if (currentNode->destination_id == G012P) { // Larry d
                pthread_mutex_lock(&mutex_larry_con);
                larry_cars_waitd += 1;
                pthread_mutex_unlock(&mutex_larry_con);

            } else if (currentNode->destination_id == BU02B) {// Larry u get
                pthread_mutex_lock(&mutex_larry_con);
                larry_cars_waitu -= 1;
                pthread_mutex_unlock(&mutex_larry_con);

            } else if (currentNode->destination_id == B002B) {// Larry d get
                pthread_mutex_lock(&mutex_larry_con);
                larry_cars_waitd -= 1;
                pthread_mutex_unlock(&mutex_larry_con);
            }

            //Joe
            if (currentNode->destination_id == R018P) { // Joe u

                pthread_mutex_lock(&mutex_joe_con);
                joe_cars_waitu += 1;
                pthread_mutex_unlock(&mutex_joe_con);

            } else if (currentNode->destination_id == K012P) { // Joe d
                pthread_mutex_lock(&mutex_joe_con);
                joe_cars_waitd += 1;
                pthread_mutex_unlock(&mutex_joe_con);

            } else if (currentNode->destination_id == BU26B) {// Joe u get
                pthread_mutex_lock(&mutex_joe_con);
                joe_cars_waitu -= 1;
                pthread_mutex_unlock(&mutex_joe_con);

            } else if (currentNode->destination_id == B026B) {// Joe d get
                pthread_mutex_lock(&mutex_joe_con);
                joe_cars_waitd -= 1;
                pthread_mutex_unlock(&mutex_joe_con);
            }

            //Fin de Larry y Joe
            //Inicio de puente central
            //Bloqueo de llegada
            if (currentNode->destination_id == B013B) { // Para abajo
                pthread_mutex_lock(&check_mutex_moe);
                if (moe_direction == 0 || moe_direction == 1) {
                    pthread_mutex_unlock(&check_mutex_moe);
                    pthread_mutex_lock(&mutex_moe);
                    moe_direction = -1;
                    printf("\033[0;31m%s\033[0m\n", "Moe change direction to: South");
                    edit_semaphore(2, SEMAPHORED);

                    pthread_mutex_lock(&check_mutex_moe);
                    moe_cars += 1;
                    pthread_mutex_unlock(&check_mutex_moe);

                } else {
                    moe_cars += 1;
                    pthread_mutex_unlock(&check_mutex_moe);
                }

            } else if (currentNode->destination_id == BU13B) {//Para arriba
                pthread_mutex_lock(&check_mutex_moe);
                if (moe_direction == 0 || moe_direction == -1) {
                    pthread_mutex_unlock(&check_mutex_moe);
                    pthread_mutex_lock(&mutex_moe);
                    moe_direction = 1;
                    printf("\033[0;31m%s\033[0m\n", "Moe change direction to: North");
                    edit_semaphore(2, SEMAPHOREU);

                    pthread_mutex_lock(&check_mutex_moe);
                    moe_cars += 1;
                    pthread_mutex_unlock(&check_mutex_moe);

                } else {
                    moe_cars += 1;
                    pthread_mutex_unlock(&check_mutex_moe);
                }


            }

            //Bloqueo de salida
            if (currentNode->destination_id == B018B || currentNode->destination_id == BU18B) {// Para abajo
                pthread_mutex_lock(&check_mutex_moe);
                moe_cars -= 1;
                if (moe_cars == 0) {
                    pthread_mutex_unlock(&mutex_moe);
                }
                pthread_mutex_unlock(&check_mutex_moe);
            }
            //Fin de puente central

            lock_priority_semaphore(5, currentStreet);

            if (previouspreviousStreet != NULL) {
                unlock_priority_semaphore(0, previouspreviousStreet);
            }

            streetInfo = lookup_street_info(map->streetInfoTable, currentNode->destination_id);

            ///Direcciones
            previousprevious = previousDir;
            previousDir = currentDir;
            currentDir = streetInfo->dir;

            previousX = currentX;
            previousY = currentY;
            currentX = streetInfo->x;
            currentY = streetInfo->y;

            if (previousStreet == NULL) {
                previousprevious = currentDir;
                previousDir = currentDir;

                previousX = currentX;
                previousY = currentY;
            }
            ///
            if (vehicle->destinations[currentDestination] == currentNode->destination_id) {
                useX = currentX;
                useY = currentY;

            } else if (best_dirc(currentDir, previousDir, previousprevious) == SOUTH_DIR ||
                       best_dirc(currentDir, previousDir, previousprevious) == EAST_DIR) {
                useX = previousX;
                useY = previousY;
            } else {
                useX = currentX;
                useY = currentY;
            }

            edit_object_with_node(
                    vehicle->ui_info,
                    from_vehicle_type(vehicle->vehicleType, best_dirc(currentDir, previousDir, previousprevious)),
                    useX,
                    useY,
                    get_stop_id(
                            vehicle->destinations[currentDestination],
                            get_destinations_size(vehicle->destinations) - (currentDestination - 1)
                    )
            );

            //Si llegue a una parada duermo 5 segundos
            if (vehicle->destinations[currentDestination] == currentNode->destination_id) {
                previouspreviousStreet = NULL;

                if (previousStreet != NULL) {
                    unlock_priority_semaphore(0, previousStreet);
                    previousStreet = NULL;
                }

                sleep(5);
                currentDestination++;
            } else {
                usleep((vehicle->speed * 1000000) / highway_multiplier(currentNode->destination_id));
            }

            pop(vehicle->current_route);

        }
        currentDestination = 0;
        vehicle->current_route = copy_list(busRouteCopy);
    }

    //Detener el bus
    delete_object(vehicle->vehicle_id);
    unlock_priority_semaphore(5, currentStreet);
    if (previousStreet != NULL) {
        unlock_priority_semaphore(0, previousStreet);
    }


    GtkWidget *active_w = GTK_WIDGET(gtk_builder_get_object(builder, get_active_button(vehicle->vehicleType)));
    gtk_widget_set_sensitive(active_w, true);
}

void *handle_vehicle(void *arg) {
    VehicleThreadInfo *info = (VehicleThreadInfo *) arg;
    Vehicle *vehicle = info->vehicle;
    switch (vehicle->vehicleType) {
        case RED_BUS:
        case GREEN_BUS:
        case BLUE_BUS:
        case WHITE_BUS:
        case GRAY_BUS:
        case BLACK_BUS:
        case PINK_BUS:
        case LIGHT_BLUE_BUS:
        case ORANGE_BUS:
            handle_bus(vehicle);
            break;
        case AMBULANCE:
            handle_normal_vehicle(vehicle, 1);
            break;
        case RED_CAR:
        case BLUE_CAR:
        case GREEN_CAR:
        case BLACK_CAR:
        case WHITE_CAR:
        case YELLOW_CAR:
            handle_normal_vehicle(vehicle, 5);
            break;
        default:
            break;
    }
    delete_object(vehicle->vehicle_id);
    free(vehicle);
    return NULL;
}

