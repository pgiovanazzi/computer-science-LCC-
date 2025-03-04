#ifndef __BSTree_H__
#define __BSTree_H__

typedef void (*VisitorFuncInt) (int data, void *extra_data);

typedef struct _BSTree{
	int data;
	struct _BSTree *left, *right;
} BSTree;

#define bstree_data(l)		(l)->data
#define bstree_left(l)		(l)->left
#define	bstree_right(l)	(l)->right

//Agrega un elemento al árbol binario ordenado.
BSTree *bstree_insert(BSTree *tree, int data);

//Verifica si un elemento está en el árbol binario ordenado.
int bstree_contains(BSTree *tree, int data);

//Devuelve la cantidad de elementos de un árbol binario ordenado.
int bstree_nelements(BSTree *tree);

//Devuelve la altura de un árbol binario ordenado.
int bstree_height(BSTree *tree);

//Aplica una función en cada node de un árbol binario ordenado.
void bstree_foreach(BSTree *tree, VisitorFuncInt visit, void *extra_data);

/*
 *Ejercicio 6
 */
//Dado un árbol binario, genera el árbol binario espejo.
void *bstree_mirror(BSTree *tree);

#endif /* __BSTree_H__ */