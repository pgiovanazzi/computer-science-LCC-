#ifndef __SLStack_H__
#define __SLStack_H__

typedef void (*VisitorFunc)(void *data);

typedef struct _SLStackNode {
  void *data;
  struct _SLStackNode *next;
} SLStackNode;

typedef SLStackNode *SLStack;

#define slstack_data(s) (s)->data
#define slstack_next(s) (s)->next
#define slstack_nil() NULL

/*
 * Crea una pila vacia.
 */
SLStack slstack_create();

/*
 * Toma una pila y devuelve el elemento en la cima.
 */
void *slstack_top(SLStack stack);

/*
 * Toma una pila y un elemento y agrega el elemento a la pila.
 */
SLStack slstack_push(SLStack stack, void *data);

/*
 * Toma una pila y quita el elemento de la cima.
 */
SLStack slstack_pop(SLStack stack);

/*
 * Toma una pila y la invierte.
 */
SLStack slstack_reverse(SLStack stack);

/*
 * Toma una pila e imprime sus elementos en orden.
 */
void slstack_print(SLStack stack, VisitorFunc visit);

/*
 * Toma una pila y la destruye.
 */
void slstack_destroy(SLStack stack);

#endif
