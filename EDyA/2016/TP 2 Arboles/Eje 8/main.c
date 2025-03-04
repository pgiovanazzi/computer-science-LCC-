#include <stdio.h>
#include "ABCTree.h"

static void pinrtInt(int data, void *extra_data){
  printf("%d ", data);
}

int main(int argc, char const *argv[]) {
  ABCTree tree = abctree_new(2);

  tree = abctree_insert(tree,1);
  tree = abctree_insert(tree,2);
  tree = abctree_insert(tree,3);

  printf("len(tree) = %i\n", abctree_nelements(tree));

  abctree_foreach(tree, pinrtInt,NULL);
  puts("");
  abctree_destroy(tree);

  return 0;
}
