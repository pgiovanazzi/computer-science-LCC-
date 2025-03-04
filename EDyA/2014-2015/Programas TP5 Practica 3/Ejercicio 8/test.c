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

	printf("Impreción preorder:\n");
	btree_foreach(root, print_int, NULL, 1);
	puts("");

	printf("Impreción por nivel:\n");
	btree_foreach_level(root, print_int, NULL);
	puts("");

	printf("Applica el menor elemento del arbol a todos los nodos:\n");
	btree_remMin(root, btree_min(root));
	
	btree_foreach(root, print_int, NULL, 1);
	puts("");

	btree_destroy(root);

	return 0;
}

