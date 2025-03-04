#ifndef __XORList_H__
#define __XORList_H__

/*Implementacion de una lista enlazada XOR*/

typedef void (*VisitorFuncInt)(int data,void *extra_data);

typedef struct _XORNode{
  int data;
  struct _XORNode *npx;
} XORNode;

typedef XORNode *XORList;

#define _xor(a,b)           (XORList)((long)(a)^(long)(b))
#define xorlist_data(l)     (l)->data
#define xorlist_npx(l)      (l)->npx

/*Agrega un elemento al principio de la lista*/
XORList xorlist_prepend(XORList list, int data);

/*Aplica una funcion a cada nodo de la lista*/
void xorlist_foreach(XORList list, VisitorFuncInt visit, void *extra_data);

/*La diferencia de una estructura de lista doblemente enlazada con respecto
a una lista enlazada XOR es que la lista doblemente enlazada almacena en memoria
dos punteros por nodo, nodos adyacentes al nodo (previo y siguiente), mientras que
la lista enlazada XOR solo almacena una direccion de memoria por nodo que es
el XOR de los punteros previo y siguiente del nodo.
Se puede recorrer la lista en ambas direcciones y se debe a las propiedades
del operador XOR.
Ejemplo: sea la lista {..ABC..}
El Nodo A:
npx = NULL ^ dir(B)
El Nodo B:
npx = dir(A)^ dir(C)
El nodo C:
npx = dir(B) ^ NULL
*/

#endif /*__XORList_H__*/
