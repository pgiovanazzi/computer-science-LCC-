#include "SLQueue.h"
#include <stdio.h>
#include <stdlib.h>


SLQueue* slqueue_create(void){
	SLQueue *cola = (SLQueue*)malloc(sizeof(SLQueue));
	*cola = NULL;
	return cola;
}

void* slqueue_front(SLQueue *cola){
	return slqueue_data(*cola);
}

void slqueue_enqueue(SLQueue *cola,void* elem){
	SLQueueNode *newNode = (SLQueueNode*)malloc(sizeof(SLQueueNode));
	slqueue_data(newNode) = elem;
	slqueue_next(newNode) = NULL;

	if (*cola == NULL){
		*cola = newNode;
		return;
	}
	SLQueueNode *nodeTmp = *cola;
	while(slqueue_next(nodeTmp) != NULL)
		nodeTmp = slqueue_next(nodeTmp);
	slqueue_next(nodeTmp) = newNode;
	return;
}

void slqueue_dequeue(SLQueue *cola){
	SLQueueNode *nodeTmp = *cola;
	if(nodeTmp == NULL)
		return;
	*cola = slqueue_next(nodeTmp);
	free(nodeTmp);
	return;
}

void slqueue_print(SLQueue *cola){
	SLQueueNode *nodeTmp = *cola;
	if(nodeTmp == NULL)
		return;

	while(nodeTmp != NULL){
		printf("%d ", *(int *)nodeTmp->data);
		nodeTmp = slqueue_next(nodeTmp);
	}
	return;
}

void slqueue_destroy(SLQueue *cola){
	while(*cola != NULL){
		SLQueueNode *nodeTmp = *cola;
		*cola = slqueue_next(nodeTmp);
		free(nodeTmp);
	}
	free(*cola);
	return;
}