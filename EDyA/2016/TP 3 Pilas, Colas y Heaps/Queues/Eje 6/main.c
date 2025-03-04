#include <stdio.h>
#include "AQueue.h"

int main(int argc, char const *argv[]) {
  AQueue *queue = aqueue_create();

  aqueue_enqueue(queue,5);
  aqueue_enqueue(queue,6);
  aqueue_enqueue(queue,9);
  aqueue_enqueue(queue,1);
  aqueue_enqueue(queue,2);

  printf("Queue: ");
  aqueue_print(queue);
  printf("\n\n");

  printf("aqueue_dequeue(queue): ");
  aqueue_dequeue(queue);
  aqueue_print(queue);
  printf("\n\n");
  printf("aqueue_dequeue(queue): ");
  aqueue_dequeue(queue);
  aqueue_print(queue);
  printf("\n\n");
  printf("aqueue_dequeue(queue): ");
  aqueue_dequeue(queue);
  aqueue_print(queue);
  printf("\n\n");
  printf("aqueue_enqueue(queue,60): ");
  aqueue_enqueue(queue,60);
  aqueue_print(queue);
  printf("\n\n");

  aqueue_destroy(queue);

  return 0;
}
