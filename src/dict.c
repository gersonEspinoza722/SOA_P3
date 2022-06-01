#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include"dict.h"

int hashCode(int key, int size) {
   return key % size;
}

struct DataItem *search(int key, struct DataItem* hashArray[], int size) {
   //get the hash 
   int hashIndex = hashCode(key, size);  
  
   //move in array until an empty 
   while(hashArray[hashIndex] != NULL) {
  
      if(hashArray[hashIndex]->key == key){
         return hashArray[hashIndex]; 
      }
      
      //go to next cell
      hashIndex++;
    
      //wrap around the table
      hashIndex %= size;
   }        
     
   return NULL;        
}

void insertDict(int key, struct DataItem *item, struct DataItem **hashArray, int size) {

   //get the hash 
   int hashIndex = hashCode(key, size);

   //move in array until an empty or deleted cell
   while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
      //go to next cell
      ++hashIndex;
    
      //wrap around the table
      hashIndex %= size;
   }
  
   hashArray[hashIndex] = item;
}
