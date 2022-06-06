#include "controlador.h"
#include <stdio.h>
#include <stdlib.h>
#include <cairo.h>
#include <gtk/gtk.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include <stdbool.h>
#include "interfaz.h"
#include "lista_enlazada_carros.h"
#include "vehiculo.h"
#include "utils.h"
#include "semaforo_prioridad.h"
#include <stdbool.h>

extern GtkWidget *window;
extern GtkBuilder *builder;

extern int K;
extern int M;
extern int N;

extern bool is_bus_rojo;
extern bool is_bus_verde;
extern bool is_bus_naranja;
extern bool is_bus_azul;
extern bool is_bus_gris;
extern bool is_bus_rosado;
extern bool is_bus_celeste;
extern bool is_bus_blanco;
extern bool is_bus_negro;

extern pthread_mutex_t mutex_bus_activo;
extern pthread_mutex_t mutex_KMN;

//Definition funtions
void cambiar_sensibilidad_botones(char *activar, char *desactivar);

void remover_espacios(char *s);

int string_a_id(char *s);

int comparar_string(char *s1, char *s2, int length);

int validar_input(char *s1);

void crear_vehiculo_en_mapa(int tipoVehiculo, char *destinosSplit);

void desactivar_sensibilidad_botones(char *nombreBoton);

//Se llama cuando la ventana es cerrada
void on_window_main_destroy(GtkWidget *widget, gpointer datosUsuario) {
    gtk_main_quit();
}

void monitor_prints(char *mensaje, char *name) {
    GtkTextView   *text_view;
    GtkTextBuffer *buffer;
    GtkTextIter iter;
    text_view = GTK_TEXT_VIEW(gtk_builder_get_object(builder, name));
    buffer = gtk_text_view_get_buffer(text_view);

    gtk_text_buffer_get_iter_at_offset(buffer, &iter, 0);
    gtk_text_buffer_insert(buffer, &iter, mensaje, -1);
}



void on_press_boton_crear_carro_aleatorio(GtkWidget *widget, gpointer datosUsuario) {
    int *destinos = calloc(4, sizeof(int));
    srand(time(0));
    destinos[0] = id_parada_aleatoria();
    destinos[1] = id_parada_aleatoria();
    destinos[2] = Z006R;
    destinos[3] = -1;

    Vehiculo *v = crear_vehiculo(id_carro_aleatorio(), NORTE, destinos);
    InfoHiloVehiculo *vi = crear_info_hilo_vehiculo(v);

    pthread_t hiloVehiculo;
    pthread_create(&hiloVehiculo, NULL, &manejar_vehiculo, vi);
    pthread_detach(hiloVehiculo);

    monitor_prints("Carro aleatorio creado\n", "console");
    

}

void on_press_boton_crear_carro_configurado(GtkWidget *widget, gpointer datosUsuario) {
    GtkWidget *inputParadas = GTK_WIDGET(gtk_builder_get_object(builder, "inputParadas"));
    GtkWidget *tipoVehiculo = GTK_WIDGET(gtk_builder_get_object(builder, "cbTipoCarros"));
    int activar = gtk_combo_box_get_active(GTK_COMBO_BOX(tipoVehiculo));
    const gchar *destino = gtk_entry_get_text(GTK_ENTRY(inputParadas));
    int length = gtk_entry_get_text_length(GTK_ENTRY(inputParadas));
    char destinosSplit_test[length];
    strcpy(destinosSplit_test, destino);

    if (length > 0 && validar_input(destinosSplit_test)) {
        
        char destinosSplit_final[length];
        strcpy(destinosSplit_final, destino);
        switch (activar) {
            case 0:
                // Rojo
                crear_vehiculo_en_mapa(CARRO_ROJO, destinosSplit_final);
                break;
            case 1:
                // Azul
                crear_vehiculo_en_mapa(CARRO_AZUL, destinosSplit_final);
                break;
            case 2:
                // Verde
                crear_vehiculo_en_mapa(CARRO_VERDE, destinosSplit_final);
                break;
            case 3:
                // Negro
                crear_vehiculo_en_mapa(CARRO_NEGRO, destinosSplit_final);
                break;
            case 4:
                // Blanco
                crear_vehiculo_en_mapa(CARRO_BLANCO, destinosSplit_final);
                break;
            case 5:
                // Amarillo
                crear_vehiculo_en_mapa(CARRO_AMARILLO, destinosSplit_final);
                break;
            case 6:
                // Ambulance
                crear_vehiculo_en_mapa(AMBULANCIA, destinosSplit_final);
                break;
            default:
                break;
        }

        monitor_prints("Carro configurado creado\n", "console");

    } else {
        GtkWidget *dialogoMensaje = gtk_message_dialog_new(GTK_WINDOW(window),
                                                          GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE,
                                                          "Error de input de paradas de Y a Z.\nEjemplo: A1,A2");
        gtk_dialog_run(GTK_DIALOG (dialogoMensaje));
        gtk_widget_destroy(dialogoMensaje);
    }

    gtk_entry_set_text(GTK_ENTRY(inputParadas), "");
}

