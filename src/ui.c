#include"ui.h"
#include<gtk/gtk.h>
#include<gdk-pixbuf/gdk-pixbuf.h>
#include<cairo.h>
#include<pthread.h>
#include<string.h>
#include"dict.h"
#include"lista_enlazada_carros.h"
#include "utils.h"


//#define TAMANIO 68 //Cantidad de elementos en el enum de ui.h
#define min(a, b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })

//Variables para calcular la respuesta rapidamente
static struct DataItem *hashImagenes[TAMANIO];
static struct NodoData *semaforos[5];
static int antesHeight = 0;
static int antesWidth = 0;
static int mapaHeight = 0;
static int mapaWidth = 0;
static NodoT *listaVehiculos = NULL;
static gint64 ultimoTick = 0;
static int fps = 60;
static pthread_mutex_t lockVehiculo;
static pthread_mutex_t lockSemaforo;

//Definition of functions
struct DataItem *crear_item(char *pathImagen, EnumImagenes tipoItem, float heightReal, float widthReal);

GdkPixbuf *transformar_imagen(GdkPixbuf *mapaImagen, float hReal, float wReal, int heightActual, int widthActual);

GdkPixbuf *transformar_relacion_imagen(GdkPixbuf *imagen, float hReal, float wReal, int heightActual, int widthActual);

void pintar_todo_mapa(cairo_t *cr);

void pintar_vehiculos(cairo_t *cr);

NodoData *crear_semaforo(EnumImagenes tipoImagenP, float x, float y);

void generar_semaforos();

//Funciones
void cargar_interfaz() {
    //MAPA
    cargar_interfaz_new(hashImagenes);
    if (pthread_mutex_init(&lockVehiculo, NULL) != 0) {
        
        printf("\n Init del mutex del vehiculo fallo\n");
    }
    if (pthread_mutex_init(&lockSemaforo, NULL) != 0) {
        printf("\n Init del mutex del semaforo fallo\n");
    }
    
    generar_semaforos();
}

void generar_semaforos() {
    semaforos[0] = crear_semaforo(SEMAFOROABAJO, 0.200, 0.42);
    semaforos[1] = crear_semaforo(SEMAFOROABAJO, 0.340, 0.42);
    semaforos[2] = crear_semaforo(SEMAFOROABAJO, 0.480, 0.42);
    semaforos[3] = crear_semaforo(SEMAFOROABAJO, 0.621, 0.42);
    semaforos[4] = crear_semaforo(SEMAFOROABAJO, 0.762, 0.42);
}

NodoData *crear_semaforo(EnumImagenes tipoImagenP, float x, float y) {
    struct NodoData *data = (struct NodoData *) malloc(sizeof(struct NodoData));

    //Data para dibujar imagenes
    data->width = x;
    data->height = y;
    data->tipoImagen = tipoImagenP;
    return data;
}

void pintar_semaforos(cairo_t *cr) {
    struct DataItem *item = NULL;

    for (int i = 0; i < 5; ++i) {
        item = search(semaforos[i]->tipoImagen, hashImagenes, TAMANIO);
        gdk_cairo_set_source_pixbuf(cr, item->imagen_trans, semaforos[i]->width * mapaWidth, semaforos[i]->height * mapaHeight);
        cairo_paint(cr);
    }
}

void pintar_vehiculos(cairo_t *cr) {
    if (listaVehiculos == NULL) {
        return;
    }

    struct DataItem *item = NULL;
    NodoT *actual = listaVehiculos;
    while (actual != NULL) {
        //Dibujar vehiculo
        item = search(actual->data->tipoImagen, hashImagenes, TAMANIO);
        gdk_cairo_set_source_pixbuf(cr, item->imagen_trans,  actual->data->width * mapaWidth, actual->data->height * mapaHeight);
        cairo_paint(cr);
        //Posicion del texto
        int total_h = item->h_real * mapaHeight;
        int total_w = item->w_real * mapaWidth;
        //Escribir texto para el vehiculo
        // cairo_move_to(cr, actual->data->width * mapaWidth, actual->data->height * mapaHeight + (1.3 * (total_h) / 2));

        cairo_set_font_size(cr, (0.6) * min(total_w, total_h));

        cairo_set_source_rgb(cr, 0.0, 0.0, 0.0);
        cairo_move_to(cr, actual->data->width * mapaWidth, actual->data->height * mapaHeight + (1.3 * (total_h) / 2));
        cairo_text_path(cr, actual->data->siguienteParada);
        cairo_stroke(cr);

        cairo_set_source_rgb(cr, 255.0, 255.0, 255.0);
        cairo_move_to(cr, actual->data->width * mapaWidth, actual->data->height * mapaHeight + (1.3 * (total_h) / 2));
        cairo_show_text(cr, actual->data->siguienteParada);
        cairo_fill(cr);
        //Siguiente elemento
        actual = actual->siguiente;
    }

}

