#include "jtree.h"
#include <stdio.h>
#include <stdlib.h>

Nodo *agregaJugador(Nodo *inicio, Jugador j) {
  Nodo *q = NULL;
	Nodo *p = inicio;
	while (p) {
		q = p;
		if (j->edad <= p->jug->edad)
			p = p->izquierda;
		else
			p = p->derecha;
	}
	Nodo *nuevoJugador = malloc(sizeof(Nodo));
	nuevoJugador->jug = j;
	nuevoJugador->izquierda = NULL;
	nuevoJugador->derecha = NULL;
	if (!q) {
		return nuevoJugador;
	} else {
		if (j->edad <= q->jug->edad) 
			q->izquierda = nuevoJugador;
		else
			q->derecha = nuevoJugador;
	}
	return inicio;
}

static void recorrer_nodos(Nodo *inicio, Nodo **nodoJugEdad, int edadMax,
                           int edadMin) {
  if (inicio) {
    recorrer_nodos(inicio->izquierda, nodoJugEdad, edadMax, edadMin);
    if (inicio->jug->edad <= edadMax && inicio->jug->edad >= edadMin)
     *nodoJugEdad = agregaJugador(*nodoJugEdad, inicio->jug);
    recorrer_nodos(inicio->derecha, nodoJugEdad, edadMax, edadMin);
  }
}

Nodo *recuperaJugadoresPorEdad(Nodo *inicio, int edadMax, int edadMin) {
  if (!inicio || edadMax < edadMin)
    return NULL;

  Nodo *arbolJugadoresPorEdad = NULL;

  recorrer_nodos(inicio, &arbolJugadoresPorEdad, edadMax, edadMin);

  return arbolJugadoresPorEdad;
}

void imprimir_jugadores(Nodo *arbol) {
  if (arbol) {
    imprimir_jugadores(arbol->izquierda);
    printf("\tNombre: %s\n", arbol->jug->nombre);
    printf("\tClub: %s\n", arbol->jug->club);
    printf("\tPosicion: %d\n", arbol->jug->posicion);
    printf("\tEdad: %d\n", arbol->jug->edad);
		puts("");
    imprimir_jugadores(arbol->derecha);
  }
}

void destruir_jugadores(Nodo *arbol) {
  if (arbol) {
    destruir_jugadores(arbol->izquierda);
    destruir_jugadores(arbol->derecha);
    free(arbol);
  }
}

int main(int argc, char *argv[]) {
  _Jugador jugador1 = {"Juancho", "rc", 5, 25};
  _Jugador jugador2 = {"Ricardone", "noob", 10, 30};
  _Jugador jugador3 = {"Ivan", "nose", 12, 32};
  _Jugador jugador4 = {"Pedro", "queseyo", 7, 27};

  Nodo *arbolDeJugadores = NULL;

  arbolDeJugadores = agregaJugador(arbolDeJugadores, &jugador1);
  arbolDeJugadores = agregaJugador(arbolDeJugadores, &jugador2);
  arbolDeJugadores = agregaJugador(arbolDeJugadores, &jugador3);
  arbolDeJugadores = agregaJugador(arbolDeJugadores, &jugador4);

	printf("Jugadores:\n");
  imprimir_jugadores(arbolDeJugadores);

	Nodo *jugadoresSelec = NULL; 
	jugadoresSelec = recuperaJugadoresPorEdad(arbolDeJugadores, 30, 27);

	printf("Jugadores seleccionados:\n");
	imprimir_jugadores(jugadoresSelec);

  destruir_jugadores(arbolDeJugadores);
	destruir_jugadores(jugadoresSelec);
  return 0;
}