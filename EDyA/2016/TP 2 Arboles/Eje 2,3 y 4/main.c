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

	printf("Tree: ");
	btree_foreach(root, print_int, NULL);
	puts("");

	printf("La suma de sus elementos es %i.\n", btree_SumElem(root));
	printf("La cantidad de sus nodos es %i.\n", btree_CountNode(root));
	printf("La cantidad de niveles son %i.\n",btree_HTree(root));
	int order = 0;
	printf("Lista de la forma %d\n", order);
	btree_foreach_v2(root,print_int,NULL,order);
	puts("");
	order = 1;
	printf("Lista de la forma %d\n", order);
	btree_foreach_v2(root,print_int,NULL,order);
	puts("");
	order = 2;
	printf("Lista de la forma %d\n", order);
	btree_foreach_v2(root,print_int,NULL,order);
	puts("");
	printf("btree_remMin(root): \n");
	btree_remMin(root,minimo);
	btree_foreach_v2(root,print_int,NULL,order);
	puts("");

	btree_destroy(root);
	free(minimo);

	return 0;
}
