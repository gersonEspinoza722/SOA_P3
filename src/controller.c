#include "controller.h"
#include <stdio.h>
#include <stdlib.h>
#include <cairo.h>
#include <gtk/gtk.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include <stdbool.h>
#include "interface.h"
#include "linked_list_cars.h"
#include "vehicle.h"
#include "utils.h"
#include "priority_semaphore.h"
#include <stdbool.h>

extern GtkWidget *window;
extern GtkBuilder *builder;

extern int K;
extern int M;
extern int N;

extern bool isa_bred;
extern bool isa_bgreen;
extern bool isa_borange;
extern bool isa_bblue;
extern bool isa_bgray;
extern bool isa_bpink;
extern bool isa_blblue;
extern bool isa_bwhite;
extern bool isa_bblack;

extern pthread_mutex_t mutex_bus_active;
extern pthread_mutex_t mutex_KMN;

//Definition funtions
void change_botons_sensitive(char *active, char *desactive);

void remove_spaces(char *s);

int string_to_id(char *s);

int compare_string(char *s1, char *s2, int length);

int val_input(char *s1);

void create_vehicle_in_map(int type_vehicule, char *destinosSplit);

void desactive_botons_sensitive(char *buton_name);

//Called when window is closed
void on_window_main_destroy(GtkWidget *widget, gpointer user_data) {
    gtk_main_quit();
}

void on_press_btn_create_car_aleatory(GtkWidget *widget, gpointer user_data) {
    int *destinations = calloc(4, sizeof(int));
    destinations[0] = random_stop_id();
    destinations[1] = random_stop_id();
    destinations[2] = Z006R;
    destinations[3] = -1;

    Vehicle *v = create_vehicle(random_car_id(), NORTH, destinations);
    VehicleThreadInfo *vi = create_vehicle_thread_info(v);

    pthread_t vehicle_thread;
    pthread_create(&vehicle_thread, NULL, &handle_vehicle, vi);
    pthread_detach(vehicle_thread);

    printf("%s\n", "\033[0;32mAleatory car created\033[0m");
}

void on_press_btn_create_car_config(GtkWidget *widget, gpointer user_data) {
    
    GtkWidget *input_stops = GTK_WIDGET(gtk_builder_get_object(builder, "input_stops"));
    GtkWidget *type_vehicule = GTK_WIDGET(gtk_builder_get_object(builder, "cb_type_cars"));
    int active = gtk_combo_box_get_active(GTK_COMBO_BOX(type_vehicule));
    const gchar *destino = gtk_entry_get_text(GTK_ENTRY(input_stops));
    int length = gtk_entry_get_text_length(GTK_ENTRY(input_stops));
    char destinosSplit_test[length];
    strcpy(destinosSplit_test, destino);

    if (length > 0 && val_input(destinosSplit_test)) {
        
        char destinosSplit_final[length];
        strcpy(destinosSplit_final, destino);
        switch (active) {
            case 0:
                // Rojo
                create_vehicle_in_map(RED_CAR, destinosSplit_final);
                break;
            case 1:
                // Azul
                create_vehicle_in_map(BLUE_CAR, destinosSplit_final);
                break;
            case 2:
                // Verde
                create_vehicle_in_map(GREEN_CAR, destinosSplit_final);
                break;
            case 3:
                // Negro
                create_vehicle_in_map(BLACK_CAR, destinosSplit_final);
                break;
            case 4:
                // Blanco
                create_vehicle_in_map(WHITE_CAR, destinosSplit_final);
                break;
            case 5:
                // Amarillo
                create_vehicle_in_map(YELLOW_CAR, destinosSplit_final);
                break;
            case 6:
                // Ambulance
                create_vehicle_in_map(AMBULANCE, destinosSplit_final);
                break;
            default:
                break;
        }

        printf("%s\n", "\033[0;34mConfigured car created\033[0m");

    } else {
        GtkWidget *messageDialog = gtk_message_dialog_new(GTK_WINDOW(window),
                                                          GTK_DIALOG_MODAL,
                                                          GTK_MESSAGE_INFO,
                                                          GTK_BUTTONS_CLOSE,
                                                          "Input error of stops from Y to Z.\nExample: A1,A2");
        gtk_dialog_run(GTK_DIALOG (messageDialog));
        gtk_widget_destroy(messageDialog);
    }

    gtk_entry_set_text(GTK_ENTRY(input_stops), "");
}

