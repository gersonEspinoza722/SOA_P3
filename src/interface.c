#include"interface.h"
#include<gtk/gtk.h>
#include<gdk-pixbuf/gdk-pixbuf.h>
#include<cairo.h>
#include<pthread.h>
#include<string.h>
#include"dict.h"
#include"linked_list_cars.h"
#include "utils.h"


#define SIZE 68 //Number is the same of the len in the enum in interface.h
#define min(a, b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })

//Variables to calculate the responsive in a quick time
static struct DataItem *hashImages[SIZE];
static struct data_node *semaphores[5];
static int before_height = 0;
static int before_width = 0;
static int map_height = 0;
static int map_width = 0;
static node_t *vehicle_list = NULL;
static gint64 last_tick = 0;
static int fps = 60;
static pthread_mutex_t lock_vehicle;
static pthread_mutex_t lock_semaphore;

//Definition of functions
struct DataItem *create_item(char *image_path, images_enum type_item, float real_height, float real_width);

GdkPixbuf *transform_image(GdkPixbuf *map_image, float h_real, float w_real, int actual_height, int actual_width);

GdkPixbuf *transform_image_relation(GdkPixbuf *imagen, float h_real, float w_real, int actual_height, int actual_width);

void paint_all_map(cairo_t *cr);

void paint_vehicles(cairo_t *cr);

data_node *create_semaphore(images_enum type_image_p, float x, float y);

void generate_semaphores();

