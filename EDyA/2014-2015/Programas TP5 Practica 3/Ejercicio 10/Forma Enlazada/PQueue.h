#ifndef __PQUEUE_H__
#define __PQUEUE_H__

typedef struct _PQueueNode{
	void *data;
	int priority;
	struct _PQueueNode *next;
} PQueueNode;

typedef PQueueNode *PQueue;

#define pqueue_data(c)		(c)->data
#define pqueue_next(c)		(c)->next
#define pqueue_priority(c)	(c)->priority


//Crea una cola.
PQueue *pqueue_create();

//Toma una cola y devuelve el elemento de la primera posición.
void *pqueue_front(PQueue *cola);

//Toma una cola y un elemento y agrega el elemento al fin de la cola.
void pqueue_enqueue(PQueue *cola, void* elem, int priority);

//Toma una cola y le quita su primer elemento.
void pqueue_dequeue(PQueue *cola);

//Toma una cola y la imprime en orden.
void pqueue_print(PQueue *cola);

//Toma una cola y la destruye.
void pqueue_destroy(PQueue *cola);


#endif /*__PQUEUE_H__*/