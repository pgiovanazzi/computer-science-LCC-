#include <stdio.h>
#include <stdlib.h>
#include "BTree.h"

static void print_int (int data, void *extra_data){
	printf("%d ", data);
}

int main(int argc, char *argv[]){
	int a = 1, b = 2, c = 3, d = 4;

	BTree *ll = btree_create(&a, NULL, NULL);
	BTree *l = btree_create(&b, ll, NULL);
	BTree *r = btree_create(&c, NULL, NULL);
	BTree *root = btree_create(&d, l, r);

	btree_foreach(root, print_int, NULL);
	puts("");

	printf("La suma de sus elementos es %i.\n", btree_SumElem(root));
	printf("La cantidad de sus nodos es %i.\n", btree_CountNode(root));
	printf("La cantidad de niveles son %i\n",btree_HTree(root));
	int order = 0;
	printf("Lista de la forma %d\n", order);
	btree_foreach_v2(root,print_int,NULL,order);
	puts("");
	btree_remMin(root);
	btree_foreach_v2(root,print_int,NULL,order);
	puts("");

	btree_destroy(root);

	return 0;
}