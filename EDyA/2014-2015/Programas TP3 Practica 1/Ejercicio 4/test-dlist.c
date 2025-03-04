/************************************************
   Tester para SList. La siguiente es la salida esperada para una
  implementación correcta de SList. Si su salida difiere, lea las
  notas abajo!
   También tener en mente que una salida igual a la siguiente no
  es garantía de una implementación correcta. De hecho, no se prueban
  todas las funciones.

 -----
	len(l1) = 10
	len(l2) = 12
	len(l3) = 9

	l1 = <48, 43, 21, 34, 0, 61, 65, 28, 39, 96, >
	l2 = <94, 89, 21, 71, 28, 59, 14, 22, 62, 2, 0, 71, >
	l3 = <96, 66, 30, 79, 72, 47, 99, 81, 11, >

	l1 ++ l2 = <48, 43, 21, 34, 0, 61, 65, 28, 39, 96, 94, 89, 21, 71, 28, 59, 14, 22, 62, 2, 0, 71, >
	l1 ++ [] = <48, 43, 21, 34, 0, 61, 65, 28, 39, 96, >
	[] ++ l2 = <94, 89, 21, 71, 28, 59, 14, 22, 62, 2, 0, 71, >

	l1 <inter> l2 = <28, 0, 21, >
	l1 <inter> l3 = <96, >

	sort(l1) = <0, 21, 28, 34, 39, 43, 48, 61, 65, 96, >

 -----

************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "DList.h"

static void print_int (int data, void *extra_data){
	printf("%d, ", data);
}

int compa(const void *a, const void *b){
	return ( *(int*)a - *(int*)b );
}

static void printlist(DList *l) {
	printf("<");
	dlist_foreach(l, print_int, NULL, 0);
	printf(">\n");
}

int main(int argc, char *argv[]){
	DList *l1=NULL, *l2=NULL, *l3=NULL;
	int i;

	l1 = dlist_append(l1, 96);
	l1 = dlist_append(l1, 39);
	l1 = dlist_append(l1, 28);
	l1 = dlist_append(l1, 65);
	l1 = dlist_append(l1, 61);
	l1 = dlist_append(l1, 00);
	l1 = dlist_append(l1, 34);
	l1 = dlist_append(l1, 21);
	l1 = dlist_append(l1, 43);
	l1 = dlist_append(l1, 48);

	l2 = dlist_append(l2, 71);
	l2 = dlist_append(l2, 00);
	l2 = dlist_append(l2, 02);
	l2 = dlist_append(l2, 62);
	l2 = dlist_append(l2, 22);
	l2 = dlist_append(l2, 14);
	l2 = dlist_append(l2, 59);
	l2 = dlist_append(l2, 28);
	l2 = dlist_append(l2, 71);
	l2 = dlist_append(l2, 21);
	l2 = dlist_append(l2, 89);
	l2 = dlist_append(l2, 94);

	l3 = dlist_append(l3, 11);
	l3 = dlist_append(l3, 81);
	l3 = dlist_append(l3, 99);
	l3 = dlist_append(l3, 47);
	l3 = dlist_append(l3, 72);
	l3 = dlist_append(l3, 79);
	l3 = dlist_append(l3, 30);
	l3 = dlist_append(l3, 66);
	l3 = dlist_append(l3, 96);

	printf("len(l1) = %i\n", dlist_length(l1));
	printf("len(l2) = %i\n", dlist_length(l2));
	printf("len(l3) = %i\n", dlist_length(l3));
	puts("");

	printf("l1 = "); printlist(l1);
	printf("l2 = "); printlist(l2);
	printf("l3 = "); printlist(l3);
	puts("");

	/* NOTA:
	    Si tu función concat modifica las listas pasadas (es decir, hace
	   que el último nodo de la primera apunte al primero de la segunda),
	   vas a obtener resultados distintos ya que l1 se estaría modificando.
	    Cambiar el argumento 'l1' por 'clonar(l1)' para que no se
	   modifique la lista. */
	printf("l1 ++ l2 = "); printlist(dlist_concat(l1, l2));
	printf("l1 ++ [] = "); printlist(dlist_concat(l1, NULL));
	printf("[] ++ l2 = "); printlist(dlist_concat(NULL, l2));
	puts("");

	/* Si tu intersect cambia las listas, hacer lo mismo explicado para
	   concat.. */
	printf("l1 <inter> l2 = "); printlist(dlist_intersect(l1, l2));
	printf("l1 <inter> l3 = "); printlist(dlist_intersect(l1, l3));
	puts("");

	printf("sort(l1) = "); printlist(dlist_sort(l1, compa));
	puts("");

	printf("l3 agregar 4 en la posicón 3: ");printlist(dlist_insert(l3, 4, 2));
	puts("");

	printf("l2 = "); printlist(l2);
	puts("");

	printf("Quitar el numero 62 de l2: ");printlist(dlist_remove(l2, dlist_index(l2, 62)));
	puts("");

	printf("len(l2) = %i\n", dlist_length(l2));

	/* NOTA:
	    Si tu lista quedó ordenada al revés, o no queda ordenada puede ser
	   por confusiones en como opera la función de comparación. Lo que debe
	   cumplir la función de comparación es:
	   		icmp(a, b) >  0   si y solo si    a > b
			icmp(a, b) == 0   si y solo si    a == b
			icmp(a, b) <  0   si y solo si    a < b

	   Los valores no son necesariamente 1 y -1. */
	   		
    return 0;
}