//Funtions code
void load_interface() {
    //MAP load
    insertar_dict(MAP, create_item("images/MAP.png", MAP, 0.5, 1.0), hashImages, SIZE);
    //SEMAPHORE load
    insertar_dict(SEMAPHORED, create_item("images/SD.png", SEMAPHORED, 0.16, 0.020), hashImages, SIZE);
    insertar_dict(SEMAPHOREU, create_item("images/SU.png", SEMAPHOREU, 0.16, 0.020), hashImages, SIZE);
    //REPAIR load
    insertar_dict(REPAIR, create_item("images/REPAIR.jpg", REPAIR, 0.025, 0.015), hashImages, SIZE);
    //Red bus load
    insertar_dict(REDBUSL, create_item("images/RED_BL.png", REDBUSL, 0.025, 0.030), hashImages, SIZE);
    insertar_dict(REDBUSR, create_item("images/RED_BR.png", REDBUSR, 0.025, 0.030), hashImages, SIZE);
    insertar_dict(REDBUSB, create_item("images/RED_BB.png", REDBUSB, 0.050, 0.015), hashImages, SIZE);
    insertar_dict(REDBUSF, create_item("images/RED_BF.png", REDBUSF, 0.050, 0.015), hashImages, SIZE);
    //Grenn bus load
    insertar_dict(GREENBUSL, create_item("images/GREEN_BL.png", GREENBUSL, 0.025, 0.030), hashImages, SIZE);
    insertar_dict(GREENBUSR, create_item("images/GREEN_BR.png", GREENBUSR, 0.025, 0.030), hashImages, SIZE);
    insertar_dict(GREENBUSB, create_item("images/GREEN_BB.png", GREENBUSB, 0.050, 0.015), hashImages, SIZE);
    insertar_dict(GREENBUSF, create_item("images/GREEN_BF.png", GREENBUSF, 0.050, 0.015), hashImages, SIZE);
    //Blue bus load
    insertar_dict(BLUEBUSL, create_item("images/BLUE_BL.png", BLUEBUSL, 0.025, 0.030), hashImages, SIZE);
    insertar_dict(BLUEBUSR, create_item("images/BLUE_BR.png", BLUEBUSR, 0.025, 0.030), hashImages, SIZE);
    insertar_dict(BLUEBUSB, create_item("images/BLUE_BB.png", BLUEBUSB, 0.050, 0.015), hashImages, SIZE);
    insertar_dict(BLUEBUSF, create_item("images/BLUE_BF.png", BLUEBUSF, 0.050, 0.015), hashImages, SIZE);
    //White busload    
    insertar_dict(WHITEBUSL, create_item("images/WHITE_BL.png", WHITEBUSL, 0.025, 0.030), hashImages, SIZE);
    insertar_dict(WHITEBUSR, create_item("images/WHITE_BR.png", WHITEBUSR, 0.025, 0.030), hashImages, SIZE);
    insertar_dict(WHITEBUSB, create_item("images/WHITE_BB.png", WHITEBUSB, 0.050, 0.015), hashImages, SIZE);
    insertar_dict(WHITEBUSF, create_item("images/WHITE_BF.png", WHITEBUSF, 0.050, 0.015), hashImages, SIZE);
    //Gray bus load
    insertar_dict(GRAYBUSL, create_item("images/GRAY_BL.png", GRAYBUSL, 0.025, 0.030), hashImages, SIZE);
    insertar_dict(GRAYBUSR, create_item("images/GRAY_BR.png", GRAYBUSR, 0.025, 0.030), hashImages, SIZE);
    insertar_dict(GRAYBUSB, create_item("images/GRAY_BB.png", GRAYBUSB, 0.050, 0.015), hashImages, SIZE);
    insertar_dict(GRAYBUSF, create_item("images/GRAY_BF.png", GRAYBUSF, 0.050, 0.015), hashImages, SIZE);
    //Black bus load
    insertar_dict(BLACKBUSL, create_item("images/BLACK_BL.png", BLACKBUSL, 0.025, 0.030), hashImages, SIZE);
    insertar_dict(BLACKBUSR, create_item("images/BLACK_BR.png", BLACKBUSR, 0.025, 0.030), hashImages, SIZE);
    insertar_dict(BLACKBUSB, create_item("images/BLACK_BB.png", BLACKBUSB, 0.050, 0.015), hashImages, SIZE);
    insertar_dict(BLACKBUSF, create_item("images/BLACK_BF.png", BLACKBUSF, 0.050, 0.015), hashImages, SIZE);
    //Pink bus load
    insertar_dict(PINKBUSL, create_item("images/PINK_BL.png", PINKBUSL, 0.025, 0.030), hashImages, SIZE);
    insertar_dict(PINKBUSR, create_item("images/PINK_BR.png", PINKBUSR, 0.025, 0.030), hashImages, SIZE);
    insertar_dict(PINKBUSB, create_item("images/PINK_BB.png", PINKBUSB, 0.050, 0.015), hashImages, SIZE);
    insertar_dict(PINKBUSF, create_item("images/PINK_BF.png", PINKBUSF, 0.050, 0.015), hashImages, SIZE);
    //Ligth blue bus load
    insertar_dict(LIGHTBLUEBUSL, create_item("images/LBLUE_BL.png", LIGHTBLUEBUSL, 0.025, 0.030), hashImages, SIZE);
    insertar_dict(LIGHTBLUEBUSR, create_item("images/LBLUE_BR.png", LIGHTBLUEBUSR, 0.025, 0.030), hashImages, SIZE);
    insertar_dict(LIGHTBLUEBUSB, create_item("images/LBLUE_BB.png", LIGHTBLUEBUSB, 0.050, 0.015), hashImages, SIZE);
    insertar_dict(LIGHTBLUEBUSF, create_item("images/LBLUE_BF.png", LIGHTBLUEBUSF, 0.050, 0.015), hashImages, SIZE);
    //Orange bus load  
    insertar_dict(ORANGEBUSL, create_item("images/ORANGE_BL.png", ORANGEBUSL, 0.025, 0.030), hashImages, SIZE);
    insertar_dict(ORANGEBUSR, create_item("images/ORANGE_BR.png", ORANGEBUSR, 0.025, 0.030), hashImages, SIZE);
    insertar_dict(ORANGEBUSB, create_item("images/ORANGE_BB.png", ORANGEBUSB, 0.050, 0.015), hashImages, SIZE);
    insertar_dict(ORANGEBUSF, create_item("images/ORANGE_BF.png", ORANGEBUSF, 0.050, 0.015), hashImages, SIZE);
    //Ambulance load
    insertar_dict(AMBULANCEL, create_item("images/AMBULANCEL.png", AMBULANCEL, 0.025, 0.015), hashImages, SIZE);
    insertar_dict(AMBULANCER, create_item("images/AMBULANCER.png", AMBULANCER, 0.025, 0.015), hashImages, SIZE);
    insertar_dict(AMBULANCEB, create_item("images/AMBULANCEB.png", AMBULANCEB, 0.025, 0.015), hashImages, SIZE);
    insertar_dict(AMBULANCEF, create_item("images/AMBULANCEF.png", AMBULANCEF, 0.025, 0.015), hashImages, SIZE);
    //Red car load  
    insertar_dict(REDCARL, create_item("images/REDL.jpg", REDCARL, 0.025, 0.015), hashImages, SIZE);
    insertar_dict(REDCARR, create_item("images/REDR.jpg", REDCARR, 0.025, 0.015), hashImages, SIZE);
    insertar_dict(REDCARB, create_item("images/REDB.jpg", REDCARB, 0.025, 0.015), hashImages, SIZE);
    insertar_dict(REDCARF, create_item("images/REDF.jpg", REDCARF, 0.025, 0.015), hashImages, SIZE);
    //Green car load    
    insertar_dict(GREENCARL, create_item("images/GREENL.png", GREENCARL, 0.025, 0.015), hashImages, SIZE);
    insertar_dict(GREENCARR, create_item("images/GREENR.png", GREENCARR, 0.025, 0.015), hashImages, SIZE);
    insertar_dict(GREENCARB, create_item("images/GREENB.png", GREENCARB, 0.025, 0.015), hashImages, SIZE);
    insertar_dict(GREENCARF, create_item("images/GREENF.png", GREENCARF, 0.025, 0.015), hashImages, SIZE);
    //Blue car load
    insertar_dict(BLUECARL, create_item("images/BLUEL.jpg", BLUECARL, 0.025, 0.015), hashImages, SIZE);
    insertar_dict(BLUECARR, create_item("images/BLUER.jpg", BLUECARR, 0.025, 0.015), hashImages, SIZE);
    insertar_dict(BLUECARB, create_item("images/BLUEB.jpg", BLUECARB, 0.025, 0.015), hashImages, SIZE);
    insertar_dict(BLUECARF, create_item("images/BLUEF.jpg", BLUECARF, 0.025, 0.015), hashImages, SIZE);
    //White car load
    insertar_dict(WHITECARL, create_item("images/WHITEL.jpg", WHITECARL, 0.025, 0.015), hashImages, SIZE);
    insertar_dict(WHITECARR, create_item("images/WHITER.jpg", WHITECARR, 0.025, 0.015), hashImages, SIZE);
    insertar_dict(WHITECARB, create_item("images/WHITEB.jpg", WHITECARB, 0.025, 0.015), hashImages, SIZE);
    insertar_dict(WHITECARF, create_item("images/WHITEF.jpg", WHITECARF, 0.025, 0.015), hashImages, SIZE);
    //Black car load    
    insertar_dict(BLACKCARL, create_item("images/BLACKL.jpg", BLACKCARL, 0.025, 0.015), hashImages, SIZE);
    insertar_dict(BLACKCARR, create_item("images/BLACKR.jpg", BLACKCARR, 0.025, 0.015), hashImages, SIZE);
    insertar_dict(BLACKCARB, create_item("images/BLACKB.jpg", BLACKCARB, 0.025, 0.015), hashImages, SIZE);
    insertar_dict(BLACKCARF, create_item("images/BLACKF.jpg", BLACKCARF, 0.025, 0.015), hashImages, SIZE);
    //Yellow car load
    insertar_dict(YELLOWCARL, create_item("images/YELLOWL.jpg", YELLOWCARL, 0.025, 0.015), hashImages, SIZE);
    insertar_dict(YELLOWCARR, create_item("images/YELLOWR.jpg", YELLOWCARR, 0.025, 0.015), hashImages, SIZE);
    insertar_dict(YELLOWCARB, create_item("images/YELLOWB.jpg", YELLOWCARB, 0.025, 0.015), hashImages, SIZE);
    insertar_dict(YELLOWCARF, create_item("images/YELLOWF.jpg", YELLOWCARF, 0.025, 0.015), hashImages, SIZE);


    if (pthread_mutex_init(&lock_vehicle, NULL) != 0) {
        printf("\n Mutex of vehiculo init failed\n");
    }
    if (pthread_mutex_init(&lock_semaphore, NULL) != 0) {
        printf("\n Mutex of semaphore init failed\n");
    }
    //Generate semaphores
    generate_semaphores();
}