void on_press_boton_crear_bus_rojo(GtkWidget *widget, gpointer datosUsuario) {
    cambiar_sensibilidad_botones("btn_dbr", "btn_cbr");
    pthread_mutex_lock(&mutex_bus_activo);
    is_bus_rojo  = true;
    pthread_mutex_unlock(&mutex_bus_activo);

    Vehiculo *v = crear_bus(BUS_ROJO, NORTE);
    InfoHiloVehiculo *vi = crear_info_hilo_vehiculo(v);

    pthread_t hiloMantenimiento;
    pthread_create(&hiloMantenimiento, NULL, &manejar_vehiculo, vi);
    pthread_detach(hiloMantenimiento);
    monitor_prints("Bus rojo creado\n", "console");
}

void on_press_boton_borrar_bus_rojo(GtkWidget *widget, gpointer datosUsuario) {
    //cambiar_sensibilidad_botones("btn_cbr", "btn_dbr");
    desactivar_sensibilidad_botones("btn_dbr");
    pthread_mutex_lock(&mutex_bus_activo);
    is_bus_rojo = false;
    pthread_mutex_unlock(&mutex_bus_activo);
    monitor_prints("Proceso de remover bus rojo iniciado\n", "console");
}

void on_press_boton_crear_bus_gris(GtkWidget *widget, gpointer datosUsuario) {
    cambiar_sensibilidad_botones("btn_dbg", "btn_cbg");
    pthread_mutex_lock(&mutex_bus_activo);
    is_bus_gris  = true;
    pthread_mutex_unlock(&mutex_bus_activo);

    Vehiculo *v = crear_bus(BUS_GRIS, NORTE);
    InfoHiloVehiculo *vi = crear_info_hilo_vehiculo(v);

    pthread_t hiloMantenimiento;
    pthread_create(&hiloMantenimiento, NULL, &manejar_vehiculo, vi);
    pthread_detach(hiloMantenimiento);
    monitor_prints("Bus gris creado\n", "console");

}

void on_press_boton_borrar_bus_gris(GtkWidget *widget, gpointer datosUsuario) {
    //cambiar_sensibilidad_botones("btn_cbg", "btn_dbg");
    desactivar_sensibilidad_botones("btn_dbg");
    pthread_mutex_lock(&mutex_bus_activo);
    is_bus_gris  = false;
    pthread_mutex_unlock(&mutex_bus_activo);
    monitor_prints("Proceso de remover bus gris iniciado\n", "console");
}

void on_press_boton_crear_bus_verde(GtkWidget *widget, gpointer datosUsuario) {
    cambiar_sensibilidad_botones("btn_dbgr", "btn_cbgr");
    pthread_mutex_lock(&mutex_bus_activo);
    is_bus_verde  = true;
    pthread_mutex_unlock(&mutex_bus_activo);

    Vehiculo *v = crear_bus(BUS_VERDE, NORTE);
    InfoHiloVehiculo *vi = crear_info_hilo_vehiculo(v);

    pthread_t hiloMantenimiento;
    pthread_create(&hiloMantenimiento, NULL, &manejar_vehiculo, vi);
    pthread_detach(hiloMantenimiento);
    monitor_prints("Bus verde creado\n", "console");
}

