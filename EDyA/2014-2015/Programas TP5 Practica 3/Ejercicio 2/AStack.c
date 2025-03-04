#include <stdlib.h>
#include <stdio.h>
#include "AStack.h"

AStack* astack_create(){
	AStack *pila = malloc(sizeof(AStack));
	pila->length = 5;
	pila->data = malloc(sizeof(int)*pila->length); // pila->data[5];
	pila->back = -1;
	return pila;
}

int astack_top(AStack *pila){
	if(pila->back == -1)
		return;
	return pila->data[pila->back];
}

void astack_push(AStack *pila, int elem){
	if(pila->length == pila->back + 1){
		pila->length *= 2;
		pila->data = (int *)realloc(pila->data, sizeof(int)*pila->length);
		pila->data[++pila->back] = elem;
		return;
	}
	pila->data[++pila->back] = elem;
	return;
}

void astack_pop(AStack *pila){
	if(pila->back == -1)
		return;
	--pila->back;
	return;
}

void astack_reverse(AStack *pila){
	AStack *pila2 = astack_create();
	int i = pila->back;
	while(i > -1){
		astack_push(pila2, astack_top(pila));
		astack_pop(pila);
		--i;
	}
	for(i = 0; i <= pila2->back; i++)
		astack_push(pila, pila2->data[i]);
	astack_destroy(pila2);
	return;
}

void astack_print(AStack *pila){
	int i;
	for(i = pila->back; i > -1 ; i--)
		printf("%d\n", pila->data[i]);
}

void astack_destroy(AStack *pila){
	pila->length = 0;
	pila->back = -1;
	free(pila->data);
	free(pila);
	return;
}