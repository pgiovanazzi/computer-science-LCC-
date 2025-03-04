#include <stdlib.h>
#include <stdio.h>
#include "BTree.h"
#include "SLQueue.h"

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

//Ejercicio 2
int btree_sumelem(BTree *tree){
	if (tree == NULL)
		return 0;
	else
		return btree_data(tree) + btree_sumelem(btree_left(tree)) + btree_sumelem(btree_right(tree));
}

int btree_cantnode(BTree *tree){
	if (tree == NULL)
		return 0;
	else
		return 1 + btree_cantnode(btree_left(tree)) + btree_cantnode(btree_right(tree));
}

int btree_altutree(BTree *tree){
	if (tree == NULL)
		return 0;
	else
		return 1 + btree_altutree(btree_left(tree));
}

//Ejercicio 3
void  btree_foreach(BTree *node, VisitorFuncInt visit, void *extra_data, BTreeTraversalOrder o){
	if (o == 0){
		if (node != NULL) {
			btree_foreach(btree_left(node), visit, extra_data, o);
			visit(btree_data(node), extra_data);
			btree_foreach(btree_right(node), visit, extra_data, o);
		}
	}
	else{
		if(o == 1){
			if (node != NULL) {
				visit(btree_data(node), extra_data);
				btree_foreach(btree_left(node), visit, extra_data, o);
				btree_foreach(btree_right(node), visit, extra_data, o);
			}
		}
		else{
			if (node != NULL) {
				btree_foreach(btree_left(node), visit, extra_data, o);
				btree_foreach(btree_right(node), visit, extra_data, o);
				visit(btree_data(node), extra_data);
			}
		}
	}
}

//Ejercicio 4
int btree_min(BTree *tree){
	if (tree == NULL)
		return 0;
	else{
		if (btree_left(tree) == NULL)
			return btree_data(tree);
		else 
			return btree_min(btree_left(tree));
	}
}


void btree_remMin(BTree *tree, int min){
	if (tree != NULL) {
		btree_remMin(btree_left(tree), min);
		btree_remMin(btree_right(tree), min);
		btree_data(tree) = min;
	}
}

//Ejercicio 8 de colas:
void btree_foreach_level(BTree *node, VisitorFuncInt visit, void *extra_data){
	if(node == NULL)
		return;

	SLQueue *cola = slqueue_create();

	slqueue_enqueue(cola, node);

	while(*cola != NULL){
		SLQueueNode *nodeCola = slqueue_front(cola);
		BTree *nodeTree = (BTree *) (slqueue_data(nodeCola));
		visit(btree_data(nodeTree), extra_data);
		slqueue_dequeue(cola);
		if(btree_left(nodeTree) != NULL)
			slqueue_enqueue(cola, btree_left(nodeTree));
		if(btree_right(nodeTree) != NULL)
			slqueue_enqueue(cola, btree_right(nodeTree));
	}
	slqueue_destroy(cola);
	return;
}