#include <stdlib.h>
#include "BTree.h"
#include "Queue.h"

BTree *btree_create(int data, BTree *left, BTree *right)
{
	BTree *newNode = malloc(sizeof(BTree));
	btree_data(newNode) = data;
	btree_left(newNode) = left;
	btree_right(newNode) = right;
	return newNode;
}

void  btree_destroy(BTree *node)
{
	if (node != NULL) {
		btree_destroy(btree_left(node));
		btree_destroy(btree_right(node));
		free(node);
	}
}

void  btree_foreach(BTree *node, VisitorFuncInt visit, void *extra_data)
{
	if (node != NULL) {
		visit(&btree_data(node), extra_data);
		btree_foreach(btree_left(node), visit, extra_data);
		btree_foreach(btree_right(node), visit, extra_data);
	}
}

void btree_foreach_level(BTree *tree, VisitorFuncInt visit, void *extra_data) {
  
  if (NULL == tree) 
    return;

  queue *cola = queue_create();

  queue_enqueue(cola, tree);
  
  while (!queueIsEmpty(cola)) {
    qNode *nodoCola = queue_front(cola);
    BTree *nodoArbol = (BTree*) (nodoCola->data);
    visit(&nodoArbol->data, extra_data);
    queue_dequeue(cola);
    if (NULL != nodoArbol->left) 
      queue_enqueue(cola, nodoArbol->left);
    if (NULL != nodoArbol->right) 
      queue_enqueue(cola, nodoArbol->right);    
  }

  queue_destroy(cola);
  return;
}
