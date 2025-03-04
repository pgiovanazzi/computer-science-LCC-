#ifndef __SLQUEUE_H__
#define __SLQUEUE_H__

typedef struct _SLQueueNode{
  void *data;
  struct _SLQueueNode *next;
} SLQueueNode;

typedef SLQueueNode *SLQueue;

#define slqueue_data(q)   (q)->data
#define slqueue_next(q)   (q)->next
#define slqueue_nil(q)    NULL

/*
  Crea una cola vacia.
*/
SLQueue slqueue_create();

/*
  Toma una cola y devuelve el elemento en la primera posición.
*/
void *slqueue_front(SLQueue queue);

/*
  Toma una cola y un elemento y agrega el elemento al fin de la cola.
*/
SLQueue slqueue_enqueue(SLQueue queue, void *data);

/*
  Toma una cola y le quita su primer elemento.
*/
SLQueue slqueue_dequeue(SLQueue queue);

/*
  Toma una cola y la imprime en orden.
*/
void slqueue_print(SLQueue queue);

/*
  Toma una cola y la destruye.
*/
void slqueue_destroy(SLQueue queue);

#endif
