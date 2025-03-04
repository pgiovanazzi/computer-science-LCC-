/*
 * Leer un archivo de una cinta tiene diferente penalidad que leer un archivo de un disco,
 * ya que hay que adelantar la cinta hasta la posicion donde leer el archivo. Suponiendo
 * que existen n archivos, donde el tamaño del archivo i es el natural l[i], deseamos obtener
 * una permutacion de <1,2,...,n> que minimice el costo de lectura promedio.
 * Si tenemos una permutacion <p[1],p[2],...,p[n]>, entonces el costo de leer el archivo k es
 *                  costo(k) = sumatoria de i=1 hasta k de l[p[i]] (el tamaño l de p[i])
 * y el costo promedio es
 *                  sumatoria de i=1 hasta n del costo(i)/n
 *
 * a) Dar una estrategia greedy que resuelva el problema.
 * b) Implemente la siguiente funcion en C, que aplica la estrategia del punto anterior para
 * resolver el problema
 *
 * void optimizarOrdenArchivos(size_t *tamaniosArchivos, size_t cantidadArchivos);
 */

//  1.a) La estrategia greedy que resuelve el problema podria ser: Ordenar los archivo
//  en funcion del tamaño de forma acendente (Creciente).
// 1.b)
#include <stdio.h>
#include <stdlib.h>

typedef struct _file {
	size_t sz;
	size_t num;
} file;

int cmp(const void *x, const void *y) {
	file *fst = (file *)x;
	file *snd = (file *)y;
	return fst->sz - snd->sz;
}

void optimizarOrdenArchivos(size_t *tamaniosArchivos, size_t cantidadArchivos) {
	file setFiles[cantidadArchivos];
	for (size_t i = 0; i < cantidadArchivos; i++) {
		setFiles[i].sz = tamaniosArchivos[i];
		setFiles[i].num = i;
	}

	qsort(setFiles, cantidadArchivos, sizeof(file), cmp);

	printf("La permutacion de archivos que disminuye la lectura son:\n");
	printf("\tArchivo nro\t\tTamaño\n");
	for (size_t i = 0; i < cantidadArchivos; i++) {
		printf("\t%d\t\t\t%d\n", setFiles[i].num, setFiles[i].sz);
	}
	puts("");
}

int main(int argc, char const *argv[]) {
	int n;
	printf("Ingrese la cantidad de archivos: ");
	scanf("%d%*c", &n);
	size_t setF[n];
	printf("Ingrese los tamaños:\n");
	for (size_t i = 0; i < n; i++) {
		scanf("%d%*c", &setF[i]);
	}

	optimizarOrdenArchivos(setF, n);

	return 0;
}

/* 
	2)
		Suponga que se tiene la siguiente tabla hash que contiene números enteros, implementada
		usando sondeo lineal como forma de resolver las colisiones (es decir, se admite sólo una clave
		por cubeta, y en caso de colisión se busca en las casillas siguietes un luguar disponible).
		La función hash usada es la siguiente función. Indique todas las opciones correctas.

		  0   1  2   3  4   5  6   7  8
		[ 9, 18,  , 12, 3, 14, 4, 21,  ]

		a) En qué orden pueden haber sido agregado los elementos a la tabla? Suponga que sólo se
			realizaron operaciones de inserción. Indique todas las opciones correctas.

			i.   9,14,4,18,12,3,21
			ii.  12,3,14,18,4,9,21
			iii. 12,14,3,9,4,18,21
			iv.  9,12,14,3,4,21,18
			v,   12,9,18,3,14,21,4

		b) Escriba en pseudocódigo el algoritmo para buscar un elemento en la tabla.
		c) Explique qué problema existe al remover al 3 de la tabla, y una forma de resolverlo 
			sin modificar el algoritmo del apartado anterior.
		d) Dibuje cómo quedaría la tabla luego de remover el 3, usando la solución descripta.

		a) 
		   iii.
			iv.
		b) 
			Function findElem( hs, key) 
			// Inputs: entra una estructura hashtable hs y la clave key a buscar
			// Output: devuelve la posicion idx de la clave key en el hashtable hs
			{
				Declaracion de la variable idx entero.
				Se inicializa la variable idx con lo que devuelve la función hash que tiene definida el hastable hs hs->h(key) con entrada key.
				Si hs->table[idx] no es igual a key
				{
					Mientras hs->table[idx] sea distitnto a key hacer
					{
						idx = idx + 1
						Fin del mientras
					}
				}
				Devuelve idx la función findElem.
				Fin de la función findElem.
			}
		c)	
			El problema que existe es que en la posicion donde se encuentra el valor 3 se perderia la propiedad
			del sondeo lineal como forma de resolver las colisiones, por lo que en la posicion 4 donde se encontraba
			el 3 tendira que estar el valor 4 y en la posicion 6 donde se encuentra el 4 pasaria a estar el valor 21.
			La forma de resolverlo es que luego de remover un valor se tendra que rehashear los valores desde la posicion
			siguiente que fue removido el valor (en este caso el 4 osea empesaria desde 5) hasta el ultimo valor luego de 
			la primera que no halla ningun valor (en este caso hasta el 7), este procedimiento se hace si tiene un valor siguiente.
		d)
			  0   1   2  3  4   5   6  7  8
			[ 9, 18,  , 12, 4, 14, 21,  ,  ]
 */
