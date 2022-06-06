#include "vehiculo.h"
#include <stdlib.h>
#include <unistd.h>
#include "utils.h"
#include "hash_table.h"
#include "interfaz.h"
#include "floyd.h"
#include "bus.h"
#include <stdbool.h>
#include<time.h>

#define DISTANCIA_AF 48.0 // distancia de A1 a F2

extern bool is_bus_rojo;
extern bool is_bus_verde;
extern bool is_bus_naranja;
extern bool is_bus_azul;
extern bool is_bus_gris;
extern bool is_bus_rosado;
extern bool is_bus_celeste;
extern bool is_bus_blanco;
extern bool is_bus_negro;

extern ThreadvilleMapa *mapa;
extern GtkWidget *window;
extern GtkBuilder *builder;

extern int moe_direccion; // 0 libre, 1 arriba, -1 abajo
extern pthread_mutex_t mutex_moe;
extern int moe_carros;
extern pthread_mutex_t mutex_chequear_moe;


extern pthread_mutex_t mutex_larry_con;
extern pthread_mutex_t mutex_joe_con;

extern int larry_espera_carros_arriba;
extern int joe_espera_carros_arriba;
extern int larry_espera_carros_abajo;
extern int joe_espera_carros_abajo;

extern pthread_mutex_t mutex_bus_activo;

static int id_global = 0;

pthread_mutex_t mutex_id_global = PTHREAD_MUTEX_INITIALIZER;

void monitor_print(char *mensaje, char *name) {
    GtkTextView   *text_view;
    GtkTextBuffer *buffer;
    GtkTextIter iter;
    text_view = GTK_TEXT_VIEW(gtk_builder_get_object(builder, name));
    buffer = gtk_text_view_get_buffer(text_view);

    gtk_text_buffer_get_iter_at_offset(buffer, &iter, 0);
    gtk_text_buffer_insert(buffer, &iter, mensaje, -1);
}

int get_id_global() {
    int resultado = 0;
    pthread_mutex_lock(&mutex_id_global);
    resultado = id_global;
    id_global += 1;
    pthread_mutex_unlock(&mutex_id_global);
    return resultado;
}

int id_parada_aleatoria() {
    return (rand() % (R006S - A001S + 1)) + A001S;
}

int id_carro_aleatorio() {
    srand(time(0));
    return (rand() % (CARRO_AMARILLO - CARRO_ROJO + 1)) + CARRO_ROJO;
}