void on_press_btn_create_bus_red(GtkWidget *widget, gpointer user_data) {
    
    change_botons_sensitive("btn_dbr", "btn_cbr");
    pthread_mutex_lock(&mutex_bus_active);
    isa_bred  = true;
    pthread_mutex_unlock(&mutex_bus_active);

    Vehicle *v = create_bus(RED_BUS, NORTH);
    VehicleThreadInfo *vi = create_vehicle_thread_info(v);

    pthread_t maintenance_thread;
    pthread_create(&maintenance_thread, NULL, &handle_vehicle, vi);
    pthread_detach(maintenance_thread);
    printf("%s\n", "Red bus created");
}

void on_press_btn_delete_bus_red(GtkWidget *widget, gpointer user_data) {
    //change_botons_sensitive("btn_cbr", "btn_dbr");
    desactive_botons_sensitive("btn_dbr");
    pthread_mutex_lock(&mutex_bus_active);
    isa_bred  = false;
    pthread_mutex_unlock(&mutex_bus_active);
    printf("%s\n", "Red bus removal process started");
}

void on_press_btn_create_bus_gray(GtkWidget *widget, gpointer user_data) {
    
    change_botons_sensitive("btn_dbg", "btn_cbg");
    pthread_mutex_lock(&mutex_bus_active);
    isa_bgray  = true;
    pthread_mutex_unlock(&mutex_bus_active);

    Vehicle *v = create_bus(GRAY_BUS, NORTH);
    VehicleThreadInfo *vi = create_vehicle_thread_info(v);

    pthread_t maintenance_thread;
    pthread_create(&maintenance_thread, NULL, &handle_vehicle, vi);
    pthread_detach(maintenance_thread);
    printf("%s\n", "Gray bus created");
}

void on_press_btn_delete_bus_gray(GtkWidget *widget, gpointer user_data) {
    //change_botons_sensitive("btn_cbg", "btn_dbg");
    desactive_botons_sensitive("btn_dbg");
    pthread_mutex_lock(&mutex_bus_active);
    isa_bgray  = false;
    pthread_mutex_unlock(&mutex_bus_active);
    printf("%s\n", "Gray bus removal process started");
}

void on_press_btn_create_bus_green(GtkWidget *widget, gpointer user_data) {
    
    change_botons_sensitive("btn_dbgr", "btn_cbgr");
    pthread_mutex_lock(&mutex_bus_active);
    isa_bgreen  = true;
    pthread_mutex_unlock(&mutex_bus_active);

    Vehicle *v = create_bus(GREEN_BUS, NORTH);
    VehicleThreadInfo *vi = create_vehicle_thread_info(v);

    pthread_t maintenance_thread;
    pthread_create(&maintenance_thread, NULL, &handle_vehicle, vi);
    pthread_detach(maintenance_thread);
    printf("%s\n", "Green bus created");
}

void on_press_btn_delete_bus_green(GtkWidget *widget, gpointer user_data) {
    //change_botons_sensitive("btn_cbgr", "btn_dbgr");
    desactive_botons_sensitive("btn_dbgr");
    pthread_mutex_lock(&mutex_bus_active);
    isa_bgreen  = false;
    pthread_mutex_unlock(&mutex_bus_active);
    printf("%s\n", "Green bus removal process started");
}

void on_press_btn_create_bus_pink(GtkWidget *widget, gpointer user_data) {
    change_botons_sensitive("btn_dbp", "btn_cbp");
    pthread_mutex_lock(&mutex_bus_active);
    isa_bpink  = true;
    pthread_mutex_unlock(&mutex_bus_active);

    Vehicle *v = create_bus(PINK_BUS, NORTH);
    VehicleThreadInfo *vi = create_vehicle_thread_info(v);

    pthread_t maintenance_thread;
    pthread_create(&maintenance_thread, NULL, &handle_vehicle, vi);
    pthread_detach(maintenance_thread);
    printf("%s\n", "Pink bus created");

}

