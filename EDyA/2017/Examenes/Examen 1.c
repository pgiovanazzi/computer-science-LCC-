/* Los multiconjuntos son un tipo de contenedores asociativos similares al
 * conjunto, con la excepción de que varios elementos pueden tener los mismos
 * valores. Implementar esta estructura de datos, con las funciones
 * insertar(): que agregue un elemento al multiconjunto
 * count(): que devuelva la cantidad de elementos repetidos de un elemento del
 * multiconjunto.*/

#include <stdio.h>
#include <stdlib.h>

typedef int (*FuncionHash)(void *elem, int sz);
typedef int (*FuncionIgualdad)(void *elem1, void *elem2);

typedef struct _Casilla {
  void *elem;
  int valor;
} Casilla;

typedef struct _Multiconjunto {
  Casilla *caillas;
  int numElems, capacidad;
  FuncionHash hash;
  FuncionIgualdad iguales;
} Multiconjunto;

Multiconjunto *mc_crear(int capacidad, FuncionHash hash,
                        FuncionIgualdad igual) {
  Multiconjunto *nuevoMc = malloc(sizeof(Multiconjunto));
  nuevoMc->numElems = 0;
  nuevoMc->capacidad = capacidad;
  nuevoMc->hash = hash;
  nuevoMc->iguales = igual;
  nuevoMc->caillas = malloc(sizeof(Casilla) * capacidad);

  for (unsigned i = 0; i < capacidad; i++) {
    nuevoMc->caillas[i].elem = NULL;
    nuevoMc->caillas[i].valor = 0;
  }
  return nuevoMc;
}

void mc_insertar(Multiconjunto *mc, void *elem, int valor) {
  int idx = mc->hash(elem, mc->capacidad);
  mc->numElems += valor;

  if (mc->caillas[idx].elem == NULL) {
    mc->caillas[idx].elem = elem;
    mc->caillas[idx].valor = valor;
  } else {
    while (mc->caillas[idx].elem != NULL)
      idx = (idx + 1) % mc->capacidad;

    mc->caillas[idx].elem = elem;
    mc->caillas[idx].valor = valor;
  }
}

int mc_count(Multiconjunto *mc, void *elem) {
  int idx = mc->hash(elem, mc->capacidad);
  if (mc->caillas[idx].elem != NULL &&
      mc->iguales(mc->caillas[idx].elem, elem)) {
    return mc->caillas[idx].valor;
  }
  return -1;
}

// Extra
int mc_cantidad_de_elementos(Multiconjunto *mc) { return mc->numElems; }

void mc_desruir(Multiconjunto *mc) {
  free(mc->caillas);
  free(mc);
}

int fun_hash(void *elem, int sz) { return *(char *)elem % sz; }

int fun_iguales(void *e1, void *e2) { return *(char *)e1 == *(char *)e2; }

int main(int argc, char *argv[]) {
  char a = 'a', b = 'b', c = 'c';
  Multiconjunto *mc = mc_crear(10, fun_hash, fun_iguales);
  mc_insertar(mc, &a, 2);
  mc_insertar(mc, &b, 3);
  mc_insertar(mc, &c, 6);

  printf("Cantidad de elementos de \"a\": %d\n", mc_count(mc, &a));
  printf("Cantidad de elementos de \"b\": %d\n", mc_count(mc, &b));
  printf("Cantidad de elementos de \"c\": %d\n", mc_count(mc, &c));
	printf("Cantidad de eleentos en el Multiconjunto: %d\n", mc_cantidad_de_elementos(mc));

  mc_desruir(mc);

  return 0;
}