void pintar_todo_mapa(cairo_t *cr) {
    struct DataItem *item = search(MAPA, hashImagenes, TAMANIO);
    gdk_cairo_set_source_pixbuf(cr, item->imagen_trans, 0, 0);
    cairo_paint(cr);
    pintar_semaforos(cr);
    pintar_vehiculos(cr);
}



//Llamada cada n FPS
gboolean on_tick(gpointer *parametros) {
    GtkWidget *drawing = (GtkWidget *) parametros;
    gint64 actual = g_get_real_time();
    if ((actual - ultimoTick) < (1000 / fps)) {
        ultimoTick = actual;
        return G_SOURCE_CONTINUE;
    }

    //Posible error de semaforos
    gtk_widget_queue_draw_area(drawing, 0, 0, antesWidth, antesHeight);

    ultimoTick = actual;
    return G_SOURCE_CONTINUE;
}

GdkPixbuf *transformar_imagen(GdkPixbuf *imagen, float hReal, float wReal, int heightActual, int widthActual) {
    GdkPixbuf *imagenFinal = gdk_pixbuf_scale_simple(imagen, wReal * widthActual, hReal * heightActual, GDK_INTERP_BILINEAR);
    return imagenFinal;
}

GdkPixbuf *transformar_relacion_imagen(GdkPixbuf *imagen, float hReal, float wReal, int heightActual, int widthActual) {
    int w, h;
    w = gdk_pixbuf_get_width(imagen);
    h = gdk_pixbuf_get_height(imagen);

    int tentatibe_width = wReal * widthActual;
    int tentatibe_height = wReal * (int) ((((float) h / (float) w) * (float) widthActual) * (float) wReal);

    GdkPixbuf *imagenFinal = NULL;

    if (tentatibe_height <= heightActual) {
        imagenFinal = gdk_pixbuf_scale_simple(imagen, tentatibe_width,
                                              (int) ((((float) h / (float) w) * (float) widthActual) * (float) wReal),
                                              GDK_INTERP_BILINEAR);
    } else {
        imagenFinal = gdk_pixbuf_scale_simple(imagen,
                                              (int) ((((float) w / (float) h) * (float) heightActual) *
                                                     (float) hReal),
                                              hReal * heightActual, GDK_INTERP_BILINEAR);
    }

    return imagenFinal;
}

gboolean on_window_draw(GtkWidget *widget, cairo_t *cr, gpointer datosUsuario) {
    int heightActual = gtk_widget_get_allocated_height(widget);
    int widthActual = gtk_widget_get_allocated_width(widget);
    int flat = 0;

    //Posible error de semaforos
    if (antesHeight != heightActual) {
        antesHeight = heightActual;
        flat = 1;
    }
    if (antesWidth != widthActual) {
        antesWidth = widthActual;\
        flat = 1;
    }

    if (flat == 1) {

        //Moe responsive
        struct DataItem *item_map = search(MAPA, hashImagenes, TAMANIO);
        item_map->imagen_trans = transformar_relacion_imagen(item_map->imagen, item_map->h_real, item_map->w_real,
                                                         antesHeight, antesWidth);
        mapaHeight = gdk_pixbuf_get_height(item_map->imagen_trans);
        mapaWidth = gdk_pixbuf_get_width(item_map->imagen_trans);

        //Todas las imagenes responsive en el mapa
        for (int i = 0; i < TAMANIO; i++) {
            if (i != MAPA) {
                if (hashImagenes[i] != NULL) {
                    if (hashImagenes[i]->imagen_trans != NULL) {
                        g_object_unref(hashImagenes[i]->imagen_trans);
                    }
                    hashImagenes[i]->imagen_trans = transformar_imagen(hashImagenes[i]->imagen,  hashImagenes[i]->h_real,
                                                                 hashImagenes[i]->w_real, mapaHeight, mapaWidth);
                }
            }
        }
    }
    pthread_mutex_lock(&lockVehiculo);
    pthread_mutex_lock(&lockSemaforo);
    pintar_todo_mapa(cr);
    pthread_mutex_unlock(&lockSemaforo);
    pthread_mutex_unlock(&lockVehiculo);
    return TRUE;
}

