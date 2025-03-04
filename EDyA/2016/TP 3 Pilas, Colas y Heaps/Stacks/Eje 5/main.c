#include <stdio.h>
#include "SLStack.h"


float RPN_Calculator(char read[]){
  int i = 0, tmp = 0, num = 0;
  float result;
  SLStack stack = slstack_create();
  while (read[i]) {
    switch (read[i]) {
      case '+':
        tmp = slstack_top(stack);
        stack = slstack_pop(stack);
        result = slstack_top(stack) + tmp;
        stack = slstack_pop(stack);
        stack = slstack_push(stack,result);
        break;
      case '-':
        tmp = slstack_top(stack);
        stack = slstack_pop(stack);
        result = slstack_top(stack) - tmp;
        stack = slstack_pop(stack);
        stack = slstack_push(stack,result);
        break;
      case '*':
        tmp = slstack_top(stack);
        stack = slstack_pop(stack);
        result = slstack_top(stack) * tmp;
        stack = slstack_pop(stack);
        stack = slstack_push(stack,result);
        break;
      case '/':
        tmp = slstack_top(stack);
        stack = slstack_pop(stack);
        result = ((float)slstack_top(stack) / tmp);
        stack = slstack_pop(stack);
        stack = slstack_push(stack,result);
        break;
      default:
        num = read[i] - '0';
        stack = slstack_push(stack,num);

    }
    i++;
  }
  slstack_destroy(stack);
  return result;
}


int main(int argc, char const *argv[]) {
  char read[] = "512+4*+3-";
  printf("RPN_Calculator(%s) = %.2f\n",read ,RPN_Calculator(read));
  return 0;
}
