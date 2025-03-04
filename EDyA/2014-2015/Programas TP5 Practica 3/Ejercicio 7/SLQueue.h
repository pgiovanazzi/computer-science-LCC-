#ifndef __SLQUEUE_H__
#define __SLQUEUE_H__


typedef struct _SLQueueNode{
	void *data;
	struct _SLQueueNode *next;
} SLQueueNode;

typedef SLQueueNode *SLQueue;

#define slqueue_data(c)		(c)->data
#define slqueue_next(c)		(c)->next


//Crea una cola.
SLQueue *slqueue_create();

//Toma una cola y devuelve el elemento de la primera posición.
void *slqueue_front(SLQueue *cola);

//Toma una cola y un elemento y agrega el elemento al fin de la cola.
void slqueue_enqueue(SLQueue *cola, void* elem);

//Toma una cola y le quita su primer elemento.
void slqueue_dequeue(SLQueue *cola);

//Toma una cola y la imprime en orden.
void slqueue_print(SLQueue *cola);

//Toma una cola y la destruye.
void slqueue_destroy(SLQueue *cola);


#endif /*__SLQUEUE_H__*/