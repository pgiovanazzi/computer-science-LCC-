#include <stdio.h>
#include <stdlib.h>

#define padre(X) ((X)-1)/2

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}


/*
 * Operacion auxiliar para insertar en un heap.
 * Restaura el invariante acomodando el  
 * elemento en posicion "pos" adonde corresponda.
 */
void flotar(int *arr, int pos) {

  int padrePos = padre(pos);	

  // Caso base
  if (padrePos == pos) {
    return;
  }

  // Caso general
  if (arr[pos] > arr[padrePos]) {
    swap(&(arr[pos]), &(arr[padrePos]));
    flotar(arr, padrePos);
  }

  return;
}


/*
 * Dado un arreglo de enteros, y su tamaño, 
 * crea un max-heap in situ.
 *
 * Ejercicio 7
 */
void heapify(int *arr, int size) {
	
  // Restauramos el invariante
  int i = 1;
  for ( ; i < size; i++) {
    // Restauramos la propiedad de heap
    flotar(arr, i);
  }
}


/*
 * Operacion auxiliar para eliminar un elemento en un heap.
 * Restaura el invariante acomodando el  
 * elemento en posicion "pos" adonde corresponda.
 */
void hundir(int *arr, int size, int pos) {

  int posHijoIzq = pos * 2 + 1;
  int posHijoDer = pos * 2 + 2;
  int numberOfChildren = 0;

  if (posHijoIzq <= size - 1)
    numberOfChildren++;
  if (posHijoDer <= size - 1)
    numberOfChildren++;

  // No tiene hijos
  if (numberOfChildren == 0)
    return;

  // Solo hijo izq
  if (numberOfChildren == 1) {
    if (arr[pos] < arr[posHijoIzq]) {
      swap(arr + pos, arr + posHijoIzq);
      hundir(arr, size, posHijoIzq);
    }
  }

  // 2 hijos
  if (numberOfChildren == 2) {
    // Si hijoIzq >= hijoDer
    if (arr[posHijoIzq] >= arr[posHijoDer]) {
      if (arr[pos] < arr[posHijoIzq]) {
	swap(arr + pos, arr + posHijoIzq);
	hundir(arr, size, posHijoIzq);
      }		
    } else {
      // hijoDer > hijoIzq
      if (arr[pos] < arr[posHijoDer]) {
	swap(arr + pos, arr + posHijoDer);
	hundir(arr, size, posHijoDer);
      }
    }
  }
}


/*
 * Dado un maxheap, posiciona el maximo en la ultima posicion
 * y restaura la propiedad de heap en las restantes posiciones.
 * 
 * Ejercicio 8
 */
void swapsift(int *arr, int size) {
  // Intercambiamos los primero y ultimo valores
  swap(arr, arr + size - 1);

  // Ajustamos el tamanio
  size--;

  // Restauramos la propiedad de heap
  hundir(arr, size, 0);

  return;
}


/*
 * Implementa heap sort.
 * Ordena un arreglo de int usando un heap.
 * Ejercicio 9
 */
void hsort(int *arr, int size) {
  // Convertimos el arreglo en un max heap
  heapify(arr, size);

  // Uno a uno vamos sacando elementos del heap
  int i = 0;
  for ( ; i < size; i++) {
    swapsift(arr, size - i); // Notar que pasamos el tamanio 'actualizado'
  }
  return;
}


// Probamos los 3 ejercicios
int main() {
  // Arreglo para probar los algoritmos
  int arr[] = {4, 5, 1, 2, 3, 8, 4, 10};
  int size1 = sizeof(arr) / sizeof(int);
  int arr2[] = {4, 5, 1, 2, 3, 8, 4, 10};
  int size2 = sizeof(arr2) / sizeof(int);
  int i;

  // Imprimimos el arreglo
  for (i = 0; i < size1; i++) {
    printf("%d, ", arr[i]);
  }
  printf("\n");
	
	
  // Probamos Ej 7
  heapify(arr, size1);

  // Imprimimos el arreglo
  for (i = 0; i < size1; i++) {
    printf("%d, ", arr[i]);
  }
  printf("\n");

  // Probamos Ej 8
  swapsift(arr, size1);

  // Imprimimos el arreglo
  for (i = 0; i < size1; i++) {
    printf("%d, ", arr[i]);
  }
  printf("\n");

  // Probamos Ej 9
  hsort(arr2, size2);

  // Imprimimos el arreglo
  for (i = 0; i < size2; i++) {
  printf("%d, ", arr2[i]);
  }
  printf("\n");

  return 0;
}