void generate_semaphores() {
    semaphores[0] = create_semaphore(SEMAPHORED, 0.211, 0.42);
    semaphores[1] = create_semaphore(SEMAPHORED, 0.351, 0.42);
    semaphores[2] = create_semaphore(SEMAPHORED, 0.491, 0.42);
    semaphores[3] = create_semaphore(SEMAPHORED, 0.632, 0.42);
    semaphores[4] = create_semaphore(SEMAPHORED, 0.773, 0.42);
}

data_node *create_semaphore(images_enum type_image_p, float x, float y) {
    struct data_node *data_add = (struct data_node *) malloc(sizeof(struct data_node));

    //Data to draw images
    data_add->width = x;
    data_add->height = y;
    data_add->type_image = type_image_p;
    return data_add;
}

void paint_semaphores(cairo_t *cr) {
    struct DataItem *item = NULL;

    for (int i = 0; i < 5; ++i) {
        item = search(semaphores[i]->type_image, hashImages, SIZE);
        gdk_cairo_set_source_pixbuf(cr,
                                    item->imagen_trans,
                                    semaphores[i]->width * map_width,
                                    semaphores[i]->height * map_height);
        cairo_paint(cr);
    }
}

void paint_vehicles(cairo_t *cr) {
    if (vehicle_list == NULL) {
        return;
    }

    struct DataItem *item = NULL;
    node_t *current = vehicle_list;
    while (current != NULL) {
        //Draw vehicule
        item = search(current->data->type_image, hashImages, SIZE);
        gdk_cairo_set_source_pixbuf(cr,
                                    item->imagen_trans,
                                    current->data->width * map_width,
                                    current->data->height * map_height);
        cairo_paint(cr);
        //Pos of text 
        int total_h = item->h_real * map_height;
        int total_w = item->w_real * map_width;
        //Write text for vehicule
        // cairo_move_to(cr, current->data->width * map_width, current->data->height * map_height + (1.3 * (total_h) / 2));

        cairo_set_font_size(cr, (0.80) * min(total_w, total_h));

        cairo_set_source_rgb(cr, 0.0, 0.0, 0.0);
        cairo_move_to(cr, current->data->width * map_width, current->data->height * map_height + (1.3 * (total_h) / 2));
        cairo_text_path(cr, current->data->next_stop);
        cairo_stroke(cr);

        cairo_set_source_rgb(cr, 255.0, 255.0, 255.0);
        cairo_move_to(cr, current->data->width * map_width, current->data->height * map_height + (1.3 * (total_h) / 2));
        cairo_show_text(cr, current->data->next_stop);
        cairo_fill(cr);
        //Next element
        current = current->next;
    }

}