void on_press_btn_delete_bus_pink(GtkWidget *widget, gpointer user_data) {
    //change_botons_sensitive("btn_cbp", "btn_dbp");
    desactive_botons_sensitive("btn_dbp");
    pthread_mutex_lock(&mutex_bus_active);
    isa_bpink  = false;
    pthread_mutex_unlock(&mutex_bus_active);
    printf("%s\n", "Pink bus removal process started");
}

void on_press_btn_create_bus_orange(GtkWidget *widget, gpointer user_data) {
    
    change_botons_sensitive("btn_dbo", "btn_cbo");
    pthread_mutex_lock(&mutex_bus_active);
    isa_borange  = true;
    pthread_mutex_unlock(&mutex_bus_active);

    Vehicle *v = create_bus(ORANGE_BUS, NORTH);
    VehicleThreadInfo *vi = create_vehicle_thread_info(v);

    pthread_t maintenance_thread;
    pthread_create(&maintenance_thread, NULL, &handle_vehicle, vi);
    pthread_detach(maintenance_thread);
    printf("%s\n", "Orange bus created");
}

void on_press_btn_delete_bus_orange(GtkWidget *widget, gpointer user_data) {
    //change_botons_sensitive("btn_cbo", "btn_dbo");
    desactive_botons_sensitive("btn_dbo");
    pthread_mutex_lock(&mutex_bus_active);
    isa_borange  = false;
    pthread_mutex_unlock(&mutex_bus_active);
    printf("%s\n", "Orange bus removal process started");
}

void on_press_btn_create_bus_lblue(GtkWidget *widget, gpointer user_data) {
    
    change_botons_sensitive("btn_dblb", "btn_cblb");
    pthread_mutex_lock(&mutex_bus_active);
    isa_blblue  = true;
    pthread_mutex_unlock(&mutex_bus_active);

    Vehicle *v = create_bus(LIGHT_BLUE_BUS, NORTH);
    VehicleThreadInfo *vi = create_vehicle_thread_info(v);

    pthread_t maintenance_thread;
    pthread_create(&maintenance_thread, NULL, &handle_vehicle, vi);
    pthread_detach(maintenance_thread);
    printf("%s\n", "Light blue bus created");
}

void on_press_btn_delete_bus_lblue(GtkWidget *widget, gpointer user_data) {
    //change_botons_sensitive("btn_cblb", "btn_dblb");
    desactive_botons_sensitive("btn_dblb");
    pthread_mutex_lock(&mutex_bus_active);
    isa_blblue  = false;
    pthread_mutex_unlock(&mutex_bus_active);
    printf("%s\n", "Light blue bus removal process started");
}

void on_press_btn_create_bus_blue(GtkWidget *widget, gpointer user_data) {
    
    change_botons_sensitive("btn_dbb", "btn_cbb");
    pthread_mutex_lock(&mutex_bus_active);
    isa_bblue   = true;
    pthread_mutex_unlock(&mutex_bus_active);

    Vehicle *v = create_bus(BLUE_BUS, NORTH);
    VehicleThreadInfo *vi = create_vehicle_thread_info(v);

    pthread_t maintenance_thread;
    pthread_create(&maintenance_thread, NULL, &handle_vehicle, vi);
    pthread_detach(maintenance_thread);
    printf("%s\n", "Blue bus created");
}

void on_press_btn_delete_bus_blue(GtkWidget *widget, gpointer user_data) {
    //change_botons_sensitive("btn_cbb", "btn_dbb");
    desactive_botons_sensitive("btn_dbb");
    pthread_mutex_lock(&mutex_bus_active);
    isa_bblue   = false;
    pthread_mutex_unlock(&mutex_bus_active);
    printf("%s\n", "Blue bus removal process started");
}

