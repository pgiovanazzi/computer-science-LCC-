#include "slist.h"
#include <stdio.h>

void marge_sort(SList *list) {
	// Al menos que tenga dos elementos.
  if (*list && (*list)->sig) {
		SList nodoAcutal = *list;
    SList res1 = slist_crear();
    SList res2 = slist_crear();
    slist_particionar(nodoAcutal, &res1, &res2);
    marge_sort(&res1);
    marge_sort(&res2);
    *list = slist_fucionar(res1, res2);
  }
}

void imprimir_entero(int dato) {
	printf("%d ", dato);
}

int main(int argc, char *argv[]) { 
	SList l1 = slist_crear();

	l1 = slist_agregar_final(l1, 1);
	l1 = slist_agregar_final(l1, 6);
	l1 = slist_agregar_final(l1, 7);
	l1 = slist_agregar_final(l1, 3);
	l1 = slist_agregar_final(l1, 5);
	l1 = slist_agregar_final(l1, 8);
	l1 = slist_agregar_final(l1, 9);

	slist_recorrer(l1, imprimir_entero);
	puts("");

	marge_sort(&l1);

	slist_recorrer(l1, imprimir_entero);
	puts("");

	slist_destruir(l1);

	return 0;
}