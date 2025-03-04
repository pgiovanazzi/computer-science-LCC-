#include <stdio.h>
#include <stdlib.h>
#include "AQueue.h"

int main(void){
	AQueue *cola = aqueue_create();

	aqueue_enqueue(cola, 20);
	aqueue_enqueue(cola, 30);
	aqueue_enqueue(cola, 40);
	aqueue_enqueue(cola, 50);
	aqueue_enqueue(cola, 60);
	aqueue_enqueue(cola, 70);
	aqueue_enqueue(cola, 80);
	aqueue_enqueue(cola, 90);
	aqueue_enqueue(cola, 100);
	aqueue_enqueue(cola, 110);

	printf("Cola:\n");
	aqueue_print(cola);
	puts("");
	printf("EL primer elemento ingresado: %d\n", aqueue_front(cola));
	aqueue_dequeue(cola);
	printf("Cola sin el primer elmento:\n");
	aqueue_print(cola);
	puts("");
	printf("EL primer elemento ingresado: %d\n", aqueue_front(cola));
	
	aqueue_destroy(cola);
	return 0;
}