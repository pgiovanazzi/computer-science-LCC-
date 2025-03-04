#include <stdio.h>
#include "XORList.h"

void printInt(int data, void *extra_data){
  printf("%i ", data);
}

int main(int argc, char const *argv[]) {
  XORList l1 = NULL;
  l1 = xorlist_prepend(l1,3);
  l1 = xorlist_prepend(l1,14);
  l1 = xorlist_prepend(l1,64);
  l1 = xorlist_prepend(l1,13);

  xorlist_foreach(l1,printInt,NULL);
  puts("");


  return 0;
}
