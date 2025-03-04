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
void  btree_foreach(BTree *list, VisitorFuncInt visit, void *extra_data);

/**
 * Ejericio 2:
 */
//Devuelve la suma de los elementos de un  árbol de enteros.
int btree_SumElem(BTree *tree);

//Devuelve la cantidad de nodos de un  árbol de enteros.
int btree_CountNode(BTree *tree);

//Devuelve la altura de un árbol de enteros.
int btree_HTree(BTree *tree);

/**
 * Ejericio 3:
 */
//Recorrido del árbol, utilizando la funcion pasada y en diferentes formas (in,pre,post).
void  btree_foreach_v2(BTree *node, VisitorFuncInt visit, void *extra_data, BTreeTraversalOrder order);

/**
 * Ejericio 4:
 */
void btree_remMin(BTree *tree, int *min);

/*
	Ejercicio de queues, Ejercicio 8:
*/
void btree_foreach_level(BTree *list, VisitorFuncInt visit, void *extra_data);

#endif /* __BTREE_H__ */
