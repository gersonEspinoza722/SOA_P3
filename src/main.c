#include <stdio.h>
#include <gtk/gtk.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include <threadville_mantenimiento.h>
#include <handlers_puentes.h>
#include "threadville_mapa.h"
#include "interface.h"
#include "floyd.h"
#include "controlador.h"

//Interface variables
extern GtkWidget *window;
GtkWidget *drA_maps_images;

extern ThreadvilleMapa *mapa;
extern GtkBuilder *builder;

extern int K;
extern int M;
extern int N;

//void startBridgeLarry() {
//    pthread_t *tid;
//    volatile int i;
//    extern pthread_cond_t *cond_larry;
//
//    cond_larry = (pthread_cond_t *) malloc(sizeof(pthread_cond_t) * 2);
//    tid = (pthread_t *) malloc(sizeof(pthread_t) * 2);
//
//    bool* siguienteDireccion = crear_memoria_compartida(sizeof(bool));
//
//    // Linking semaphores
//    LarryJoeInformacion* northInfo = crearLarryJoeInfo(false, LARRY, siguienteDireccion);
//    LarryJoeInformacion* southInfo = crearLarryJoeInfo(true, LARRY, siguienteDireccion);
//
//    pthread_create(&tid[0], NULL, handleCurlyShemp, (void *) northInfo);
//    pthread_create(&tid[1], NULL, handleCurlyShemp, (void *) southInfo);
//
//    // waiting for thread
//    for (i = 0; i < 2; i++) {
//        pthread_join(tid[i], NULL);
//    }
//
//}

void startShemp(
        int idInicioNorte, int idFinNorte,
        int idInicioSur, int idFinSur
) {
    pthread_t *tid;
    extern pthread_cond_t *cond_shemp;
    extern pthread_mutex_t *mutex_shemp;
    // allocate memory to cond (conditional variable),
    // thread id's and array of tamanio threads
    cond_shemp = (pthread_cond_t *) crear_memoria_compartida(sizeof(pthread_cond_t) * 2);
    mutex_shemp = get_mutex(get_atributos_mutex());
    tid = (pthread_t *) malloc(sizeof(pthread_t) * 2);

    bool* siguienteDireccion = crear_memoria_compartida(sizeof(bool));

    CurlyShempInformacion* northInfo = crearCurlyShempInfo(
            PUENTE_DIR_NORTE, SHEMP, siguienteDireccion,
            idInicioNorte, idFinNorte,
            idInicioSur, idFinSur
    );
    CurlyShempInformacion* southInfo = crearCurlyShempInfo(
            PUENTE_DIR_SUR, SHEMP, siguienteDireccion,
            idInicioNorte, idFinNorte,
            idInicioSur, idFinSur
    );

    pthread_create(&tid[0], NULL, handleCurlyShemp, (void *) northInfo);
    pthread_detach(tid[0]);
    pthread_create(&tid[1], NULL, handleCurlyShemp, (void *) southInfo);
    pthread_detach(tid[1]);
}

void startCurl(int idInicioNorte, int idFinNorte,
               int idInicioSur, int idFinSur) {
    pthread_t *tid;
    extern pthread_cond_t *cond_curly;
    extern pthread_mutex_t *mutex_curly;
    // allocate memory to cond (conditional variable),
    // thread id's and array of tamanio threads
    cond_curly = (pthread_cond_t *) crear_memoria_compartida(sizeof(pthread_cond_t) * 2);
    mutex_curly = get_mutex(get_atributos_mutex());
    tid = (pthread_t *) malloc(sizeof(pthread_t) * 2);

    bool* siguienteDireccion = crear_memoria_compartida(sizeof(bool));

    CurlyShempInformacion* northInfo = crearCurlyShempInfo(
            PUENTE_DIR_NORTE, CURLY, siguienteDireccion,
            idInicioNorte, idFinNorte,
            idInicioSur, idFinSur
    );
    CurlyShempInformacion* southInfo = crearCurlyShempInfo(
            PUENTE_DIR_SUR, CURLY, siguienteDireccion,
            idInicioNorte, idFinNorte,
            idInicioSur, idFinSur
    );

    pthread_create(&tid[0], NULL, handleCurlyShemp, (void *) southInfo);
    pthread_create(&tid[1], NULL, handleCurlyShemp, (void *) northInfo);
    pthread_detach(tid[0]);
    pthread_detach(tid[1]);
}

