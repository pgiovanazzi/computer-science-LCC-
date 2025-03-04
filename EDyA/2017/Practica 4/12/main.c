#include "BSTree.h"
#include <stdio.h>

void imprimir_entero(int dato) { printf("%d ", dato); }

int main(int argc, char *argv[]) {
  BSTree arbol = NULL;

  bstree_insertar(&arbol, 20);
  bstree_insertar(&arbol, 10);
  bstree_insertar(&arbol, 9);
  bstree_insertar(&arbol, 8);
  bstree_insertar(&arbol, 7);
  bstree_insertar(&arbol, 6);
  bstree_insertar(&arbol, 5);
  // La condicion necesaria para que el arbol binario de busqueda tenga forma de
  // lista es ingresando lo valores de mayor a menor.
  // La cantidad de nodos que tendra que recorrer para buscar un elemento en un
  // arbol binario de busqueda con forma de lista, van ha ser los primeros n
  // nodos, donde n es el elemento a encontrar. Mientras que en un arbol binario
  // de busqueda que no tenga forma de lista seran la mitad.

  printf("Arbol:\n");
  bstree_recorrer(arbol, imprimir_entero);
  puts("");
  printf("Cantidad de elemetos: %d\n", bstree_nelementos(arbol));
  printf("Altura: %d\n", bstree_altura(arbol));
  printf("Contiene el 5? %d\n", bstree_contiene(arbol, 5));
  printf("Contiene el 3? %d\n", bstree_contiene(arbol, 3));

  printf("bstree_eliminar(arbol, 10)\n");
  bstree_eliminar(&arbol, 10);
  printf("Arbol:\n");
  bstree_recorrer(arbol, imprimir_entero);
  puts("");
  printf("bstree_eliminar(arbol, 2)\n");
  bstree_eliminar(&arbol, 2);
  printf("Arbol:\n");
  bstree_recorrer(arbol, imprimir_entero);
  puts("");
	printf("Minimo: %d\n", bstree_minimo(arbol));

	bstree_balancear(&arbol);
	printf("Arbol:\n");
  bstree_recorrer(arbol, imprimir_entero);
  puts("");
	printf("Altura: %d\n", bstree_altura(arbol));

  bstree_destruir(arbol);
  return 0;
}