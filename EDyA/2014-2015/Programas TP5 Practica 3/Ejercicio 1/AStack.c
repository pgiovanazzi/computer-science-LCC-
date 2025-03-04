#include <stdlib.h>
#include <stdio.h>
#include "AStack.h"

AStack *astack_create(){
	AStack *pila = malloc(sizeof(AStack));
	pila->back = -1;
	return pila;
}

int astack_top(AStack *pila){
	if(pila->back == -1)
		return;
	return pila->data[pila->back];
}

void astack_push(AStack *pila, int elem){
	if(pila->back == MAX_STACK)
		return;
	else
		pila->data[++pila->back] = elem;
}

void astack_pop(AStack *pila){
	if(pila->back == -1)
		return;
	else
		--pila->back;
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
}

void astack_print(AStack *pila){
	int i;
	for(i = pila->back; i > -1; i--)
		printf("%d\n", pila->data[i]);
}

void astack_destroy(AStack *pila){
	pila->back = -1;
	free(pila);
}