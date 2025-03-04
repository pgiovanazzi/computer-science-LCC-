#include "ssortl.h"

static void swap(int *x, int *y){
	int t = *x;
	*x = *y;
	*y = t;
}

void ssortl(SList lista) {
	SList menor = NULL;
	for (SList i = lista; i != NULL ; i = i->sig) {
		menor = i;
		for (SList j = i->sig; j != NULL; j = j->sig)
			if (menor->dato > j->dato)
				menor = j;
		swap(&(i->dato), &(menor->dato));
	}
}