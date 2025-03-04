#include <stdlib.h>
#include "BTree.h"

BTree *btree_create(int data, BTree *left, BTree *right){
	BTree *newNode = malloc(sizeof(BTree));
	btree_data(newNode) = data;
	btree_left(newNode) = left;
	btree_right(newNode) = right;
	return newNode;
}

void  btree_destroy(BTree *node){
	if (node != NULL) {
		btree_destroy(btree_left(node));
		btree_destroy(btree_right(node));
		free(node);
	}
}

void  btree_foreach(BTree *node, VisitorFuncInt visit, void *extra_data){
	if (node != NULL) {
		visit(btree_data(node), extra_data);
		btree_foreach(btree_left(node), visit, extra_data);
		btree_foreach(btree_right(node), visit, extra_data);
	}
}

int btree_SumElem(BTree *tree){
	if(!tree) return 0;
	return btree_data(tree) + btree_SumElem(btree_left(tree)) + btree_SumElem(btree_right(tree));
}

int btree_CountNode(BTree *tree){
	if(!tree) return 0;
	return 1 + btree_CountNode(btree_left(tree)) + btree_CountNode(btree_right(tree));
}

int btree_HTree(BTree *tree){
	if(!tree) return 0;
	return 1 + MAX(btree_HTree(btree_left(tree)),btree_HTree(btree_right(tree)));
}

void  btree_foreach_v2(BTree *node, VisitorFuncInt visit, void *extra_data, BTreeTraversalOrder order){
	switch(order){
		case 0:
			if(node){
				btree_foreach_v2(btree_left(node),visit,extra_data,order);
				visit(btree_data(node),extra_data);
				btree_foreach_v2(btree_right(node),visit,extra_data,order);
			}
			break;
		case 1:
			if(node){
				visit(btree_data(node),extra_data);
				btree_foreach_v2(btree_left(node),visit,extra_data,order);
				btree_foreach_v2(btree_right(node),visit,extra_data,order);
			}
			break;
		case 2:
			if(node){
				btree_foreach_v2(btree_left(node),visit,extra_data,order);
				btree_foreach_v2(btree_right(node),visit,extra_data,order);
				visit(btree_data(node),extra_data);
			}
			break;
		default:;
	}
}

void btree_remMin(BTree *tree, int *min){
	if(tree){
		if(btree_data(tree) < *min)
			*min = btree_data(tree);
		btree_remMin(btree_left(tree), min);
		btree_remMin(btree_right(tree), min);
		btree_data(tree) = *min;
	}
}

BTree *btree_fib(int n){
	if(n < 2)
		return btree_create(n,NULL,NULL);
	return btree_create(n,btree_fib(n-1),btree_fib(n-2));
}

int btree_Childrens(BTree tree){
	return btree_CountNode(tree) - 1;
}

int btree_leafs(BTree *tree){
	if(!(btree_left(tree) && btree_right(tree)))
		return 1;
	return btree_Childrens(btree_left(tree)) + btree_Childrens(btree_right(tree));
}
