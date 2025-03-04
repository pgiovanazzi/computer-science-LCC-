#ifndef __BSTree_H__
#define __BSTree_H__

typedef void (*VisitorFuncInt)(int data, void *extra_data);

typedef struct _BSTNode{
	int 	data;
	struct _BSTNode *left, *right;
} BSTNode;

typedef BSTNode *BSTree;

#define bstree_data(t)		(t)->data
#define bstree_left(t)		(t)->left
#define bstree_right(t)		(t)->right
#define bstree_nil()			NULL
/*
 *Agrega un elemento a un arblol binario ordenado
*/
BSTree bstree_insert(BSTree tree, int data);

/*
 *Dice si el elemento esta en el arbol binario ordenado
*/
int bstree_contains(BSTree tree, int data);

/*
 *Devuelve la cantidad de elementos de un arbol binario ordenado
*/
int bstree_nelements(BSTree tree);

/*
 *Devuekve la altura de un arbol binario ordenado
*/
int bstree_height(BSTree tree);

/*
 *Aplica una funcion a cada nodo del arbol binario ordenado
*/
void bstree_foreach(BSTree tree, VisitorFuncInt visit, void *extra_data);

/*
 *Destruye el arbol
*/
void bstree_destroy(BSTree tree);

/*
 *Funcion mirror genera a partir de un arbol binario un arbol binario espejo
 */
void bstree_mirror(BSTree tree);

#endif /*__BSTee_H__*/
