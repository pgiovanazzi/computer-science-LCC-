#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int *direccion;
	size_t capacidad;
} ArregloEnteros;

ArregloEnteros *arreglo_enteros_crear(size_t capacidad)
{
	ArregloEnteros *newArray = malloc(sizeof(ArregloEnteros));
	newArray->direccion = malloc(sizeof(int) * capacidad);
	newArray->capacidad = 0;
	return newArray;
}

void arreglo_enteros_destruir(ArregloEnteros *arreglo)
{
	free(arreglo->direccion);
	free(arreglo);
}

int arreglo_enteros_leer(ArregloEnteros *arreglo, size_t pos)
{
	return arreglo->direccion[pos];
}

void arreglo_enteros_escribir(ArregloEnteros *arreglo, size_t pos, int dato)
{
	if (pos > arreglo->capacidad)
		return;
	arreglo->capacidad++;
	arreglo->direccion[pos] = dato;
}

size_t arreglo_enteros_capacidad(ArregloEnteros *arreglo)
{
	return arreglo->capacidad;
}

void arreglo_enteros_imprimir_en_pantalla(ArregloEnteros *arreglo)
{
	for (size_t i = 0; i < arreglo->capacidad; i++)
	{
		printf("%d, ", arreglo->direccion[i]);
	}
	puts("");
}

void arreglo_enteros_ajustar(ArregloEnteros *arreglo, size_t capacidad)
{
	if (capacidad < arreglo->capacidad)
		arreglo->direccion = realloc(arreglo->direccion, sizeof(int) * arreglo->capacidad);
	else
		arreglo->direccion = realloc(arreglo->direccion, sizeof(int) * capacidad);
}

void arreglo_enteros_insertar(ArregloEnteros *arreglo, size_t pos, int dato)
{
	size_t i = 0;
	for (; i < arreglo->capacidad && i != pos; i++)
		;
	arreglo->capacidad++;
	int lenBuffer = arreglo->capacidad - i, buffer[lenBuffer];
	buffer[0] = dato;
	for (size_t j = 1; j < lenBuffer; j++)
		buffer[j] = arreglo->direccion[i + j - 1];
	for (size_t j = i, h = 0; h < lenBuffer; j++, h++)
		arreglo->direccion[j] = buffer[h];
}

void arreglo_enteros_eliminar(ArregloEnteros *arreglo, size_t pos)
{
	size_t i = 0;
	for (; i < arreglo->capacidad && i != pos; i++)
		;
	arreglo->capacidad--;
	int lenBuffer = arreglo->capacidad - i, buffer[lenBuffer];
	for (size_t j = 0; j < lenBuffer; j++)
		buffer[j] = arreglo->direccion[i + j + 1];
	for (size_t j = i , h = 0; h < lenBuffer; j++, h++)
		arreglo->direccion[j] = buffer[h];
}

int main(int argc, char *argv[])
{
	ArregloEnteros *newArray = arreglo_enteros_crear(5);
	arreglo_enteros_escribir(newArray, 0, 5);
	arreglo_enteros_escribir(newArray, 1, 6);
	arreglo_enteros_escribir(newArray, 2, 2);
	arreglo_enteros_escribir(newArray, 3, 3);
	arreglo_enteros_escribir(newArray, 4, 1);
	printf("Capacidad: %lu\n", arreglo_enteros_capacidad(newArray));
	arreglo_enteros_imprimir_en_pantalla(newArray);
	printf("array[3]: %d\n", arreglo_enteros_leer(newArray, 3));
	printf("array[4]: %d\n", arreglo_enteros_leer(newArray, 4));
	printf("array[0]: %d\n", arreglo_enteros_leer(newArray, 0));


	arreglo_enteros_ajustar(newArray,10);
	arreglo_enteros_insertar(newArray, 1, 4);
	arreglo_enteros_insertar(newArray, 3, 10);
	arreglo_enteros_insertar(newArray, 3, 13);
	arreglo_enteros_insertar(newArray, 9, 9);
	printf("Capacidad: %lu\n", arreglo_enteros_capacidad(newArray));
	arreglo_enteros_imprimir_en_pantalla(newArray);

	arreglo_enteros_eliminar(newArray, 4);
	printf("Capacidad: %lu\n", arreglo_enteros_capacidad(newArray));
	arreglo_enteros_imprimir_en_pantalla(newArray);
	arreglo_enteros_eliminar(newArray, 0);
	printf("Capacidad: %lu\n", arreglo_enteros_capacidad(newArray));
	arreglo_enteros_imprimir_en_pantalla(newArray);
	arreglo_enteros_eliminar(newArray, 4);
	printf("Capacidad: %lu\n", arreglo_enteros_capacidad(newArray));
	arreglo_enteros_imprimir_en_pantalla(newArray);

	arreglo_enteros_destruir(newArray);
	return 0;
}