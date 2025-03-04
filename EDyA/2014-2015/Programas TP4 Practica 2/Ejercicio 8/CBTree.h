#ifndef __CBTree_H__
#define __CBTree_H__

#define MAX 128

typedef void (*visitorFunInt)(int data, void *extradata);

typedef struct _CBTree{
	int data[MAX];
	int nelems;
} CBTree;

#define bctree_data(t,i)		t.data[i]
#define bctree_len(t)			t.nelems

//Crea un nuevo árbol de una cantidad de niveles dado.
CBTree *cbtree_new(CBTree *tree, int n);

//Destruye un árbol.
void cbtree_destroy(CBTree *tree);

//Agrea un elemento a un árbol en la siguiente posición disponible.
CBTree *cbtree_insert(CBTree *tree, int data);

//Devuelve la cantidad de elementos de un arblo.
int cbtree_nelements(CBTree *tree);

//Aplica una función a cada nodo del árbol.
void cbtree_foreach(CBTree *tree, visitorFunInt visit, void *extradata);

#endif