void on_press_boton_borrar_bus_verde(GtkWidget *widget, gpointer datosUsuario) {
    //cambiar_sensibilidad_botones("btn_cbgr", "btn_dbgr");
    desactivar_sensibilidad_botones("btn_dbgr");
    pthread_mutex_lock(&mutex_bus_activo);
    is_bus_verde  = false;
    pthread_mutex_unlock(&mutex_bus_activo);
    monitor_prints( "Proceso de remover bus verde iniciado\n", "console");
}

void on_press_boton_crear_bus_rosado(GtkWidget *widget, gpointer datosUsuario) {
    cambiar_sensibilidad_botones("btn_dbp", "btn_cbp");
    pthread_mutex_lock(&mutex_bus_activo);
    is_bus_rosado  = true;
    pthread_mutex_unlock(&mutex_bus_activo);

    Vehiculo *v = crear_bus(BUS_ROSADO, NORTE);
    InfoHiloVehiculo *vi = crear_info_hilo_vehiculo(v);

    pthread_t hiloMantenimiento;
    pthread_create(&hiloMantenimiento, NULL, &manejar_vehiculo, vi);
    pthread_detach(hiloMantenimiento);
   monitor_prints("Bus rosado creado\n", "console");
}

void on_press_boton_borrar_bus_rosado(GtkWidget *widget, gpointer datosUsuario) {
    //cambiar_sensibilidad_botones("btn_cbp", "btn_dbp");
    desactivar_sensibilidad_botones("btn_dbp");
    pthread_mutex_lock(&mutex_bus_activo);
    is_bus_rosado  = false;
    pthread_mutex_unlock(&mutex_bus_activo);
    monitor_prints("Proceso de remover bus rosado iniciado\n", "console");
}

void on_press_boton_crear_bus_naranja(GtkWidget *widget, gpointer datosUsuario) {
    cambiar_sensibilidad_botones("btn_dbo", "btn_cbo");
    pthread_mutex_lock(&mutex_bus_activo);
    is_bus_naranja  = true;
    pthread_mutex_unlock(&mutex_bus_activo);

    Vehiculo *v = crear_bus(BUS_NARANJA, NORTE);
    InfoHiloVehiculo *vi = crear_info_hilo_vehiculo(v);

    pthread_t hiloMantenimiento;
    pthread_create(&hiloMantenimiento, NULL, &manejar_vehiculo, vi);
    pthread_detach(hiloMantenimiento);
    monitor_prints("Bus naranja creado\n", "console");
}

void on_press_boton_borrar_bus_naranja(GtkWidget *widget, gpointer datosUsuario) {
    //cambiar_sensibilidad_botones("btn_cbo", "btn_dbo");
    desactivar_sensibilidad_botones("btn_dbo");
    pthread_mutex_lock(&mutex_bus_activo);
    is_bus_naranja = false;
    pthread_mutex_unlock(&mutex_bus_activo);
   monitor_prints("Proceso de remover bus naranja iniciado\n", "console");
}

void on_press_boton_crear_bus_celeste(GtkWidget *widget, gpointer datosUsuario) {
    cambiar_sensibilidad_botones("btn_dblb", "btn_cblb");
    pthread_mutex_lock(&mutex_bus_activo);
    is_bus_celeste  = true;
    pthread_mutex_unlock(&mutex_bus_activo);

    Vehiculo *v = crear_bus(BUS_CELESTE, NORTE);
    InfoHiloVehiculo *vi = crear_info_hilo_vehiculo(v);

    pthread_t hiloMantenimiento;
    pthread_create(&hiloMantenimiento, NULL, &manejar_vehiculo, vi);
    pthread_detach(hiloMantenimiento);
   monitor_prints("Bus celeste creado\n", "console");
}

void on_press_boton_borrar_bus_celeste(GtkWidget *widget, gpointer datosUsuario) {
    //cambiar_sensibilidad_botones("btn_cblb", "btn_dblb");
    desactivar_sensibilidad_botones("btn_dblb");
    pthread_mutex_lock(&mutex_bus_activo);
    is_bus_celeste = false;
    pthread_mutex_unlock(&mutex_bus_activo);
    monitor_prints("Proceso de remover bus celeste iniciado\n", "console");
}

