#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Objetivo {
  char *pais;
  char *ciudad;
  int latidud;
  int longitud;
} Objetivo;

typedef struct _Nodo {
  Objetivo dato;
  struct _Nodo *siguiente;
  struct _Nodo *anterior;
} Nodo;

Nodo *agregarObjetivo(Nodo *inicio, Objetivo o) {
  Nodo *nodoNuevo = malloc(sizeof(Nodo));
  nodoNuevo->dato = o;
  nodoNuevo->siguiente = nodoNuevo;
  nodoNuevo->anterior = nodoNuevo;

  if (inicio == NULL)
    return nodoNuevo;

  nodoNuevo->siguiente = inicio;
  nodoNuevo->anterior = inicio->anterior;
  inicio->anterior = nodoNuevo;
  nodoNuevo->anterior->siguiente = nodoNuevo;

  return inicio;
}

void muestraObjetivosPorPais(Nodo *inicio, char *pais) {
  Nodo *nodoActual = inicio;
  int objetivoEncontrado = 0;

  while (nodoActual) {
    if (!strcmp(pais, nodoActual->dato.pais)) {
      objetivoEncontrado++;
      printf("Pais: %s\n", pais);
      printf("Ciudad: %s\n", nodoActual->dato.ciudad);
      printf("Latitud: %d\n", nodoActual->dato.latidud);
      printf("Longitud: %d\n", nodoActual->dato.longitud);
    }
    nodoActual = nodoActual->siguiente;
    if (nodoActual == inicio && objetivoEncontrado)
      break;
    else if (nodoActual == inicio) {
      printf("No se enotro objetivo para este pais %s.\n", pais);
      break;
    }
  }
}

void lista_destruir(Nodo *lista) {
	Nodo *inicial = lista;
	while (1) {
		Nodo *nodoActual = lista;
		lista = lista->siguiente;
		free(nodoActual);
		if (inicial == lista)
			break;
	}
}

int main(int argc, char *argv[]) {
  Objetivo objetivo1 = {"SurCorea", "Sakakaka", 20, 50};
	Objetivo objetivo2 = {"EEUU", "LosAguacates", 200, 413};
	Objetivo objetivo3 = {"SurCorea", "ChinChan", 51, 10};
	Objetivo objetivo4 = {"Japon", "NikuraNiSaka", 100, 110};
	Nodo *listaDeObjetivos = NULL;

	listaDeObjetivos = agregarObjetivo(listaDeObjetivos, objetivo1);
	listaDeObjetivos = agregarObjetivo(listaDeObjetivos, objetivo2);
	listaDeObjetivos = agregarObjetivo(listaDeObjetivos, objetivo3);

	muestraObjetivosPorPais(listaDeObjetivos, "SurCorea");
	muestraObjetivosPorPais(listaDeObjetivos, "EEUU");

	lista_destruir(listaDeObjetivos);

  return 0;
}