#ifndef __MTREE_H__
#define __MTREE_H__

typedef void (*FuncionVisitante)(int dato);
typedef void (*FuncionVisitanteExtrea)(int dato, void *extra);

typedef struct _Nodo {
  int elem;
	int cantidadDeHijos;
  struct _Nodo *primerHijo;
  struct _Nodo *primerHermano;
} Nodo;

typedef Nodo *MTree;

// Crea un arbol de multiples hijos.
MTree mtree_crear(int elem);

// Destruye un arbol de multiples hijos.
void mtree_destruir(MTree arbol);

// Dado un dato, agrega un nodo hijo en la posicion indicada.
// Si la posicion indicada es mayor al numero de hijos se agragara al final.
MTree mtree_agregar_n_hijo(MTree raiz, MTree nodoHijo, int pos);

// Recorre el arbol.
void mtree_recorrer(MTree arbol, FuncionVisitante visit);

// Recorre el arbol con un valor extra.
void mtree_recorrer_extra(MTree arbol, FuncionVisitanteExtrea visit, void *extra);

// Rreorna la cantidad de nodos del arbol de multiples hijos.
unsigned mtree_cantidad(MTree arbol);

// Retorna la altura del arbol de multiples hijos.
unsigned mtree_altura(MTree arbol);

#endif /* __MTREE_H__ */