void paint_all_map(cairo_t *cr) {
    struct DataItem *item = search(MAP, hashImages, SIZE);
    gdk_cairo_set_source_pixbuf(cr, item->imagen_trans, 0, 0);
    cairo_paint(cr);
    paint_semaphores(cr);
    paint_vehicles(cr);
}

struct DataItem *create_item(char *image_path, images_enum type_item, float real_height, float real_width) {
    GError *err = NULL;
    struct DataItem *item = (struct DataItem *) malloc(sizeof(struct DataItem));
    if (err) {
        printf("Error : %s\n", err->message);
        g_error_free(err);
    }
    item->llave = type_item;
    item->imagen = gdk_pixbuf_new_from_file(image_path, &err);
    item->width = gdk_pixbuf_get_width(item->imagen);
    item->height = gdk_pixbuf_get_height(item->imagen);
    item->h_real = real_height;
    item->w_real = real_width;
    item->imagen_trans = NULL;

    return item;
}

//CCall every n FPS
gboolean on_tick(gpointer *parameters) {
    GtkWidget *drawing = (GtkWidget *) parameters;
    gint64 current = g_get_real_time();
    if ((current - last_tick) < (1000 / fps)) {
        last_tick = current;
        return G_SOURCE_CONTINUE;
    }

    //Posible error de semaforos
    gtk_widget_queue_draw_area(drawing, 0, 0, before_width, before_height);

    last_tick = current;
    return G_SOURCE_CONTINUE;
}

GdkPixbuf *transform_image(GdkPixbuf *imagen, float h_real, float w_real, int actual_height, int actual_width) {
    GdkPixbuf *final_image = gdk_pixbuf_scale_simple(imagen,
                                                     w_real * actual_width,
                                                     h_real * actual_height,
                                                     GDK_INTERP_BILINEAR);

    return final_image;
}

