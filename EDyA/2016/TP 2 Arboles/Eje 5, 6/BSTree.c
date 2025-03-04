#include <stdlib.h>
#include "BSTree.h"

BSTree bstree_insert(BSTree tree, int data){
	if(data < bstree_data(tree)){
		if(!bstree_left(tree)){
			BSTree newNode = malloc(sizeof(BSTNode));
			bstree_data(newNode) = data;
			bstree_left(newNode) = bstree_nil();
			bstree_right(newNode) = bstree_nil();
			bstree_left(tree) = newNode;
		}
		else
			bstree_insert(bstree_left(tree),data);
	}
	else{
		if(!bstree_right(tree)){
			BSTree newNode = malloc(sizeof(BSTNode));
			bstree_data(newNode) = data;
			bstree_right(newNode) = bstree_nil();
			bstree_left(newNode) = bstree_nil();
			bstree_right(tree) = newNode;
		}
		else
			bstree_insert(bstree_right(tree),data);
	}
	return tree;
}

int bstree_contains(BSTree tree, int data){
	if(tree){
		if(bstree_data(tree) == data) return 1;
		bstree_contains(bstree_left(tree),data);
		bstree_contains(bstree_right(tree),data);
	}
	return 0;
}

int bstree_nelements(BSTree tree){
	if(tree){
		return 1 + bstree_nelements(bstree_left(tree)) + bstree_nelements(bstree_right(tree));
	}
	else return 0;
}

int bstree_height(BSTree tree){
	if(tree){
		return 1 + bstree_height(bstree_left(tree));
	}
	else return 0;
}

void bstree_foreach(BSTree tree, VisitorFuncInt visit, void *extra_data){
	if(tree){
		bstree_foreach(bstree_left(tree),visit,extra_data);
		visit(bstree_data(tree),extra_data);
		bstree_foreach(bstree_right(tree),visit,extra_data);
	}
}

void bstree_destroy(BSTree tree){
	if (tree) {
		free(tree);
		bstree_destroy(bstree_left(tree));
		bstree_destroy(bstree_right(tree));
	}

}

void bstree_mirror(BSTree tree){
	if(tree){
		BSTree tmp = bstree_left(tree);
		bstree_left(tree) = bstree_right(tree);
		bstree_right(tree) = tmp;
		bstree_mirror(bstree_left(tree));
		bstree_mirror(bstree_right(tree));
	}
}
