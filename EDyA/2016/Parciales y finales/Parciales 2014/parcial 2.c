#include <stdio.h>

// Ejercicio 2
// a)  Algoritmo de ordenamiento por seleccion.
// b) El mejor caso es de orden O(n^2)
//    El peor caso es de orden O(n^2)
// c) El algoritmo trabaja de manera in-situ (por el swap);
// d)
void rsort(int data[], int sz, int i)
{
	if (i < sz)
	{
		int z = i;
		for (int j = i + 1; j < sz; j++)
		{
			if (data[j] < data[z])
				z = j;
		}
		int t = data[i];
		data[i] = data[z];
		data[z] = t;
		rsort(data, sz, i + 1);
	}
}

// e) E: Crsort(n) = Crsort( n - 1 ) + n + 5
//    E: Crsort(n) = Crsort( n - 2 ) + (n - 1) + 5 + (n) + 5
//      ... 0 + 1 + 2 + 3 + ... + n  + 5*n
//    E: Crsort(n) = n*(n+1)/2 + 5*n

// Ejercicio 3 a)
int sum(int data[], int i, int l)
{
	int s1, s2;

	if (l == i)
		return data[i];

	s1 = sum(data, i, (l + i) / 2);
	s2 = sum(data, (l + i) / 2 + 1, l);

	return s1 + s2;
}
// b)
/*
  Mejor caso para cuando n = 0 o n = 1 tiene el algoritmo una complejidad de O(1).
  Para el peor caso cuando n > 1 tiene el algoritmo una complejidad de O(n).
  E: Csum(n) = 2Csum(n/2) + k, k constante.
  f(n) = k => Cf pertenece a O(1) => c = 0.
  a = 2, b = 2, log base b de a es 1 > c = 0, por lo tanto por el teorema maestro caso 1
  Csum pertenece a O(n a la log en base 2 de 2) = O(n a la 1) = O(n).
*/

// c)
/*
  La diferencia principal entre la programacion dinamica y divde et impera es que
  la programacion divide and conquer resuelve los problemas mediante la solucion
  de subproblemas por separado, en este caso s1 y s2 son subproblemas y luego combinarlos
  para la resolucion del problema principal, en este caso s1 + s2.
  A diferencia de la programacion dinamica es que se puede solapar los subproblemas y memorizarlos 
  (esto es acumulado en una variable para optener la suma total de los elemetos del arreglo)
  para solucionar otros subproblemas para luego combinarlos para solucionar el problema principal.
*/

int main(int argc, char const *argv[])
{
	int arr2[] = {4, 2, 1, 3, 6, 8};

	rsort(arr2, 6, 0);
	for (int i = 0; i < 6; i++)
	{
		printf("%d, ", arr2[i]);
	}
	puts("");

	printf("La suma de los numeros del arreglo es: %d\n", sum(arr2, 0, 5));
	return 0;
}
