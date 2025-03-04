
#include "qsort.h"
#include <time.h>
#include <stdlib.h>

static void intercambiar(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

static int particionar(int arr[], int inicial, int final, EleccionPivote ep) {
  int izq = inicial;
  int der = final;
	int inicialFinalAleatorio;
  int pivote;

	switch(ep) {
		case PIVOTE_ALEATORIO:
			srand(time(NULL));
			inicialFinalAleatorio = (rand() % (final - inicial)) + inicial;
			pivote = arr[inicialFinalAleatorio];
			break;
		case PIVOTE_CENTRAL:
			pivote = arr[(inicial + final) / 2];
			break;
		case PIVOTE_FINAL:
			pivote = arr[final];
			break;
		case PIVOTE_MEDIANA:
			pivote = arr[(inicial + (inicial + final)/2 + final)/3];
			break;
		default:
			pivote = arr[inicial];
	}

  while (izq < der) {
		
    while (arr[izq] < pivote)
      izq++;
    while (arr[der] > pivote)
      der--;

    intercambiar(&arr[izq], &arr[der]);
  }
  return der;
}

void qsort_(int arr[], int init, int last, EleccionPivote ep) {
  if (init < last) {
    int pivote = particionar(arr, init, last, ep);
    qsort_(arr, init, pivote - 1, ep);
    qsort_(arr, pivote + 1, last, ep);
  }
}