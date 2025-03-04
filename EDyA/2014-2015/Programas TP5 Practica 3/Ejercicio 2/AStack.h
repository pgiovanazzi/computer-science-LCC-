#ifndef __AStack_H__
#define __AStack_H__

typedef struct __AStack{
	int length;
	int *data;
	int back;
} AStack;

//Crea una pila vacía.
AStack* astack_create();

//Toma una pila y devuelve el elemento en la cima.
int astack_top(AStack *pila);

//Toma una pila y un elemento y agreaga el elemento a la pila.
void astack_push(AStack *pila, int elem);

//Toma una pila y quita el elemento de la cima.
void astack_pop(AStack *pila);

//Toma una pila y la invierte.
void astack_reverse(AStack *pila);

//Toma una pila y imprime los elementos en orden.
void astack_print(AStack *pila);

//Toma una pila y la destruye.
void astack_destroy(AStack *pila);

#endif /*__AStack_H__*/