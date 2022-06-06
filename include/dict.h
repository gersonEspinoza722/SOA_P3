#ifndef DICT_H
#define DICT_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<cairo.h>
#include<gtk/gtk.h>
#include<gdk-pixbuf/gdk-pixbuf.h>

struct DataItem {
  int llave;
  int width;
  int height;
  float h_real;
  float w_real;
  GdkPixbuf *imagen;
  GdkPixbuf *imagen_trans;
};

int hashCode(int llave, int tamanio);

struct DataItem *search(int llave, struct DataItem* hashArray[], int tamanio);

void insertar_dict(int llave, struct DataItem *item, struct DataItem **hashArray, int tamanio);

#endif /* DICT */
