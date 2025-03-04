#include <stdlib.h>
#include "BTree.h"

BTree btree_create(int data, BTree left, BTree right)
{
	BTree newNode = malloc(sizeof(BTNode));
	btree_data(newNode) = data;
	btree_left(newNode) = left;
	btree_right(newNode) = right;
	return newNode;
}

void  btree_destroy(BTree node)
{
	if (node != NULL) {
		btree_destroy(btree_left(node));
		btree_destroy(btree_right(node));
		free(node);
	}
}

void  btree_foreach(BTree node, VisitorFuncInt visit, void *extra_data)
{
	if (node != NULL) {
		visit(btree_data(node), extra_data);
		btree_foreach(btree_left(node), visit, extra_data);
		btree_foreach(btree_right(node), visit, extra_data);
	}
}

