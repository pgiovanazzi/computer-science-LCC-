#include <stdlib.h>
#include "BTree.h"

BTree *btree_create(int *data, BTree *left, BTree *right){
	BTree *newNode = malloc(sizeof(BTree));
	newNode->data = data;
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

static int min = 10000;

void btree_remMin(BTree *tree){
	if(tree){
		if(btree_data(tree) < min)
			min = btree_data(tree);
		btree_remMin(btree_left(tree));
		btree_remMin(btree_right(tree));
		btree_data(tree) = min;
	}
}