GdkPixbuf *transform_image_relation(GdkPixbuf *imagen, float h_real, float w_real, int actual_height, int actual_width) {
    int w, h;
    w = gdk_pixbuf_get_width(imagen);
    h = gdk_pixbuf_get_height(imagen);

    int tentatibe_width = w_real * actual_width;
    int tentatibe_height = w_real * (int) ((((float) h / (float) w) * (float) actual_width) * (float) w_real);

    GdkPixbuf *final_image = NULL;

    if (tentatibe_height <= actual_height) {
        final_image = gdk_pixbuf_scale_simple(imagen,
                                              tentatibe_width,
                                              (int) ((((float) h / (float) w) * (float) actual_width) * (float) w_real),
                                              GDK_INTERP_BILINEAR);
    } else {
        final_image = gdk_pixbuf_scale_simple(imagen,
                                              (int) ((((float) w / (float) h) * (float) actual_height) *
                                                     (float) h_real),
                                              h_real * actual_height,
                                              GDK_INTERP_BILINEAR);
    }

    return final_image;
}

gboolean on_window_draw(GtkWidget *widget, cairo_t *cr, gpointer user_data) {
    int actual_height = gtk_widget_get_allocated_height(widget);
    int actual_width = gtk_widget_get_allocated_width(widget);
    int flat = 0;

    //Posible error de semaforos
    if (before_height != actual_height) {
        before_height = actual_height;
        flat = 1;
    }
    if (before_width != actual_width) {
        before_width = actual_width;\
        flat = 1;
    }

    if (flat == 1) {

        //Mao responsive
        struct DataItem *item_map = search(MAP, hashImages, SIZE);
        item_map->imagen_trans = transform_image_relation(item_map->imagen,
                                                         item_map->h_real,
                                                         item_map->w_real,
                                                         before_height,
                                                         before_width);
        map_height = gdk_pixbuf_get_height(item_map->imagen_trans);
        map_width = gdk_pixbuf_get_width(item_map->imagen_trans);

        //All imagen responsive about the mapa
        for (int i = 0; i < SIZE; i++) {
            if (i != MAP) {
                if (hashImages[i] != NULL) {
                    if (hashImages[i]->imagen_trans != NULL) {
                        g_object_unref(hashImages[i]->imagen_trans);
                    }
                    hashImages[i]->imagen_trans = transform_image(hashImages[i]->imagen,
                                                                 hashImages[i]->h_real,
                                                                 hashImages[i]->w_real,
                                                                 map_height,
                                                                 map_width);
                }
            }
        }
    }
    pthread_mutex_lock(&lock_vehicle);
    pthread_mutex_lock(&lock_semaphore);
    paint_all_map(cr);
    pthread_mutex_unlock(&lock_semaphore);
    pthread_mutex_unlock(&lock_vehicle);
    return TRUE;
}

node_t *create_object(int num, images_enum type_image_p, double x, double y, char *next_stop_p) {
    struct data_node *data_add = (struct data_node *) malloc(sizeof(struct data_node));

    //Data to draw images
    data_add->width = x;
    data_add->height = y;
    data_add->type_image = type_image_p;
    strcpy(data_add->next_stop, next_stop_p);

    pthread_mutex_lock(&lock_vehicle);
    vehicle_list = push_begin(vehicle_list, num, data_add);
    pthread_mutex_unlock(&lock_vehicle);
    fflush(stdout);
    return vehicle_list;
}

void delete_object(int num) {
    pthread_mutex_lock(&lock_vehicle);
    if (vehicle_list == NULL) {
        pthread_mutex_unlock(&lock_vehicle);
        return;
    }

    vehicle_list = remove_by_val(vehicle_list, num);
    pthread_mutex_unlock(&lock_vehicle);
}

void edit_object(int num, images_enum type_image_p, float x_p, float y_p, char *next_stop_p) {
    pthread_mutex_lock(&lock_vehicle);
    node_t *current = vehicle_list;
    while (current != NULL) {
        if (current->val == num) {
            current->data->width = x_p;
            current->data->height = y_p;
            current->data->type_image = type_image_p;
            strcpy(current->data->next_stop, next_stop_p);
            break;
        }
        current = current->next;
    }
    pthread_mutex_unlock(&lock_vehicle);
}