void on_press_boton_crear_bus_azul(GtkWidget *widget, gpointer datosUsuario) {
    cambiar_sensibilidad_botones("btn_dbb", "btn_cbb");
    pthread_mutex_lock(&mutex_bus_activo);
    is_bus_azul = true;
    pthread_mutex_unlock(&mutex_bus_activo);

    Vehiculo *v = crear_bus(BUS_AZUL, NORTE);
    InfoHiloVehiculo *vi = crear_info_hilo_vehiculo(v);

    pthread_t hiloMantenimiento;
    pthread_create(&hiloMantenimiento, NULL, &manejar_vehiculo, vi);
    pthread_detach(hiloMantenimiento);
    monitor_prints("Crear bus azul\n", "console");
}

void on_press_boton_borrar_bus_azul(GtkWidget *widget, gpointer datosUsuario) {
    //cambiar_sensibilidad_botones("btn_cbb", "btn_dbb");
    desactivar_sensibilidad_botones("btn_dbb");
    pthread_mutex_lock(&mutex_bus_activo);
    is_bus_azul   = false;
    pthread_mutex_unlock(&mutex_bus_activo);
   monitor_prints("Proceso de remover bus azul iniciado\n", "console");
}

void on_press_boton_crear_bus_blanco(GtkWidget *widget, gpointer datosUsuario) {
    cambiar_sensibilidad_botones("btn_dbw", "btn_cbw");
    pthread_mutex_lock(&mutex_bus_activo);
    is_bus_blanco = true;
    pthread_mutex_unlock(&mutex_bus_activo);

    Vehiculo *v = crear_bus(BUS_BLANCO, NORTE);
    InfoHiloVehiculo *vi = crear_info_hilo_vehiculo(v);

    pthread_t hiloMantenimiento;
    pthread_create(&hiloMantenimiento, NULL, &manejar_vehiculo, vi);
    pthread_detach(hiloMantenimiento);
    monitor_prints("Bus blanco creado\n", "console");
}

void on_press_boton_borrar_bus_blanco(GtkWidget *widget, gpointer datosUsuario) {
    //cambiar_sensibilidad_botones("btn_cbw", "btn_dbw");
    desactivar_sensibilidad_botones("btn_dbw");
    pthread_mutex_lock(&mutex_bus_activo);
    is_bus_blanco   = false;
    pthread_mutex_unlock(&mutex_bus_activo);
    monitor_prints("Proceso de remover bus blanco iniciado\n", "console");
}

void on_press_boton_crear_bus_negro(GtkWidget *widget, gpointer datosUsuario) {
    cambiar_sensibilidad_botones("btn_dbbl", "btn_cbbl");
    pthread_mutex_lock(&mutex_bus_activo);
    is_bus_negro  = true;
    pthread_mutex_unlock(&mutex_bus_activo);

    Vehiculo *v = crear_bus(BUS_NEGRO, NORTE);
    InfoHiloVehiculo *vi = crear_info_hilo_vehiculo(v);

    pthread_t hiloMantenimiento;
    pthread_create(&hiloMantenimiento, NULL, &manejar_vehiculo, vi);
    pthread_detach(hiloMantenimiento);
    monitor_prints("Crear bus negro\n", "con_larry");
}

void on_press_boton_borrar_bus_negro(GtkWidget *widget, gpointer datosUsuario) {
    //cambiar_sensibilidad_botones("btn_cbbl", "btn_dbbl");
    desactivar_sensibilidad_botones("btn_dbbl");
    pthread_mutex_lock(&mutex_bus_activo);
    is_bus_negro  = false;
    pthread_mutex_unlock(&mutex_bus_activo);
    monitor_prints("Proceso de remover bus negro iniciado\n", "console");
}

