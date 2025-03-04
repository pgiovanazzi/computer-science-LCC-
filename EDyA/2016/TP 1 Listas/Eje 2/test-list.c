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
#include "SList.h"

static void print_int (int data, void *extra_data)
{
       printf("%d, ", data);
}

static void printlist(SList l) {
	printf("<");
	slist_foreach(l, print_int, NULL);
	printf(">\n");
}

int icmp(const int *x, const int *y) {
	return *x-*y;
}

int mod5(int x, int y) {
	return (x-y)%5 == 0;
}

SList  clonar(SList l) {
	SList ret = NULL;

	for(; l != NULL; l = slist_next(l))
		ret = slist_append(ret, slist_data(l));

	return ret;
}

int main(int argc, char *argv[])
{
	SList l1=NULL, l2=NULL, l3=NULL;
	int i;

	l1 = slist_prepend(l1, 96);
	l1 = slist_prepend(l1, 39);
	l1 = slist_prepend(l1, 28);
	l1 = slist_prepend(l1, 65);
	l1 = slist_prepend(l1, 61);
	l1 = slist_prepend(l1, 00);
	l1 = slist_prepend(l1, 34);
	l1 = slist_prepend(l1, 21);
	l1 = slist_prepend(l1, 43);
	l1 = slist_prepend(l1, 48);

	l2 = slist_prepend(l2, 71);
	l2 = slist_prepend(l2, 00);
	l2 = slist_prepend(l2, 02);
	l2 = slist_prepend(l2, 62);
	l2 = slist_prepend(l2, 22);
	l2 = slist_prepend(l2, 14);
	l2 = slist_prepend(l2, 59);
	l2 = slist_prepend(l2, 28);
	l2 = slist_prepend(l2, 71);
	l2 = slist_prepend(l2, 21);
	l2 = slist_prepend(l2, 89);
	l2 = slist_prepend(l2, 94);

	l3 = slist_prepend(l3, 11);
	l3 = slist_prepend(l3, 81);
	l3 = slist_prepend(l3, 99);
	l3 = slist_prepend(l3, 47);
	l3 = slist_prepend(l3, 72);
	l3 = slist_prepend(l3, 79);
	l3 = slist_prepend(l3, 30);
	l3 = slist_prepend(l3, 66);
	l3 = slist_prepend(l3, 96);

	printf("len(l1) = %i\n", slist_length(l1));
	printf("len(l2) = %i\n", slist_length(l2));
	printf("len(l3) = %i\n", slist_length(l3));
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
	SList lclone = clonar(l1);
	printf("l1 ++ l2 = "); printlist(slist_concat(lclone, l2));
	printf("l1 ++ [] = "); printlist(slist_concat(l1, NULL));
	printf("[] ++ l2 = "); printlist(slist_concat(NULL, l2));
	puts("");

	/* Si tu intersect cambia las listas, hacer lo mismo explicado para
	   concat.. */
	printf("l1 <inter> l2 = "); printlist(slist_intersect(l1, l2));
	printf("l1 <inter> l3 = "); printlist(slist_intersect(l1, l3));
	puts("");

	printf("sort(l1) = "); printlist(slist_sort(l1, icmp));
	puts("");

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