void edit_semaphore(int num, images_enum type_image_p) {
    if (num >= 0 && num < 5) {
        pthread_mutex_lock(&lock_semaphore);
        semaphores[num]->type_image = type_image_p;
        pthread_mutex_unlock(&lock_semaphore);
    }
}

void edit_object_with_node(node_t *node, images_enum type_image_p, float x_p, float y_p, char *next_stop_p) {
    fflush(stdout);
    pthread_mutex_lock(&lock_vehicle);
    node->data->width = x_p;
    node->data->height = y_p;
    node->data->type_image = type_image_p;
    strcpy(node->data->next_stop, next_stop_p);
    pthread_mutex_unlock(&lock_vehicle);
}

images_enum from_vehicle_type(TipoVehiculo type, StreetDir direccion) {
    switch (type) {
        case BUS_ROJO:
            switch (direccion) {
                case NORTH_DIR:
                    return REDBUSB;
                case SOUTH_DIR:
                    return REDBUSF;
                case WEST_DIR:
                    return REDBUSL;
                case EAST_DIR:
                    return REDBUSR;
            }
            break;
        case BUS_VERDE:
            switch (direccion) {
                case NORTH_DIR:
                    return GREENBUSB;
                case SOUTH_DIR:
                    return GREENBUSF;
                case WEST_DIR:
                    return GREENBUSL;
                case EAST_DIR:
                    return GREENBUSR;
            }
            break;
        case BUS_AZUL:
            switch (direccion) {
                case NORTH_DIR:
                    return BLUEBUSB;
                case SOUTH_DIR:
                    return BLUEBUSF;
                case WEST_DIR:
                    return BLUEBUSL;
                case EAST_DIR:
                    return BLUEBUSR;
            }
            break;
        case BUS_BLANCO:
            switch (direccion) {
                case NORTH_DIR:
                    return WHITEBUSB;
                case SOUTH_DIR:
                    return WHITEBUSF;
                case WEST_DIR:
                    return WHITEBUSL;
                case EAST_DIR:
                    return WHITEBUSR;
            }
            break;
        case BUS_GRIS:
            switch (direccion) {
                case NORTH_DIR:
                    return GRAYBUSB;
                case SOUTH_DIR:
                    return GRAYBUSF;
                case WEST_DIR:
                    return GRAYBUSL;
                case EAST_DIR:
                    return GRAYBUSR;
            }
            break;
        case BUS_NEGRO:
            switch (direccion) {
                case NORTH_DIR:
                    return BLACKBUSB;
                case SOUTH_DIR:
                    return BLACKBUSF;
                case WEST_DIR:
                    return BLACKBUSL;
                case EAST_DIR:
                    return BLACKBUSR;
            }
            break;
        case BUS_ROSADO:
            switch (direccion) {
                case NORTH_DIR:
                    return PINKBUSB;
                case SOUTH_DIR:
                    return PINKBUSF;
                case WEST_DIR:
                    return PINKBUSL;
                case EAST_DIR:
                    return PINKBUSR;
            }
            break;
        case BUS_CELESTE:
            switch (direccion) {
                case NORTH_DIR:
                    return LIGHTBLUEBUSB;
                case SOUTH_DIR:
                    return LIGHTBLUEBUSF;
                case WEST_DIR:
                    return LIGHTBLUEBUSL;
                case EAST_DIR:
                    return LIGHTBLUEBUSR;
            }
            break;
        case BUS_NARANJA:
            switch (direccion) {
                case NORTH_DIR:
                    return ORANGEBUSB;
                case SOUTH_DIR:
                    return ORANGEBUSF;
                case WEST_DIR:
                    return ORANGEBUSL;
                case EAST_DIR:
                    return ORANGEBUSR;
            }
            break;
        case AMBULANCIA:
            switch (direccion) {
                case NORTH_DIR:
                    return AMBULANCEB;
                case SOUTH_DIR:
                    return AMBULANCEF;
                case WEST_DIR:
                    return AMBULANCEL;
                case EAST_DIR:
                    return AMBULANCER;
            }
            break;
        case CARRO_ROJO:
            switch (direccion) {
                case NORTH_DIR:
                    return REDCARB;
                case SOUTH_DIR:
                    return REDCARF;
                case WEST_DIR:
                    return REDCARL;
                case EAST_DIR:
                    return REDCARR;
            }
            break;
        case CARRO_AZUL:
            switch (direccion) {
                case NORTH_DIR:
                    return BLUECARB;
                case SOUTH_DIR:
                    return BLUECARF;
                case WEST_DIR:
                    return BLUECARL;
                case EAST_DIR:
                    return BLUECARR;
            }
            break;
        case CARRO_VERDE:
            switch (direccion) {
                case NORTH_DIR:
                    return GREENCARB;
                case SOUTH_DIR:
                    return GREENCARF;
                case WEST_DIR:
                    return GREENCARL;
                case EAST_DIR:
                    return GREENCARR;
            }
            break;
        case CARRO_NEGRO:
            switch (direccion) {
                case NORTH_DIR:
                    return BLACKCARB;
                case SOUTH_DIR:
                    return BLACKCARF;
                case WEST_DIR:
                    return BLACKCARL;
                case EAST_DIR:
                    return BLACKCARR;
            }
            break;
        case CARRO_BLANCO:
            switch (direccion) {
                case NORTH_DIR:
                    return WHITECARB;
                case SOUTH_DIR:
                    return WHITECARF;
                case WEST_DIR:
                    return WHITECARL;
                case EAST_DIR:
                    return WHITECARR;
            }
            break;
        case CARRO_AMARILLO:
            switch (direccion) {
                case NORTH_DIR:
                    return YELLOWCARB;
                case SOUTH_DIR:
                    return YELLOWCARF;
                case WEST_DIR:
                    return YELLOWCARL;
                case EAST_DIR:
                    return YELLOWCARR;
            }
            break;
    }

    return 0;
}


