#include <stdlib.h>
#include <stdio.h>
#include "SLStack.h"


SLStack *slstack_create(){
	SLStack *newNode = malloc(sizeof(SLStack));
	*newNode = NULL;
	return newNode;
}

int slstack_top(SLStack *pila){
	return slstack_data(*pila);
}

void slstack_push(SLStack *pila, int elem){
	SLStack newNode = malloc(sizeof(SLStack));
	slstack_data(newNode) = elem;
	slstack_next(newNode) = *pila;
	*pila = newNode;
}

void slstack_pop(SLStack *pila){
	SLStack newNode;
	newNode = *pila;
	*pila = slstack_next(*pila);
	free(newNode);
}

void slstack_reverse(SLStack *pila){
	SLStack newNode, nodeTemp;
	newNode = *pila;
	while(newNode != NULL){
		slstack_push(&nodeTemp,slstack_data(newNode));
		newNode = slstack_next(newNode);
	}
	slstack_destroy(pila);
	*pila = nodeTemp;
}

void slstack_print(SLStack *pila){
	SLStack newNode = *pila;
	while(newNode != NULL){
		printf("%d\n", slstack_data(newNode));
		newNode = slstack_next(newNode);
	}
}

void slstack_destroy(SLStack *pila){
	SLStack newNode;
	while(*pila != NULL){
		newNode = *pila;
		free(newNode);
		*pila = slstack_next(*pila);
	}
}