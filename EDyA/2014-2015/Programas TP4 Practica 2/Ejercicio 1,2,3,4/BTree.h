#ifndef __BTREE_H__
#define __BTREE_H__

typedef void (*VisitorFuncInt) (int data, void *extra_data);

typedef enum {
	BTREE_TRAVERSAL_ORDER_IN,
	BTREE_TRAVERSAL_ORDER_PRE,
	BTREE_TRAVERSAL_ORDER_POST
} BTreeTraversalOrder;

/**
 * Los campos son privados, y no deberian ser accedidos
 * desde el código cliente.
 */
typedef struct _BTNode{
	int    data;
	struct _BTNode *left;
	struct _BTNode *right;
} BTree;

#define btree_data(l)       (l)->data
#define btree_left(l)       (l)->left
#define btree_right(l)      (l)->right

/**
 * Crea un nuevo nodo, en complejidad O(1).
 *
 * Nota: el árbol vacio se representa con un (BTree *) NULL.
 */
BTree *btree_create(int data, BTree *left, BTree *right);

/**
 * Destruccion del árbol.
 */
void  btree_destroy(BTree *root);

/**
 * Recorrido del árbol, utilizando la funcion pasada.
 */
//void  btree_foreach(BTree *list, VisitorFuncInt visit, void *extra_data);

/**
 * Ejericio 2
 */
//suma de los elementos de un  árbol de enteros.
int btree_sumelem(BTree *tree);

//la cantidad de nodos de un  árbol de enteros.
int btree_cantnode(BTree *tree);

//la altura de un  árbol de enteros.
int btree_altutree(BTree *tree);

/**
 * Ejericio 3
 */
//Recorrido del árbol, utilizando la funcion pasada y en diferentes formas (in,pre,post).
void  btree_foreach(BTree *node, VisitorFuncInt visit, void *extra_data, BTreeTraversalOrder o);

/**
 * Ejericio 4
 */

void btree_remMin(BTree *tree, int min);

#endif /* __BTREE_H__ */

