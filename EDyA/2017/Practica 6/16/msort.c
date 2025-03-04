#include "msort.h"
#include <stdlib.h>

static void intercalar(int a1[], int a2[], int a3[], int n1, int n2, int n3) {
  for (unsigned i = 0, j = 0, k = 0; k < n3; k++) {
    if (i < n1 && j < n2 && a1[i] < a2[j])
      a3[k] = a1[i++];
    else if (i < n1 && j < n2 && a1[i] >= a2[j])
      a3[k] = a2[j++];
    else if (!(i < n1) && j < n2)
      a3[k] = a2[j++];
    else if (i < n1 && !(j < n2))
      a3[k] = a1[i++];
    else
      break;
  }
}

int* msort_(int arr[], unsigned tam) {
  int* r = malloc(sizeof(int) * tam);
  if (tam == 1) {
    r[0] = arr[0];
    return r;
  }
  int mid = tam / 2;

  int* a = msort_(arr, mid);
  int* b = msort_(arr + mid, tam - mid);

  intercalar(a, b, r, mid, tam - mid, tam);

  free(a);
  free(b);

  return r;
}

/****    Otra forma sin usar arreglos temporarios.    ***/

static void fucionar(int arr[], int i, int m, int d) {
  int p, j, k;
  int n1 = m - i + 1;
  int n2 = d - m;
  int izq[n1];
  int der[n2];

  // Copia los datos del arreglo en los arreglos izq y der.
  for (p = 0; p < n1; p++)
    izq[p] = arr[i + p];
  for (j = 0; j < n2; j++)
    der[j] = arr[m + 1 + j];

  // Fuciona los arreglos temporales denuevo dentro del arr[i..d]. i: indice
  // izquierdo, d:indicie derecho.
  p = 0;
  j = 0;
  k = i;

  while (p < n1 && j < n2) {
    if (izq[p] <= der[j])
      arr[k] = izq[p++];
    else
      arr[k] = der[j++];
    k++;
  }

  // Copia los datos restantes de arreglo izq al arr.
  while (p < n1)
    arr[k++] = izq[p++];
  // Copia los datos restantes de arreglo der al arr.
  while (j < n2)
    arr[k++] = der[j++];
}

void marge_sort(int arr[], int i, int d) {
  if (i < d) {
    int m = i + (d - i) / 2;
    marge_sort(arr, i, m);
    marge_sort(arr, m + 1, d);
    fucionar(arr, i, m, d);
  }
}