void startLarry(int idInicioNorte, int idFinNorte,
                int idInicioSur, int idFinSur) {
    pthread_t *tid;
    extern pthread_cond_t *cond_larry;
    extern pthread_mutex_t *mutex_larry;

    // allocate memory to cond (conditional variable),
    // thread id's and array of tamanio threads
    cond_larry = (pthread_cond_t *) crear_memoria_compartida(sizeof(pthread_cond_t) * 2);
    mutex_larry = get_mutex(get_atributos_mutex());
    tid = (pthread_t *) malloc(sizeof(pthread_t) * 2);

    bool* siguienteDireccion = crear_memoria_compartida(sizeof(bool));

    LarryJoeInformacion* northInfo = crearLarryJoeInfo(
            PUENTE_DIR_NORTE, LARRY, siguienteDireccion,
            idInicioNorte, idFinNorte,
            idInicioSur, idFinSur
    );
    LarryJoeInformacion* southInfo = crearLarryJoeInfo(
            PUENTE_DIR_SUR, LARRY, siguienteDireccion,
            idInicioNorte, idFinNorte,
            idInicioSur, idFinSur
    );

    pthread_create(&tid[0], NULL, handleLarryJoe, (void *) northInfo);
    pthread_create(&tid[1], NULL, handleLarryJoe, (void *) southInfo);
    pthread_detach(tid[0]);
    pthread_detach(tid[1]);
}

void startJoe(int idInicioNorte, int idFinNorte,
              int idInicioSur, int idFinSur) {
    pthread_t *tid;
    extern pthread_cond_t *cond_joe;
    extern pthread_mutex_t *mutex_joe;

    // allocate memory to cond (conditional variable),
    // thread id's and array of tamanio threads
    cond_joe = (pthread_cond_t *) crear_memoria_compartida(sizeof(pthread_cond_t) * 2);
    mutex_joe = get_mutex(get_atributos_mutex());
    tid = (pthread_t *) malloc(sizeof(pthread_t) * 2);

    bool* siguienteDireccion = crear_memoria_compartida(sizeof(bool));

    LarryJoeInformacion* northInfo = crearLarryJoeInfo(
            PUENTE_DIR_NORTE, JOE, siguienteDireccion,
            idInicioNorte, idFinNorte,
            idInicioSur, idFinSur
    );
    LarryJoeInformacion* southInfo = crearLarryJoeInfo(
            PUENTE_DIR_SUR, JOE, siguienteDireccion,
            idInicioNorte, idFinNorte,
            idInicioSur, idFinSur
    );

    pthread_create(&tid[0], NULL, handleLarryJoe, (void *) northInfo);
    pthread_create(&tid[1], NULL, handleLarryJoe, (void *) southInfo);
    pthread_detach(tid[0]);
    pthread_detach(tid[1]);
}

int main(int argc, char *argv[]) {
    print_wellcome();
//    floyd();  //Solo hay que ejecutarlo una vez para crear el archivo y ya
//    generar_archivo();
    mapa = crear_threadville_mapa();

    //Init
    gtk_init(&argc, &argv);
    load_interface();

    //Add glade files
    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "glade/threadville.glade", NULL);

    // Maintenance thread
    pthread_t hiloMantenimiento;
    pthread_create(&hiloMantenimiento, NULL, &hacer_mantenimiento, NULL);
    pthread_detach(hiloMantenimiento);

    // Curly bridge initialization
    startCurl(
            B007B, B012B,
            BU07B, BU12B
    );
    // Shemp bridge initialization
    startShemp(
            B019B, B024B,
            BU19B, BU24B
    );
    // Larry bridge initialization
    startLarry(
            B001B, B006B,
            BU01B, BU06B
    );
    // Joe bridge initialization
   startJoe(
           B025B, B030B,
           BU25B, BU30B
   );

    //Conect xml with code with main code/variables
    window = GTK_WIDGET(gtk_builder_get_object(builder, "win_threadville"));
    drA_maps_images = GTK_WIDGET(gtk_builder_get_object(builder, "drA_maps_images"));
    g_signal_connect(drA_maps_images, "draw", G_CALLBACK(on_window_draw), NULL);

    gtk_builder_connect_signals(builder, NULL);

    gtk_widget_show(window);
    g_timeout_add(1000 / 60 / 2, (GSourceFunc) on_tick, drA_maps_images);  //60 is the fps

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