void print_wellcome(){
    printf("%s\n", "  _____  _                              _            _      _      _           ");
    printf("%s\n", " |_   _|| |_      _ _   ___   __ _   __| |  __ __   (_)    | |    | |    ___   ");
    printf("%s\n", "   | |  | ' \\    | '_| / -_) / _` | / _` |  \\ V /   | |    | |    | |   / -_)  ");
    printf("%s\n", "  _|_|_ |_||_|  _|_|_  \\___| \\__,_| \\__,_|  _\\_/_  _|_|_  _|_|_  _|_|_  \\___|  ");
    printf("%s\n", "_|\"\"\"\"\"_|\"\"\"\"\"_|\"\"\"\"\"_|\"\"\"\"\"_|\"\"\"\"\"_|\"\"\"\"\"_|\"\"\"\"\"_|\"\"\"\"\"_|\"\"\"\"\"_|\"\"\"\"\"_|\"\"\"\"\"| ");
    printf("%s\n", "\"`-0-0-\"`-0-0-\"`-0-0-\"`-0-0-\"`-0-0-\"`-0-0-\"`-0-0-\"`-0-0-\"`-0-0-\"`-0-0-\"`-0-0-'");
    printf("%s\n", "    _           ");
    printf("%s\n", "   (_)    ___   ");
    printf("%s\n", "   | |   (_-<   ");
    printf("%s\n", "  _|_|_  /__/_  ");
    printf("%s\n", "_|\"\"\"\"\"_|\"\"\"\"\"| ");
    printf("%s\n", "\"`-0-0-\"`-0-0-' ");
    printf("%s\n", "          _                    _       _            __ _  ");
    printf("%s\n", "   ___   | |_   __ _     _ _  | |_    (_)   _ _    / _` | ");
    printf("%s\n", "  (_-<   |  _| / _` |   | '_| |  _|   | |  | ' \\   \\__, | ");
    printf("%s\n", "  /__/_  _\\__| \\__,_|  _|_|_  _\\__|  _|_|_ |_||_|  |___/  ");
    printf("%s\n", "_|\"\"\"\"\"_|\"\"\"\"\"_|\"\"\"\"\"_|\"\"\"\"\"_|\"\"\"\"\"_|\"\"\"\"\"_|\"\"\"\"\"_|\"\"\"\"\"| ");
    printf("%s\n", "\"`-0-0-\"`-0-0-\"`-0-0-\"`-0-0-\"`-0-0-\"`-0-0-\"`-0-0-\"`-0-0-' ");
}