#ifndef PROYECTO3_VEHICLE_H
#define PROYECTO3_VEHICLE_H

#include "utils.h"
#include "linked_list.h"
#include "threadville_map.h"
#include "linked_list_cars.h"

typedef enum VehicleType {
    RED_BUS,
    GREEN_BUS,
    BLUE_BUS,
    WHITE_BUS,
    GRAY_BUS,
    BLACK_BUS,
    PINK_BUS,
    LIGHT_BLUE_BUS,
    ORANGE_BUS,
    AMBULANCE,
    RED_CAR,
    BLUE_CAR,
    GREEN_CAR,
    BLACK_CAR,
    WHITE_CAR,
    YELLOW_CAR
} VehicleType;

typedef enum VehicleDir {
    NORTH,
    SOUTH,
    WEST,
    EAST
} VehicleDir;

typedef struct Vehicle {
    int vehicle_id;
    VehicleType vehicleType;
    VehicleDir vehicleDir;
    // Vehicle speed
    double speed;
    // Route to get current destination
    LinkedList *current_route;
    // Vehicle must have 2 destinations and thrid one for the exit point
    // Buses have n dedstinations, final element of array should be -1
    int *destinations;
    node_t *ui_info;
} Vehicle;

typedef struct VehicleThreadInfo {
    Vehicle *vehicle;
} VehicleThreadInfo;

int random_stop_id();

int random_car_id();

char *get_stop_id(int, int);

LinkedList *create_route(int start_point, int end_point);

void create_bus_route(Vehicle *v);

float getVehicleSpeed(VehicleType);

Vehicle *create_vehicle(VehicleType, VehicleDir, int *destinations);

Vehicle *create_bus(VehicleType, VehicleDir);

void free_vehicle(Vehicle *);

VehicleThreadInfo *create_vehicle_thread_info(Vehicle *);

void *handle_vehicle(void *arg);

void handle_normal_vehicle(Vehicle *vehicle, int priority_value);

void handle_bus(Vehicle *vehicle);

int highway_multiplier(int);

int is_bus(VehicleType);

int get_destinations_size(const int *destinations);

int *copy_destinations(int *);

#endif //PROYECTO3_VEHICLE_H
