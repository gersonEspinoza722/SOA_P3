#include"lista_enlazada_carros.h"
#include "utils.h"

#ifndef INTERFAZ_H
#define INTERFAZ_H

#include<gtk/gtk.h>
#include<gdk-pixbuf/gdk-pixbuf.h>
#include<cairo.h>
#include<stdio.h>
#include <conduccion.h>
#include <cargar.h>
#include <controlador.h>


void imprimir_bienvenida();



gboolean on_window_draw(GtkWidget *widget, cairo_t *cr, gpointer datosUsuario);
void borrar_objeto(int num);
gboolean on_tick(gpointer *parametros);
void editar_semaforo(int num, EnumImagenes tipoImagenP);
EnumImagenes imagen_tipo_vehiculo(TipoVehiculo tipo, DireccionCalle direccion);
NodoT *crear_objeto(int num, EnumImagenes tipoImagenP, double x, double y, char *siguienteParadaP);
void cargar_interfaz();
void editar_objeto(int num, EnumImagenes tipoImagenP, float xP, float yP, char *siguienteParadaP);
void editar_objeto_con_nodo(NodoT *node, EnumImagenes tipoImagenP, float xP, float yP, char *siguienteParadaP);



#endif /* INTERFAZ_H */

