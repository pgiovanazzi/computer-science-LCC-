#include <stdio.h>
#include <stdlib.h>
#include "SLStack.h"




int main(int argc, char const *argv[]){
	SLStack *p = slstack_create();

	slstack_push(p,20);
	slstack_push(p,30);
	slstack_push(p,40);
	slstack_push(p,50);
	slstack_push(p,60);
	slstack_push(p,70);
	slstack_push(p,80);
	slstack_push(p,90);

	printf("Pila:");
	puts("");
	slstack_print(p);
	puts("");

	printf("Pila revertida:\n");
	slstack_reverse(p);
	slstack_print(p);
	puts("");
	printf("Pop  de la Pila revertida:\n");
	slstack_pop(p);
	slstack_print(p);

	slstack_destroy(p);
	return 0;
}