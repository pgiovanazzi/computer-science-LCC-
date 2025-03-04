#include <stdio.h>
#include "SLStack.h"

int main(int argc, char const *argv[]) {
  SLStack stack = slstack_create();

  stack = slstack_push(stack,10);
  stack = slstack_push(stack,15);
  stack = slstack_push(stack,11);
  stack = slstack_push(stack,31);
  stack = slstack_push(stack,23);
  stack = slstack_push(stack,86);

  printf("Pila:\n");
  slstack_print(stack);
  puts("");
  printf("slstack_top(stack): %d\n\n", slstack_top(stack));
  printf("slstack_pop(stack):\n");
  stack = slstack_pop(stack);
  slstack_print(stack);
  puts("");
  printf("slstack_reverse(stack):\n");
  stack = slstack_reverse(stack);
  slstack_print(stack);

  slstack_destroy(stack);

  return 0;
}
