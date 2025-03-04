#include <stdlib.h>
#include <stdio.h>
#include "AQueue.h"

AQueue *aqueue_create(){
  AQueue *newQueue = malloc(sizeof(AQueue));
  aqueue_fr(newQueue) = 0;
  aqueue_back(newQueue) = 0;
  return newQueue;
}

int aqueue_front(AQueue *queue){
  return aqueue_data(queue,aqueue_fr(queue));
}

void aqueue_enqueue(AQueue *queue, int data){
  if(MAX_QUEUE != aqueue_back(queue)){
    //i sera el indice a incertar el nuevo elemento
    // (frente+n) % m  = r y  0 <= r < m (lo que se llama arreglo circular)
    int i = (aqueue_fr(queue)+aqueue_back(queue)) % MAX_QUEUE;
    aqueue_data(queue,i) = data;
    aqueue_back(queue)++;
  }
}

void aqueue_dequeue(AQueue *queue){
  if(aqueue_back(queue)){
    //Incrementa el frente en 1
    aqueue_fr(queue) = (aqueue_fr(queue) + 1) % MAX_QUEUE;
    aqueue_back(queue)--;
  }
}

void aqueue_print(AQueue *queue){
  int i = aqueue_fr(queue), j = 0;
  printf("Frente -> ");
  for(; j < aqueue_back(queue) ; i = (i + 1) % MAX_QUEUE,j++)
    printf("%d ", aqueue_data(queue,i));
}

void aqueue_destroy(AQueue *queue){
  free(queue);
}
