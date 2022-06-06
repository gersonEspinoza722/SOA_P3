#include <stdio.h>
#include <stdlib.h>
#include "grafico.h"
#include "grafico_floyd.h"
#include <stdbool.h>
#include "algoritmo_floyd.h"

#define CONTEO_NODOS 985

int threadville_floyd_matriz[CONTEO_NODOS][CONTEO_NODOS];

void print_matriz(int matrix[CONTEO_NODOS][CONTEO_NODOS]) {
    int i, j;
    for (i = 0; i < CONTEO_NODOS; i++) {
        for (j = 0; j < CONTEO_NODOS; j++) {
            printf("%d,", matrix[i][j]);
        }
        printf("\n");
    }
}

void generar_archivo(){
    FILE *fp;
    fp = fopen ("./include/grafico_floyd.h", "w");
    fputs("int threadville_graph_fast[", fp);

    char snum[100];
    sprintf(snum, "%d", CONTEO_NODOS);
    fputs(snum, fp);
    fputs("][", fp);
    fputs(snum, fp);
    fputs("]  =  {", fp);

    int i, j;
    for (i = 0; i < CONTEO_NODOS; i++) {
        fputs("{", fp);

        for (j = 0; j < CONTEO_NODOS; j++) {

            sprintf(snum, "%d", threadville_floyd_matriz[i][j]);
            fputs(snum, fp);
            if (j+1<CONTEO_NODOS){
                    fputs(" ,", fp);
            }

        }
        if (i+1<CONTEO_NODOS){
            fputs("},\n", fp);
        }else{
            fputs("}};\n", fp);
        }
    }

    fclose (fp);
}

void inicializar_reconstruccion_matriz() {
    int i, j;
    for (i = 0; i < CONTEO_NODOS; i++) {
        for (j = 0; j < CONTEO_NODOS; j++) {
            threadville_floyd_matriz[i][j] = i;
        }
    }
}

bool floyd_comparar_nodos(int i, int j, int k) {
    if (threadville_graph[i][k] < 0 || threadville_graph[k][j] < 0) {
        return false;
    }
    if (threadville_graph[i][j] < 0) {
        return true;
    }
    return threadville_graph[i][k] + threadville_graph[k][j] < threadville_graph[i][j];
}

void floyd() {
    inicializar_reconstruccion_matriz();
    for (int k = 0; k < CONTEO_NODOS; k++) {
        for (int i = 0; i < CONTEO_NODOS; i++) {
            for (int j = 0; j < CONTEO_NODOS; j++) {
                if (floyd_comparar_nodos(i, j, k)) {
                    threadville_graph[i][j] = threadville_graph[i][k] + threadville_graph[k][j];
                    threadville_floyd_matriz[i][j] = threadville_floyd_matriz[k][j];
                }
            }
        }
    }
}

int *floyd_path_auxiliar(int i, int j, int *floyd_path) {
    floyd_path[0]++;
    floyd_path[floyd_path[0]] = j;
    if (i != j) {
        floyd_path_auxiliar(i, threadville_floyd_matriz[i][j], floyd_path);
    }
    return floyd_path;
}

int *floyd_path_auxiliar_rapido(int i, int j, int *floyd_path) {
    floyd_path[0]++;
    floyd_path[floyd_path[0]] = j;
    if (i != j) {
        floyd_path_auxiliar_rapido(i, threadville_graph_fast[i][j], floyd_path);
    }
    return floyd_path;
}

int *floyd_path(int i, int j) {
    int pathBuffer[CONTEO_NODOS*CONTEO_NODOS];
    pathBuffer[0] = 0;
    // floyd_path_auxiliar(i, j, pathBuffer);
    floyd_path_auxiliar_rapido(i, j, pathBuffer);
    int largoPath = pathBuffer[0];
    int *floyd_path = malloc(sizeof(int) * (largoPath + 1));
    floyd_path[0] = largoPath;
    for (i = 0; i < largoPath; i++) {
        floyd_path[largoPath - i] = pathBuffer[i + 1];
    }
    return floyd_path;
}
