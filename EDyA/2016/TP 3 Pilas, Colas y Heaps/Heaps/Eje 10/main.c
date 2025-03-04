#include "PQueue.h"
#include <stdio.h>

int main(int argc, char const *argv[]) {
  PQueue *queue = pqueue_create();

  pqueue_enqueue(queue, 10, 3);
  pqueue_enqueue(queue, 40, 1);
  pqueue_enqueue(queue, 17, 9);
  pqueue_enqueue(queue, 11, 8);
  pqueue_enqueue(queue, 23, 10);
  pqueue_enqueue(queue, 19, 15);
  pqueue_enqueue(queue, 120, 28);
  pqueue_enqueue(queue, 99, 13);
  pqueue_enqueue(queue, 89, 5);
  pqueue_enqueue(queue, 13, 10);
  pqueue_enqueue(queue, 22, 30);

  pqueue_print(queue);
  puts("");
  printf("front: %d\n", pequeue_front(queue));

  pqueue_dequeue(queue);
  pqueue_dequeue(queue);
  pqueue_dequeue(queue);

  puts("");
  pqueue_print(queue);
  puts("");
  printf("front: %d\n", pequeue_front(queue));

  pqueue_desroy(queue);

  return 0;
}
