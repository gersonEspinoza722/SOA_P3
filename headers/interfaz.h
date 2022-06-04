#include"lista_enlazada_carros.h"
#include "utils.h"

#ifndef INTERFAZ_H
#define INTERFAZ_H

#include<gtk/gtk.h>
#include<gdk-pixbuf/gdk-pixbuf.h>
#include<cairo.h>
#include<stdio.h>
#include <vehiculo.h>

typedef enum {
    MAPA,
    SEMAFOROARRIBA,
    SEMAFOROABAJO,
    REPARACION,
    BUSROJOIZQ,
    BUSROJODER,
    BUSROJOATRAS,
    BUSROJOFRENTE,
    BUSVERDEIZQ,
    BUSVERDEDER,
    BUSVERDEATRAS,
    BUSVERDEFRENTE,
    BUSAZULIZQ,
    BUSAZULDER,
    BUSAZULATRAS,
    BUSAZULFRENTE,
    BUSBLANCOIZQ,
    BUSBLANCODER,
    BUSBLANCOATRAS,
    BUSBLANCOFRENTE,
    BUSGRISIZQ,
    BUSGRISDER,
    BUSGRISATRAS,
    BUSGRISFRENTE,
    BUSNEGROIZQ,
    BUSNEGRODER,
    BUSNEGROATRAS,
    BUSNEGROFRENTE,
    BUSROSADOIZQ,
    BUSROSADODER,
    BUSROSADOATRAS,
    BUSROSADOFRENTE,
    BUSCELESTEIZQ,
    BUSCELESTEDER,
    BUSCELESTEATRAS,
    BUSCELESTEFRENTE,
    BUSNARANJAIZQ,
    BUSNARANJADER,
    BUSNARANJAATRAS,
    BUSNARANJAFRENTE,
    AMBULANCIAIZQ,
    AMBULANCIADER,
    AMBULANCIAATRAS,
    AMBULANCIAFRENTE,
    CARROROJOIZQ,
    CARROROJODER,
    CARROROJOATRAS,
    CARROROJOFRENTE,
    CARROVERDEIZQ,
    CARROVERDEDER,
    CARROVERDEATRAS,
    CARROVERDEFRENTE,
    CARROAZULIZQ,
    CARROAZULDER,
    CARROAZULATRAS,
    CARROAZULFRENTE,
    CARROBLANCOIZQ,
    CARROBLANCODER,
    CARROBLANCOATRAS,
    CARROBLANCOFRENTE,
    CARRONEGROIZQ,
    CARRONEGRODER,
    CARRONEGROATRAS,
    CARRONEGROFRENTE,
    CARROAMARILLOIZQ,
    CARROAMARILLODER,
    CARROAMARILLOATRAS,
    CARROAMARILLOFRENTE
} EnumImagenes;


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

