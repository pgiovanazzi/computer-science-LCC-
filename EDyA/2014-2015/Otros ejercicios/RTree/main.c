#include <stdio.h>
#include <stdlib.h>
#include "RTree.h"

static void print_int (void* data, void *extra_data)
{
  printf("%d ", *(int*)data);
}

static void dup_int (void* data, void *extra_data)
{
  *(int*)data *= 2;
}


int main(int argc, char *argv[])
{
  int i1 = 1, i2 = 2, i3 = 3, i4 = 4, i5 = 5, i6 = 6;
  RTree *n1 = createNode(&i1);
  RTree *n2 = createNode(&i2);
  RTree *n3 = createNode(&i3);
  RTree *n4 = createNode(&i4);
  RTree *n5 = createNode(&i5);
  RTree *n6 = createNode(&i6);

  rtreeAddChild(n1, n2);
  rtreeAddChild(n1, n3);

  rtreeAddChild(n3, n4);

  rtreeAddChild(n4, n5);
  rtreeAddChild(n4, n6);
    
  rtreeForeach(n1, print_int, NULL);
  rtreeForeach(n1, dup_int, NULL);
  rtreeForeach(n1, print_int, NULL);

  return 0;
}

