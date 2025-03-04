#include <stdio.h>
#include <stdlib.h>
#include "AStack.h"


int main(){
	AStack *pila = astack_create();

	astack_push(pila, 100);
	astack_push(pila, 200);
	astack_push(pila, 300);
	astack_push(pila, 400);
	astack_push(pila, 500);

	printf("Pila:\n");
	astack_print(pila);
	puts("");
	

	printf("Elemento top de la pila: %d", astack_top(pila));
	puts("");

	astack_pop(pila);
	printf("Pop de la pila:\n");
	astack_print(pila);
	puts("");

	astack_reverse(pila);
	printf("pila reverse:\n");
	astack_print(pila);
	puts("");

	astack_destroy(pila);

	return 0;
}