void on_press_boton_crear_ambulancia(GtkWidget *widget, gpointer datosUsuario) {
    int *destinos = calloc(4, sizeof(int));
    srand(time(0));
    destinos[0] = id_parada_aleatoria();
    destinos[1] = id_parada_aleatoria();
    destinos[2] = Z006R;
    destinos[3] = -1;

    Vehiculo *v = crear_vehiculo(AMBULANCIA, NORTE, destinos);
    InfoHiloVehiculo *vi = crear_info_hilo_vehiculo(v);

    pthread_t hiloMantenimiento;
    pthread_create(&hiloMantenimiento, NULL, &manejar_vehiculo, vi);
    pthread_detach(hiloMantenimiento);
    monitor_prints("Ambulancia creada\n", "console");
}

void on_press_boton_actualizar_valores(GtkWidget *widget, gpointer datosUsuario) {
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
        GtkWidget *dialogoMensaje = gtk_message_dialog_new(GTK_WINDOW(window),
                                                          GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE,
                                                          "Error input K, M y N deben ser enteros mayores a 0.");
        gtk_dialog_run(GTK_DIALOG (dialogoMensaje));
        gtk_widget_destroy(dialogoMensaje);
    } else {
        pthread_mutex_lock(&mutex_KMN);
        K = temp_k;
        M = temp_M;
        N = temp_N;
        pthread_mutex_unlock(&mutex_KMN);

       monitor_prints("Valores actualizados\n", "console");
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

//Funciones
void cambiar_sensibilidad_botones(char *activar, char *desactivar) {
    GtkWidget *active_w = GTK_WIDGET(gtk_builder_get_object(builder, activar));;
    GtkWidget *desactivar_w = GTK_WIDGET(gtk_builder_get_object(builder, desactivar));;
    gtk_widget_set_sensitive(desactivar_w, false);
    gtk_widget_set_sensitive(active_w, true);
}

void desactivar_sensibilidad_botones(char *nombreBoton) {
    GtkWidget *desactivar_w = GTK_WIDGET(gtk_builder_get_object(builder, nombreBoton));;
    gtk_widget_set_sensitive(desactivar_w, false);
}

int validar_input(char *s1) {
    int var = 0;
    for (char *p = strtok(s1, ","); p != NULL; p = strtok(NULL, ",")) {
        remover_espacios(p);
        var = string_a_id(p);
        if (var == -1) {
            return 0;
        }
    }
    return 1;
}

void remover_espacios(char *s) {
    const char *d = s;
    do {
        while (*d == ' ') {
            ++d;
        }
    } while ((*s++ = *d++));
}

int comparar_string(char *s1, char *s2, int length) {
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
void crear_vehiculo_en_mapa(int tipoVehiculo, char *destinosSplit) {
    int total = 3;
    int posicionActual = 0;
    int *destinos = (int *) malloc(total * sizeof(int));
    int var = 0;

    for (char *p = strtok(destinosSplit, ","); p != NULL; p = strtok(NULL, ",")) {
        remover_espacios(p);
        total += 1;
        var = string_a_id(p);
        if (destinos[posicionActual - 1] != var) {
            destinos = (int *) realloc(destinos, total);
            destinos[posicionActual] = var;
            posicionActual += 1;
        }
    }

    destinos[posicionActual] = Z006R;
    destinos[posicionActual + 1] = -1;
    destinos[posicionActual + 2] = '\0';

    Vehiculo *v = crear_vehiculo(tipoVehiculo, NORTE, destinos);
    InfoHiloVehiculo *vi = crear_info_hilo_vehiculo(v);

    pthread_t hiloMantenimiento;
    pthread_create(&hiloMantenimiento, NULL, &manejar_vehiculo, vi);
    pthread_detach(hiloMantenimiento);
}

void activar_todos_buses() {
    is_bus_rojo  = true;
    is_bus_verde  = true;
    is_bus_naranja  = true;
    is_bus_azul  = true;
    is_bus_gris  = true;
    is_bus_rosado  = true;
    is_bus_celeste  = true;
    is_bus_blanco  = true;
    is_bus_negro  = true;

    for (int i = BUS_ROJO; i <= BUS_NARANJA; ++i){
        Vehiculo *v = crear_bus(i, NORTE);
        InfoHiloVehiculo *vi = crear_info_hilo_vehiculo(v);

        pthread_t hiloMantenimiento;
        pthread_create(&hiloMantenimiento, NULL, &manejar_vehiculo, vi);
        pthread_detach(hiloMantenimiento);
    }
}

int string_a_id(char *s) {
    if (comparar_string("A1", s, 2)) {
        return A001S;
    } else if (comparar_string("A2", s, 2)) {
        return A002S;
    } else if (comparar_string("A3", s, 2)) {
        return A003S;
    } else if (comparar_string("A4", s, 2)) {
        return A004S;
    } else if (comparar_string("A5", s, 2)) {
        return A005S;
    } else if (comparar_string("A6", s, 2)) {
        return A006S;
    } else if (comparar_string("A7", s, 2)) {
        return A007S;
    } else if (comparar_string("A8", s, 2)) {
        return A008S;
    } else if (comparar_string("B1", s, 2)) {
        return B001S;
    } else if (comparar_string("B2", s, 2)) {
        return B002S;
    } else if (comparar_string("B3", s, 2)) {
        return B003S;
    } else if (comparar_string("B4", s, 2)) {
        return B004S;
    } else if (comparar_string("B5", s, 2)) {
        return B005S;
    } else if (comparar_string("B6", s, 2)) {
        return B006S;
    } else if (comparar_string("B7", s, 2)) {
        return B007S;
    } else if (comparar_string("B8", s, 2)) {
        return B008S;
    } else if (comparar_string("C1", s, 2)) {
        return C001S;
    } else if (comparar_string("C2", s, 2)) {
        return C002S;
    } else if (comparar_string("C3", s, 2)) {
        return C003S;
    } else if (comparar_string("C4", s, 2)) {
        return C004S;
    } else if (comparar_string("C5", s, 2)) {
        return C005S;
    } else if (comparar_string("C6", s, 2)) {
        return C006S;
    } else if (comparar_string("C7", s, 2)) {
        return C007S;
    } else if (comparar_string("C8", s, 2)) {
        return C008S;
    } else if (comparar_string("D1", s, 2)) {
        return D001S;
    } else if (comparar_string("D2", s, 2)) {
        return D002S;
    } else if (comparar_string("D3", s, 2)) {
        return D003S;
    } else if (comparar_string("D4", s, 2)) {
        return D004S;
    } else if (comparar_string("D5", s, 2)) {
        return D005S;
    } else if (comparar_string("D6", s, 2)) {
        return D006S;
    } else if (comparar_string("D7", s, 2)) {
        return D007S;
    } else if (comparar_string("D8", s, 2)) {
        return D008S;
    } else if (comparar_string("E1", s, 2)) {
        return E001S;
    } else if (comparar_string("E2", s, 2)) {
        return E002S;
    } else if (comparar_string("E3", s, 2)) {
        return E003S;
    } else if (comparar_string("E4", s, 2)) {
        return E004S;
    } else if (comparar_string("E5", s, 2)) {
        return E005S;
    } else if (comparar_string("E6", s, 2)) {
        return E006S;
    } else if (comparar_string("E7", s, 2)) {
        return E007S;
    } else if (comparar_string("E8", s, 2)) {
        return E008S;
    } else if (comparar_string("F1", s, 2)) {
        return F001S;
    } else if (comparar_string("F2", s, 2)) {
        return F002S;
    } else if (comparar_string("F3", s, 2)) {
        return F003S;
    } else if (comparar_string("F4", s, 2)) {
        return F004S;
    } else if (comparar_string("F5", s, 2)) {
        return F005S;
    } else if (comparar_string("F6", s, 2)) {
        return F006S;
    } else if (comparar_string("F7", s, 2)) {
        return F007S;
    } else if (comparar_string("F8", s, 2)) {
        return F008S;
    } else if (comparar_string("S1", s, 2)) {
        return S001S;
    } else if (comparar_string("S2", s, 2)) {
        return S002S;
    } else if (comparar_string("S3", s, 2)) {
        return S003S;
    } else if (comparar_string("S4", s, 2)) {
        return S004S;
    } else if (comparar_string("S5", s, 2)) {
        return S005S;
    } else if (comparar_string("S6", s, 2)) {
        return S006S;
    } else if (comparar_string("S7", s, 2)) {
        return S007S;
    } else if (comparar_string("S8", s, 2)) {
        return S008S;
    } else if (comparar_string("T1", s, 2)) {
        return T001S;
    } else if (comparar_string("T2", s, 2)) {
        return T002S;
    } else if (comparar_string("T3", s, 2)) {
        return T003S;
    } else if (comparar_string("T4", s, 2)) {
        return T004S;
    } else if (comparar_string("T5", s, 2)) {
        return T005S;
    } else if (comparar_string("T6", s, 2)) {
        return T006S;
    } else if (comparar_string("T7", s, 2)) {
        return T007S;
    } else if (comparar_string("T8", s, 2)) {
        return T008S;
    } else if (comparar_string("U1", s, 2)) {
        return U001S;
    } else if (comparar_string("U2", s, 2)) {
        return U002S;
    } else if (comparar_string("U3", s, 2)) {
        return U003S;
    } else if (comparar_string("U4", s, 2)) {
        return U004S;
    } else if (comparar_string("U5", s, 2)) {
        return U005S;
    } else if (comparar_string("U6", s, 2)) {
        return U006S;
    } else if (comparar_string("U7", s, 2)) {
        return U007S;
    } else if (comparar_string("88", s, 2)) {
        return U008S;
    } else if (comparar_string("V1", s, 2)) {
        return V001S;
    } else if (comparar_string("V2", s, 2)) {
        return V002S;
    } else if (comparar_string("V3", s, 2)) {
        return V003S;
    } else if (comparar_string("V4", s, 2)) {
        return V004S;
    } else if (comparar_string("V5", s, 2)) {
        return V005S;
    } else if (comparar_string("V6", s, 2)) {
        return V006S;
    } else if (comparar_string("V7", s, 2)) {
        return V007S;
    } else if (comparar_string("V8", s, 2)) {
        return V008S;
    } else if (comparar_string("W1", s, 2)) {
        return W001S;
    } else if (comparar_string("W2", s, 2)) {
        return W002S;
    } else if (comparar_string("W3", s, 2)) {
        return W003S;
    } else if (comparar_string("W4", s, 2)) {
        return W004S;
    } else if (comparar_string("W5", s, 2)) {
        return W005S;
    } else if (comparar_string("W6", s, 2)) {
        return W006S;
    } else if (comparar_string("W7", s, 2)) {
        return W007S;
    } else if (comparar_string("W8", s, 2)) {
        return W008S;
    } else if (comparar_string("X1", s, 2)) {
        return X001S;
    } else if (comparar_string("X2", s, 2)) {
        return X002S;
    } else if (comparar_string("X3", s, 2)) {
        return X003S;
    } else if (comparar_string("X4", s, 2)) {
        return X004S;
    } else if (comparar_string("X5", s, 2)) {
        return X005S;
    } else if (comparar_string("X6", s, 2)) {
        return X006S;
    } else if (comparar_string("X7", s, 2)) {
        return X007S;
    } else if (comparar_string("X8", s, 2)) {
        return X008S;
    } else if (comparar_string("G1", s, 2)) {
        return G001S;
    } else if (comparar_string("G2", s, 2)) {
        return G002S;
    } else if (comparar_string("G3", s, 2)) {
        return G003S;
    } else if (comparar_string("G4", s, 2)) {
        return G004S;
    } else if (comparar_string("G5", s, 2)) {
        return G005S;
    } else if (comparar_string("G6", s, 2)) {
        return G006S;
    } else if (comparar_string("H1", s, 2)) {
        return H001S;
    } else if (comparar_string("H2", s, 2)) {
        return H002S;
    } else if (comparar_string("H3", s, 2)) {
        return H003S;
    } else if (comparar_string("H4", s, 2)) {
        return H004S;
    } else if (comparar_string("H5", s, 2)) {
        return H005S;
    } else if (comparar_string("H6", s, 2)) {
        return H006S;
    } else if (comparar_string("I1", s, 2)) {
        return I001S;
    } else if (comparar_string("I2", s, 2)) {
        return I002S;
    } else if (comparar_string("I3", s, 2)) {
        return I003S;
    } else if (comparar_string("I4", s, 2)) {
        return I004S;
    } else if (comparar_string("I5", s, 2)) {
        return I005S;
    } else if (comparar_string("I6", s, 2)) {
        return I006S;
    } else if (comparar_string("J1", s, 2)) {
        return J001S;
    } else if (comparar_string("J2", s, 2)) {
        return J002S;
    } else if (comparar_string("J3", s, 2)) {
        return J003S;
    } else if (comparar_string("J4", s, 2)) {
        return J004S;
    } else if (comparar_string("J5", s, 2)) {
        return J005S;
    } else if (comparar_string("J6", s, 2)) {
        return J006S;
    } else if (comparar_string("K1", s, 2)) {
        return K001S;
    } else if (comparar_string("K2", s, 2)) {
        return K002S;
    } else if (comparar_string("K3", s, 2)) {
        return K003S;
    } else if (comparar_string("K4", s, 2)) {
        return K004S;
    } else if (comparar_string("K5", s, 2)) {
        return K005S;
    } else if (comparar_string("K6", s, 2)) {
        return K006S;
    } else if (comparar_string("L1", s, 2)) {
        return L001S;
    } else if (comparar_string("L2", s, 2)) {
        return L002S;
    } else if (comparar_string("L3", s, 2)) {
        return L003S;
    } else if (comparar_string("L4", s, 2)) {
        return L004S;
    } else if (comparar_string("L5", s, 2)) {
        return L005S;
    } else if (comparar_string("L6", s, 2)) {
        return L006S;
    } else if (comparar_string("M1", s, 2)) {
        return M001S;
    } else if (comparar_string("M2", s, 2)) {
        return M002S;
    } else if (comparar_string("M3", s, 2)) {
        return M003S;
    } else if (comparar_string("M4", s, 2)) {
        return M004S;
    } else if (comparar_string("M5", s, 2)) {
        return M005S;
    } else if (comparar_string("M6", s, 2)) {
        return M006S;
    } else if (comparar_string("N1", s, 2)) {
        return N001S;
    } else if (comparar_string("N2", s, 2)) {
        return N002S;
    } else if (comparar_string("N3", s, 2)) {
        return N003S;
    } else if (comparar_string("N4", s, 2)) {
        return N004S;
    } else if (comparar_string("N5", s, 2)) {
        return N005S;
    } else if (comparar_string("N6", s, 2)) {
        return N006S;
    } else if (comparar_string("O1", s, 2)) {
        return O001S;
    } else if (comparar_string("O2", s, 2)) {
        return O002S;
    } else if (comparar_string("O3", s, 2)) {
        return O003S;
    } else if (comparar_string("O4", s, 2)) {
        return O004S;
    } else if (comparar_string("O5", s, 2)) {
        return O005S;
    } else if (comparar_string("O6", s, 2)) {
        return O006S;
    } else if (comparar_string("P1", s, 2)) {
        return P001S;
    } else if (comparar_string("P2", s, 2)) {
        return P002S;
    } else if (comparar_string("P3", s, 2)) {
        return P003S;
    } else if (comparar_string("P4", s, 2)) {
        return P004S;
    } else if (comparar_string("P5", s, 2)) {
        return P005S;
    } else if (comparar_string("P6", s, 2)) {
        return P006S;
    } else if (comparar_string("Q1", s, 2)) {
        return Q001S;
    } else if (comparar_string("Q2", s, 2)) {
        return Q002S;
    } else if (comparar_string("Q3", s, 2)) {
        return Q003S;
    } else if (comparar_string("Q4", s, 2)) {
        return Q004S;
    } else if (comparar_string("Q5", s, 2)) {
        return Q005S;
    } else if (comparar_string("Q6", s, 2)) {
        return Q006S;
    } else if (comparar_string("R1", s, 2)) {
        return R001S;
    } else if (comparar_string("R2", s, 2)) {
        return R002S;
    } else if (comparar_string("R3", s, 2)) {
        return R003S;
    } else if (comparar_string("R4", s, 2)) {
        return R004S;
    } else if (comparar_string("R5", s, 2)) {
        return R005S;
    } else if (comparar_string("R6", s, 2)) {
        return R006S;
    } else {
        return -1;
    }
}
