#include <stdio.h>
#include "MTree.h"

static void imprimir(int datoIn) {
	printf("%d ", datoIn);
}

int main(int argc, char *argv[]) {
	
	MTree raiz = mtree_crear(5);
	MTree h1 = mtree_crear(6);
	MTree h2 = mtree_crear(1);
	MTree h3 = mtree_crear(8);
	MTree h4 = mtree_crear(4);
	MTree h5 = mtree_crear(9);
	MTree h6 = mtree_crear(0);
	MTree h7 = mtree_crear(3);
	MTree h8 = mtree_crear(7);
	MTree h9 = mtree_crear(10);
	MTree h10 = mtree_crear(11);
	MTree h11 = mtree_crear(12);


	raiz = mtree_agregar_n_hijo(raiz, h1, 0);
	raiz = mtree_agregar_n_hijo(raiz, h2, 0);
	raiz = mtree_agregar_n_hijo(raiz, h3, 0);
	h3 = mtree_agregar_n_hijo(h3, h4, 0);
	h3 = mtree_agregar_n_hijo(h3, h5, 1);
	h1 = mtree_agregar_n_hijo(h1, h6, 0);
	h1 = mtree_agregar_n_hijo(h1, h7, 1);
	h1 = mtree_agregar_n_hijo(h1, h8, 2);
	h2 = mtree_agregar_n_hijo(h2, h9, 0);
	h9 = mtree_agregar_n_hijo(h9, h10, 0);
	h10 = mtree_agregar_n_hijo(h10, h11, 0);

	mtree_recorrer(raiz, imprimir);
	puts("");

	printf("Cantidad de nodos: %d\n", mtree_cantidad(raiz));
	printf("Altura: %d\n", mtree_altura(raiz));

	mtree_destruir(raiz);

	return 0;
}