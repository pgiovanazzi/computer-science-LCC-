#include <stdlib.h>
#include "dlist.h"

DList dlist_crear()
{
	DList nuevaLista = NULL;
	return nuevaLista;
}

void dlist_destruir(DList lista)
{
	while (!lista->limite->final)
	{
		DList nodo = lista;
		lista = lista->sig;
		free(nodo->limite);
		free(nodo);
	}
	free(lista->limite);
	free(lista);
}

int dlist_vacia(DList lista)
{
	return (lista) ? 0 : 1;
}

DList dlist_agregar_final(DList lista, int dato)
{
	DNodo *nuevoNodo = malloc(sizeof(DNodo));
	nuevoNodo->limite = malloc(sizeof(Limites));
	nuevoNodo->dato = dato;

	if (dlist_vacia(lista))
	{
		nuevoNodo->limite->inicio = nuevoNodo->limite->final = 1;
		nuevoNodo->prev = nuevoNodo->sig = nuevoNodo;
		return nuevoNodo;
	}
	nuevoNodo->limite->inicio = 0;
	nuevoNodo->limite->final = 1;
	lista->prev->limite->final = 0;
	lista->prev->sig = nuevoNodo;
	nuevoNodo->prev = lista->prev;
	lista->prev = nuevoNodo;
	nuevoNodo->sig = lista;

	return lista;
}

DList dlist_agregar_inicio(DList lista, int dato)
{
	DNodo *nuevoNodo = malloc(sizeof(DNodo));
	nuevoNodo->limite = malloc(sizeof(Limites));
	nuevoNodo->dato = dato;

	if (dlist_vacia(lista))
	{
		nuevoNodo->limite->inicio = nuevoNodo->limite->final = 1;
		nuevoNodo->prev = nuevoNodo->sig = nuevoNodo;
		return nuevoNodo;
	}
	nuevoNodo->limite->inicio = 1;
	nuevoNodo->limite->final = 0;
	lista->limite->inicio = 0;
	lista->prev->sig = nuevoNodo;
	nuevoNodo->prev = lista->prev;
	nuevoNodo->sig = lista;
	lista->prev = nuevoNodo;

	return nuevoNodo;
}

void dlist_recorrer(DList lista, FuncionVisitante visita, DListOrdenDeRecorrido orden)
{
	DList nodoTemp = lista;
	if (dlist_vacia(lista))
		return;
	if (!orden)
	{
		do
		{
			visita(nodoTemp->dato);
			nodoTemp = nodoTemp->sig;
		} while (!nodoTemp->limite->inicio);
		return;
	}
	do
	{
		visita(nodoTemp->dato);
		nodoTemp = nodoTemp->prev;
	} while (!nodoTemp->limite->inicio);
	return;
}

int dlist_longitud(DList lista)
{
	DList nodoTemp = lista;
	int len = 0;
	if (dlist_vacia(lista))
		return len;
	do
	{
		len++;
		nodoTemp = nodoTemp->sig;
	} while (!nodoTemp->limite->inicio);
	return len;
}

DList dlist_concatenar(DList lista1, DList lista2)
{
	if (dlist_vacia(lista1)) 
		return lista2;
	if (dlist_vacia(lista2))
		return lista1;
	lista1->limite->final = 0;
	lista2->limite->inicio = 0;
	lista1->prev->sig = lista2;
	lista2->prev->sig = lista1;
	DList tmp = lista1->prev;
	lista1->prev = lista2->prev;
	lista2->prev = tmp;
	return lista1;
}