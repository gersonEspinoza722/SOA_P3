//
// Created by bmena on 6/18/20.
//

#ifndef PROYECTO3_GLOBALS_H
#define PROYECTO3_GLOBALS_H

#include <gtk/gtk.h>
#include <gtk/gtktypes.h>
#include "threadville_map.h"
#include <stdbool.h>
#include <pthread.h>

GtkBuilder *builder;
GtkWidget *window;

ThreadvilleMap *map;

pthread_mutex_t mutex_KMN = PTHREAD_MUTEX_INITIALIZER;
volatile int K = 5;
volatile int M = 5;
volatile int N = 5;


pthread_mutex_t mutex_bus_active = PTHREAD_MUTEX_INITIALIZER;
volatile bool isa_bred  = false;
volatile bool isa_bgreen  = false;
volatile bool isa_borange  = false;
volatile bool isa_bblue  = false;
volatile bool isa_bgray  = false;
volatile bool isa_bpink  = false;
volatile bool isa_blblue  = false;
volatile bool isa_bwhite  = false;
volatile bool isa_bblack  = false;

//Moe variables
int moe_direction = 0; // 0 libre, 1 arriba, -1 abajo
pthread_mutex_t mutex_moe = PTHREAD_MUTEX_INITIALIZER;
int moe_cars = 0;
pthread_mutex_t check_mutex_moe = PTHREAD_MUTEX_INITIALIZER;


//Larry and joe variables
pthread_mutex_t mutex_larry_con = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_joe_con = PTHREAD_MUTEX_INITIALIZER;

volatile int larry_cars_waitd = 0;
volatile int joe_cars_waitd = 0;

volatile int larry_cars_waitu = 0;
volatile int joe_cars_waitu = 0;



// Bridges data
pthread_mutex_t *mutex_larry;
pthread_cond_t *cond_larry;

pthread_mutex_t *mutex_joe;
pthread_cond_t *cond_joe;

pthread_mutex_t *mutex_curly;
pthread_cond_t *cond_curly;

pthread_mutex_t *mutex_shemp;
pthread_cond_t *cond_shemp;

#endif //PROYECTO3_GLOBALS_H
