#include "BTree.h"
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

queue* queue_create(void){
  queue *q = (queue*) malloc(sizeof(queue));
  q->head = NULL;
  return q;
}

int queueIsEmpty(queue* q) {
  return (q->head == NULL);
}

void* queue_front(queue* q) {
  return q->head;
}

void queue_enqueue(queue* cola, void* newData) {
  qNode *node = (qNode*) malloc(sizeof(qNode));
  node->data = newData;
  node->next = NULL;

  if (NULL == cola->head) {
    cola->head = node;
    return;
  }

  qNode *temp = cola->head;
  while (temp->next != NULL)
    temp = temp->next;
  temp->next = node;
  return;
}

void queue_dequeue(queue* q) {
  qNode *temp = q->head;
  if (NULL == temp)
    return;
  
  q->head = temp->next;
  free(temp);
  return;
}

void queue_destroy(queue* q) {
  while (q->head != NULL) {
    qNode *temp = q->head;
    q->head = q->head->next;
    free(temp);
  }

  free(q);
  return;
}
