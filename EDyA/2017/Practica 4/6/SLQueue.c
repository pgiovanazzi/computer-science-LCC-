#include "SLQueue.h"
#include <stdio.h>
#include <stdlib.h>

SLQueue slqueue_create() {
  SLQueue newQueue = slqueue_nil();
  return newQueue;
}

void *slqueue_front(SLQueue queue) { return slqueue_data(queue); }

SLQueue slqueue_enqueue(SLQueue queue, void *data) {
  SLQueue newQueue = malloc(sizeof(SLQueueNode));
  slqueue_data(newQueue) = data;
  slqueue_next(newQueue) = slqueue_nil();

  if (!queue)
    return newQueue;

  SLQueue node = queue;
  while (slqueue_next(node))
    node = slqueue_next(node);
  slqueue_next(node) = newQueue;

  return queue;
}

SLQueue slqueue_dequeue(SLQueue queue) {
  SLQueue node = queue;
  queue = slqueue_next(queue);
  free(node);
  return queue;
}

void slqueue_print(SLQueue queue, FuncionVisitanteCola visit) {
  SLQueue node = queue;
  printf("Queue front -> ");
  while (node) {
    visit(slqueue_data(node));
    node = slqueue_next(node);
  }
  printf("\n\n");
}

void slqueue_destroy(SLQueue queue) {
  while (queue) {
    SLQueue node = queue;
    queue = slqueue_next(queue);
    free(node);
  }
}
