/* Implementar una estructura que represente los conjuntos tipicos de matemática
 * con un arbol binario de busqueda BST. Teniendo la siguiente estructura
 * definida
 * implementar las siguientes funciones, teniendo su criterio de la signatura.
 * */

typedef struct _nodoBST {
  int dato;
  struct _nodoBST *izq, *der;
} nodoBST;

typedef nodoBST* BSTSet;

// a. crearBST, crea un BST basio.
BSTSet crearBST();

// b. agregarBST, que agrege un elemento al conjunto. Tener encuenta que si el
// elemento ya existe no tiene que agregarlo porque tiene que cumplir las
// propidades de conjunto.
BSTSet agregaBST(BSTSet set, int elem);

// c. imprimirBST, que imprima los elementos del conjunto de manera acendente.
void imprimirBST(BSTSet set);

// d. contieneBST, que determine si el elemento pertenece al conjunto, que
// devuelva
// 1 si esta en el conjunto, 0 en caso contrario.
int contieneBST(BSTSet set, int elem);

// e. unionBST, que una dos conjuntos y devuelva el resutlado.
BSTSet unionBST(BSTSet s1, BSTSet s2);

// f. cercanoBST, que dado un conjunto y un entero k devuelva el elemento mas
// sercano a k tanto como negativo o positivo (el valor absoluto).
int cercanoBST(BSTSet set, int k);

#include <stdio.h>
#include <stdlib.h>

BSTSet crearBST() {
  return NULL;
}

BSTSet agregaBST(BSTSet set, int elem) {
  BSTSet nuevoNodo = malloc(sizeof(nodoBST));
  nuevoNodo->dato = elem;
  nuevoNodo->der = NULL;
  nuevoNodo->izq = NULL;

  BSTSet q = NULL;
  BSTSet p = set;

  while (p) {
    q = p;
    if (p->dato == elem)
      return set;
    if (p->dato < elem)
      p = p->der;
    else
      p = p->izq;
  }

  if (!q)
    return nuevoNodo;
  if (q->dato < elem)
    q->der = nuevoNodo;
  else
    q->izq = nuevoNodo;

  return set;
}

void imprimirBST(BSTSet set) {
  if (set) {
    imprimirBST(set->izq);
    printf("%d, ", set->dato);
    imprimirBST(set->der);
  }
}

int contienBST(BSTSet set, int elem) {
  int elemPertenece = 0;
  if (!set)
    return elemPertenece;

  BSTSet nodoActual = set;
  while (nodoActual) {
    if (nodoActual->dato == elem) {
      elemPertenece = 1;
      break;
    } else if (nodoActual->dato < elem)
      nodoActual = nodoActual->der;
    else
      nodoActual = nodoActual->izq;
  }

  return elemPertenece;
}

static void cargarBST(BSTSet set, BSTSet* setUnion) {
  if (set) {
    *setUnion = agregaBST(*setUnion, set->dato);
    cargarBST(set->izq, setUnion);
    cargarBST(set->der, setUnion);
  }
}

BSTSet unionBST(BSTSet s1, BSTSet s2) {
  BSTSet conjuntoUnion = NULL;
  cargarBST(s1, &conjuntoUnion);
  cargarBST(s2, &conjuntoUnion);
  return conjuntoUnion;
}

static unsigned absoluto(int a) {
  return (a < 0) ? (-a) : a;
}

static int distancia(int x, int y) {
  return absoluto(x - y);
}

int cercanoBST(BSTSet set, int k) {
  int cercano = set->dato;
  BSTSet nodoActual = set;

  while (nodoActual) {
    if (distancia(nodoActual->dato, k) < distancia(cercano, k))
      cercano = nodoActual->dato;
    if (nodoActual->dato < k)
      nodoActual = nodoActual->der;
    else
      nodoActual = nodoActual->izq;
  }

  return cercano;
}

void destruirBST(BSTSet set) {
  if (set) {
    destruirBST(set->izq);
    destruirBST(set->der);
    free(set);
  }
}

int main(int argc, char* argv[]) {
  BSTSet c1 = crearBST();
  BSTSet c2 = crearBST();
  BSTSet c3 = crearBST();

  c1 = agregaBST(c1, 6);
  c1 = agregaBST(c1, 1);
  c1 = agregaBST(c1, 5);
  c1 = agregaBST(c1, 5);
  c1 = agregaBST(c1, 8);
  c1 = agregaBST(c1, 8);
  c1 = agregaBST(c1, 8);

  c2 = agregaBST(c2, 2);
  c2 = agregaBST(c2, 3);
  c2 = agregaBST(c2, 9);
  c2 = agregaBST(c2, 7);
  c2 = agregaBST(c2, 5);

  printf("Conjunto A = { ");
  imprimirBST(c1);
  puts("}");

  printf("Conjunto B = { ");
  imprimirBST(c2);
  puts("}");

  c3 = unionBST(c1, c2);
  printf("Conjunto A U B = { ");
  imprimirBST(c3);
  puts("}");

  printf("El elemento mas cercano a 4 del conjunto A U B es %d\n",
         cercanoBST(c3, 4));

  destruirBST(c1);
  destruirBST(c2);
  destruirBST(c3);

  return 0;
}