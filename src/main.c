#include <stdio.h>
#include <gtk/gtk.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include <threadville_maintenance.h>
#include <bridge_handlers.h>
#include "threadville_map.h"
#include "interface.h"
#include "floyd.h"
#include "controller.h"

//Interface variables
extern GtkWidget *window;
GtkWidget *drA_maps_images;

extern ThreadvilleMap *map;
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
//    bool* nextDirection = create_shared_memory(sizeof(bool));
//
//    // Linking semaphores
//    LarryJoeInformation* northInfo = createLarryJoeInfo(false, LARRY, nextDirection);
//    LarryJoeInformation* southInfo = createLarryJoeInfo(true, LARRY, nextDirection);
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
        int start_north_id, int end_north_id,
        int start_south_id, int end_south_id
) {
    pthread_t *tid;
    extern pthread_cond_t *cond_shemp;
    extern pthread_mutex_t *mutex_shemp;
    // allocate memory to cond (conditional variable),
    // thread id's and array of size threads
    cond_shemp = (pthread_cond_t *) create_shared_memory(sizeof(pthread_cond_t) * 2);
    mutex_shemp = get_mutex(get_mutex_attributes());
    tid = (pthread_t *) malloc(sizeof(pthread_t) * 2);

    bool* nextDirection = create_shared_memory(sizeof(bool));

    CurlyShempInformation* northInfo = createCurlyShempInfo(
            NORTH_DIR_BRIDGE, SHEMP, nextDirection,
            start_north_id, end_north_id,
            start_south_id, end_south_id
    );
    CurlyShempInformation* southInfo = createCurlyShempInfo(
            SOUTH_DIR_BRIDGE, SHEMP, nextDirection,
            start_north_id, end_north_id,
            start_south_id, end_south_id
    );

    pthread_create(&tid[0], NULL, handleCurlyShemp, (void *) northInfo);
    pthread_detach(tid[0]);
    pthread_create(&tid[1], NULL, handleCurlyShemp, (void *) southInfo);
    pthread_detach(tid[1]);
}

void startCurl(int start_north_id, int end_north_id,
               int start_south_id, int end_south_id) {
    pthread_t *tid;
    extern pthread_cond_t *cond_curly;
    extern pthread_mutex_t *mutex_curly;
    // allocate memory to cond (conditional variable),
    // thread id's and array of size threads
    cond_curly = (pthread_cond_t *) create_shared_memory(sizeof(pthread_cond_t) * 2);
    mutex_curly = get_mutex(get_mutex_attributes());
    tid = (pthread_t *) malloc(sizeof(pthread_t) * 2);

    bool* nextDirection = create_shared_memory(sizeof(bool));

    CurlyShempInformation* northInfo = createCurlyShempInfo(
            NORTH_DIR_BRIDGE, CURLY, nextDirection,
            start_north_id, end_north_id,
            start_south_id, end_south_id
    );
    CurlyShempInformation* southInfo = createCurlyShempInfo(
            SOUTH_DIR_BRIDGE, CURLY, nextDirection,
            start_north_id, end_north_id,
            start_south_id, end_south_id
    );

    pthread_create(&tid[0], NULL, handleCurlyShemp, (void *) southInfo);
    pthread_create(&tid[1], NULL, handleCurlyShemp, (void *) northInfo);
    pthread_detach(tid[0]);
    pthread_detach(tid[1]);
}

void startLarry(int start_north_id, int end_north_id,
                int start_south_id, int end_south_id) {
    pthread_t *tid;
    extern pthread_cond_t *cond_larry;
    extern pthread_mutex_t *mutex_larry;

    // allocate memory to cond (conditional variable),
    // thread id's and array of size threads
    cond_larry = (pthread_cond_t *) create_shared_memory(sizeof(pthread_cond_t) * 2);
    mutex_larry = get_mutex(get_mutex_attributes());
    tid = (pthread_t *) malloc(sizeof(pthread_t) * 2);

    bool* nextDirection = create_shared_memory(sizeof(bool));

    LarryJoeInformation* northInfo = createLarryJoeInfo(
            NORTH_DIR_BRIDGE, LARRY, nextDirection,
            start_north_id, end_north_id,
            start_south_id, end_south_id
    );
    LarryJoeInformation* southInfo = createLarryJoeInfo(
            SOUTH_DIR_BRIDGE, LARRY, nextDirection,
            start_north_id, end_north_id,
            start_south_id, end_south_id
    );

    pthread_create(&tid[0], NULL, handleLarryJoe, (void *) northInfo);
    pthread_create(&tid[1], NULL, handleLarryJoe, (void *) southInfo);
    pthread_detach(tid[0]);
    pthread_detach(tid[1]);
}

void startJoe(int start_north_id, int end_north_id,
              int start_south_id, int end_south_id) {
    pthread_t *tid;
    extern pthread_cond_t *cond_joe;
    extern pthread_mutex_t *mutex_joe;

    // allocate memory to cond (conditional variable),
    // thread id's and array of size threads
    cond_joe = (pthread_cond_t *) create_shared_memory(sizeof(pthread_cond_t) * 2);
    mutex_joe = get_mutex(get_mutex_attributes());
    tid = (pthread_t *) malloc(sizeof(pthread_t) * 2);

    bool* nextDirection = create_shared_memory(sizeof(bool));

    LarryJoeInformation* northInfo = createLarryJoeInfo(
            NORTH_DIR_BRIDGE, JOE, nextDirection,
            start_north_id, end_north_id,
            start_south_id, end_south_id
    );
    LarryJoeInformation* southInfo = createLarryJoeInfo(
            SOUTH_DIR_BRIDGE, JOE, nextDirection,
            start_north_id, end_north_id,
            start_south_id, end_south_id
    );

    pthread_create(&tid[0], NULL, handleLarryJoe, (void *) northInfo);
    pthread_create(&tid[1], NULL, handleLarryJoe, (void *) southInfo);
    pthread_detach(tid[0]);
    pthread_detach(tid[1]);
}

int main(int argc, char *argv[]) {
    print_wellcome();
//    floyd();  //Solo hay que ejecutarlo una vez para crear el archivo y ya
//    generate_file();
    map = create_threadville_map();

    //Init
    gtk_init(&argc, &argv);
    load_interface();

    //Add glade files
    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "glade/threadville.glade", NULL);

    // Maintenance thread
    pthread_t maintenance_thread;
    pthread_create(&maintenance_thread, NULL, &run_maintenance, NULL);
    pthread_detach(maintenance_thread);

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
    active_all_buses();
    gtk_main();

    return 0;
}
