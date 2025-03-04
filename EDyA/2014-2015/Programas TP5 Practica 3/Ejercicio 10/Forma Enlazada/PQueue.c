#include "PQueue.h"
#include "BHeap.h"
#include <stdio.h>
#include <stdlib.h>


PQueue* pqueue_create(void){
	PQueue *cola = (PQueue*)malloc(sizeof(PQueue));
	*cola = NULL;
	return cola;
}

void* pqueue_front(PQueue *cola){
	return pqueue_data(*cola);
}

void pqueue_enqueue(PQueue *cola, void* elem, int priority){
	PQueueNode *newNode = (PQueueNode*)malloc(sizeof(PQueueNode));
	pqueue_data(newNode) = elem;
	pqueue_priority(newNode) = priority;
	pqueue_next(newNode) = NULL;

	if (*cola == NULL){
		*cola = newNode;
		return;
	}
	PQueueNode *nodeTmp = *cola;
	while(pqueue_next(nodeTmp) != NULL)
		nodeTmp = pqueue_next(nodeTmp);
	pqueue_next(nodeTmp) = newNode;

	BHeap *heap = bheap_create();
	nodeTmp = *cola;
	while(nodeTmp != NULL){
		bheap_insert(heap, pqueue_priority(nodeTmp));
		nodeTmp = pqueue_next(nodeTmp);
	}

	PQueueNode nodeTemp2, nodeTmp1 = *cola;
	while (pqueue_next(nodeTmp1) != NULL){
		if(pqueue_priority(pqueue_next(nodeTmp1)) == bheap_minimum(heap)){
			nodeTemp2 = pqueue_next(nodeTmp1);
			nodeTmp1 = pqueue_next(nodeTemp2);
			pqueue_next(nodeTmp2) = NULL;
		}
		nodeTmp = pqueue_next(nodeTmp);
	}


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