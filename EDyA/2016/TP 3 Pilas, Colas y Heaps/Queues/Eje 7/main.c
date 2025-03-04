#include <stdio.h>
#include "SLQueue.h"

int main(int argc, char const *argv[]) {
  SLQueue queue = slqueue_create();

  queue = slqueue_enqueue(queue,32);
  queue = slqueue_enqueue(queue,60);
  queue = slqueue_enqueue(queue,12);
  queue = slqueue_enqueue(queue,93);
  queue = slqueue_enqueue(queue,46);
  queue = slqueue_enqueue(queue,13);
  queue = slqueue_enqueue(queue,11);

  slqueue_print(queue);

  printf("slqueue_dequeue(queue):\n");
  queue = slqueue_dequeue(queue);
  slqueue_print(queue);
  printf("slqueue_dequeue(queue):\n");
  queue = slqueue_dequeue(queue);
  slqueue_print(queue);
  printf("slqueue_dequeue(queue):\n");
  queue = slqueue_dequeue(queue);
  slqueue_print(queue);
  printf("slqueue_enqueue(queue,58):\n");
  queue = slqueue_enqueue(queue,58);
  slqueue_print(queue);
  printf("slqueue_enqueue(queue,6):\n");
  queue = slqueue_enqueue(queue,6);
  slqueue_print(queue);

  printf("slqueue_front(queue): %d\n", slqueue_front(queue));

  slqueue_destroy(queue);

  return 0;
}
