/************************************************
   Tester para GList. La siguiente es la salida esperada para una
  implementación correcta de GList. Si su salida difiere, lea las
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
#include "GList.h"

static void print_int(void *data, void *extra_data)
{
	printf("%i, ", *(int *)data);
}

static void printlist(GList l)
{
	printf("<");
	glist_foreach(l, print_int, NULL);
	printf(">\n");
}

int icmp(const void *x, const void *y)
{
	return *(int *)x - *(int *)y;
}

int mod5(int x, int y)
{
	return (x - y) % 5 == 0;
}

GList clonar(GList l)
{
	GList ret = NULL;

	for (; l != NULL; l = glist_next(l))
		ret = glist_append(ret, glist_data(l));

	return ret;
}

int main(int argc, char *argv[])
{
	GList l1 = NULL, l2 = NULL, l3 = NULL;
	int i, a1, a2, a4, a3, a6, a5, a7, a8, a9, a0, b1 = 11, b2 = 00, b3 = 99, b4 = 28;
	a1 = 96;
	a2 = 39;
	a3 = 28;
	a4 = 65;
	a5 = 39;
	a6 = 00;
	a7 = 34;
	a8 = 39;
	a9 = 28;
	a0 = 48;

	l1 = glist_prepend(l1, &a1);
	l1 = glist_prepend(l1, &a2);
	l1 = glist_prepend(l1, &a3);
	l1 = glist_prepend(l1, &a4);

	l2 = glist_prepend(l2, &a5);
	l2 = glist_prepend(l2, &a6);
	l2 = glist_prepend(l2, &a7);
	l2 = glist_prepend(l2, &a8);
	l2 = glist_prepend(l2, &a9);

	l3 = glist_prepend(l3, &a0);
	l3 = glist_prepend(l3, &b1);
	l3 = glist_prepend(l3, &b2);
	l3 = glist_prepend(l3, &b3);
	l3 = glist_prepend(l3, &b4);

	printf("len(l1) = %i\n", glist_length(l1));
	printf("len(l2) = %i\n", glist_length(l2));
	printf("len(l3) = %i\n", glist_length(l3));
	puts("");

	printf("l1 = ");
	printlist(l1);
	printf("l2 = ");
	printlist(l2);
	printf("l3 = ");
	printlist(l3);
	puts("");

	/* NOTA:
	    Si tu función concat modifica las listas pasadas (es decir, hace
	   que el último nodo de la primera apunte al primero de la segunda),
	   vas a obtener resultados distintos ya que l1 se estaría modificando.
	    Cambiar el argumento 'l1' por 'clonar(l1)' para que no se
	   modifique la lista. */
	GList lclone = clonar(l1);
	printf("l1 ++ l2 = ");
	printlist(glist_concat(lclone, l2));
	printf("l1 ++ [] = ");
	printlist(glist_concat(l1, NULL));
	printf("[] ++ l2 = ");
	printlist(glist_concat(NULL, l2));
	puts("");

	/* Si tu intersect cambia las listas, hacer lo mismo explicado para
	   concat.. */
	printf("l1 <inter> l2 = ");
	printlist(glist_intersect(l1, l2, icmp));
	printf("l1 <inter> l3 = ");
	printlist(glist_intersect(l1, l3, icmp));
	puts("");

	printf("sort(l1) = ");
	printlist(glist_sort(l1, icmp));
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
