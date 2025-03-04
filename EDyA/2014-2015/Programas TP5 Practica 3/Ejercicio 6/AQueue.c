#include <stdio.h>
#include <stdlib.h>
#include "AQueue.h"


AQueue* aqueue_create(){
	AQueue *cola = (AQueue *)malloc(sizeof(AQueue));
	cola->front = -1;
	cola->back = -1;
	return cola;
}

int aqueue_front(AQueue *cola){
	if(cola->front == cola->back)
		return;
	return cola->data[cola->front];
}

void aqueue_enqueue(AQueue *cola, int elem){
	int i;
	if (cola->back == MAX_QUEUE)
		return;
	if(cola->front < 0)
		cola->front = 0;
	cola->data[++cola->back] = elem;
	return;
}

void aqueue_dequeue(AQueue *cola){
	if(cola->front == MAX_QUEUE)
		return;
	++cola->front;
	return;
}

void aqueue_print(AQueue *cola){
	int i;
	for(i = cola->back; i >= cola->front; i--){
		printf("%d ", cola->data[i]);
	}
	return;
}

void aqueue_destroy(AQueue *cola){
	cola->back = -1;
	cola->front = -1;
	free(cola);
	return;
}