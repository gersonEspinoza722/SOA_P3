#ifndef CONTROLLER_H
#define CONTROLLER_H
#include<cairo.h>
#include<gtk/gtk.h>
#include<gdk-pixbuf/gdk-pixbuf.h>

void on_window_main_destroy(GtkWidget *widget, gpointer user_data);
void on_press_btn_create_car_aleatory(GtkWidget *widget, gpointer user_data);
void btn_create_car_config(GtkWidget *widget, gpointer user_data);
void on_press_btn_create_bus_blue(GtkWidget *widget, gpointer user_data);
void on_press_btn_delete_bus_blue(GtkWidget *widget, gpointer user_data);
void active_all_buses();
#endif /* CONTROLLER_H */