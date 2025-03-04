#include "bsortg.h"
#include <string.h>
#include <stdlib.h>

void swap(void *d1, void *d2) {
   //d2-d1 nos devuelve la cantidad de memoria que ocupa la variable (como tipo)
   //ya que d1 antecede a d2 (d1 y d2 son dirrecciones de memoria)
   //o bien tmbien se puede saber el sz de la variable como (d1 + 1) - d1
   //ACLARACION: ESTO FUNCIONA SIEMPRE Y CUANDO d2 SEA EL SIGUIENTE VALOR DE d1
   //YA QUE SI POR EJEMPLO d2 ESTUBIESE 3 LUGARES DE MEMORIA MAS ADELANTE QUE d1 Y
   //FUESEN ENTEROS, d2 - d1 RESULTARIA 4+4+4 = 12 Y NO ES EL TAMANIO DE UN ENTERO QUE ES 4.

   int mem_sz = d2-d1;
   void *t = malloc(sizeof(mem_sz));
   memcpy(t,d1,mem_sz);
   memcpy(d1,d2,mem_sz);
   memcpy(d2,t,mem_sz);
   free(t);
}

void bsortg(void *arr[], int sz, CmpFunc func){
   for (int i = 0; i < sz; i++)
      for (int j = 0; j < sz - 1; j++)
         if(func(arr[j],arr[j + 1]) > 0)
            swap(arr[j], arr[j + 1]);
}

/*
   Algo interesante que aclarar es que el mem_sz para utilizarlo en la funcion
   memcpy, el tamanio que debe almacenar en el tercer argumento es el tamanio
   del tipo de la variable osea que si la variable es un int entonces mem_sz
   debe ser igual a 4, pero tambien puede ser menor que 4 siempre que no
   sea menor que 1 ya que al parecer el tamanio por mas que sea un 1 o un 2 o un 3
   d1 almacena un entero y recerba 4 lugares de memoria y no se puede fragmentar los
   lugares de memoria de la variable almacenada. Produciria un error o tomaria
   lugares de memoria en donde abria basura si fuese mayor que 4 o menor que 1.
*/
