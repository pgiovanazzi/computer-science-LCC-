#include <stdio.h>
#include "SList.h"
#include "ssortl.h"

void printInt(int data, void *extra_data) {
  printf("%d, ", data);
}

int main(int argc, char const *argv[]) {
  SList list = NULL;
  list = slist_append(list,6);
  list = slist_append(list,1);
  list = slist_append(list,8);
  list = slist_append(list,4);
  list = slist_append(list,34);
  list = slist_append(list,11);


  printf("list: < ");
  slist_foreach(list,printInt,NULL);
  printf(" >\n");

  ssortl(list);

  printf("sortl(list): < ");
  slist_foreach(list,printInt,NULL);
  printf(" >\n");

  slist_destroy(list);

  return 0;
}
