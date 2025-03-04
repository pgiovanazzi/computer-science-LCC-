#ifndef __AQUEUE_H__
#define __AQUEUE_H__

#define MAX_QUEUE	128

typedef struct _AQueue{
	int data[MAX_QUEUE];
	int front, back;
} AQueue;

//Crea una cola.
AQueue* aqueue_create();

//Toma una cola y devuelve el elemento de la primera posición.
int aqueue_front(AQueue *cola);

//Toma una cola y un elemento y agrega el elemento al fin de la cola.
void aqueue_enqueue(AQueue *cola, int elem);

//Toma una cola y le quita su primer elemento.
void aqueue_dequeue(AQueue *cola);

//Toma una cola y la imprime en orden.
void aqueue_print(AQueue *cola);

//Toma una cola y la destruye.
void aqueue_destroy(AQueue *cola);


#endif /*__AQUEUE_H__*/