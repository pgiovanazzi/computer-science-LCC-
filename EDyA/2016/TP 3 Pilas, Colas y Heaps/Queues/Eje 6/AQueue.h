#ifndef __AQueue_H__
#define __AQueue_H__

#define MAX_QUEUE 5

typedef struct _AQueue{
  int data[MAX_QUEUE];
  int fr, back;
} AQueue;

/*
 * back nos da referencia a la cantidad de elementos que tiene la cola
 * y front nos da la pocicion del primer elemento de la cola.
 */

#define aqueue_data(q,i)    (q)->data[(i)]
#define aqueue_fr(q)        (q)->fr
#define aqueue_back(q)      (q)->back

/**
 * Crea una cola.
 */
 AQueue *aqueue_create();

/**
 * Toma una cola y devuelve el elemento en la primera posición.
 */
 int aqueue_front(AQueue *queue);

/**
 * Toma una cola y un elemento y agrega el elemento al fin de la cola.
 */
 void aqueue_enqueue(AQueue *queue, int data);

/**
 * Toma una cola y le quita su primer elemento.
 */
 void aqueue_dequeue(AQueue *queue);

/**
 * Toma una cola y la imprime en orden.
 */
 void aqueue_print(AQueue *queue);

/**
 * Toma una cola y la imprime en orden.
 */
 void aqueue_destroy(AQueue *queue);


#endif