char *get_id_parada(int parada, int destinosIzquierda) {
    char *resultado = calloc(6, sizeof(char));
    switch (parada) {
        case A001S:
            sprintf(resultado, "%s-%d", "A1", destinosIzquierda);
            break;
        case A002S:
            sprintf(resultado, "%s-%d", "A2", destinosIzquierda);
            break;
        case A003S:
            sprintf(resultado, "%s-%d", "A3", destinosIzquierda);
            break;
        case A004S:
            sprintf(resultado, "%s-%d", "A4", destinosIzquierda);
            break;
        case A005S:
            sprintf(resultado, "%s-%d", "A5", destinosIzquierda);
            break;
        case A006S:
            sprintf(resultado, "%s-%d", "A6", destinosIzquierda);
            break;
        case A007S:
            sprintf(resultado, "%s-%d", "A7", destinosIzquierda);
            break;
        case A008S:
            sprintf(resultado, "%s-%d", "A8", destinosIzquierda);
            break;
        case B001S:
            sprintf(resultado, "%s-%d", "B1", destinosIzquierda);
            break;
        case B002S:
            sprintf(resultado, "%s-%d", "B2", destinosIzquierda);
            break;
        case B003S:
            sprintf(resultado, "%s-%d", "B3", destinosIzquierda);
            break;
        case B004S:
            sprintf(resultado, "%s-%d", "B4", destinosIzquierda);
            break;
        case B005S:
            sprintf(resultado, "%s-%d", "B5", destinosIzquierda);
            break;
        case B006S:
            sprintf(resultado, "%s-%d", "B6", destinosIzquierda);
            break;
        case B007S:
            sprintf(resultado, "%s-%d", "B7", destinosIzquierda);
            break;
        case B008S:
            sprintf(resultado, "%s-%d", "B8", destinosIzquierda);
            break;
        case C001S:
            sprintf(resultado, "%s-%d", "C1", destinosIzquierda);
            break;
        case C002S:
            sprintf(resultado, "%s-%d", "C2", destinosIzquierda);
            break;
        case C003S:
            sprintf(resultado, "%s-%d", "C3", destinosIzquierda);
            break;
        case C004S:
            sprintf(resultado, "%s-%d", "C4", destinosIzquierda);
            break;
        case C005S:
            sprintf(resultado, "%s-%d", "C5", destinosIzquierda);
            break;
        case C006S:
            sprintf(resultado, "%s-%d", "C6", destinosIzquierda);
            break;
        case C007S:
            sprintf(resultado, "%s-%d", "C7", destinosIzquierda);
            break;
        case C008S:
            sprintf(resultado, "%s-%d", "C8", destinosIzquierda);
            break;
        case D001S:
            sprintf(resultado, "%s-%d", "D1", destinosIzquierda);
            break;
        case D002S:
            sprintf(resultado, "%s-%d", "D2", destinosIzquierda);
            break;
        case D003S:
            sprintf(resultado, "%s-%d", "D3", destinosIzquierda);
            break;
        case D004S:
            sprintf(resultado, "%s-%d", "D4", destinosIzquierda);
            break;
        case D005S:
            sprintf(resultado, "%s-%d", "D5", destinosIzquierda);
            break;
        case D006S:
            sprintf(resultado, "%s-%d", "D6", destinosIzquierda);
            break;
        case D007S:
            sprintf(resultado, "%s-%d", "D7", destinosIzquierda);
            break;
        case D008S:
            sprintf(resultado, "%s-%d", "D8", destinosIzquierda);
            break;
        case E001S:
            sprintf(resultado, "%s-%d", "E1", destinosIzquierda);
            break;
        case E002S:
            sprintf(resultado, "%s-%d", "E2", destinosIzquierda);
            break;
        case E003S:
            sprintf(resultado, "%s-%d", "E3", destinosIzquierda);
            break;
        case E004S:
            sprintf(resultado, "%s-%d", "E4", destinosIzquierda);
            break;
        case E005S:
            sprintf(resultado, "%s-%d", "E5", destinosIzquierda);
            break;
        case E006S:
            sprintf(resultado, "%s-%d", "E6", destinosIzquierda);
            break;
        case E007S:
            sprintf(resultado, "%s-%d", "E7", destinosIzquierda);
            break;
        case E008S:
            sprintf(resultado, "%s-%d", "E8", destinosIzquierda);
            break;
        case F001S:
            sprintf(resultado, "%s-%d", "F1", destinosIzquierda);
            break;
        case F002S:
            sprintf(resultado, "%s-%d", "F2", destinosIzquierda);
            break;
        case F003S:
            sprintf(resultado, "%s-%d", "F3", destinosIzquierda);
            break;
        case F004S:
            sprintf(resultado, "%s-%d", "F4", destinosIzquierda);
            break;
        case F005S:
            sprintf(resultado, "%s-%d", "F5", destinosIzquierda);
            break;
        case F006S:
            sprintf(resultado, "%s-%d", "F6", destinosIzquierda);
            break;
        case F007S:
            sprintf(resultado, "%s-%d", "F7", destinosIzquierda);
            break;
        case F008S:
            sprintf(resultado, "%s-%d", "F8", destinosIzquierda);
            break;
        case S001S:
            sprintf(resultado, "%s-%d", "S1", destinosIzquierda);
            break;
        case S002S:
            sprintf(resultado, "%s-%d", "S2", destinosIzquierda);
            break;
        case S003S:
            sprintf(resultado, "%s-%d", "S3", destinosIzquierda);
            break;
        case S004S:
            sprintf(resultado, "%s-%d", "S4", destinosIzquierda);
            break;
        case S005S:
            sprintf(resultado, "%s-%d", "S5", destinosIzquierda);
            break;
        case S006S:
            sprintf(resultado, "%s-%d", "S6", destinosIzquierda);
            break;
        case S007S:
            sprintf(resultado, "%s-%d", "S7", destinosIzquierda);
            break;
        case S008S:
            sprintf(resultado, "%s-%d", "S8", destinosIzquierda);
            break;
        case T001S:
            sprintf(resultado, "%s-%d", "T1", destinosIzquierda);
            break;
        case T002S:
            sprintf(resultado, "%s-%d", "T2", destinosIzquierda);
            break;
        case T003S:
            sprintf(resultado, "%s-%d", "T3", destinosIzquierda);
            break;
        case T004S:
            sprintf(resultado, "%s-%d", "T4", destinosIzquierda);
            break;
        case T005S:
            sprintf(resultado, "%s-%d", "T5", destinosIzquierda);
            break;
        case T006S:
            sprintf(resultado, "%s-%d", "T6", destinosIzquierda);
            break;
        case T007S:
            sprintf(resultado, "%s-%d", "T7", destinosIzquierda);
            break;
        case T008S:
            sprintf(resultado, "%s-%d", "T8", destinosIzquierda);
            break;
        case U001S:
            sprintf(resultado, "%s-%d", "U1", destinosIzquierda);
            break;
        case U002S:
            sprintf(resultado, "%s-%d", "U2", destinosIzquierda);
            break;
        case U003S:
            sprintf(resultado, "%s-%d", "U3", destinosIzquierda);
            break;
        case U004S:
            sprintf(resultado, "%s-%d", "U4", destinosIzquierda);
            break;
        case U005S:
            sprintf(resultado, "%s-%d", "U5", destinosIzquierda);
            break;
        case U006S:
            sprintf(resultado, "%s-%d", "U6", destinosIzquierda);
            break;
        case U007S:
            sprintf(resultado, "%s-%d", "U7", destinosIzquierda);
            break;
        case U008S:
            sprintf(resultado, "%s-%d", "U8", destinosIzquierda);
            break;
        case V001S:
            sprintf(resultado, "%s-%d", "V1", destinosIzquierda);
            break;
        case V002S:
            sprintf(resultado, "%s-%d", "V2", destinosIzquierda);
            break;
        case V003S:
            sprintf(resultado, "%s-%d", "V3", destinosIzquierda);
            break;
        case V004S:
            sprintf(resultado, "%s-%d", "V4", destinosIzquierda);
            break;
        case V005S:
            sprintf(resultado, "%s-%d", "V5", destinosIzquierda);
            break;
        case V006S:
            sprintf(resultado, "%s-%d", "V6", destinosIzquierda);
            break;
        case V007S:
            sprintf(resultado, "%s-%d", "V7", destinosIzquierda);
            break;
        case V008S:
            sprintf(resultado, "%s-%d", "V8", destinosIzquierda);
            break;
        case W001S:
            sprintf(resultado, "%s-%d", "W1", destinosIzquierda);
            break;
        case W002S:
            sprintf(resultado, "%s-%d", "W2", destinosIzquierda);
            break;
        case W003S:
            sprintf(resultado, "%s-%d", "W3", destinosIzquierda);
            break;
        case W004S:
            sprintf(resultado, "%s-%d", "W4", destinosIzquierda);
            break;
        case W005S:
            sprintf(resultado, "%s-%d", "W5", destinosIzquierda);
            break;
        case W006S:
            sprintf(resultado, "%s-%d", "W6", destinosIzquierda);
            break;
        case W007S:
            sprintf(resultado, "%s-%d", "W7", destinosIzquierda);
            break;
        case W008S:
            sprintf(resultado, "%s-%d", "W8", destinosIzquierda);
            break;
        case X001S:
            sprintf(resultado, "%s-%d", "X1", destinosIzquierda);
            break;
        case X002S:
            sprintf(resultado, "%s-%d", "X2", destinosIzquierda);
            break;
        case X003S:
            sprintf(resultado, "%s-%d", "X3", destinosIzquierda);
            break;
        case X004S:
            sprintf(resultado, "%s-%d", "X4", destinosIzquierda);
            break;
        case X005S:
            sprintf(resultado, "%s-%d", "X5", destinosIzquierda);
            break;
        case X006S:
            sprintf(resultado, "%s-%d", "X6", destinosIzquierda);
            break;
        case X007S:
            sprintf(resultado, "%s-%d", "X7", destinosIzquierda);
            break;
        case X008S:
            sprintf(resultado, "%s-%d", "X8", destinosIzquierda);
            break;
        case G001S:
            sprintf(resultado, "%s-%d", "G1", destinosIzquierda);
            break;
        case G002S:
            sprintf(resultado, "%s-%d", "G2", destinosIzquierda);
            break;
        case G003S:
            sprintf(resultado, "%s-%d", "G3", destinosIzquierda);
            break;
        case G004S:
            sprintf(resultado, "%s-%d", "G4", destinosIzquierda);
            break;
        case G005S:
            sprintf(resultado, "%s-%d", "G5", destinosIzquierda);
            break;
        case G006S:
            sprintf(resultado, "%s-%d", "G6", destinosIzquierda);
            break;
        case H001S:
            sprintf(resultado, "%s-%d", "H1", destinosIzquierda);
            break;
        case H002S:
            sprintf(resultado, "%s-%d", "H2", destinosIzquierda);
            break;
        case H003S:
            sprintf(resultado, "%s-%d", "H3", destinosIzquierda);
            break;
        case H004S:
            sprintf(resultado, "%s-%d", "H4", destinosIzquierda);
            break;
        case H005S:
            sprintf(resultado, "%s-%d", "H5", destinosIzquierda);
            break;
        case H006S:
            sprintf(resultado, "%s-%d", "H6", destinosIzquierda);
            break;
        case I001S:
            sprintf(resultado, "%s-%d", "I1", destinosIzquierda);
            break;
        case I002S:
            sprintf(resultado, "%s-%d", "I2", destinosIzquierda);
            break;
        case I003S:
            sprintf(resultado, "%s-%d", "I3", destinosIzquierda);
            break;
        case I004S:
            sprintf(resultado, "%s-%d", "I4", destinosIzquierda);
            break;
        case I005S:
            sprintf(resultado, "%s-%d", "I5", destinosIzquierda);
            break;
        case I006S:
            sprintf(resultado, "%s-%d", "I6", destinosIzquierda);
            break;
        case J001S:
            sprintf(resultado, "%s-%d", "J1", destinosIzquierda);
            break;
        case J002S:
            sprintf(resultado, "%s-%d", "J2", destinosIzquierda);
            break;
        case J003S:
            sprintf(resultado, "%s-%d", "J3", destinosIzquierda);
            break;
        case J004S:
            sprintf(resultado, "%s-%d", "J4", destinosIzquierda);
            break;
        case J005S:
            sprintf(resultado, "%s-%d", "J5", destinosIzquierda);
            break;
        case J006S:
            sprintf(resultado, "%s-%d", "J6", destinosIzquierda);
            break;
        case K001S:
            sprintf(resultado, "%s-%d", "K1", destinosIzquierda);
            break;
        case K002S:
            sprintf(resultado, "%s-%d", "K2", destinosIzquierda);
            break;
        case K003S:
            sprintf(resultado, "%s-%d", "K3", destinosIzquierda);
            break;
        case K004S:
            sprintf(resultado, "%s-%d", "K4", destinosIzquierda);
            break;
        case K005S:
            sprintf(resultado, "%s-%d", "K5", destinosIzquierda);
            break;
        case K006S:
            sprintf(resultado, "%s-%d", "K6", destinosIzquierda);
            break;
        case L001S:
            sprintf(resultado, "%s-%d", "L1", destinosIzquierda);
            break;
        case L002S:
            sprintf(resultado, "%s-%d", "L2", destinosIzquierda);
            break;
        case L003S:
            sprintf(resultado, "%s-%d", "L3", destinosIzquierda);
            break;
        case L004S:
            sprintf(resultado, "%s-%d", "L4", destinosIzquierda);
            break;
        case L005S:
            sprintf(resultado, "%s-%d", "L5", destinosIzquierda);
            break;
        case L006S:
            sprintf(resultado, "%s-%d", "L6", destinosIzquierda);
            break;
        case M001S:
            sprintf(resultado, "%s-%d", "M1", destinosIzquierda);
            break;
        case M002S:
            sprintf(resultado, "%s-%d", "M2", destinosIzquierda);
            break;
        case M003S:
            sprintf(resultado, "%s-%d", "M3", destinosIzquierda);
            break;
        case M004S:
            sprintf(resultado, "%s-%d", "M4", destinosIzquierda);
            break;
        case M005S:
            sprintf(resultado, "%s-%d", "M5", destinosIzquierda);
            break;
        case M006S:
            sprintf(resultado, "%s-%d", "M6", destinosIzquierda);
            break;
        case N001S:
            sprintf(resultado, "%s-%d", "N1", destinosIzquierda);
            break;
        case N002S:
            sprintf(resultado, "%s-%d", "N2", destinosIzquierda);
            break;
        case N003S:
            sprintf(resultado, "%s-%d", "N3", destinosIzquierda);
            break;
        case N004S:
            sprintf(resultado, "%s-%d", "N4", destinosIzquierda);
            break;
        case N005S:
            sprintf(resultado, "%s-%d", "N5", destinosIzquierda);
            break;
        case N006S:
            sprintf(resultado, "%s-%d", "N6", destinosIzquierda);
            break;
        case O001S:
            sprintf(resultado, "%s-%d", "O1", destinosIzquierda);
            break;
        case O002S:
            sprintf(resultado, "%s-%d", "O2", destinosIzquierda);
            break;
        case O003S:
            sprintf(resultado, "%s-%d", "O3", destinosIzquierda);
            break;
        case O004S:
            sprintf(resultado, "%s-%d", "O4", destinosIzquierda);
            break;
        case O005S:
            sprintf(resultado, "%s-%d", "O5", destinosIzquierda);
            break;
        case O006S:
            sprintf(resultado, "%s-%d", "O6", destinosIzquierda);
            break;
        case P001S:
            sprintf(resultado, "%s-%d", "P1", destinosIzquierda);
            break;
        case P002S:
            sprintf(resultado, "%s-%d", "P2", destinosIzquierda);
            break;
        case P003S:
            sprintf(resultado, "%s-%d", "P3", destinosIzquierda);
            break;
        case P004S:
            sprintf(resultado, "%s-%d", "P4", destinosIzquierda);
            break;
        case P005S:
            sprintf(resultado, "%s-%d", "P5", destinosIzquierda);
            break;
        case P006S:
            sprintf(resultado, "%s-%d", "P6", destinosIzquierda);
            break;
        case Q001S:
            sprintf(resultado, "%s-%d", "Q1", destinosIzquierda);
            break;
        case Q002S:
            sprintf(resultado, "%s-%d", "Q2", destinosIzquierda);
            break;
        case Q003S:
            sprintf(resultado, "%s-%d", "Q3", destinosIzquierda);
            break;
        case Q004S:
            sprintf(resultado, "%s-%d", "Q4", destinosIzquierda);
            break;
        case Q005S:
            sprintf(resultado, "%s-%d", "Q5", destinosIzquierda);
            break;
        case Q006S:
            sprintf(resultado, "%s-%d", "Q6", destinosIzquierda);
            break;
        case R001S:
            sprintf(resultado, "%s-%d", "R1", destinosIzquierda);
            break;
        case R002S:
            sprintf(resultado, "%s-%d", "R2", destinosIzquierda);
            break;
        case R003S:
            sprintf(resultado, "%s-%d", "R3", destinosIzquierda);
            break;
        case R004S:
            sprintf(resultado, "%s-%d", "R4", destinosIzquierda);
            break;
        case R005S:
            sprintf(resultado, "%s-%d", "R5", destinosIzquierda);
            break;
        case R006S:
            sprintf(resultado, "%s-%d", "R6", destinosIzquierda);
            break;
        case Z006R:
            sprintf(resultado, "%s-%d", "Z6", destinosIzquierda);
            break;
        case Y006R:
            sprintf(resultado, "%s-%d", "Y6", destinosIzquierda);
            break;
        default:
            return "";
            break;
    }
    return resultado;
}

