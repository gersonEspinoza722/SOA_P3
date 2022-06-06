#ifndef CONTROLADOR_H
#define CONTROLADOR_H
#include<cairo.h>
#include<gtk/gtk.h>
#include<gdk-pixbuf/gdk-pixbuf.h>

void on_window_main_destroy(GtkWidget *widget, gpointer datosUsuario);
void on_press_boton_crear_carro_aleatorio(GtkWidget *widget, gpointer datosUsuario);
void boton_crear_carro_configurado(GtkWidget *widget, gpointer datosUsuario);
void on_press_boton_crear_bus_azul(GtkWidget *widget, gpointer datosUsuario);
void on_press_boton_borrar_bus_azul(GtkWidget *widget, gpointer datosUsuario);
void activar_todos_buses();
#endif /* CONTROLADOR_H */