void on_press_btn_create_bus_white(GtkWidget *widget, gpointer user_data) {
    
    change_botons_sensitive("btn_dbw", "btn_cbw");
    pthread_mutex_lock(&mutex_bus_active);
    isa_bwhite   = true;
    pthread_mutex_unlock(&mutex_bus_active);

    Vehicle *v = create_bus(WHITE_BUS, NORTH);
    VehicleThreadInfo *vi = create_vehicle_thread_info(v);

    pthread_t maintenance_thread;
    pthread_create(&maintenance_thread, NULL, &handle_vehicle, vi);
    pthread_detach(maintenance_thread);
    printf("%s\n", "White bus created");
}

void on_press_btn_delete_bus_white(GtkWidget *widget, gpointer user_data) {
    //change_botons_sensitive("btn_cbw", "btn_dbw");
    desactive_botons_sensitive("btn_dbw");
    pthread_mutex_lock(&mutex_bus_active);
    isa_bwhite   = false;
    pthread_mutex_unlock(&mutex_bus_active);
    printf("%s\n", "White bus removal process started");
}

void on_press_btn_create_bus_black(GtkWidget *widget, gpointer user_data) {
    
    change_botons_sensitive("btn_dbbl", "btn_cbbl");
    pthread_mutex_lock(&mutex_bus_active);
    isa_bblack  = true;
    pthread_mutex_unlock(&mutex_bus_active);

    Vehicle *v = create_bus(BLACK_BUS, NORTH);
    VehicleThreadInfo *vi = create_vehicle_thread_info(v);

    pthread_t maintenance_thread;
    pthread_create(&maintenance_thread, NULL, &handle_vehicle, vi);
    pthread_detach(maintenance_thread);
    printf("%s\n", "Black bus created");
}

void on_press_btn_delete_bus_black(GtkWidget *widget, gpointer user_data) {
    //change_botons_sensitive("btn_cbbl", "btn_dbbl");
    desactive_botons_sensitive("btn_dbbl");
    pthread_mutex_lock(&mutex_bus_active);
    isa_bblack  = false;
    pthread_mutex_unlock(&mutex_bus_active);
    printf("%s\n", "Black bus removal process started");
}

void on_press_btn_create_ambulance(GtkWidget *widget, gpointer user_data) {
    
    int *destinations = calloc(4, sizeof(int));
    destinations[0] = random_stop_id();
    destinations[1] = random_stop_id();
    destinations[2] = Z006R;
    destinations[3] = -1;

    Vehicle *v = create_vehicle(AMBULANCE, NORTH, destinations);
    VehicleThreadInfo *vi = create_vehicle_thread_info(v);

    pthread_t maintenance_thread;
    pthread_create(&maintenance_thread, NULL, &handle_vehicle, vi);
    pthread_detach(maintenance_thread);
    printf("%s\n", "\033[0;33mAmbulance created\033[0m");

}

void on_press_btn_update_values(GtkWidget *widget, gpointer user_data) {
    GtkWidget *input_K = GTK_WIDGET(gtk_builder_get_object(builder, "input_K"));
    GtkWidget *input_M = GTK_WIDGET(gtk_builder_get_object(builder, "input_M"));
    GtkWidget *input_N = GTK_WIDGET(gtk_builder_get_object(builder, "input_N"));

    const gchar *char_K = gtk_entry_get_text(GTK_ENTRY(input_K));
    const gchar *char_M = gtk_entry_get_text(GTK_ENTRY(input_M));
    const gchar *char_N = gtk_entry_get_text(GTK_ENTRY(input_N));

    int temp_k = atoi(char_K);
    int temp_M = atoi(char_M);
    int temp_N = atoi(char_N);

    if (temp_k <= 0 || temp_M <= 0 || temp_N <= 0) {
        GtkWidget *messageDialog = gtk_message_dialog_new(GTK_WINDOW(window),
                                                          GTK_DIALOG_MODAL,
                                                          GTK_MESSAGE_INFO,
                                                          GTK_BUTTONS_CLOSE,
                                                          "Input error K, M and N must be integers greater than 0.");
        gtk_dialog_run(GTK_DIALOG (messageDialog));
        gtk_widget_destroy(messageDialog);


    } else {
        pthread_mutex_lock(&mutex_KMN);
        K = temp_k;
        M = temp_M;
        N = temp_N;
        pthread_mutex_unlock(&mutex_KMN);

        printf("%s\n", "\033[0;36mValues are updated\033[0m");
    }

    pthread_mutex_lock(&mutex_KMN);
    char int_char[5];
    sprintf(int_char, "%d", K);
    gtk_entry_set_text(GTK_ENTRY(input_K), int_char);
    sprintf(int_char, "%d", M);
    gtk_entry_set_text(GTK_ENTRY(input_M), int_char);
    sprintf(int_char, "%d", N);
    gtk_entry_set_text(GTK_ENTRY(input_N), int_char);
    pthread_mutex_unlock(&mutex_KMN);
}


