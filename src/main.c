#include <stdio.h>
#include <gtk/gtk.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include <reparacion.h>
#include <controlador_puentes.h>
#include "mapa.h"
#include "ui.h"
#include "algoritmo_floyd.h"
#include "controlador.h"

//Variables de interfaz
extern GtkWidget *window;
GtkWidget *drA_mapas_imagenes;

extern ThreadvilleMapa *mapa;
extern GtkBuilder *builder;

extern int K;
extern int M;
extern int N;

//void iniciarPuenteLarry() {
//    pthread_t *tid;
//    volatile int i;
//    extern pthread_cond_t *cond_larry;
//
//    cond_larry = (pthread_cond_t *) malloc(sizeof(pthread_cond_t) * 2);
//    tid = (pthread_t *) malloc(sizeof(pthread_t) * 2);
//
//    bool* siguienteDireccion = crear_memoria_compartida(sizeof(bool));
//
//    // Linking semaforos
//    LarryJoeInformacion* infoNorte = crearLarryJoeInfo(false, LARRY, siguienteDireccion);
//    LarryJoeInformacion* infoSur = crearLarryJoeInfo(true, LARRY, siguienteDireccion);
//
//    pthread_create(&tid[0], NULL, handleCurlyShemp, (void *) infoNorte);
//    pthread_create(&tid[1], NULL, handleCurlyShemp, (void *) infoSur);
//
//    // Esperando por el hilo
//    for (i = 0; i < 2; i++) {
//        pthread_join(tid[i], NULL);
//    }
//
//}

void iniciarShemp(int idInicioNorte, int idFinNorte, int idInicioSur, int idFinSur) {
    pthread_t *tid;
    extern pthread_cond_t *cond_shemp;
    extern pthread_mutex_t *mutex_shemp;

    cond_shemp = (pthread_cond_t *) crear_memoria_compartida(sizeof(pthread_cond_t) * 2);
    mutex_shemp = get_mutex(get_atributos_mutex());
    tid = (pthread_t *) malloc(sizeof(pthread_t) * 2);

    bool* siguienteDireccion = crear_memoria_compartida(sizeof(bool));

    CurlyShempInformacion* infoNorte = crearCurlyShempInfo(
            PUENTE_DIR_NORTE, SHEMP, siguienteDireccion,
            idInicioNorte, idFinNorte,
            idInicioSur, idFinSur
    );
    CurlyShempInformacion* infoSur = crearCurlyShempInfo(
            PUENTE_DIR_SUR, SHEMP, siguienteDireccion,
            idInicioNorte, idFinNorte,
            idInicioSur, idFinSur
    );

    pthread_create(&tid[0], NULL, handleCurlyShemp, (void *) infoNorte);
    pthread_detach(tid[0]);
    pthread_create(&tid[1], NULL, handleCurlyShemp, (void *) infoSur);
    pthread_detach(tid[1]);
}

void iniciarCurl(int idInicioNorte, int idFinNorte, int idInicioSur, int idFinSur) {
    pthread_t *tid;
    extern pthread_cond_t *cond_curly;
    extern pthread_mutex_t *mutex_curly;

    // Reservar memoria para variables condicionales, ids de los hilos y el array de hilos
    cond_curly = (pthread_cond_t *) crear_memoria_compartida(sizeof(pthread_cond_t) * 2);
    mutex_curly = get_mutex(get_atributos_mutex());
    tid = (pthread_t *) malloc(sizeof(pthread_t) * 2);

    bool* siguienteDireccion = crear_memoria_compartida(sizeof(bool));

    CurlyShempInformacion* infoNorte = crearCurlyShempInfo(PUENTE_DIR_NORTE, CURLY, siguienteDireccion,
            idInicioNorte, idFinNorte, idInicioSur, idFinSur);
    CurlyShempInformacion* infoSur = crearCurlyShempInfo(PUENTE_DIR_SUR, CURLY, siguienteDireccion,
            idInicioNorte, idFinNorte, idInicioSur, idFinSur);

    pthread_create(&tid[0], NULL, handleCurlyShemp, (void *) infoSur);
    pthread_create(&tid[1], NULL, handleCurlyShemp, (void *) infoNorte);
    pthread_detach(tid[0]);
    pthread_detach(tid[1]);
}

