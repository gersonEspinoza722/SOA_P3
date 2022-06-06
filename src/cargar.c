#include"cargar.h"
#include<gtk/gtk.h>
#include<gdk-pixbuf/gdk-pixbuf.h>
#include<cairo.h>
#include<pthread.h>
#include<string.h>
#include"dict.h"
#include"lista_enlazada_carros.h"
#include "utils.h"

struct DataItem *crear_item(char *pathImagen, EnumImagenes tipoItem, float heightReal, float widthReal) {
    GError *err = NULL;
    struct DataItem *item = (struct DataItem *) malloc(sizeof(struct DataItem));
    if (err) {
        printf("Error : %s\n", err->message);
        g_error_free(err);
    }
    item->llave = tipoItem;
    item->imagen = gdk_pixbuf_new_from_file(pathImagen, &err);
    item->width = gdk_pixbuf_get_width(item->imagen);
    item->height = gdk_pixbuf_get_height(item->imagen);
    item->h_real = heightReal;
    item->w_real = widthReal;
    item->imagen_trans = NULL;

    return item;
}
void cargar_interfaz_new(struct DataItem **hashImagenes) {
    insertar_dict(MAPA, crear_item("images/MAP.PNG", MAPA, 1.0, 1.0), hashImagenes, TAMANIO);
    //Semaforo
    insertar_dict(SEMAFOROABAJO, crear_item("images/SEMVERDEARRIBA.png", SEMAFOROABAJO, 0.16, 0.040), hashImagenes, TAMANIO);
    insertar_dict(SEMAFOROARRIBA, crear_item("images/SEMVERDEABAJO.png", SEMAFOROARRIBA, 0.16, 0.040), hashImagenes, TAMANIO);
   //REPARACION 
    insertar_dict(REPARACION, crear_item("images/ARREGLO.png", REPARACION, 0.050, 0.040), hashImagenes, TAMANIO);
    //Bus rojo
    insertar_dict(BUSROJOIZQ, crear_item("images/B_ROJO_IZ.png", BUSROJOIZQ, 0.040, 0.045), hashImagenes, TAMANIO);
    insertar_dict(BUSROJODER, crear_item("images/B_ROJO_DE.png", BUSROJODER, 0.040, 0.045), hashImagenes, TAMANIO);
    insertar_dict(BUSROJOATRAS, crear_item("images/B_ROJO_ARRIBA.png", BUSROJOATRAS, 0.065, 0.020), hashImagenes, TAMANIO);
    insertar_dict(BUSROJOFRENTE, crear_item("images/B_ROJO_ABAJO.png", BUSROJOFRENTE, 0.065, 0.020), hashImagenes, TAMANIO);
    //Bus verde
    insertar_dict(BUSVERDEIZQ, crear_item("images/B_VERDE_IZ.png", BUSVERDEIZQ, 0.040, 0.045), hashImagenes, TAMANIO);
    insertar_dict(BUSVERDEDER, crear_item("images/B_VERDE_DE.png", BUSVERDEDER, 0.040, 0.045), hashImagenes, TAMANIO);
    insertar_dict(BUSVERDEATRAS, crear_item("images/B_VERDE_ARRIBA.png", BUSVERDEATRAS, 0.065, 0.020), hashImagenes, TAMANIO);
    insertar_dict(BUSVERDEFRENTE, crear_item("images/B_VERDE_ABAJO.png", BUSVERDEFRENTE, 0.065, 0.020), hashImagenes, TAMANIO);
    //Bus azul
    insertar_dict(BUSAZULIZQ, crear_item("images/B_AZUL_IZ.png", BUSAZULIZQ, 0.040, 0.045), hashImagenes, TAMANIO);
    insertar_dict(BUSAZULDER, crear_item("images/B_AZUL_DE.png", BUSAZULDER, 0.040, 0.045), hashImagenes, TAMANIO);
    insertar_dict(BUSAZULATRAS, crear_item("images/B_AZUL_ARRIBA.png", BUSAZULATRAS, 0.065, 0.020), hashImagenes, TAMANIO);
    insertar_dict(BUSAZULFRENTE, crear_item("images/B_AZUL_ABAJO.png", BUSAZULFRENTE, 0.065, 0.020), hashImagenes, TAMANIO);
    //Bus blanco   
    insertar_dict(BUSBLANCOIZQ, crear_item("images/B_BLANCO_IZ.png", BUSBLANCOIZQ, 0.040, 0.045), hashImagenes, TAMANIO);
    insertar_dict(BUSBLANCODER, crear_item("images/B_BLANCO_DE.png", BUSBLANCODER, 0.040, 0.045), hashImagenes, TAMANIO);
    insertar_dict(BUSBLANCOATRAS, crear_item("images/B_BLANCO_ARRIBA.png", BUSBLANCOATRAS, 0.065, 0.020), hashImagenes, TAMANIO);
    insertar_dict(BUSBLANCOFRENTE, crear_item("images/B_BLANCO_ABAJO.png", BUSBLANCOFRENTE, 0.065, 0.020), hashImagenes, TAMANIO);
    //Bus gris
    insertar_dict(BUSGRISIZQ, crear_item("images/B_GRIS_IZ.png", BUSGRISIZQ, 0.040, 0.045), hashImagenes, TAMANIO);
    insertar_dict(BUSGRISDER, crear_item("images/B_GRIS_DE.png", BUSGRISDER, 0.040, 0.045), hashImagenes, TAMANIO);
    insertar_dict(BUSGRISATRAS, crear_item("images/B_GRIS_ARRIBA.png", BUSGRISATRAS, 0.065, 0.020), hashImagenes, TAMANIO);
    insertar_dict(BUSGRISFRENTE, crear_item("images/B_GRIS_ABAJO.png", BUSGRISFRENTE, 0.065, 0.020), hashImagenes, TAMANIO);
    //Bus negro
    insertar_dict(BUSNEGROIZQ, crear_item("images/B_NEGRO_IZ.png", BUSNEGROIZQ, 0.040, 0.045), hashImagenes, TAMANIO);
    insertar_dict(BUSNEGRODER, crear_item("images/B_NEGRO_DE.png", BUSNEGRODER, 0.040, 0.045), hashImagenes, TAMANIO);
    insertar_dict(BUSNEGROATRAS, crear_item("images/B_NEGRO_ARRIBA.png", BUSNEGROATRAS, 0.065, 0.020), hashImagenes, TAMANIO);
    insertar_dict(BUSNEGROFRENTE, crear_item("images/B_NEGRO_ABAJO.png", BUSNEGROFRENTE, 0.065, 0.020), hashImagenes, TAMANIO);
    //Bus rosado
    insertar_dict(BUSROSADOIZQ, crear_item("images/B_ROSA_IZ.png", BUSROSADOIZQ, 0.040, 0.045), hashImagenes, TAMANIO);
    insertar_dict(BUSROSADODER, crear_item("images/B_ROSA_DE.png", BUSROSADODER, 0.040, 0.045), hashImagenes, TAMANIO);
    insertar_dict(BUSROSADOATRAS, crear_item("images/B_ROSA_ARRIBA.png", BUSROSADOATRAS, 0.065, 0.020), hashImagenes, TAMANIO);
    insertar_dict(BUSROSADOFRENTE, crear_item("images/B_ROSA_ABAJO.png", BUSROSADOFRENTE, 0.065, 0.020), hashImagenes, TAMANIO);
    //Bus celeste
    insertar_dict(BUSCELESTEIZQ, crear_item("images/B_CELESTE_IZ.png", BUSCELESTEIZQ, 0.040, 0.045), hashImagenes, TAMANIO);
    insertar_dict(BUSCELESTEDER, crear_item("images/B_CELESTE_DE.png", BUSCELESTEDER, 0.040, 0.045), hashImagenes, TAMANIO);
    insertar_dict(BUSCELESTEATRAS, crear_item("images/B_CELESTE_ARRIBA.png", BUSCELESTEATRAS, 0.065, 0.020), hashImagenes, TAMANIO);
    insertar_dict(BUSCELESTEFRENTE, crear_item("images/B_CELESTE_ABAJO.png", BUSCELESTEFRENTE, 0.065, 0.020), hashImagenes, TAMANIO);
    //Bus naranja 
    insertar_dict(BUSNARANJAIZQ, crear_item("images/B_NARANJA_IZ.png", BUSNARANJAIZQ, 0.040, 0.045), hashImagenes, TAMANIO);
    insertar_dict(BUSNARANJADER, crear_item("images/B_NARANJA_DE.png", BUSNARANJADER, 0.040, 0.045), hashImagenes, TAMANIO);
    insertar_dict(BUSNARANJAATRAS, crear_item("images/B_NARANJA_ARRIBA.png", BUSNARANJAATRAS, 0.065, 0.020), hashImagenes, TAMANIO);
    insertar_dict(BUSNARANJAFRENTE, crear_item("images/B_NARANJA_ABAJO.png", BUSNARANJAFRENTE, 0.065, 0.020), hashImagenes, TAMANIO);
    //Ambulancia
    insertar_dict(AMBULANCIAIZQ, crear_item("images/AMBULANCIAIZ.png", AMBULANCIAIZQ, 0.035, 0.025), hashImagenes, TAMANIO);
    insertar_dict(AMBULANCIADER, crear_item("images/AMBULANCIADE.png", AMBULANCIADER, 0.035, 0.025), hashImagenes, TAMANIO);
    insertar_dict(AMBULANCIAATRAS, crear_item("images/AMBULANCIAARRIBA.png", AMBULANCIAATRAS, 0.035, 0.025), hashImagenes, TAMANIO);
    insertar_dict(AMBULANCIAFRENTE, crear_item("images/AMBULANCIAABAJO.png", AMBULANCIAFRENTE, 0.035, 0.025), hashImagenes, TAMANIO);
    //Carro rojo
    insertar_dict(CARROROJOIZQ, crear_item("images/ROJOIZ.png", CARROROJOIZQ, 0.035, 0.025), hashImagenes, TAMANIO);
    insertar_dict(CARROROJODER, crear_item("images/ROJODE.png", CARROROJODER, 0.035, 0.025), hashImagenes, TAMANIO);
    insertar_dict(CARROROJOATRAS, crear_item("images/ROJOARRIBA.png", CARROROJOATRAS, 0.035, 0.025), hashImagenes, TAMANIO);
    insertar_dict(CARROROJOFRENTE, crear_item("images/ROJOABAJO.png", CARROROJOFRENTE, 0.035, 0.025), hashImagenes, TAMANIO);
    //Carro verde    
    insertar_dict(CARROVERDEIZQ, crear_item("images/VERDEIZ.png", CARROVERDEIZQ, 0.035, 0.025), hashImagenes, TAMANIO);
    insertar_dict(CARROVERDEDER, crear_item("images/VERDEDE.png", CARROVERDEDER, 0.035, 0.025), hashImagenes, TAMANIO);
    insertar_dict(CARROVERDEATRAS, crear_item("images/VERDEARRIBA.png", CARROVERDEATRAS, 0.035, 0.025), hashImagenes, TAMANIO);
    insertar_dict(CARROVERDEFRENTE, crear_item("images/VERDEABAJO.png", CARROVERDEFRENTE, 0.035, 0.025), hashImagenes, TAMANIO);
    //Carro azul
    insertar_dict(CARROAZULIZQ, crear_item("images/AZULIZ.png", CARROAZULIZQ, 0.035, 0.025), hashImagenes, TAMANIO);
    insertar_dict(CARROAZULDER, crear_item("images/AZULDE.png", CARROAZULDER, 0.035, 0.025), hashImagenes, TAMANIO);
    insertar_dict(CARROAZULATRAS, crear_item("images/AZULARRIBA.png", CARROAZULATRAS, 0.035, 0.025), hashImagenes, TAMANIO);
    insertar_dict(CARROAZULFRENTE, crear_item("images/AZULABAJO.png", CARROAZULFRENTE, 0.035, 0.025), hashImagenes, TAMANIO);
    //Carro blanco
    insertar_dict(CARROBLANCOIZQ, crear_item("images/BLANCOIZ.png", CARROBLANCOIZQ, 0.035, 0.025), hashImagenes, TAMANIO);
    insertar_dict(CARROBLANCODER, crear_item("images/BLANCODE.png", CARROBLANCODER, 0.035, 0.025), hashImagenes, TAMANIO);
    insertar_dict(CARROBLANCOATRAS, crear_item("images/BLANCOARRIBA.png", CARROBLANCOATRAS, 0.035, 0.025), hashImagenes, TAMANIO);
    insertar_dict(CARROBLANCOFRENTE, crear_item("images/BLANCOABAJO.png", CARROBLANCOFRENTE, 0.035, 0.025), hashImagenes, TAMANIO);
    //Carro negro   
    insertar_dict(CARRONEGROIZQ, crear_item("images/NEGROIZ.png", CARRONEGROIZQ, 0.035, 0.025), hashImagenes, TAMANIO);
    insertar_dict(CARRONEGRODER, crear_item("images/NEGRODE.png", CARRONEGRODER, 0.035, 0.025), hashImagenes, TAMANIO);
    insertar_dict(CARRONEGROATRAS, crear_item("images/NEGROARRIBA.png", CARRONEGROATRAS, 0.035, 0.025), hashImagenes, TAMANIO);
    insertar_dict(CARRONEGROFRENTE, crear_item("images/NEGROABAJO.png", CARRONEGROFRENTE, 0.035, 0.025), hashImagenes, TAMANIO);
    //Carro amarillo
    insertar_dict(CARROAMARILLOIZQ, crear_item("images/AMARILLOIZ.png", CARROAMARILLOIZQ, 0.035, 0.025), hashImagenes, TAMANIO);
    insertar_dict(CARROAMARILLODER, crear_item("images/AMARILLODE.png", CARROAMARILLODER, 0.035, 0.025), hashImagenes, TAMANIO);
    insertar_dict(CARROAMARILLOATRAS, crear_item("images/AMARILLOARRIBA.png", CARROAMARILLOATRAS, 0.035, 0.025), hashImagenes, TAMANIO);
    insertar_dict(CARROAMARILLOFRENTE, crear_item("images/AMARILLOABAJO.png", CARROAMARILLOFRENTE, 0.035, 0.025), hashImagenes, TAMANIO);

}