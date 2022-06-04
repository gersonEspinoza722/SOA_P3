#include"lista_enlazada_carros.h"
#include "utils.h"

#ifndef INTERFACE_H
#define INTERFACE_H

#include<gtk/gtk.h>
#include<gdk-pixbuf/gdk-pixbuf.h>
#include<cairo.h>
#include<stdio.h>
#include <vehiculo.h>


typedef enum {
    MAP,
    SEMAPHOREU,
    SEMAPHORED,
    REPAIR,
    REDBUSL,
    REDBUSR,
    REDBUSB,
    REDBUSF,
    GREENBUSL,
    GREENBUSR,
    GREENBUSB,
    GREENBUSF,
    BLUEBUSL,
    BLUEBUSR,
    BLUEBUSB,
    BLUEBUSF,
    WHITEBUSL,
    WHITEBUSR,
    WHITEBUSB,
    WHITEBUSF,
    GRAYBUSL,
    GRAYBUSR,
    GRAYBUSB,
    GRAYBUSF,
    BLACKBUSL,
    BLACKBUSR,
    BLACKBUSB,
    BLACKBUSF,
    PINKBUSL,
    PINKBUSR,
    PINKBUSB,
    PINKBUSF,
    LIGHTBLUEBUSL,
    LIGHTBLUEBUSR,
    LIGHTBLUEBUSB,
    LIGHTBLUEBUSF,
    ORANGEBUSL,
    ORANGEBUSR,
    ORANGEBUSB,
    ORANGEBUSF,
    AMBULANCEL,
    AMBULANCER,
    AMBULANCEB,
    AMBULANCEF,
    REDCARL,
    REDCARR,
    REDCARB,
    REDCARF,
    GREENCARL,
    GREENCARR,
    GREENCARB,
    GREENCARF,
    BLUECARL,
    BLUECARR,
    BLUECARB,
    BLUECARF,
    WHITECARL,
    WHITECARR,
    WHITECARB,
    WHITECARF,
    BLACKCARL,
    BLACKCARR,
    BLACKCARB,
    BLACKCARF,
    YELLOWCARL,
    YELLOWCARR,
    YELLOWCARB,
    YELLOWCARF
} images_enum;


void print_wellcome();

void load_interface();

gboolean on_window_draw(GtkWidget *widget, cairo_t *cr, gpointer datosUsuario);

gboolean on_tick(gpointer *parameters);

NodoT *create_object(int num, images_enum type_image_p, double x, double y, char *next_stop_p);

void delete_object(int num);

void edit_object(int num, images_enum type_image_p, float x_p, float y_p, char *next_stop_p);

void edit_object_with_node(NodoT *node, images_enum type_image_p, float x_p, float y_p, char *next_stop_p);

void edit_semaphore(int num, images_enum type_image_p);

images_enum from_vehicle_type(TipoVehiculo tipo, DireccionCalle direccion);

#endif /* INTERFACE_H */

