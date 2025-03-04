#include "slist.h"
#include <stdlib.h>

SList slist_crear()
{
	return NULL;
}

void slist_destruir(SList lista)
{
	SNodo *nodoAEliminar;
	while (lista != NULL)
	{
		nodoAEliminar = lista;
		lista = lista->sig;
		free(nodoAEliminar);
	}
}

int slist_vacia(SList lista)
{
	return lista == NULL;
}

SList slist_agregar_final(SList lista, int dato)
{
	SNodo *nuevoNodo = malloc(sizeof(SNodo));
	nuevoNodo->dato = dato;
	nuevoNodo->sig = NULL;

	if (lista == NULL)
		return nuevoNodo;

	SList nodo = lista;
	for (; nodo->sig != NULL; nodo = nodo->sig)
		;
	/* ahora 'nodo' apunta al ultimo elemento en la lista */

	nodo->sig = nuevoNodo;
	return lista;
}

SList slist_agregar_inicio(SList lista, int dato)
{
	SNodo *nuevoNodo = malloc(sizeof(SNodo));
	nuevoNodo->dato = dato;
	nuevoNodo->sig = lista;
	return nuevoNodo;
}

void slist_recorrer(SList lista, FuncionVisitante visit)
{
	for (SNodo *nodo = lista; nodo != NULL; nodo = nodo->sig)
		visit(nodo->dato);
}

void slist_ordenar(SList lista, CmpFun cmp)
{
	int ordenado, temporal;
	do
	{
		ordenado = 1;
		for (SList nodo = lista; nodo->sig; nodo = nodo->sig)
		{
			if (cmp(&nodo->dato, &nodo->sig->dato) > 0)
			{
				ordenado = 0;
				temporal = nodo->dato;
				nodo->dato = nodo->sig->dato;
				nodo->sig->dato = temporal;
			}
		}

	} while (!ordenado);
}

void slist_reverso(SList lista)
{
	SList listaTemporal = slist_crear(), nodoTemporal1 = lista, nodoTemporal2;

	for (; nodoTemporal1; nodoTemporal1 = nodoTemporal1->sig)
		listaTemporal = slist_agregar_inicio(listaTemporal, nodoTemporal1->dato);

	nodoTemporal2 = listaTemporal;

	for (nodoTemporal1 = lista; nodoTemporal2; nodoTemporal2 = nodoTemporal2->sig, nodoTemporal1 = nodoTemporal1->sig)
		nodoTemporal1->dato = nodoTemporal2->dato;

	slist_destruir(listaTemporal);
}

SList slist_intercalar(SList lista1, SList lista2)
{
	SList lista3 = slist_crear();
	SList nodoTemporal1 = lista1;
	SList nodoTemporal2 = lista2;
	while (nodoTemporal1 || nodoTemporal2)
	{
		if (nodoTemporal1)
		{
			lista3 = slist_agregar_final(lista3, nodoTemporal1->dato);
			nodoTemporal1 = nodoTemporal1->sig;
		}
		if (nodoTemporal2)
		{
			lista3 = slist_agregar_final(lista3, nodoTemporal2->dato);
			nodoTemporal2 = nodoTemporal2->sig;
		}
	}
	return lista3;
}
