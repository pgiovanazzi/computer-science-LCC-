#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

unsigned int hash(void *key)
{
	int *p = key;
	return *p % 10;
}

int main(void)
{
	int x = 42, y = 42, z = 3;
	Hashtable *ht = hashtable_new(10, hash);

	hashtable_insert(ht, &x, &z);
	hashtable_insert(ht, &x, &z);

	printf("z : %d\n", *((int *)hashtable_lookup(ht, &x)));
	/*
		Al aplicar dos veces insert con la misma clave, no se produce ningun error.
		La primera vez que la ejemcutamos la funciun insert hashea la llave, y luego
		pasa por el if sumando un elemento, y luego se le asigna a la clave y el valor
		en la posicion de la tabla que le corresponde.
		La segunda vez que se ejecuta la diferencia es que no pasa por el if, ya que ya
		tiene una direccion asosciada en la posicion de la tabla en la clave, y luego
		reescribe la dirreccion nuevamente con las mismas direcciones sus respectivas 
		dirreciones clave valor.
  */

	hashtable_delete(ht, &x);

	hashtable_destroy(ht);

	return 0;
}
