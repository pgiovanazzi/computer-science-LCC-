#ifndef __AStack_H__
#define __AStack_H__

#define MAX_STACK 128

typedef struct _AStack{
  int data[MAX_STACK];
  int back;
} AStack;

#define astack_data(s,i)    (s)->data[(i)]
#define astack_back(s)      (s)->back

/*
 * Crea una pila vacia.
 */
 AStack *astack_create();

/*
 * Toma una pila y devuelve el elemento en la cima.
 */
 int astack_top(AStack *stack);

/*
 * Toma una pila y un elemento y agrega el elemento a la pila.
 */
 void astack_push(AStack *stack, int data);

/*
 * Toma una pila y quita el elemento de la cima.
 */
 void astack_pop(AStack *stack);

/*
 * Toma una pila y la invierte.
 */
 void astack_reverse(AStack *stack);

/*
 * Toma una pila e imprime sus elementos en orden.
 */
 void astack_print(AStack *stack);

/*
 * Toma una pila y la destruye.
 */
 void astack_destroy(AStack *stack);

#endif
