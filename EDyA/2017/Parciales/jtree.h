#ifndef __JTREE_H__
#define __JTREE_H__

typedef struct {
	char *nombre, *club;
	int posicion, edad;
} _Jugador;

typedef _Jugador *Jugador;

typedef struct _Nodo {
	Jugador jug;
	struct _Nodo *izquierda, *derecha;
} Nodo;

Nodo *agregaJugador(Nodo *inicio, Jugador j);
Nodo *recuperaJugadoresPorEdad(Nodo *inicio, int edadMax, int edadMin);

#endif /* __JTREE_H__ */