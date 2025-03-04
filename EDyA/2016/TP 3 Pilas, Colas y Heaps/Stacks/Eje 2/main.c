#include <stdio.h>
#include "AStack.h"

int main(int argc, char const *argv[]) {
  AStack *stack = astack_create();

  astack_push(stack,1);
  astack_push(stack,2);
  astack_push(stack,17);
  astack_push(stack,6);
  astack_push(stack,15);
  astack_push(stack,5);
  astack_push(stack,20);

  printf("Stack:\n");
  astack_print(stack);

  printf("astack_top(stack) = %d\n", astack_top(stack));
  printf("astack_pop(stack):\n");
  astack_pop(stack);
  astack_print(stack);

  printf("astack_top(stack) = %d\n", astack_top(stack));

  printf("astack_reverse(stack):\n");
  astack_reverse(stack);
  astack_print(stack);

  astack_destroy(stack);

  return 0;
}
