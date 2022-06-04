//
// Created by bmena on 6/18/20.
//

#ifndef PROYECTO3_GLOBALES_H
#define PROYECTO3_GLOBALES_H

#include <gtk/gtk.h>
#include <gtk/gtktypes.h>
#include "threadville_map.h"
#include <stdbool.h>
#include <pthread.h>

GtkBuilder *builder;
GtkWidget *window;

ThreadvilleMap *mapa;

pthread_mutex_t mutex_KMN = PTHREAD_MUTEX_INITIALIZER;
volatile int K = 5;
volatile int M = 5;
volatile int N = 5;


pthread_mutex_t mutex_bus_activo = PTHREAD_MUTEX_INITIALIZER;
volatile bool is_bus_rojo  = false;
volatile bool is_bus_verde  = false;
volatile bool is_bus_naranja  = false;
volatile bool is_bus_azul  = false;
volatile bool is_bus_gris  = false;
volatile bool is_bus_rosado  = false;
volatile bool is_bus_celeste  = false;
volatile bool is_bus_blanco  = false;
volatile bool is_bus_negro  = false;

//Moe variables
int moe_direccion = 0; // 0 libre, 1 arriba, -1 abajo
pthread_mutex_t mutex_moe = PTHREAD_MUTEX_INITIALIZER;
int moe_carros = 0;
pthread_mutex_t mutex_chequear_moe = PTHREAD_MUTEX_INITIALIZER;


//Larry and joe variables
pthread_mutex_t mutex_larry_con = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_joe_con = PTHREAD_MUTEX_INITIALIZER;

volatile int larry_espera_carros_abajo = 0;
volatile int joe_espera_carros_abajo = 0;

volatile int larry_espera_carros_arriba = 0;
volatile int joe_espera_carros_arriba = 0;



// Bridges data
pthread_mutex_t *mutex_larry;
pthread_cond_t *cond_larry;

pthread_mutex_t *mutex_joe;
pthread_cond_t *cond_joe;

pthread_mutex_t *mutex_curly;
pthread_cond_t *cond_curly;

pthread_mutex_t *mutex_shemp;
pthread_cond_t *cond_shemp;

#endif //PROYECTO3_GLOBALES_H
