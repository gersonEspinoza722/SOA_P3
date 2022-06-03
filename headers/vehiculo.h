#ifndef PROYECTO3_VEHICULO_H
#define PROYECTO3_VEHICULO_H

#include "utils.h"
#include "lista_enlazada.h"
#include "threadville_map.h"
#include "lista_enlazada_carros.h"

typedef enum TipoVehiculo {
    BUS_ROJO,
    BUS_VERDE,
    BUS_AZUL,
    BUS_BLANCO,
    BUS_GRIS,
    BUS_NEGRO,
    BUS_ROSADO,
    BUS_CELESTE,
    BUS_NARANJA,
    AMBULANCIA,
    CARRO_ROJO,
    CARRO_AZUL,
    CARRO_VERDE,
    CARRO_NEGRO,
    CARRO_BLANCO,
    CARRO_AMARILLO
} TipoVehiculo;

typedef enum DireccionVehiculo {
    NORTE,
    SUR,
    OESTE,
    ESTE
} DireccionVehiculo;

typedef struct Vehiculo {
    int id_vehiculo;
    TipoVehiculo tipoVehiculo;
    DireccionVehiculo direccionVehiculo;
    double velocidad;
    // Ruta para llegar a los destinos
    ListaEnlazada *ruta_actual;
    // El vehiculo debe tener 2 destino y un tercero como el punto de salida
    // Los buses tienen n destinos, el elemento final del array debe ser -1
    int *destinos;
    NodoT *infoUI;
} Vehiculo;

typedef struct InfoHiloVehiculo {
    Vehiculo *vehiculo;
} InfoHiloVehiculo;

int id_parada_aleatoria();

int id_carro_aleatorio();

char *get_id_parada(int, int);

ListaEnlazada *crear_ruta(int puntoInicio, int puntoFin);

void crear_ruta_bus(Vehiculo *vehiculo);

float get_velocidad_vehiculo(TipoVehiculo);

Vehiculo *crear_vehiculo(TipoVehiculo, DireccionVehiculo, int *destinos);

Vehiculo *crear_bus(TipoVehiculo, DireccionVehiculo);

void vehiculo_libre(Vehiculo *);

InfoHiloVehiculo *crear_info_hilo_vehiculo(Vehiculo *);

void *manejar_vehiculo(void *arg);

void manejar_vehiculo_normal(Vehiculo *vehiculo, int prioridad);

void manejar_bus(Vehiculo *vehiculo);

int multiplicador_carretera(int);

int is_bus(TipoVehiculo);

int get_tamanio_destinos(const int *destinos);

int *copiar_destinos(int *);

#endif //PROYECTO3_VEHICULO_H
