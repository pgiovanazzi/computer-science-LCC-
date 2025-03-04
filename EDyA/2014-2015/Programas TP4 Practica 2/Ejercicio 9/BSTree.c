#include <stdlib.h>
#include "BSTree.h"

BSTree *bstree_insert(BSTree *tree, int data){
	if (data < bstree_data(tree)){
		if(bstree_left(tree) == NULL){
			BSTree *newNode = malloc(sizeof(BSTree));
			bstree_left(newNode) = NULL;
			bstree_right(newNode) = NULL;
			bstree_data(newNode) = data;
			bstree_left(tree) = newNode;
		}
		else
			bstree_insert(bstree_left(tree), data);
	}
	else{
		if (data > bstree_data(tree)){
			if(bstree_right(tree) == NULL){
				BSTree *newNode = malloc(sizeof(BSTree));
				bstree_right(newNode) = NULL;
				bstree_left(newNode) = NULL;
				bstree_data(newNode) = data;
				bstree_right(tree) = newNode;
			}
			else
				bstree_insert(bstree_right(tree), data);
		}
		else
			puts("El valor ya existe");
	}
	return tree;
}


int bstree_contains(BSTree *tree, int data){
	if (tree == NULL)
		return 0;
	else
		if (bstree_data(tree) == data)
			return 1;
		else{
			bstree_contains(bstree_left(tree), data);
			bstree_contains(bstree_right(tree), data);
		}
}

int bstree_nelements(BSTree *tree){
	if(tree == NULL)
		return 0;
	else
		return 1 + bstree_nelements(bstree_left(tree)) + bstree_nelements(bstree_right(tree));
}

int bstree_height(BSTree *tree){
	if (tree == NULL)
		return 0;
	else
		return 1 + bstree_height(bstree_left(tree));
}

void bstree_foreach(BSTree *tree, VisitorFuncInt visit, void *extra_data){
	if(tree != NULL){
		visit(bstree_data(tree), extra_data);
		bstree_foreach(bstree_left(tree), visit, extra_data);
		bstree_foreach(bstree_right(tree), visit, extra_data);
	}
}


//Ejercicio 6
void *bstree_mirror(BSTree *tree){
	if(tree == NULL)
		return;
	else{
		BSTree *nodeTemp = NULL;
		bstree_mirror(bstree_left(tree));
		bstree_mirror(bstree_right(tree));
		nodeTemp = bstree_left(tree);
		bstree_left(tree) = bstree_right(tree);
		bstree_right(tree)= nodeTemp;
	}
}


//Ejercicio 9 a.
BSTree *bstree_fibo(unsigned int n){
	if( n == 0 || n == 1) {
		BSTree *tree = malloc(sizeof(BSTree));
		bstree_data(tree) = n;
		bstree_right(tree) = NULL;
		bstree_left(tree) = NULL;
		return tree;
	}
	else{
		BSTree *tree = malloc(sizeof(BSTree));
		bstree_data(tree) = n;
		bstree_right(tree) = bstree_fibo(n - 2);
		bstree_left(tree) = bstree_fibo(n - 1);
		return tree;
	}
}

//Ejercicio 9 b. esta mal esta funcion
int bstree_child(BSTree *tree){
	return bstree_nelements(tree) - 1;
}

//Ejercicio 9 c.
