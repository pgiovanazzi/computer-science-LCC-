#include <stdio.h>
#include <stdlib.h>
#include "SList.h"

static void print_int (int data, void *extra_data)
{
  printf("%d ", data);
}

int main(int argc, char *argv[])
{
  SList list = slist_nil();
  list = slist_prepend(list, 1);
  list = slist_prepend(list, 2);
  list = slist_prepend(list, 3);
  list = slist_append(list, 4);
  slist_foreach(list, print_int, NULL);
  puts("");
  slist_destroy(list);

  return 0;
}
