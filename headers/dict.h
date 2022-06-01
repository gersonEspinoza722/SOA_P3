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
  int key;
  int width;
  int height;
  float real_h;
  float real_w;
  GdkPixbuf *image;
  GdkPixbuf *trans_image;
};

int hashCode(int key, int size);

struct DataItem *search(int key, struct DataItem* hashArray[], int size);

void insertDict(int key, struct DataItem *item, struct DataItem **hashArray, int size);

#endif /* DICT */