char *get_boton_activo(TipoVehiculo tipo) {
    switch (tipo) {
        case BUS_ROJO:
            return "btn_cbr";
        case BUS_VERDE:
            return "btn_cbgr";
        case BUS_AZUL:
            return "btn_cbb";
        case BUS_BLANCO:
            return "btn_cbw";
        case BUS_GRIS:
            return "btn_cbg";
        case BUS_NEGRO:
            return "btn_cbbl";
        case BUS_ROSADO:
            return "btn_cbp";
        case BUS_CELESTE:
            return "btn_cblb";
        case BUS_NARANJA:
            return "btn_cbo";
        default:
            return "";
    }
}

bool get_variable_actual(TipoVehiculo tipo) {

    pthread_mutex_lock(&mutex_bus_activo);
    switch (tipo) {
        case BUS_ROJO:
            pthread_mutex_unlock(&mutex_bus_activo);
            return is_bus_rojo;
        case BUS_VERDE:
            pthread_mutex_unlock(&mutex_bus_activo);
            return is_bus_verde;
        case BUS_AZUL:
            pthread_mutex_unlock(&mutex_bus_activo);
            return is_bus_azul;
        case BUS_BLANCO:
            pthread_mutex_unlock(&mutex_bus_activo);
            return is_bus_blanco;
        case BUS_GRIS:
            pthread_mutex_unlock(&mutex_bus_activo);
            return is_bus_gris;
        case BUS_NEGRO:
            pthread_mutex_unlock(&mutex_bus_activo);
            return is_bus_negro;
        case BUS_ROSADO:
            pthread_mutex_unlock(&mutex_bus_activo);
            return is_bus_rosado;
        case BUS_CELESTE:
            pthread_mutex_unlock(&mutex_bus_activo);
            return is_bus_celeste;
        case BUS_NARANJA:
            pthread_mutex_unlock(&mutex_bus_activo);
            return is_bus_naranja;
        default:
            pthread_mutex_unlock(&mutex_bus_activo);
            return false;
    }
}