NodoT *crear_objeto(int num, EnumImagenes tipoImagenP, double x, double y, char *siguienteParadaP) {
    struct NodoData *data = (struct NodoData *) malloc(sizeof(struct NodoData));

    //Data para dibujar imagenes
    data->width = x;
    data->height = y;
    data->tipoImagen = tipoImagenP;
    strcpy(data->siguienteParada, siguienteParadaP);

    pthread_mutex_lock(&lockVehiculo);
    listaVehiculos = iniciar_push(listaVehiculos, num, data);
    pthread_mutex_unlock(&lockVehiculo);
    fflush(stdout);
    return listaVehiculos;
}

void borrar_objeto(int num) {
    pthread_mutex_lock(&lockVehiculo);
    if (listaVehiculos == NULL) {
        pthread_mutex_unlock(&lockVehiculo);
        return;
    }

    listaVehiculos = remover_por_valor(listaVehiculos, num);
    pthread_mutex_unlock(&lockVehiculo);
}

void editar_objeto(int num, EnumImagenes tipoImagenP, float xP, float yP, char *siguienteParadaP) {
    pthread_mutex_lock(&lockVehiculo);
    NodoT *actual = listaVehiculos;
    while (actual != NULL) {
        if (actual->valor == num) {
            actual->data->width = xP;
            actual->data->height = yP;
            actual->data->tipoImagen = tipoImagenP;
            strcpy(actual->data->siguienteParada, siguienteParadaP);
            break;
        }
        actual = actual->siguiente;
    }
    pthread_mutex_unlock(&lockVehiculo);
}

void editar_semaforo(int num, EnumImagenes tipoImagenP) {
    if (num >= 0 && num < 5) {
        pthread_mutex_lock(&lockSemaforo);
        semaforos[num]->tipoImagen = tipoImagenP;
        pthread_mutex_unlock(&lockSemaforo);
    }
}

void editar_objeto_con_nodo(NodoT *node, EnumImagenes tipoImagenP, float xP, float yP, char *siguienteParadaP) {
    fflush(stdout);
    pthread_mutex_lock(&lockVehiculo);
    node->data->width = xP;
    node->data->height = yP;
    node->data->tipoImagen = tipoImagenP;
    strcpy(node->data->siguienteParada, siguienteParadaP);
    pthread_mutex_unlock(&lockVehiculo);
}

