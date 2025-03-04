#include "RTree.h"
#include <stdio.h>

static void printInt(void *data, void *extra_data) {
  printf("%d ", *(int *)data);
}

static void dupInt(void *data, void *extra_data) { *(int *)data *= 2; }

int main() {
  int i1 = 1, i2 = 2, i3 = 3, i4 = 4, i5 = 5, i6 = 6;
  RTree n1 = rtree_createNode(&i1);
  RTree n2 = rtree_createNode(&i2);
  RTree n3 = rtree_createNode(&i3);
  RTree n4 = rtree_createNode(&i4);
  RTree n5 = rtree_createNode(&i5);
  RTree n6 = rtree_createNode(&i6);

  rtree_addChild(n1, n2);
  rtree_addChild(n1, n3);

  rtree_addChild(n3, n4);

  rtree_addChild(n4, n5);
  rtree_addChild(n4, n6);

  rtree_foreach(n1, printInt, NULL);
  puts("");
  rtree_foreach(n1, dupInt, NULL);
  rtree_foreach(n1, printInt, NULL);
  puts("");
  return 0;
}