ListaEnlazada *crear_ruta(int puntoInicio, int puntoFin) {
    ListaEnlazada *l = crear_lista_enlazada();
    int *path = floyd_path(puntoInicio, puntoFin);
    for (int i = path[0]; i >= 1; --i) {

        push(l, crear_nodo(path[i]));
    }
    free(path);
    return l;
}

ListaEnlazada *crear_ruta_auxiliar(int puntoInicio, int puntoFin) {
    ListaEnlazada *l = crear_lista_enlazada();
    int *path = floyd_path(puntoInicio, puntoFin);
    for (int i = path[0]; i > 1; --i) {
        push(l, crear_nodo(path[i]));
    }
    free(path);
    return l;
}

void crear_ruta_bus(Vehiculo *vehiculo) {
    switch (vehiculo->tipoVehiculo) {
        case BUS_ROJO:
            crear_ruta_rojo(vehiculo);
            break;
        case BUS_VERDE:
            crear_ruta_verde(vehiculo);
            break;
        case BUS_AZUL:
            crear_ruta_azul(vehiculo);
            break;
        case BUS_BLANCO:
            crear_ruta_blanco(vehiculo);
            break;
        case BUS_GRIS:
            crear_ruta_gris(vehiculo);
            break;
        case BUS_NEGRO:
            crear_ruta_negro(vehiculo);
            break;
        case BUS_ROSADO:
            crear_ruta_rosado(vehiculo);
            break;
        case BUS_CELESTE:
            crear_ruta_celeste(vehiculo);
            break;
        case BUS_NARANJA:
            crear_ruta_naranja(vehiculo);
            break;
        default:
            break;
    }
}

