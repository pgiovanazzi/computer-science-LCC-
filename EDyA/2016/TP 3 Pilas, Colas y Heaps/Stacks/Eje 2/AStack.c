#include <stdio.h>
#include <stdlib.h>
#include "AStack.h"

AStack *astack_create(){
  AStack *newStack = malloc(sizeof(AStack));
  newStack->data = malloc(sizeof(int)*STORE);
  astack_back(newStack) = -1;
  return newStack;
}

int astack_top(AStack *stack){
  return astack_data(stack,astack_back(stack));
}

void astack_push(AStack *stack, int data){
  if(astack_back(stack) + 1 > STORE - 1){
    STORE += 3;
    stack->data = realloc(stack->data, sizeof(int)*STORE);
  }
  astack_data(stack,++astack_back(stack)) = data;
  return;
}

void astack_pop(AStack *stack){
  if(astack_back(stack) - 1 < 0)
    return;
  astack_data(stack,astack_back(stack)--) = 0;
}

void astack_reverse(AStack *stack){
  int l = astack_back(stack)+1;
  int tmp[l], i = 0;
  for(; i < l; i++)
    tmp[i] = astack_data(stack,i);
  astack_back(stack) = -1;
  for (i = l-1; i > -1 ; i--)
    astack_push(stack,tmp[i]);
}

void astack_print(AStack *stack){
  for (int i = astack_back(stack); i > -1; i--)
    printf("%d\n", astack_data(stack,i));
}

void astack_destroy(AStack *stack){
  free(stack->data);
  free(stack);
}
