#ifndef __TABLAHASH_H__
#define __TABLAHASH_H__

/**
 * Tipo de las funciones hash a ser consideradas por las tablas hash.
 */
typedef unsigned (*FuncionHash)(void *clave);
/**
 * Tipo de las funciones igualdad a ser consideradas por las tablas hash.
 */
typedef int (*FuncionIgualdad)(void *, void *);

/**
 * Casillas en la que almacenaremos los datos de la tabla hash.
 */
typedef struct _CasillaHash{
  void *clave;
  void *dato;
	struct _CasillaHash *sig;
} Casilla;

typedef Casilla *CasillasHash;

/**
 * Estructura principal que representa la tabla hash.
 */
typedef struct {
  CasillasHash *tabla;
  unsigned numElems;
  unsigned capacidad;
  FuncionHash hash;
	FuncionIgualdad igualdad;
} TablaHash;

/**
 * Crea una nueva tabla Hash vacía, con la capacidad dada.
 */
TablaHash *tablahash_crear(unsigned capacidad, FuncionHash funH, FuncionIgualdad funI);

/**
 * Inserta el dato en la tabla, asociado a la clave dada.
 */
void tablahash_insertar(TablaHash *tabla, void *clave, void *dato);

/**
 * Busca un elemento dado en la tabla, y retorna un puntero al mismo.
 * En caso de no existir, se retorna un puntero nulo.
 */
void *tablahash_buscar(TablaHash *tabla, void *clave);

/**
 * Elimina un elemento de la tabla.
 */
TablaHash *tablahash_eliminar(TablaHash *tabla, void *clave);

/**
 * Destruye la tabla.
 */
void tablahash_destruir(TablaHash *tabla);

#endif /* __TABLAHASH_H__ */