//Funtions
void change_botons_sensitive(char *active, char *desactive) {
    GtkWidget *active_w = GTK_WIDGET(gtk_builder_get_object(builder, active));;
    GtkWidget *desactive_w = GTK_WIDGET(gtk_builder_get_object(builder, desactive));;
    gtk_widget_set_sensitive(desactive_w, false);
    gtk_widget_set_sensitive(active_w, true);
}

void desactive_botons_sensitive(char *buton_name) {
    GtkWidget *desactive_w = GTK_WIDGET(gtk_builder_get_object(builder, buton_name));;
    gtk_widget_set_sensitive(desactive_w, false);
}

int val_input(char *s1) {
    int var = 0;
    for (char *p = strtok(s1, ","); p != NULL; p = strtok(NULL, ",")) {
        remove_spaces(p);
        var = string_to_id(p);
        if (var == -1) {
            return 0;
        }
    }
    return 1;
}

void remove_spaces(char *s) {
    const char *d = s;
    do {
        while (*d == ' ') {
            ++d;
        }
    } while ((*s++ = *d++));
}


int compare_string(char *s1, char *s2, int length) {
    int i;
    for (i = 0; i < length; ++i) {
        if (s2[i] == '\0' || s1[i] != s2[i]) {
            return 0;
        }
    }
    if (s2[length] != '\0') {
        return 0;
    } else {
        return 1;
    }
}


// Revisar codigo posibles ciclos para paradas iguales seguidas, hay que ignorarlas
void create_vehicle_in_map(int type_vehicule, char *destinosSplit) {
    int total = 3;
    int actual_pos = 0;
    int *destinations = (int *) malloc(total * sizeof(int));
    int var = 0;

    for (char *p = strtok(destinosSplit, ","); p != NULL; p = strtok(NULL, ",")) {
        remove_spaces(p);
        total += 1;
        var = string_to_id(p);
        if (destinations[actual_pos - 1] != var) {
            destinations = (int *) realloc(destinations, total);
            destinations[actual_pos] = var;
            actual_pos += 1;
        }
    }

    destinations[actual_pos] = Z006R;
    destinations[actual_pos + 1] = -1;
    destinations[actual_pos + 2] = '\0';

    Vehicle *v = create_vehicle(type_vehicule, NORTH, destinations);
    VehicleThreadInfo *vi = create_vehicle_thread_info(v);

    pthread_t maintenance_thread;
    pthread_create(&maintenance_thread, NULL, &handle_vehicle, vi);
    pthread_detach(maintenance_thread);
}

void active_all_buses(){


    isa_bred  = true;
    isa_bgreen  = true;
    isa_borange  = true;
    isa_bblue  = true;
    isa_bgray  = true;
    isa_bpink  = true;
    isa_blblue  = true;
    isa_bwhite  = true;
    isa_bblack  = true;

    for (int i = RED_BUS; i <= ORANGE_BUS; ++i)
    {
        Vehicle *v = create_bus(i, NORTH);
        VehicleThreadInfo *vi = create_vehicle_thread_info(v);

        pthread_t maintenance_thread;
        pthread_create(&maintenance_thread, NULL, &handle_vehicle, vi);
        pthread_detach(maintenance_thread);
    }


}