EnumImagenes imagen_tipo_vehiculo(TipoVehiculo tipo, DireccionCalle direccion) {
    switch (tipo) {
        case BUS_ROJO:
            switch (direccion) {
                case DIR_NORTE:
                    return BUSROJOATRAS;
                case DIR_SUR:
                    return BUSROJOFRENTE;
                case DIR_OESTE:
                    return BUSROJOIZQ;
                case DIR_ESTE:
                    return BUSROJODER;
            }
            break;
        case BUS_VERDE:
            switch (direccion) {
                case DIR_NORTE:
                    return BUSVERDEATRAS;
                case DIR_SUR:
                    return BUSVERDEFRENTE;
                case DIR_OESTE:
                    return BUSVERDEIZQ;
                case DIR_ESTE:
                    return BUSVERDEDER;
            }
            break;
        case BUS_AZUL:
            switch (direccion) {
                case DIR_NORTE:
                    return BUSAZULATRAS;
                case DIR_SUR:
                    return BUSAZULFRENTE;
                case DIR_OESTE:
                    return BUSAZULIZQ;
                case DIR_ESTE:
                    return BUSAZULDER;
            }
            break;
        case BUS_BLANCO:
            switch (direccion) {
                case DIR_NORTE:
                    return BUSBLANCOATRAS;
                case DIR_SUR:
                    return BUSBLANCOFRENTE;
                case DIR_OESTE:
                    return BUSBLANCOIZQ;
                case DIR_ESTE:
                    return BUSBLANCODER;
            }
            break;
        case BUS_GRIS:
            switch (direccion) {
                case DIR_NORTE:
                    return BUSGRISATRAS;
                case DIR_SUR:
                    return BUSGRISFRENTE;
                case DIR_OESTE:
                    return BUSGRISIZQ;
                case DIR_ESTE:
                    return BUSGRISDER;
            }
            break;
        case BUS_NEGRO:
            switch (direccion) {
                case DIR_NORTE:
                    return BUSNEGROATRAS;
                case DIR_SUR:
                    return BUSNEGROFRENTE;
                case DIR_OESTE:
                    return BUSNEGROIZQ;
                case DIR_ESTE:
                    return BUSNEGRODER;
            }
            break;
        case BUS_ROSADO:
            switch (direccion) {
                case DIR_NORTE:
                    return BUSROSADOATRAS;
                case DIR_SUR:
                    return BUSROSADOFRENTE;
                case DIR_OESTE:
                    return BUSROSADOIZQ;
                case DIR_ESTE:
                    return BUSROSADODER;
            }
            break;
        case BUS_CELESTE:
            switch (direccion) {
                case DIR_NORTE:
                    return BUSCELESTEATRAS;
                case DIR_SUR:
                    return BUSCELESTEFRENTE;
                case DIR_OESTE:
                    return BUSCELESTEIZQ;
                case DIR_ESTE:
                    return BUSCELESTEDER;
            }
            break;
        case BUS_NARANJA:
            switch (direccion) {
                case DIR_NORTE:
                    return BUSNARANJAATRAS;
                case DIR_SUR:
                    return BUSNARANJAFRENTE;
                case DIR_OESTE:
                    return BUSNARANJAIZQ;
                case DIR_ESTE:
                    return BUSNARANJADER;
            }
            break;
        case AMBULANCIA:
            switch (direccion) {
                case DIR_NORTE:
                    return AMBULANCIAATRAS;
                case DIR_SUR:
                    return AMBULANCIAFRENTE;
                case DIR_OESTE:
                    return AMBULANCIAIZQ;
                case DIR_ESTE:
                    return AMBULANCIADER;
            }
            break;
        case CARRO_ROJO:
            switch (direccion) {
                case DIR_NORTE:
                    return CARROROJOATRAS;
                case DIR_SUR:
                    return CARROROJOFRENTE;
                case DIR_OESTE:
                    return CARROROJOIZQ;
                case DIR_ESTE:
                    return CARROROJODER;
            }
            break;
        case CARRO_AZUL:
            switch (direccion) {
                case DIR_NORTE:
                    return CARROAZULATRAS;
                case DIR_SUR:
                    return CARROAZULFRENTE;
                case DIR_OESTE:
                    return CARROAZULIZQ;
                case DIR_ESTE:
                    return CARROAZULDER;
            }
            break;
        case CARRO_VERDE:
            switch (direccion) {
                case DIR_NORTE:
                    return CARROVERDEATRAS;
                case DIR_SUR:
                    return CARROVERDEFRENTE;
                case DIR_OESTE:
                    return CARROVERDEIZQ;
                case DIR_ESTE:
                    return CARROVERDEDER;
            }
            break;
        case CARRO_NEGRO:
            switch (direccion) {
                case DIR_NORTE:
                    return CARRONEGROATRAS;
                case DIR_SUR:
                    return CARRONEGROFRENTE;
                case DIR_OESTE:
                    return CARRONEGROIZQ;
                case DIR_ESTE:
                    return CARRONEGRODER;
            }
            break;
        case CARRO_BLANCO:
            switch (direccion) {
                case DIR_NORTE:
                    return CARROBLANCOATRAS;
                case DIR_SUR:
                    return CARROBLANCOFRENTE;
                case DIR_OESTE:
                    return CARROBLANCOIZQ;
                case DIR_ESTE:
                    return CARROBLANCODER;
            }
            break;
        case CARRO_AMARILLO:
            switch (direccion) {
                case DIR_NORTE:
                    return CARROAMARILLOATRAS;
                case DIR_SUR:
                    return CARROAMARILLOFRENTE;
                case DIR_OESTE:
                    return CARROAMARILLOIZQ;
                case DIR_ESTE:
                    return CARROAMARILLODER;
            }
            break;
    }

    return 0;
}


void imprimir_bienvenida(){
    printf("SIMULACIÓN INICIADA \n");
}

