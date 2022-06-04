cmake_minimum_required(VERSION 3.16)
project(proyecto3 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_EXE_LINKER_FLAGS "-rdynamic")

include_directories(src headers)

add_executable(proyecto3
        headers/bus.h
        headers/handlers_puentes.h
        headers/controller.h
        headers/dict.h
        headers/floyd.h
        headers/globales.h
        headers/grafico.h
        headers/hash_table.h
        headers/hash_table_info_calle.h
        headers/interface.h
        headers/lista_enlazada.h
        headers/lista_enlazada_carros.h
        headers/semaforo_prioridad.h
        headers/threadville_mantenimiento.h
        headers/threadville_mapa.h
        headers/utils.h
        headers/vehiculo.h
        src/handlers_puentes.c
        src/controller.c
        src/dict.c
        src/floyd.c
        src/hash_table.c
        src/hash_table_info_calle.c
        src/interface.c
        src/lista_enlazada.c
        src/lista_enlazada_carros.c
        src/semaforo_prioridad.c
        src/main.c
        src/threadville_mantenimiento.c
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
