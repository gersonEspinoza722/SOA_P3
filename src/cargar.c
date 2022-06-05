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
    insertar_dict(MAPA, crear_item("images/MAP.png", MAPA, 0.5, 1.0), hashImagenes, TAMANIO);
    //Semaforo
    insertar_dict(SEMAFOROABAJO, crear_item("images/SD.png", SEMAFOROABAJO, 0.16, 0.040), hashImagenes, TAMANIO);
    insertar_dict(SEMAFOROARRIBA, crear_item("images/SU.png", SEMAFOROARRIBA, 0.16, 0.040), hashImagenes, TAMANIO);
    //REPARACION 
    insertar_dict(REPARACION, crear_item("images/REPAIR.png", REPARACION, 0.050, 0.040), hashImagenes, TAMANIO);
    //Bus rojo
    insertar_dict(BUSROJOIZQ, crear_item("images/RED_BL.png", BUSROJOIZQ, 0.040, 0.045), hashImagenes, TAMANIO);
    insertar_dict(BUSROJODER, crear_item("images/RED_BR.png", BUSROJODER, 0.040, 0.045), hashImagenes, TAMANIO);
    insertar_dict(BUSROJOATRAS, crear_item("images/RED_BB.png", BUSROJOATRAS, 0.065, 0.020), hashImagenes, TAMANIO);
    insertar_dict(BUSROJOFRENTE, crear_item("images/RED_BF.png", BUSROJOFRENTE, 0.065, 0.020), hashImagenes, TAMANIO);
    //Bus verde
    insertar_dict(BUSVERDEIZQ, crear_item("images/GREEN_BL.png", BUSVERDEIZQ, 0.040, 0.045), hashImagenes, TAMANIO);
    insertar_dict(BUSVERDEDER, crear_item("images/GREEN_BR.png", BUSVERDEDER, 0.040, 0.045), hashImagenes, TAMANIO);
    insertar_dict(BUSVERDEATRAS, crear_item("images/GREEN_BB.png", BUSVERDEATRAS, 0.065, 0.020), hashImagenes, TAMANIO);
    insertar_dict(BUSVERDEFRENTE, crear_item("images/GREEN_BF.png", BUSVERDEFRENTE, 0.065, 0.020), hashImagenes, TAMANIO);
    //Bus azul
    insertar_dict(BUSAZULIZQ, crear_item("images/BLUE_BL.png", BUSAZULIZQ, 0.040, 0.045), hashImagenes, TAMANIO);
    insertar_dict(BUSAZULDER, crear_item("images/BLUE_BR.png", BUSAZULDER, 0.040, 0.045), hashImagenes, TAMANIO);
    insertar_dict(BUSAZULATRAS, crear_item("images/BLUE_BB.png", BUSAZULATRAS, 0.065, 0.020), hashImagenes, TAMANIO);
    insertar_dict(BUSAZULFRENTE, crear_item("images/BLUE_BF.png", BUSAZULFRENTE, 0.065, 0.020), hashImagenes, TAMANIO);
    //Bus blanco   
    insertar_dict(BUSBLANCOIZQ, crear_item("images/WHITE_BL.png", BUSBLANCOIZQ, 0.040, 0.045), hashImagenes, TAMANIO);
    insertar_dict(BUSBLANCODER, crear_item("images/WHITE_BR.png", BUSBLANCODER, 0.040, 0.045), hashImagenes, TAMANIO);
    insertar_dict(BUSBLANCOATRAS, crear_item("images/WHITE_BB.png", BUSBLANCOATRAS, 0.065, 0.020), hashImagenes, TAMANIO);
    insertar_dict(BUSBLANCOFRENTE, crear_item("images/WHITE_BF.png", BUSBLANCOFRENTE, 0.065, 0.020), hashImagenes, TAMANIO);
    //Bus gris
    insertar_dict(BUSGRISIZQ, crear_item("images/GRAY_BL.png", BUSGRISIZQ, 0.040, 0.045), hashImagenes, TAMANIO);
    insertar_dict(BUSGRISDER, crear_item("images/GRAY_BR.png", BUSGRISDER, 0.040, 0.045), hashImagenes, TAMANIO);
    insertar_dict(BUSGRISATRAS, crear_item("images/GRAY_BB.png", BUSGRISATRAS, 0.065, 0.020), hashImagenes, TAMANIO);
    insertar_dict(BUSGRISFRENTE, crear_item("images/GRAY_BF.png", BUSGRISFRENTE, 0.065, 0.020), hashImagenes, TAMANIO);
    //Bus negro
    insertar_dict(BUSNEGROIZQ, crear_item("images/BLACK_BL.png", BUSNEGROIZQ, 0.040, 0.045), hashImagenes, TAMANIO);
    insertar_dict(BUSNEGRODER, crear_item("images/BLACK_BR.png", BUSNEGRODER, 0.040, 0.045), hashImagenes, TAMANIO);
    insertar_dict(BUSNEGROATRAS, crear_item("images/BLACK_BB.png", BUSNEGROATRAS, 0.065, 0.020), hashImagenes, TAMANIO);
    insertar_dict(BUSNEGROFRENTE, crear_item("images/BLACK_BF.png", BUSNEGROFRENTE, 0.065, 0.020), hashImagenes, TAMANIO);
    //Bus rosado
    insertar_dict(BUSROSADOIZQ, crear_item("images/PINK_BL.png", BUSROSADOIZQ, 0.040, 0.045), hashImagenes, TAMANIO);
    insertar_dict(BUSROSADODER, crear_item("images/PINK_BR.png", BUSROSADODER, 0.040, 0.045), hashImagenes, TAMANIO);
    insertar_dict(BUSROSADOATRAS, crear_item("images/PINK_BB.png", BUSROSADOATRAS, 0.065, 0.020), hashImagenes, TAMANIO);
    insertar_dict(BUSROSADOFRENTE, crear_item("images/PINK_BF.png", BUSROSADOFRENTE, 0.065, 0.020), hashImagenes, TAMANIO);
    //Bus celeste
    insertar_dict(BUSCELESTEIZQ, crear_item("images/LBLUE_BL.png", BUSCELESTEIZQ, 0.040, 0.045), hashImagenes, TAMANIO);
    insertar_dict(BUSCELESTEDER, crear_item("images/LBLUE_BR.png", BUSCELESTEDER, 0.040, 0.045), hashImagenes, TAMANIO);
    insertar_dict(BUSCELESTEATRAS, crear_item("images/LBLUE_BB.png", BUSCELESTEATRAS, 0.065, 0.020), hashImagenes, TAMANIO);
    insertar_dict(BUSCELESTEFRENTE, crear_item("images/LBLUE_BF.png", BUSCELESTEFRENTE, 0.065, 0.020), hashImagenes, TAMANIO);
    //Bus naranja 
    insertar_dict(BUSNARANJAIZQ, crear_item("images/ORANGE_BL.png", BUSNARANJAIZQ, 0.040, 0.045), hashImagenes, TAMANIO);
    insertar_dict(BUSNARANJADER, crear_item("images/ORANGE_BR.png", BUSNARANJADER, 0.040, 0.045), hashImagenes, TAMANIO);
    insertar_dict(BUSNARANJAATRAS, crear_item("images/ORANGE_BB.png", BUSNARANJAATRAS, 0.065, 0.020), hashImagenes, TAMANIO);
    insertar_dict(BUSNARANJAFRENTE, crear_item("images/ORANGE_BF.png", BUSNARANJAFRENTE, 0.065, 0.020), hashImagenes, TAMANIO);
    //Ambulancia
    insertar_dict(AMBULANCIAIZQ, crear_item("images/AMBULANCEL.png", AMBULANCIAIZQ, 0.035, 0.025), hashImagenes, TAMANIO);
    insertar_dict(AMBULANCIADER, crear_item("images/AMBULANCER.png", AMBULANCIADER, 0.035, 0.025), hashImagenes, TAMANIO);
    insertar_dict(AMBULANCIAATRAS, crear_item("images/AMBULANCEB.png", AMBULANCIAATRAS, 0.035, 0.025), hashImagenes, TAMANIO);
    insertar_dict(AMBULANCIAFRENTE, crear_item("images/AMBULANCEF.png", AMBULANCIAFRENTE, 0.035, 0.025), hashImagenes, TAMANIO);
    //Carro rojo
    insertar_dict(CARROROJOIZQ, crear_item("images/REDL.png", CARROROJOIZQ, 0.035, 0.025), hashImagenes, TAMANIO);
    insertar_dict(CARROROJODER, crear_item("images/REDR.png", CARROROJODER, 0.035, 0.025), hashImagenes, TAMANIO);
    insertar_dict(CARROROJOATRAS, crear_item("images/REDB.png", CARROROJOATRAS, 0.035, 0.025), hashImagenes, TAMANIO);
    insertar_dict(CARROROJOFRENTE, crear_item("images/REDF.png", CARROROJOFRENTE, 0.035, 0.025), hashImagenes, TAMANIO);
    //Carro verde    
    insertar_dict(CARROVERDEIZQ, crear_item("images/GREENL.png", CARROVERDEIZQ, 0.035, 0.025), hashImagenes, TAMANIO);
    insertar_dict(CARROVERDEDER, crear_item("images/GREENR.png", CARROVERDEDER, 0.035, 0.025), hashImagenes, TAMANIO);
    insertar_dict(CARROVERDEATRAS, crear_item("images/GREENB.png", CARROVERDEATRAS, 0.035, 0.025), hashImagenes, TAMANIO);
    insertar_dict(CARROVERDEFRENTE, crear_item("images/GREENF.png", CARROVERDEFRENTE, 0.035, 0.025), hashImagenes, TAMANIO);
    //Carro azul
    insertar_dict(CARROAZULIZQ, crear_item("images/BLUEL.png", CARROAZULIZQ, 0.035, 0.025), hashImagenes, TAMANIO);
    insertar_dict(CARROAZULDER, crear_item("images/BLUER.png", CARROAZULDER, 0.035, 0.025), hashImagenes, TAMANIO);
    insertar_dict(CARROAZULATRAS, crear_item("images/BLUEB.png", CARROAZULATRAS, 0.035, 0.025), hashImagenes, TAMANIO);
    insertar_dict(CARROAZULFRENTE, crear_item("images/BLUEF.png", CARROAZULFRENTE, 0.035, 0.025), hashImagenes, TAMANIO);
    //Carro blanco
    insertar_dict(CARROBLANCOIZQ, crear_item("images/WHITEL.png", CARROBLANCOIZQ, 0.035, 0.025), hashImagenes, TAMANIO);
    insertar_dict(CARROBLANCODER, crear_item("images/WHITER.png", CARROBLANCODER, 0.035, 0.025), hashImagenes, TAMANIO);
    insertar_dict(CARROBLANCOATRAS, crear_item("images/WHITEB.png", CARROBLANCOATRAS, 0.035, 0.025), hashImagenes, TAMANIO);
    insertar_dict(CARROBLANCOFRENTE, crear_item("images/WHITEF.png", CARROBLANCOFRENTE, 0.035, 0.025), hashImagenes, TAMANIO);
    //Carro negro   
    insertar_dict(CARRONEGROIZQ, crear_item("images/BLACKL.png", CARRONEGROIZQ, 0.035, 0.025), hashImagenes, TAMANIO);
    insertar_dict(CARRONEGRODER, crear_item("images/BLACKR.png", CARRONEGRODER, 0.035, 0.025), hashImagenes, TAMANIO);
    insertar_dict(CARRONEGROATRAS, crear_item("images/BLACKB.png", CARRONEGROATRAS, 0.035, 0.025), hashImagenes, TAMANIO);
    insertar_dict(CARRONEGROFRENTE, crear_item("images/BLACKF.png", CARRONEGROFRENTE, 0.035, 0.025), hashImagenes, TAMANIO);
    //Carro amarillo
    insertar_dict(CARROAMARILLOIZQ, crear_item("images/YELLOWL.png", CARROAMARILLOIZQ, 0.035, 0.025), hashImagenes, TAMANIO);
    insertar_dict(CARROAMARILLODER, crear_item("images/YELLOWR.png", CARROAMARILLODER, 0.035, 0.025), hashImagenes, TAMANIO);
    insertar_dict(CARROAMARILLOATRAS, crear_item("images/YELLOWB.png", CARROAMARILLOATRAS, 0.035, 0.025), hashImagenes, TAMANIO);
    insertar_dict(CARROAMARILLOFRENTE, crear_item("images/YELLOWF.png", CARROAMARILLOFRENTE, 0.035, 0.025), hashImagenes, TAMANIO);

}