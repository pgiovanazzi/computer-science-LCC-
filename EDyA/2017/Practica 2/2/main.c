#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

static void imprimir_entero(int dato)
{
	printf("%d ", dato);
}

int cmpInt(const void *a, const void *b)
{
	int priEntero = *(int *)a;
	int segEntero = *(int *)b;
	return priEntero - segEntero;
}

int main(int argc, char *argv[])
{

	SList lista = slist_crear(), lista2 = slist_crear(), lista3 = slist_crear();

	lista = slist_agregar_inicio(lista, 1);
	lista = slist_agregar_inicio(lista, 2);
	lista = slist_agregar_inicio(lista, 3);
	lista = slist_agregar_final(lista, 4);

	lista2 = slist_agregar_final(lista2, 5);
	lista2 = slist_agregar_final(lista2, 8);
	lista2 = slist_agregar_inicio(lista2, 9);

	slist_recorrer(lista, imprimir_entero);
	puts("");

	slist_ordenar(lista, cmpInt);
	slist_recorrer(lista, imprimir_entero);
	puts("");

	slist_reverso(lista);
	slist_recorrer(lista, imprimir_entero);
	puts("");

	slist_recorrer(lista2, imprimir_entero);
	puts("");
	
	lista3 = slist_intercalar(lista, lista2);
	slist_recorrer(lista3, imprimir_entero);
	puts("");

	slist_destruir(lista);
	slist_destruir(lista2);
	slist_destruir(lista3);

	return 0;
}
