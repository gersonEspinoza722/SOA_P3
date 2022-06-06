#ifndef PROYECTO_3_HANDLERS_PUENTES_H
#define PROYECTO_3_HANDLERS_PUENTES_H

#include <stdbool.h>

#define PUENTE_DIR_NORTE false
#define PUENTE_DIR_SUR true

typedef enum TipoPuentes {
    LARRY = 0,
    CURLY = 1,
    MOE = 2,
    SHEMP = 3,
    JOE = 4
} TipoPuentes;

typedef struct CurlyShempInformacion {
    int *rango_lado_norte;
    int *rango_lado_sur;
    TipoPuentes tipo;
    bool direccion;
    bool *siguienteDireccion;
} CurlyShempInformacion;

typedef struct LarryJoeInformacion {
    int *rango_lado_norte;
    int *rango_lado_sur;
    TipoPuentes tipo;
    bool direccion;
    bool *siguienteDireccion;
} LarryJoeInformacion;

void *handleLarryJoe(void *arg);

void *handleCurlyShemp(void *arg);

CurlyShempInformacion *crearCurlyShempInfo(
        bool direccion, TipoPuentes tipo, bool *siguienteDireccion,
        int idInicioNorte, int idFinNorte,
        int idInicioSur, int idFinSur
);

LarryJoeInformacion *crearLarryJoeInfo(
        bool direccion, TipoPuentes tipo, bool *siguienteDireccion,
        int idInicioNorte, int idFinNorte,
        int idInicioSur, int idFinSur
);

#endif 
