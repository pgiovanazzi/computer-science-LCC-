#include <stdlib.h>
#include <stdio.h>
#include "SLStack.h"

SLStack slstack_create(){
  SLStack StackNull = slstack_nil();
  return StackNull;
}

int slstack_top(SLStack stack){
  if(stack){
    return slstack_data(stack);
  }
  return -1;
}

SLStack slstack_push(SLStack stack, int data){
  SLStack newNode = malloc(sizeof(SLStackNode));
  slstack_data(newNode) = data;
  slstack_next(newNode) = stack;
  return newNode;
}

SLStack slstack_pop(SLStack stack){
  if(!stack) return slstack_nil();
  SLStack node = stack;
  stack = slstack_next(stack);
  free(node);
  return stack;
}

SLStack slstack_reverse(SLStack stack){
  SLStack stackTmp = slstack_create();
  while (stack) {
    SLStack node = stack;
    stackTmp = slstack_push(stackTmp,slstack_data(stack));
    stack = slstack_next(stack);
    free(node);
  }
  return stackTmp;
}

void slstack_print(SLStack stack){
  SLStack node = stack;
  while (node) {
    printf("%d\n", slstack_data(node));
    node = slstack_next(node);
  }
  return;
}

void slstack_destroy(SLStack stack){
  while (stack) {
    SLStack node = stack;
    stack = slstack_next(stack);
    free(node);
  }
  return;
}
