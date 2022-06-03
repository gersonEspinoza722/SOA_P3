#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include"dict.h"

int hashCode(int llave, int tamanio) {
   return llave % tamanio;
}

struct DataItem *search(int llave, struct DataItem* hashArray[], int tamanio) {
   //obtener hash 
   int indice = hashCode(llave, tamanio);  
  
   //moverse en el array hasta que haya un espacio vacio
   while(hashArray[indice] != NULL) {
      if(hashArray[indice]->llave == llave){
         return hashArray[indice]; 
      }
      
      indice++;    
      indice %= tamanio;
   }        
     
   return NULL;        
}

void insertar_dict(int llave, struct DataItem *item, struct DataItem **hashArray, int tamanio) {
   //obtener hash 
   int indice = hashCode(llave, tamanio);

   //moverse en el array hasta que haya un espacio vacio
   while(hashArray[indice] != NULL && hashArray[indice]->llave != -1) {
      ++indice;    
      indice %= tamanio;
   }
  
   hashArray[indice] = item;
}
