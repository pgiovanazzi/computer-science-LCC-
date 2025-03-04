#ifndef __ABCTree_H__
#define __ABCTree_H__

typedef void (*VisitorFuncInt)(int data, void *extra_data);

#define MAX   128
static int store = 0;

typedef struct _ABCNode{
  int *data;
  int nelems;
} ABCNode;

typedef ABCNode *ABCTree;

#define abctree_data(t,d)   (t)->data[(d)]
#define abctree_len(t)      (t)->nelems

/*
  Crea un nuevo árbol de una cantidad de niveles dado.
*/
ABCTree abctree_new(int lvl);

/*
  Recibe un árbol y lo destruye.
*/
void abctree_destroy(ABCTree tree);

/*
  Agrega un elemento a un árbol en la siguiente posición disponible.
*/
ABCTree abctree_insert(ABCTree tree, int data);

/*
  Devuelve la cantidad de elementos en el árbol.
*/
int abctree_nelements(ABCTree tree);

/*
  Aplica una función a cada nodo del árbol.
*/
void abctree_foreach(ABCTree tree, VisitorFuncInt visit, void *extra_data);

#endif