void iniciarLarry(int idInicioNorte, int idFinNorte, int idInicioSur, int idFinSur) {
    pthread_t *tid;
    extern pthread_cond_t *cond_larry;
    extern pthread_mutex_t *mutex_larry;

    // Reservar memoria para variables condicionales, ids de los hilos y el array de hilos
    cond_larry = (pthread_cond_t *) crear_memoria_compartida(sizeof(pthread_cond_t) * 2);
    mutex_larry = get_mutex(get_atributos_mutex());
    tid = (pthread_t *) malloc(sizeof(pthread_t) * 2);

    bool* siguienteDireccion = crear_memoria_compartida(sizeof(bool));

    LarryJoeInformacion* infoNorte = crearLarryJoeInfo(PUENTE_DIR_NORTE, LARRY, siguienteDireccion,
            idInicioNorte, idFinNorte, idInicioSur, idFinSur);
    LarryJoeInformacion* infoSur = crearLarryJoeInfo(PUENTE_DIR_SUR, LARRY, siguienteDireccion,
            idInicioNorte, idFinNorte, idInicioSur, idFinSur);

    pthread_create(&tid[0], NULL, handleLarryJoe, (void *) infoNorte);
    pthread_create(&tid[1], NULL, handleLarryJoe, (void *) infoSur);
    pthread_detach(tid[0]);
    pthread_detach(tid[1]);
}

void iniciarJoe(int idInicioNorte, int idFinNorte, int idInicioSur, int idFinSur) {
    pthread_t *tid;
    extern pthread_cond_t *cond_joe;
    extern pthread_mutex_t *mutex_joe;

    // Reservar memoria para variables condicionales, ids de los hilos y el array de hilos
    cond_joe = (pthread_cond_t *) crear_memoria_compartida(sizeof(pthread_cond_t) * 2);
    mutex_joe = get_mutex(get_atributos_mutex());
    tid = (pthread_t *) malloc(sizeof(pthread_t) * 2);

    bool* siguienteDireccion = crear_memoria_compartida(sizeof(bool));

    LarryJoeInformacion* infoNorte = crearLarryJoeInfo(PUENTE_DIR_NORTE, JOE, siguienteDireccion,
            idInicioNorte, idFinNorte, idInicioSur, idFinSur);
    LarryJoeInformacion* infoSur = crearLarryJoeInfo(PUENTE_DIR_SUR, JOE, siguienteDireccion,
            idInicioNorte, idFinNorte, idInicioSur, idFinSur);

    pthread_create(&tid[0], NULL, handleLarryJoe, (void *) infoNorte);
    pthread_create(&tid[1], NULL, handleLarryJoe, (void *) infoSur);
    pthread_detach(tid[0]);
    pthread_detach(tid[1]);
}

int main(int argc, char *argv[]) {
    imprimir_bienvenida();
//    floyd();  //Solo hay que ejecutarlo una vez para crear el archivo y ya
//    generar_archivo();
    mapa = crear_threadville_mapa();

    //Inicializacion
    gtk_init(&argc, &argv);
    cargar_interfaz();

    //Agregar archivos Glade
    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "glade/threadville.glade", NULL);


        // Nuevo CCS
    GtkCssProvider *cssProvider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(cssProvider, "glade/style.css", NULL);
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(), GTK_STYLE_PROVIDER(cssProvider), GTK_STYLE_PROVIDER_PRIORITY_USER);

    // Hilo de mantenimiento 
    pthread_t hiloMantenimiento;
    pthread_create(&hiloMantenimiento, NULL, &hacer_mantenimiento, NULL);
    pthread_detach(hiloMantenimiento);

    // Inicializacion de puentes
    iniciarCurl(B007B, B012B, BU07B, BU12B);
    iniciarShemp(B019B, B024B, BU19B, BU24B);
    iniciarLarry(B001B, B006B, BU01B, BU06B);
    iniciarJoe(B025B, B030B, BU25B, BU30B);

    //Conectar el xml con codigo del main
    window = GTK_WIDGET(gtk_builder_get_object(builder, "win_threadville"));
    drA_mapas_imagenes = GTK_WIDGET(gtk_builder_get_object(builder, "drA_mapas_imagenes"));
    g_signal_connect(drA_mapas_imagenes, "draw", G_CALLBACK(on_window_draw), NULL);

    gtk_builder_connect_signals(builder, NULL);

    gtk_widget_show(window);
    g_timeout_add(1000 / 60 / 2, (GSourceFunc) on_tick, drA_mapas_imagenes);  //60 fps

    GtkWidget *input= GTK_WIDGET(gtk_builder_get_object(builder, "input_K"));
    char int_char[5];
    sprintf(int_char, "%d", K);
    gtk_entry_set_text(GTK_ENTRY(input), int_char);
    input= GTK_WIDGET(gtk_builder_get_object(builder, "input_M"));
    sprintf(int_char, "%d", M);
    gtk_entry_set_text(GTK_ENTRY(input), int_char);
    input= GTK_WIDGET(gtk_builder_get_object(builder, "input_N"));
    sprintf(int_char, "%d", N);
    gtk_entry_set_text(GTK_ENTRY(input), int_char);
    activar_todos_buses();
    gtk_main();

    return 0;
}
