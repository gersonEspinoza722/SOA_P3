cmake_minimum_required(VERSION 3.16)
project(proyecto3 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_EXE_LINKER_FLAGS "-rdynamic")

include_directories(src include)

add_executable(proyecto3
        include/bus.h
        include/handlers_puentes.h
        include/controlador.h
        include/dict.h
        include/floyd.h
        include/globales.h
        include/grafico.h
        include/hash_table.h
        include/hash_table_info_calle.h
        include/ui.h
        include/lista_enlazada.h
        include/lista_enlazada_carros.h
        include/semaforo_prioridad.h
        include/reparacion.h
        include/mapa.h
        include/utils.h
        include/conduccion.h
        src/handlers_puentes.c
        src/controlador.c
        src/dict.c
        src/floyd.c
        src/hash_table.c
        src/hash_table_info_calle.c
        src/interfaz.c
        src/lista_enlazada.c
        src/lista_enlazada_carros.c
        src/semaforo_prioridad.c
        src/main.c
        src/reparacion.h.c
        src/threadville_mapa.c
        src/utils.c
        src/vehiculo.c
        src/bus.c)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

add_definitions(${GTK3_CFLAGS_OTHER})

target_link_libraries(proyecto3 ${GTK3_LIBRARIES})
target_link_libraries(proyecto3 pthread)
target_link_libraries(proyecto3 m)
