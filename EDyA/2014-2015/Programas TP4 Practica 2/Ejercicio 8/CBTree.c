#include <stdlib.h>
#include "CBTree.h"

CBTree *cbtree_new(CBTree *tree, int n){
	cbtree_len(tree) = 2**n;
	return tree;
}

void cbtree_destroy(CBTree *tree){
	int i;
	for(i = 0; i < cbtree_len(tree); i++){
		cbtree_data(tree, i) = '\0';
	}
	cbtree_len(tree) = 0;
}

CBTree *cbtree_insert(CBTree *tree, int data){
	cbtree_data(tree, cbtree_len(tree)) = data;
	cbtree_len(tree) = cbtree_len(tree)  + 1;
	return tree;
}

int cbtree_nelements(CBTree *tree){
	return cbtree_len(tree);
}

void cbtree_foreach(CBTree *tree, visitorFunInt visit, void *extradata){
	int i;
	for(i = 0; i < cbtree_len(tree); i++){
		visit(cbtree_data(tree, i), extradata);
	}
}