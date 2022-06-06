#include"lista_enlazada_carros.h"
#include "utils.h"

#ifndef INTERFAZ_H
#define INTERFAZ_H

#include<gtk/gtk.h>
#include<gdk-pixbuf/gdk-pixbuf.h>
#include<cairo.h>
#include<stdio.h>
#include <vehiculo.h>
#include <cargar.h>
#include <controlador.h>


void imprimir_bienvenida();

void cargar_interfaz();

gboolean on_window_draw(GtkWidget *widget, cairo_t *cr, gpointer datosUsuario);

gboolean on_tick(gpointer *parametros);

NodoT *crear_objeto(int num, EnumImagenes tipoImagenP, double x, double y, char *siguienteParadaP);

void borrar_objeto(int num);

void editar_objeto(int num, EnumImagenes tipoImagenP, float xP, float yP, char *siguienteParadaP);

void editar_objeto_con_nodo(NodoT *node, EnumImagenes tipoImagenP, float xP, float yP, char *siguienteParadaP);

void editar_semaforo(int num, EnumImagenes tipoImagenP);

EnumImagenes imagen_tipo_vehiculo(TipoVehiculo tipo, DireccionCalle direccion);

#endif /* INTERFAZ_H */