int string_to_id(char *s) {
    if (compare_string("A1", s, 2)) {
        return A001S;
    } else if (compare_string("A2", s, 2)) {
        return A002S;
    } else if (compare_string("A3", s, 2)) {
        return A003S;
    } else if (compare_string("A4", s, 2)) {
        return A004S;
    } else if (compare_string("A5", s, 2)) {
        return A005S;
    } else if (compare_string("A6", s, 2)) {
        return A006S;
    } else if (compare_string("A7", s, 2)) {
        return A007S;
    } else if (compare_string("A8", s, 2)) {
        return A008S;
    } else if (compare_string("B1", s, 2)) {
        return B001S;
    } else if (compare_string("B2", s, 2)) {
        return B002S;
    } else if (compare_string("B3", s, 2)) {
        return B003S;
    } else if (compare_string("B4", s, 2)) {
        return B004S;
    } else if (compare_string("B5", s, 2)) {
        return B005S;
    } else if (compare_string("B6", s, 2)) {
        return B006S;
    } else if (compare_string("B7", s, 2)) {
        return B007S;
    } else if (compare_string("B8", s, 2)) {
        return B008S;
    } else if (compare_string("C1", s, 2)) {
        return C001S;
    } else if (compare_string("C2", s, 2)) {
        return C002S;
    } else if (compare_string("C3", s, 2)) {
        return C003S;
    } else if (compare_string("C4", s, 2)) {
        return C004S;
    } else if (compare_string("C5", s, 2)) {
        return C005S;
    } else if (compare_string("C6", s, 2)) {
        return C006S;
    } else if (compare_string("C7", s, 2)) {
        return C007S;
    } else if (compare_string("C8", s, 2)) {
        return C008S;
    } else if (compare_string("D1", s, 2)) {
        return D001S;
    } else if (compare_string("D2", s, 2)) {
        return D002S;
    } else if (compare_string("D3", s, 2)) {
        return D003S;
    } else if (compare_string("D4", s, 2)) {
        return D004S;
    } else if (compare_string("D5", s, 2)) {
        return D005S;
    } else if (compare_string("D6", s, 2)) {
        return D006S;
    } else if (compare_string("D7", s, 2)) {
        return D007S;
    } else if (compare_string("D8", s, 2)) {
        return D008S;
    } else if (compare_string("E1", s, 2)) {
        return E001S;
    } else if (compare_string("E2", s, 2)) {
        return E002S;
    } else if (compare_string("E3", s, 2)) {
        return E003S;
    } else if (compare_string("E4", s, 2)) {
        return E004S;
    } else if (compare_string("E5", s, 2)) {
        return E005S;
    } else if (compare_string("E6", s, 2)) {
        return E006S;
    } else if (compare_string("E7", s, 2)) {
        return E007S;
    } else if (compare_string("E8", s, 2)) {
        return E008S;
    } else if (compare_string("F1", s, 2)) {
        return F001S;
    } else if (compare_string("F2", s, 2)) {
        return F002S;
    } else if (compare_string("F3", s, 2)) {
        return F003S;
    } else if (compare_string("F4", s, 2)) {
        return F004S;
    } else if (compare_string("F5", s, 2)) {
        return F005S;
    } else if (compare_string("F6", s, 2)) {
        return F006S;
    } else if (compare_string("F7", s, 2)) {
        return F007S;
    } else if (compare_string("F8", s, 2)) {
        return F008S;
    } else if (compare_string("S1", s, 2)) {
        return S001S;
    } else if (compare_string("S2", s, 2)) {
        return S002S;
    } else if (compare_string("S3", s, 2)) {
        return S003S;
    } else if (compare_string("S4", s, 2)) {
        return S004S;
    } else if (compare_string("S5", s, 2)) {
        return S005S;
    } else if (compare_string("S6", s, 2)) {
        return S006S;
    } else if (compare_string("S7", s, 2)) {
        return S007S;
    } else if (compare_string("S8", s, 2)) {
        return S008S;
    } else if (compare_string("T1", s, 2)) {
        return T001S;
    } else if (compare_string("T2", s, 2)) {
        return T002S;
    } else if (compare_string("T3", s, 2)) {
        return T003S;
    } else if (compare_string("T4", s, 2)) {
        return T004S;
    } else if (compare_string("T5", s, 2)) {
        return T005S;
    } else if (compare_string("T6", s, 2)) {
        return T006S;
    } else if (compare_string("T7", s, 2)) {
        return T007S;
    } else if (compare_string("T8", s, 2)) {
        return T008S;
    } else if (compare_string("U1", s, 2)) {
        return U001S;
    } else if (compare_string("U2", s, 2)) {
        return U002S;
    } else if (compare_string("U3", s, 2)) {
        return U003S;
    } else if (compare_string("U4", s, 2)) {
        return U004S;
    } else if (compare_string("U5", s, 2)) {
        return U005S;
    } else if (compare_string("U6", s, 2)) {
        return U006S;
    } else if (compare_string("U7", s, 2)) {
        return U007S;
    } else if (compare_string("88", s, 2)) {
        return U008S;
    } else if (compare_string("V1", s, 2)) {
        return V001S;
    } else if (compare_string("V2", s, 2)) {
        return V002S;
    } else if (compare_string("V3", s, 2)) {
        return V003S;
    } else if (compare_string("V4", s, 2)) {
        return V004S;
    } else if (compare_string("V5", s, 2)) {
        return V005S;
    } else if (compare_string("V6", s, 2)) {
        return V006S;
    } else if (compare_string("V7", s, 2)) {
        return V007S;
    } else if (compare_string("V8", s, 2)) {
        return V008S;
    } else if (compare_string("W1", s, 2)) {
        return W001S;
    } else if (compare_string("W2", s, 2)) {
        return W002S;
    } else if (compare_string("W3", s, 2)) {
        return W003S;
    } else if (compare_string("W4", s, 2)) {
        return W004S;
    } else if (compare_string("W5", s, 2)) {
        return W005S;
    } else if (compare_string("W6", s, 2)) {
        return W006S;
    } else if (compare_string("W7", s, 2)) {
        return W007S;
    } else if (compare_string("W8", s, 2)) {
        return W008S;
    } else if (compare_string("X1", s, 2)) {
        return X001S;
    } else if (compare_string("X2", s, 2)) {
        return X002S;
    } else if (compare_string("X3", s, 2)) {
        return X003S;
    } else if (compare_string("X4", s, 2)) {
        return X004S;
    } else if (compare_string("X5", s, 2)) {
        return X005S;
    } else if (compare_string("X6", s, 2)) {
        return X006S;
    } else if (compare_string("X7", s, 2)) {
        return X007S;
    } else if (compare_string("X8", s, 2)) {
        return X008S;
    } else if (compare_string("G1", s, 2)) {
        return G001S;
    } else if (compare_string("G2", s, 2)) {
        return G002S;
    } else if (compare_string("G3", s, 2)) {
        return G003S;
    } else if (compare_string("G4", s, 2)) {
        return G004S;
    } else if (compare_string("G5", s, 2)) {
        return G005S;
    } else if (compare_string("G6", s, 2)) {
        return G006S;
    } else if (compare_string("H1", s, 2)) {
        return H001S;
    } else if (compare_string("H2", s, 2)) {
        return H002S;
    } else if (compare_string("H3", s, 2)) {
        return H003S;
    } else if (compare_string("H4", s, 2)) {
        return H004S;
    } else if (compare_string("H5", s, 2)) {
        return H005S;
    } else if (compare_string("H6", s, 2)) {
        return H006S;
    } else if (compare_string("I1", s, 2)) {
        return I001S;
    } else if (compare_string("I2", s, 2)) {
        return I002S;
    } else if (compare_string("I3", s, 2)) {
        return I003S;
    } else if (compare_string("I4", s, 2)) {
        return I004S;
    } else if (compare_string("I5", s, 2)) {
        return I005S;
    } else if (compare_string("I6", s, 2)) {
        return I006S;
    } else if (compare_string("J1", s, 2)) {
        return J001S;
    } else if (compare_string("J2", s, 2)) {
        return J002S;
    } else if (compare_string("J3", s, 2)) {
        return J003S;
    } else if (compare_string("J4", s, 2)) {
        return J004S;
    } else if (compare_string("J5", s, 2)) {
        return J005S;
    } else if (compare_string("J6", s, 2)) {
        return J006S;
    } else if (compare_string("K1", s, 2)) {
        return K001S;
    } else if (compare_string("K2", s, 2)) {
        return K002S;
    } else if (compare_string("K3", s, 2)) {
        return K003S;
    } else if (compare_string("K4", s, 2)) {
        return K004S;
    } else if (compare_string("K5", s, 2)) {
        return K005S;
    } else if (compare_string("K6", s, 2)) {
        return K006S;
    } else if (compare_string("L1", s, 2)) {
        return L001S;
    } else if (compare_string("L2", s, 2)) {
        return L002S;
    } else if (compare_string("L3", s, 2)) {
        return L003S;
    } else if (compare_string("L4", s, 2)) {
        return L004S;
    } else if (compare_string("L5", s, 2)) {
        return L005S;
    } else if (compare_string("L6", s, 2)) {
        return L006S;
    } else if (compare_string("M1", s, 2)) {
        return M001S;
    } else if (compare_string("M2", s, 2)) {
        return M002S;
    } else if (compare_string("M3", s, 2)) {
        return M003S;
    } else if (compare_string("M4", s, 2)) {
        return M004S;
    } else if (compare_string("M5", s, 2)) {
        return M005S;
    } else if (compare_string("M6", s, 2)) {
        return M006S;
    } else if (compare_string("N1", s, 2)) {
        return N001S;
    } else if (compare_string("N2", s, 2)) {
        return N002S;
    } else if (compare_string("N3", s, 2)) {
        return N003S;
    } else if (compare_string("N4", s, 2)) {
        return N004S;
    } else if (compare_string("N5", s, 2)) {
        return N005S;
    } else if (compare_string("N6", s, 2)) {
        return N006S;
    } else if (compare_string("O1", s, 2)) {
        return O001S;
    } else if (compare_string("O2", s, 2)) {
        return O002S;
    } else if (compare_string("O3", s, 2)) {
        return O003S;
    } else if (compare_string("O4", s, 2)) {
        return O004S;
    } else if (compare_string("O5", s, 2)) {
        return O005S;
    } else if (compare_string("O6", s, 2)) {
        return O006S;
    } else if (compare_string("P1", s, 2)) {
        return P001S;
    } else if (compare_string("P2", s, 2)) {
        return P002S;
    } else if (compare_string("P3", s, 2)) {
        return P003S;
    } else if (compare_string("P4", s, 2)) {
        return P004S;
    } else if (compare_string("P5", s, 2)) {
        return P005S;
    } else if (compare_string("P6", s, 2)) {
        return P006S;
    } else if (compare_string("Q1", s, 2)) {
        return Q001S;
    } else if (compare_string("Q2", s, 2)) {
        return Q002S;
    } else if (compare_string("Q3", s, 2)) {
        return Q003S;
    } else if (compare_string("Q4", s, 2)) {
        return Q004S;
    } else if (compare_string("Q5", s, 2)) {
        return Q005S;
    } else if (compare_string("Q6", s, 2)) {
        return Q006S;
    } else if (compare_string("R1", s, 2)) {
        return R001S;
    } else if (compare_string("R2", s, 2)) {
        return R002S;
    } else if (compare_string("R3", s, 2)) {
        return R003S;
    } else if (compare_string("R4", s, 2)) {
        return R004S;
    } else if (compare_string("R5", s, 2)) {
        return R005S;
    } else if (compare_string("R6", s, 2)) {
        return R006S;
    } else {
        return -1;
    }
}
