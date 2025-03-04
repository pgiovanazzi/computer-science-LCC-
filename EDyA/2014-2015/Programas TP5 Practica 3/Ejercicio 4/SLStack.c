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
	SLStackNode *newNode = malloc(sizeof(SLStackNode));
	slstack_data(newNode) = elem;
	slstack_next(newNode) = *pila;
	*pila = newNode;
	return;
}

void slstack_pop(SLStack *pila){
	SLStackNode *newNode = *pila;
	*pila = slstack_next(*pila);
	free(newNode);
	return;
}

void slstack_reverse(SLStack *pila){
	SLStackNode *nodeTmp = NULL;
	while(*pila != NULL){
		slstack_push(&nodeTmp, slstack_top(pila));
		slstack_pop(pila);
	}
	*pila = nodeTmp;
	return;
}

void slstack_print(SLStack *pila){
	SLStackNode *newNode = *pila;
	while(newNode != NULL){
		printf("%d\n", slstack_data(newNode));
		newNode = slstack_next(newNode);
	}
}

void slstack_destroy(SLStack *pila){
	SLStackNode *newNode;
	while(*pila != NULL){
		newNode = *pila;
		free(newNode);
		*pila = slstack_next(*pila);
	}
}