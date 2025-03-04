#include "SLQueue.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
	SLQueue *cola = slqueue_create();
	int a1 = 10, a2 = 20, a3 = 30, a4 = 40;

	slqueue_enqueue(cola, &a1);
	slqueue_enqueue(cola, &a2);
	slqueue_enqueue(cola, &a3);
	slqueue_enqueue(cola, &a4);

	printf("Cola:\n");
	slqueue_print(cola);
	puts("");
	printf("El primer elemento de la cola: %d\n", *(int *)slqueue_front(cola));
	printf("Cola sin el primer elemento:\n");
	slqueue_dequeue(cola);
	slqueue_print(cola);
	puts("");
	printf("El primer elemento de la cola: %d\n", *(int *)slqueue_front(cola));
	printf("Cola sin el primer elemento:\n");
	slqueue_dequeue(cola);
	slqueue_print(cola);
	puts("");
	printf("El primer elemento de la cola: %d\n", *(int *)slqueue_front(cola));
	slqueue_destroy(cola);
	return 0;
}