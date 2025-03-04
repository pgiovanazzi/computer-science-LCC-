#ifndef __SLStack_H__
#define __SLStack_H__

typedef struct _SLStackNode{
	int data;
	struct _SLStackNode *next;
} SLStackNode;

typedef SLStackNode *SLStack;

#define slstack_data(s)		(s)->data
#define slstack_next(s)		(s)->next

//Crea una pila vacía
SLStack *slstack_create();

//Toma una pila y devuelve el elemento de la cima.
int slstack_top(SLStack *pila);

//Toma una pila y un entero y agrea el elemento a la pila.
void slstack_push(SLStack *pila, int elem);

//Toma una pila y quita el elemento de la cima.
void slstack_pop(SLStack *pila);

//Toma una pila y la invierte.
void slstack_reverse(SLStack *pila);

//Toma una pila e imprime sus elementos.
void slstack_print(SLStack *pila);

//Toma una pila y la destruye.
void slstack_destroy(SLStack *pila);

#endif /*__SLStack_H__*/