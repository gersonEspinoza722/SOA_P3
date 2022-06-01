#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "graph_floyd.h"
#include <stdbool.h>
#include "floyd.h"

#define NODES_COUNT 985

int threadville_floyd_matrix[NODES_COUNT][NODES_COUNT];

void print_matrix(int matrix[NODES_COUNT][NODES_COUNT]) {
    int i, j;
    for (i = 0; i < NODES_COUNT; i++) {
        for (j = 0; j < NODES_COUNT; j++) {
            printf("%d,", matrix[i][j]);
        }
        printf("\n");
    }
}

void generate_file(){
    FILE *fp;
    fp = fopen ("./headers/graph_floyd.h", "w");
    fputs("int threadville_graph_fast[", fp);

    char snum[100];
    sprintf(snum, "%d", NODES_COUNT);
    fputs(snum, fp);
    fputs("][", fp);
    fputs(snum, fp);
    fputs("]  =  {", fp);

    int i, j;
    for (i = 0; i < NODES_COUNT; i++) {

        fputs("{", fp);

        for (j = 0; j < NODES_COUNT; j++) {

            sprintf(snum, "%d", threadville_floyd_matrix[i][j]);
            fputs(snum, fp);
            if (j+1<NODES_COUNT){
                    fputs(" ,", fp);
            }

        }
        if (i+1<NODES_COUNT){
            fputs("},\n", fp);
        }else{
            fputs("}};\n", fp);
        }
    }


    fclose (fp);

}

void initialize_reconstruction_matrix() {
    int i, j;
    for (i = 0; i < NODES_COUNT; i++) {
        for (j = 0; j < NODES_COUNT; j++) {
            threadville_floyd_matrix[i][j] = i;
        }
    }
}

bool floyd_compare_nodes(int i, int j, int k) {
    if (threadville_graph[i][k] < 0 || threadville_graph[k][j] < 0) {
        return false;
    }
    if (threadville_graph[i][j] < 0) {
        return true;
    }
    return threadville_graph[i][k] + threadville_graph[k][j] < threadville_graph[i][j];
}

void floyd() {
    initialize_reconstruction_matrix();
    for (int k = 0; k < NODES_COUNT; k++) {
        for (int i = 0; i < NODES_COUNT; i++) {
            for (int j = 0; j < NODES_COUNT; j++) {
                if (floyd_compare_nodes(i, j, k)) {
                    threadville_graph[i][j] = threadville_graph[i][k] + threadville_graph[k][j];
                    threadville_floyd_matrix[i][j] = threadville_floyd_matrix[k][j];
                }
            }
        }
    }
}

int *floyd_path_aux(int i, int j, int *floyd_path) {
    floyd_path[0]++;
    floyd_path[floyd_path[0]] = j;
    if (i != j) {
        floyd_path_aux(i, threadville_floyd_matrix[i][j], floyd_path);
    }
    return floyd_path;
}

int *floyd_path_aux_fast(int i, int j, int *floyd_path) {
    floyd_path[0]++;
    floyd_path[floyd_path[0]] = j;
    if (i != j) {
        floyd_path_aux_fast(i, threadville_graph_fast[i][j], floyd_path);
    }
    return floyd_path;
}

int *floyd_path(int i, int j) {
    int path_buffer[NODES_COUNT*NODES_COUNT];
    path_buffer[0] = 0;
    // floyd_path_aux(i, j, path_buffer);
    floyd_path_aux_fast(i, j, path_buffer);
    int path_length = path_buffer[0];
    int *floyd_path = malloc(sizeof(int) * (path_length + 1)); // to accommodate for size as first index
    floyd_path[0] = path_length;
    for (i = 0; i < path_length; i++) {
        floyd_path[path_length - i] = path_buffer[i + 1];
    }
    return floyd_path;
}
