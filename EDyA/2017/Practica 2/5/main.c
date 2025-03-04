#include <stdio.h>
#include "dlist.h"

void imprimir_entero(int d)
{
	printf("%d ", d);
}

int main(int argc, char *argv[])
{
	DList lista = dlist_crear(), l2 = dlist_crear();

	lista = dlist_agregar_inicio(lista, 5);
	lista = dlist_agregar_inicio(lista, 3);
	lista = dlist_agregar_final(lista, 1);
	lista = dlist_agregar_final(lista, 9);
	l2 = dlist_agregar_inicio(l2, 1);
	l2 = dlist_agregar_inicio(l2, 2);
	l2 = dlist_agregar_inicio(l2, 3);

	dlist_recorrer(lista, imprimir_entero, 0);
	puts("");
	dlist_recorrer(lista, imprimir_entero, 1);
	puts("");
	printf("Len(lista): %d\n", dlist_longitud(lista));

	dlist_concatenar(lista,l2);
	dlist_recorrer(lista, imprimir_entero, 0);
	puts("");
	dlist_recorrer(lista, imprimir_entero, 1);
	puts("");

	dlist_destruir(lista);
	
	return 0;
}