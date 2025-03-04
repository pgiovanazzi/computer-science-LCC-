#include "SLStack.h"
#include <stdlib.h>

SLStack slstack_create() {
  SLStack StackNull = slstack_nil();
  return StackNull;
}

void *slstack_top(SLStack stack) {
  if (stack) {
    return slstack_data(stack);
  }
  return NULL;
}

SLStack slstack_push(SLStack stack, void *data) {
  SLStack newNode = malloc(sizeof(SLStackNode));
  slstack_data(newNode) = data;
  slstack_next(newNode) = stack;
  return newNode;
}

SLStack slstack_pop(SLStack stack) {
  if (!stack)
    return slstack_nil();
  SLStack node = stack;
  stack = slstack_next(stack);
  free(node);
  return stack;
}

SLStack slstack_reverse(SLStack stack) {
  SLStack stackTmp = slstack_create();
  while (stack) {
    SLStack node = stack;
    stackTmp = slstack_push(stackTmp, slstack_data(stack));
    stack = slstack_next(stack);
    free(node);
  }
  return stackTmp;
}

void slstack_print(SLStack stack, VisitorFunc visit) {
  SLStack node = stack;
  while (node) {
    visit(slstack_data(node));
    node = slstack_next(node);
  }
  return;
}

void slstack_destroy(SLStack stack) {
  while (stack) {
    SLStack node = stack;
    stack = slstack_next(stack);
    free(node);
  }
  return;
}
