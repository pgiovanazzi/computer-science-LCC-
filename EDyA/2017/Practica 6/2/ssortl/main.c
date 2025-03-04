#include <stdio.h>
#include "ssortl.h"

void imprimir_entero(int dato) {
	printf("%d ", dato);
}

int main(int argc, char *argv[]) {
	SList l = slist_crear();

	l = slist_agregar_final(l, 5);
	l = slist_agregar_final(l, 1);
	l = slist_agregar_final(l, 7);
	l = slist_agregar_final(l, 2);
	l = slist_agregar_final(l, 9);
	l = slist_agregar_final(l, 6);
	l = slist_agregar_final(l, 3);

	slist_recorrer(l, imprimir_entero);
	puts("");

	ssortl(l);

	slist_recorrer(l, imprimir_entero);
	puts("");

	slist_destruir(l);
	
	return 0;
}