float get_velocidad_vehiculo(TipoVehiculo tipo) {
    //Velocidad dada en "lugares" por segundo
    float velocidad;
    switch (tipo) {
        case BUS_NARANJA:
            velocidad = 7.0 / DISTANCIA_AF;
            break;
        case AMBULANCIA:
            velocidad = 0.5 / DISTANCIA_AF;
            break;
        case CARRO_ROJO:
            velocidad = 1.0 / DISTANCIA_AF;
            break;
        case CARRO_AZUL:
            velocidad = 2.0 / DISTANCIA_AF;
            break;
        case BUS_ROSADO:
        case BUS_CELESTE:
        case CARRO_VERDE:
            velocidad = 3.0 / DISTANCIA_AF;
            break;
        case BUS_BLANCO:
        case BUS_GRIS:
        case BUS_NEGRO:
        case CARRO_NEGRO:
            velocidad = 4.0 / DISTANCIA_AF;
            break;
        case BUS_ROJO:
        case BUS_VERDE:
        case BUS_AZUL:
        case CARRO_BLANCO:
            velocidad = 5.0 / DISTANCIA_AF;
            break;
        case CARRO_AMARILLO:
            velocidad = 6.0 / DISTANCIA_AF;
            break;
        default:
            velocidad = -1;
            break;
    }
    return velocidad;
}

Vehiculo *crear_bus(TipoVehiculo tipo, DireccionVehiculo direccion) {
    int id_actual = get_id_global();
    Vehiculo *vehiculo = malloc(sizeof(Vehiculo));
    float velocidad = get_velocidad_vehiculo(tipo);
    if (velocidad < 0) {
        return NULL;
    }
    vehiculo->velocidad = velocidad;
    vehiculo->tipoVehiculo = tipo;
    vehiculo->direccionVehiculo = direccion;

    crear_ruta_bus(vehiculo);

    // El punto de inicio siempre es Y006R
    InfoCalle *info = lookup_info_calle(
            mapa->tablaInfoCalle,
            vehiculo->ruta_actual->primerNodo->idDestino
    );
    NodoT *infoUI = crear_objeto(
            id_actual,
            imagen_tipo_vehiculo(tipo, info->direccion),
            info->x, info->y,
            get_id_parada(
                    vehiculo->ruta_actual->primerNodo->idDestino,
                    get_tamanio_destinos(vehiculo->destinos)
            )
    );
    vehiculo->infoUI = infoUI;
    vehiculo->id_vehiculo = id_actual;
    return vehiculo;
}

Vehiculo *crear_vehiculo(TipoVehiculo tipo, DireccionVehiculo direccion, int *destinos) {
    int id_actual = get_id_global();
    Vehiculo *vehiculo = malloc(sizeof(Vehiculo));
    float velocidad = get_velocidad_vehiculo(tipo);
    if (velocidad < 0) {
        return NULL;
    }
    vehiculo->velocidad = velocidad;
    vehiculo->tipoVehiculo = tipo;
    vehiculo->direccionVehiculo = direccion;
    vehiculo->destinos = destinos;
    vehiculo->ruta_actual = crear_ruta(Y006R, destinos[0]);

    // Starting point is always Y006R
    InfoCalle *info = lookup_info_calle(
            mapa->tablaInfoCalle,
            vehiculo->ruta_actual->primerNodo->idDestino
    );
    NodoT *infoUI = crear_objeto(
            id_actual,
            imagen_tipo_vehiculo(tipo, info->direccion),
            info->x, info->y,
            get_id_parada(
                    vehiculo->ruta_actual->primerNodo->idDestino,
                    get_tamanio_destinos(vehiculo->destinos)
            )
    );
    vehiculo->infoUI = infoUI;
    vehiculo->id_vehiculo = id_actual;
    return vehiculo;
}

