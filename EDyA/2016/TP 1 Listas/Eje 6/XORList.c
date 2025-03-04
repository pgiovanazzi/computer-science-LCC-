#include <stdlib.h>
#include "XORList.h"

XORList xorlist_prepend(XORList list, int data) {
  XORList newNode = malloc(sizeof(XORNode));
  xorlist_data(newNode) = data;
  // Dado que el nuevo nodo se inserta al principio, el npx del nuevo nodo sera
  // siempre el XOR del nodo actual y el NULL
  xorlist_npx(newNode) = _xor(list,NULL);

  if (!list) {
    // El xorlist_npx(list) es el XOR de NULL y el siguente, asi que si hacemos el XOR
    // de xorlist_npx(list) con NULL tenemos el siguiente
    XORList next = _xor(xorlist_npx(list),NULL);
    xorlist_npx(list) = _xor(newNode,next);
  }
  list = newNode;
  return list;
}

void xorlist_foreach(XORList list, VisitorFuncInt visit, void *extra_data) {
  XORList node = list, prev = NULL, next;

  while (node != NULL) {
    // Aplica la funcon al dato del nodo
    visit(xorlist_data(node),extra_data);
    // Optiene la direccion del siguiente nodo: xorlist_npx(node) es next^prev,
    // asi que xorlist_npx(node)^prev sera next^prev^prev lo cual es next
    next = _xor(prev,xorlist_npx(node));
    // Actualiza el prev y el nodo para la proxima iteracion
    prev = node;
    node = next;
  }

}
