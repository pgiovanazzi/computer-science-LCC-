#include <stdio.h>
#include <stdlib.h>
#include "BTree.h"

static void print_int (int data, void *extra_data){
	printf("%d ", data);
}

int main(int argc, char *argv[]){
	BTree *ll = btree_create(1, NULL, NULL);
	BTree *l = btree_create(2, ll, NULL);
	BTree *r = btree_create(3, NULL, NULL);
	BTree *root = btree_create(4, l, r);
	int *minimo = malloc(sizeof(int));
	*minimo = 10000;

	btree_foreach(root, print_int, NULL);
	puts("");

	printf("La suma de sus elementos es %i.\n", btree_SumElem(root));
	printf("La cantidad de sus nodos es %i.\n", btree_CountNode(root));
	printf("La cantidad de niveles son %i\n",btree_HTree(root));
	int order = 0;
	printf("Lista de la forma %d\n", order);
	btree_foreach_v2(root,print_int,NULL,order);
	puts("");
	btree_remMin(root,minimo);
	btree_foreach_v2(root,print_int,NULL,order);
	puts("");

	BTree *FibTree = btree_fib(4);
	printf("Arbol de Fibonacci:\n");
	btree_foreach(FibTree,print_int,NULL);
	puts("");
	printf("Hijos: %i\n",btree_leafs(FibTree));

	btree_destroy(root);
	btree_destroy(FibTree);
	free(minimo);

	return 0;
}