InfoHiloVehiculo *crear_info_hilo_vehiculo(Vehiculo *vehiculo) {
    InfoHiloVehiculo *info = malloc(sizeof(InfoHiloVehiculo));
    info->vehiculo = vehiculo;
    return info;
}

int multiplicador_carretera(int idCalle) {
    return idCalle >= 1 && idCalle <= 144 ? 2 : 1;
}

int get_tamanio_destinos(const int *destinos) {
    int indice = 0;
    while (destinos[indice] != -1) indice++;
    return indice - 2;
}

void manejar_vehiculo_normal(Vehiculo *vehiculo, int prioridad) {
    int destinoInicio;
    int siguienteDestino = 0;
    SemaforoPrioridad *calleActual = NULL;
    SemaforoPrioridad *calleAnterior = NULL;
    NodoL *nodoActual;

    while (1) {
        while (vehiculo->ruta_actual->primerNodo != NULL) {
            nodoActual = vehiculo->ruta_actual->primerNodo;
            calleAnterior = calleActual;
            calleActual = lookup(mapa->mapa, nodoActual->idDestino);

            //Inicio de Larry y Joe
            //Larry
            if (nodoActual->idDestino == N018P) { // Larry arriba
                pthread_mutex_lock(&mutex_larry_con);
                larry_espera_carros_arriba += 1;
                pthread_mutex_unlock(&mutex_larry_con);

            } else if (nodoActual->idDestino == G012P) { // Larry abajo
                pthread_mutex_lock(&mutex_larry_con);
                larry_espera_carros_abajo += 1;
                pthread_mutex_unlock(&mutex_larry_con);

            } else if (nodoActual->idDestino == BU02B) {// Larry arriba get
                pthread_mutex_lock(&mutex_larry_con);
                larry_espera_carros_arriba -= 1;
                pthread_mutex_unlock(&mutex_larry_con);

            } else if (nodoActual->idDestino == B002B) {// Larry abajo get
                pthread_mutex_lock(&mutex_larry_con);
                larry_espera_carros_abajo -= 1;
                pthread_mutex_unlock(&mutex_larry_con);
            }

            //Joe
            if (nodoActual->idDestino == R018P) { // Joe arriba
                pthread_mutex_lock(&mutex_joe_con);
                joe_espera_carros_arriba += 1;
                pthread_mutex_unlock(&mutex_joe_con);

            } else if (nodoActual->idDestino == K012P) { // Joe abajo
                pthread_mutex_lock(&mutex_joe_con);
                joe_espera_carros_abajo += 1;
                pthread_mutex_unlock(&mutex_joe_con);

            } else if (nodoActual->idDestino == BU26B) {// Joe arriba get
                pthread_mutex_lock(&mutex_joe_con);
                joe_espera_carros_arriba -= 1;
                pthread_mutex_unlock(&mutex_joe_con);

            } else if (nodoActual->idDestino == B026B) {// Joe abajo get
                pthread_mutex_lock(&mutex_joe_con);
                joe_espera_carros_abajo -= 1;
                pthread_mutex_unlock(&mutex_joe_con);
            }
            //Fin de Larry y Joe

            //Inicio de puente central Moe
            //Bloqueo de llegada
            if (nodoActual->idDestino == B013B) { // Para abajo
                pthread_mutex_lock(&mutex_chequear_moe);
                if (moe_direccion == 0 || moe_direccion == 1) {
                    pthread_mutex_unlock(&mutex_chequear_moe);
                    pthread_mutex_lock(&mutex_moe);
                    moe_direccion = -1;
                    monitor_print("Moe cambio direccion a: Sur\n", "con_moe");
                    editar_semaforo(2, SEMAFOROABAJO);

                    pthread_mutex_lock(&mutex_chequear_moe);
                    moe_carros += 1;
                    pthread_mutex_unlock(&mutex_chequear_moe);
                } else {
                    moe_carros += 1;
                    pthread_mutex_unlock(&mutex_chequear_moe);
                }

            } else if (nodoActual->idDestino == BU13B) {//Para arriba
                pthread_mutex_lock(&mutex_chequear_moe);
                if (moe_direccion == 0 || moe_direccion == -1) {
                    pthread_mutex_unlock(&mutex_chequear_moe);
                    pthread_mutex_lock(&mutex_moe);
                    moe_direccion = 1;
                    monitor_print("Moe cambio direccion a: Norte\n", "con_moe");
                    editar_semaforo(2, SEMAFOROARRIBA);

                    pthread_mutex_lock(&mutex_chequear_moe);
                    moe_carros += 1;
                    pthread_mutex_unlock(&mutex_chequear_moe);
                } else {
                    moe_carros += 1;
                    pthread_mutex_unlock(&mutex_chequear_moe);
                }
            }

            //Bloqueo de salida
            if (nodoActual->idDestino == B018B || nodoActual->idDestino == BU18B) {// Para abajo
                pthread_mutex_lock(&mutex_chequear_moe);
                moe_carros -= 1;
                if (moe_carros == 0) {
                    pthread_mutex_unlock(&mutex_moe);
                }
                pthread_mutex_unlock(&mutex_chequear_moe);
            }

            //Fin de puente central
            lock_semaforo_prioridad(prioridad, calleActual);

            if (calleAnterior != NULL) {
                unlock_semaforo_prioridad(prioridad, calleAnterior);
            }

            //Se pinta luego de obtener el semaforo
            InfoCalle *infoCalle = lookup_info_calle(mapa->tablaInfoCalle, nodoActual->idDestino);
            editar_objeto_con_nodo(
                    vehiculo->infoUI,
                    imagen_tipo_vehiculo(vehiculo->tipoVehiculo, infoCalle->direccion),
                    infoCalle->x, infoCalle->y,
                    get_id_parada(vehiculo->destinos[siguienteDestino], 3 - siguienteDestino)
            );

            //Duerme el tiempo que necesite para pasar la calle
            usleep((vehiculo->velocidad * 1000000) / multiplicador_carretera(nodoActual->idDestino));

            if (vehiculo->ruta_actual->primerNodo->siguienteNodo == NULL) {
                destinoInicio = vehiculo->ruta_actual->primerNodo->idDestino;
            }

            pop(vehiculo->ruta_actual);
        }
        siguienteDestino++;
        if (vehiculo->destinos[siguienteDestino] != -1) {
            if(vehiculo->tipoVehiculo == AMBULANCIA){
                sleep(8);
            }else {
                sleep(3); 
            }
            vehiculo->ruta_actual = crear_ruta_auxiliar(destinoInicio, vehiculo->destinos[siguienteDestino]);
        } else {
            break;
        }
    }

    unlock_semaforo_prioridad(prioridad, calleActual);
}

