#include <stdio.h>
#include <stdlib.h>
#include "BSTree.h"

void bstree_print(int data, void *extra_data){
	printf("%d ", data);
}

int main(int argc, char const *argv[]){
	BSTree *t = malloc(sizeof(BSTree));
	bstree_data(t) = 33;
	bstree_left(t) = NULL;
	bstree_right(t) = NULL;

	bstree_insert(t, 27);
	bstree_insert(t, 57);
	bstree_insert(t, 51);
	bstree_insert(t, 29);
	bstree_insert(t, 21);


	printf("t = ");
	bstree_foreach(t, bstree_print, NULL);
	puts("");

	printf("cantidad de nodos de t: %d\n", bstree_nelements(t));
	printf("la altura de t: %d\n", bstree_height(t));

	printf("¿33 esta en el arbol?, si esta 1 sino 0: %d\n", bstree_contains(t, 33));
	printf("¿44 esta en el arbol?, si esta 1 sino 0: %d\n", bstree_contains(t, 44));
	
	printf("t = ");
	bstree_foreach(t, bstree_print, NULL);
	puts("");
	
	printf("árbol espejo de t = ");
	bstree_mirror(t);
	bstree_foreach(t, bstree_print, NULL);
	puts("");

	printf("Arblo de fibonacci: ");
	BSTree *fib = NULL;
	fib = bstree_fibo(4);
	bstree_foreach(fib, bstree_print, NULL);
	puts("");

	return 0;
}