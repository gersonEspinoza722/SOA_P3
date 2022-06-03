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
        headers/globals.h
        headers/graph.h
        headers/hash_table.h
        headers/hash_table_street_info.h
        headers/interface.h
        headers/lista_enlazada.h
        headers/lista_enlazada_carros.h
        headers/priority_semaphore.h
        headers/threadville_maintenance.h
        headers/threadville_map.h
        headers/utils.h
        headers/vehiculo.h
        src/bridge_handlers.c
        src/controller.c
        src/dict.c
        src/floyd.c
        src/hash_table.c
        src/hash_table_street_info.c
        src/interface.c
        src/linked_list.c
        src/linked_lists_cars.c
        src/priority_semaphore.c
        src/main.c
        src/threadville_maintenance.c
        src/threadville_map.c
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