DireccionCalle mejor_direccion(DireccionCalle direccionActualP, DireccionCalle direccionPreviaP, DireccionCalle previaPreviaP) {
    if (direccionActualP == direccionPreviaP) {
        return direccionActualP;
    } else if (direccionPreviaP == previaPreviaP) {
        return direccionPreviaP;
    } else if (direccionActualP == previaPreviaP) {
        return direccionActualP;
    } else {
        return direccionActualP;
    }
}

void manejar_bus(Vehiculo *vehiculo) {
    SemaforoPrioridad *calleActual = NULL;
    SemaforoPrioridad *calleAnterior = NULL;
    SemaforoPrioridad *calleAnteriorAnterior = NULL;
    NodoL *nodoActual;
    int destinoActual = 0;
    InfoCalle *infoCalle;
    ListaEnlazada *copiaRutaBus = copiar_lista(vehiculo->ruta_actual);

    DireccionCalle direccionActual = 0;
    DireccionCalle direccionAnterior = 0;
    DireccionCalle direccionAnteriorAnterior = 0;

    float xActual;
    float yActual;
    float xAnterior;
    float yAnterior;

    float xUsada;
    float yUsada;


    // TODO MECANISMO PARA DETENER EL BUS
    while (get_variable_actual(vehiculo->tipoVehiculo)) {
        while (vehiculo->ruta_actual->primerNodo != NULL && get_variable_actual(vehiculo->tipoVehiculo)) {
            nodoActual = vehiculo->ruta_actual->primerNodo;
            calleAnteriorAnterior = calleAnterior;
            calleAnterior = calleActual;
            calleActual = lookup(mapa->mapa, nodoActual->idDestino);

            //Incio de Larry y Joe
            //Larry
            if (nodoActual->idDestino == N018P) { // Larry arriba
                pthread_mutex_lock(&mutex_larry_con);
                larry_espera_carros_arriba += 1;
                pthread_mutex_unlock(&mutex_larry_con);

            } else if (nodoActual->idDestino == G012P) { // Larry abajo
                pthread_mutex_lock(&mutex_larry_con);
                larry_espera_carros_abajo += 1;
                pthread_mutex_unlock(&mutex_larry_con);

            } else if (nodoActual->idDestino == BU02B) {// Larry arriba get
                pthread_mutex_lock(&mutex_larry_con);
                larry_espera_carros_arriba -= 1;
                pthread_mutex_unlock(&mutex_larry_con);

            } else if (nodoActual->idDestino == B002B) {// Larry abajo get
                pthread_mutex_lock(&mutex_larry_con);
                larry_espera_carros_abajo -= 1;
                pthread_mutex_unlock(&mutex_larry_con);
            }

            //Joe
            if (nodoActual->idDestino == R018P) { // Joe arriba

                pthread_mutex_lock(&mutex_joe_con);
                joe_espera_carros_arriba += 1;
                pthread_mutex_unlock(&mutex_joe_con);

            } else if (nodoActual->idDestino == K012P) { // Joe abajo
                pthread_mutex_lock(&mutex_joe_con);
                joe_espera_carros_abajo += 1;
                pthread_mutex_unlock(&mutex_joe_con);

            } else if (nodoActual->idDestino == BU26B) {// Joe arriba get
                pthread_mutex_lock(&mutex_joe_con);
                joe_espera_carros_arriba -= 1;
                pthread_mutex_unlock(&mutex_joe_con);

            } else if (nodoActual->idDestino == B026B) {// Joe abajo get
                pthread_mutex_lock(&mutex_joe_con);
                joe_espera_carros_abajo -= 1;
                pthread_mutex_unlock(&mutex_joe_con);
            }
            //Fin de Larry y Joe

            //Inicio de puente central Moe
            //Bloqueo de llegada
            if (nodoActual->idDestino == B013B) { // Para abajo
                pthread_mutex_lock(&mutex_chequear_moe);
                if (moe_direccion == 0 || moe_direccion == 1) {
                    pthread_mutex_unlock(&mutex_chequear_moe);
                    pthread_mutex_lock(&mutex_moe);
                    moe_direccion = -1;
                    monitor_print("Moe cambio direccion a: Sur \n", "con_moe");
                    editar_semaforo(2, SEMAFOROABAJO);

                    pthread_mutex_lock(&mutex_chequear_moe);
                    moe_carros += 1;
                    pthread_mutex_unlock(&mutex_chequear_moe);
                } else {
                    moe_carros += 1;
                    pthread_mutex_unlock(&mutex_chequear_moe);
                }

            } else if (nodoActual->idDestino == BU13B) {//Para arriba
                pthread_mutex_lock(&mutex_chequear_moe);
                if (moe_direccion == 0 || moe_direccion == -1) {
                    pthread_mutex_unlock(&mutex_chequear_moe);
                    pthread_mutex_lock(&mutex_moe);
                    moe_direccion = 1;
                    monitor_print("Moe cambio direccion a: Norte\n", "con_moe");
                    editar_semaforo(2, SEMAFOROARRIBA);

                    pthread_mutex_lock(&mutex_chequear_moe);
                    moe_carros += 1;
                    pthread_mutex_unlock(&mutex_chequear_moe);
                } else {
                    moe_carros += 1;
                    pthread_mutex_unlock(&mutex_chequear_moe);
                }
            }

            //Bloqueo de salida
            if (nodoActual->idDestino == B018B || nodoActual->idDestino == BU18B) {// Para abajo
                pthread_mutex_lock(&mutex_chequear_moe);
                moe_carros -= 1;
                if (moe_carros == 0) {
                    pthread_mutex_unlock(&mutex_moe);
                }
                pthread_mutex_unlock(&mutex_chequear_moe);
            }
            //Fin de puente central

            lock_semaforo_prioridad(5, calleActual);

            if (calleAnteriorAnterior != NULL) {
                unlock_semaforo_prioridad(0, calleAnteriorAnterior);
            }

            infoCalle = lookup_info_calle(mapa->tablaInfoCalle, nodoActual->idDestino);

            ///Direcciones
            direccionAnteriorAnterior = direccionAnterior;
            direccionAnterior = direccionActual;
            direccionActual = infoCalle->direccion;

            xAnterior = xActual;
            yAnterior = yActual;
            xActual = infoCalle->x;
            yActual = infoCalle->y;

            if (calleAnterior == NULL) {
                direccionAnteriorAnterior = direccionActual;
                direccionAnterior = direccionActual;

                xAnterior = xActual;
                yAnterior = yActual;
            }

            if (vehiculo->destinos[destinoActual] == nodoActual->idDestino) {
                xUsada = xActual;
                yUsada = yActual;

            } else if (mejor_direccion(direccionActual, direccionAnterior, direccionAnteriorAnterior) == DIR_SUR ||
                       mejor_direccion(direccionActual, direccionAnterior, direccionAnteriorAnterior) == DIR_ESTE) {
                xUsada = xAnterior;
                yUsada = yAnterior;
            } else {
                xUsada = xActual;
                yUsada = yActual;
            }

            editar_objeto_con_nodo(
                    vehiculo->infoUI,
                    imagen_tipo_vehiculo(vehiculo->tipoVehiculo, mejor_direccion(direccionActual, direccionAnterior, direccionAnteriorAnterior)),
                    xUsada,
                    yUsada,
                    get_id_parada(
                        vehiculo->destinos[destinoActual],
                        get_tamanio_destinos(vehiculo->destinos) - (destinoActual - 1)
                    )
            );

            //Si llego a una parada duermo 5 segundos
            if (vehiculo->destinos[destinoActual] == nodoActual->idDestino) {
                calleAnteriorAnterior = NULL;

                if (calleAnterior != NULL) {
                    unlock_semaforo_prioridad(0, calleAnterior);
                    calleAnterior = NULL;
                }

                sleep(5);
                destinoActual++;
            } else {
                usleep((vehiculo->velocidad * 1000000) / multiplicador_carretera(nodoActual->idDestino));
            }

            pop(vehiculo->ruta_actual);

        }
        destinoActual = 0;
        vehiculo->ruta_actual = copiar_lista(copiaRutaBus);
    }

    //Detener el bus
    borrar_objeto(vehiculo->id_vehiculo);
    unlock_semaforo_prioridad(5, calleActual);
    if (calleAnterior != NULL) {
        unlock_semaforo_prioridad(0, calleAnterior);
    }

    GtkWidget *active_w = GTK_WIDGET(gtk_builder_get_object(builder, get_boton_activo(vehiculo->tipoVehiculo)));
    gtk_widget_set_sensitive(active_w, true);
}

void *manejar_vehiculo(void *arg) {
    InfoHiloVehiculo *info = (InfoHiloVehiculo *) arg;
    Vehiculo *vehiculo = info->vehiculo;
    switch (vehiculo->tipoVehiculo) {
        case BUS_ROJO:
        case BUS_VERDE:
        case BUS_AZUL:
        case BUS_BLANCO:
        case BUS_GRIS:
        case BUS_NEGRO:
        case BUS_ROSADO:
        case BUS_CELESTE:
        case BUS_NARANJA:
            manejar_bus(vehiculo);
            break;
        case AMBULANCIA:
            manejar_vehiculo_normal(vehiculo, 1);
            break;
        case CARRO_ROJO:
        case CARRO_AZUL:
        case CARRO_VERDE:
        case CARRO_NEGRO:
        case CARRO_BLANCO:
        case CARRO_AMARILLO:
            manejar_vehiculo_normal(vehiculo, 5);
            break;
        default:
            break;
    }
    borrar_objeto(vehiculo->id_vehiculo);
    free(vehiculo);
    return NULL;
}

