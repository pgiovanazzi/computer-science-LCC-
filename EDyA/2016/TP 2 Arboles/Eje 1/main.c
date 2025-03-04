#include <stdio.h>
#include <stdlib.h>
#include "BTree.h"

static void print_int (int data, void *extra_data)
{
	printf("%d ", data);
}

int main(int argc, char *argv[])
{
  BTree ll = btree_create(1, btree_empty(), btree_empty());
  BTree l = btree_create(2, ll, btree_empty());
  BTree r = btree_create(3, btree_empty(), btree_empty());
  BTree root = btree_create(4, l, r);

  btree_foreach(root, print_int, btree_empty());
  puts("");
  btree_destroy(root);

  return 0;
}

