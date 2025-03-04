#include <stdio.h>
#include <stdlib.h>

#include "ej3.h"

lista *lista_crear(size_t tamanio)
{
	lista *nueva_lista = (lista *)malloc(sizeof(lista));

	nueva_lista->tamanio = tamanio;
	nueva_lista->datos = (int *)malloc(sizeof(int) * tamanio);
	nueva_lista->siguientes = (int *)malloc(sizeof(int) * tamanio);
	nueva_lista->primero = -1;
	nueva_lista->ultimo = -1;

	nueva_lista->usados = (char *)malloc(sizeof(char) * tamanio);
	for (int i = 0; i < tamanio; i++)
		nueva_lista->usados[i] = 0;

	return nueva_lista;
}

void lista_destruir(lista *lista)
{
	free(lista->datos);
	free(lista->siguientes);
	free(lista->usados);
	free(lista);

	return;
}

int lista_agregar_final(lista *lista, int nuevo_dato)
{

	if (lista->primero == -1)
	{
		// Lista vacia
		lista->primero = 0;
		lista->ultimo = 0;
		lista->datos[0] = nuevo_dato;
		lista->usados[0] = 1;
		lista->siguientes[0] = -1;
		return 0;
	}

	int posicion = 0;
	while (posicion < lista->tamanio && lista->usados[posicion])
		posicion++;

	if (posicion == lista->tamanio)
		// No podemos insertar, devolver error
		return 1;

	// posicion apunta a un lugar vacio, lo usamos para guardar nuevo dato
	lista->datos[posicion] = nuevo_dato;
	lista->usados[posicion] = 1;
	lista->siguientes[lista->ultimo] = posicion;
	lista->ultimo = posicion;
	lista->siguientes[posicion] = -1;

	return 0;
}

int lista_agregar_principio(lista *lista, int nuevo_dato)
{

	if (lista->primero == -1)
	{
		// Lista vacia
		lista->primero = 0;
		lista->ultimo = 0;
		lista->datos[0] = nuevo_dato;
		lista->usados[0] = 1;
		lista->siguientes[0] = -1;
		return 0;
	}

	int posicion = 0;
	while (posicion < lista->tamanio && lista->usados[posicion])
		posicion++;

	if (posicion == lista->tamanio)
		// No podemos insertar, devolver error
		return 1;

	// posicion apunta a un lugar vacio, lo usamos para guardar nuevo dato
	lista->datos[posicion] = nuevo_dato;
	lista->usados[posicion] = 1;
	lista->siguientes[posicion] = lista->primero;
	lista->primero = posicion;

	return 0;
}

void lista_imprimir(lista *lista)
{
	int i = lista->primero;

	if (i == -1 || !lista->usados[i])
	{
		// Nada que imprimir!
		printf("\n");
		return;
	}

	do
	{
		printf("%i ", lista->datos[i]);
		i = lista->siguientes[i];
	} while (i != -1);

	printf("\n");

	return;
}

int main()
{
	lista *lista_prueba = lista_crear(20);

	lista_agregar_final(lista_prueba, 1);
	lista_agregar_final(lista_prueba, 2);
	lista_agregar_final(lista_prueba, 3);
	lista_agregar_final(lista_prueba, 4);
	lista_agregar_final(lista_prueba, 5);

	lista_imprimir(lista_prueba);

	lista_agregar_principio(lista_prueba, 0);
	lista_agregar_principio(lista_prueba, -1);

	lista_imprimir(lista_prueba);

	lista_destruir(lista_prueba);

	return 0;
}
