#ifndef __BSTREE_H__
#define __BSTREE_H__

typedef void (*FuncionVisitante)(int dato);

typedef struct _Nodo {
  int dato;
  struct _Nodo *izq, *der;
} Nodo;

typedef Nodo *BSTree;

// Agrega un elemento al arbol binario de búsqueda.
void bstree_insertar(BSTree *arbol, int elem);

// Elimina un elemento del arbol binario de búsqueda
void bstree_eliminar(BSTree *arbol, int elem);

// Determina si el elemento esta en el arbol binario de búsqueda.
unsigned bstree_contiene(BSTree arbol, int elem);

// Devielve la cantidad de elementos del arbol binario de búsqueda.
unsigned bstree_nelementos(BSTree arbol);

// Devuelve la altura de un árbol binario de búsqueda.
unsigned bstree_altura(BSTree arbol);

// Aplica una funcion a cada nodo del árbol binario de búsqueda.
void bstree_recorrer(BSTree arbol, FuncionVisitante visit);

// Destruye el arbol binario de busqueda.
void bstree_destruir(BSTree arbol);

// Balancea en cantidad un arbol binario de busqueda.
void bstree_balancear(BSTree *arbol);

// Devuelve el minimo elemento del arbol binario de busqueda de manera eficiente.
int bstree_minimo(BSTree arbol);

// Retorna el elemento que se encuentra en la posicion de un indice.
int bstree_acceder(BSTree arbol, int indice);

#endif /* __BSTREE_H__ */