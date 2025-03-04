#include <stdio.h>
#include <stdlib.h>
#include "BSTree.h"

void printInt(int data, void *extra_data){
	printf("%d ", data);
}

int main(){
	BSTree tree = malloc(sizeof(BSTNode));
	bstree_left(tree) = bstree_nil();
	bstree_right(tree) = bstree_nil();
	bstree_data(tree) = 10;

	bstree_insert(tree,2);
	bstree_insert(tree,7);
	bstree_insert(tree,6);
	bstree_insert(tree,5);
	bstree_insert(tree,11);
	bstree_insert(tree,5);
	bstree_insert(tree,9);
	bstree_insert(tree,4);

	bstree_foreach(tree,printInt,bstree_nil());
	puts("");

	bstree_mirror(tree);

	bstree_foreach(tree,printInt,bstree_nil());
	puts("");
	bstree_destroy(tree);

	return 0;
}
