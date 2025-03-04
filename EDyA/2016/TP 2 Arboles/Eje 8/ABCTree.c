#include <stdlib.h>
#include "ABCTree.h"

ABCTree abctree_new(int lvl){
  ABCTree tree = malloc(sizeof(ABCNode));
  int i = 0;
  for(; i < lvl; i++)
    store += 2^i;
  if(store > MAX)
    return NULL;
  tree->data = malloc(sizeof(int)*store);
  abctree_len(tree) = -1;
  return tree;
}

void abctree_destroy(ABCTree tree){
  free(tree->data);
  free(tree);
}

ABCTree abctree_insert(ABCTree tree, int data){
  if(abctree_len(tree) > store)
    return NULL;
  if(abctree_len(tree) == -1)
    abctree_len(tree)++;
  abctree_data(tree,abctree_len(tree)++) = data;
  return tree;
}

int abctree_nelements(ABCTree tree){
  return abctree_len(tree);
}

void abctree_foreach(ABCTree tree, VisitorFuncInt visit, void *extra_data){
  int i = 0;
  for(; i  < abctree_len(tree); i++)
    visit(abctree_data(tree,i),extra_data);
}
