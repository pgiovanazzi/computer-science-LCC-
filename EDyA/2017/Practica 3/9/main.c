#include <stdio.h>
#define LEN(X) (sizeof(X) / sizeof(*X))
#define PADRE(X) ((X - 1) / 2)
#define HIJO_IZQ(X) (X * 2 + 1)
#define HIJO_DER(X) (X * 2 + 2)

void intercambiar(int *x, int *y) {
  int t = *x;
  *x = *y;
  *y = t;
}

// Se utilzia para hsort en la funcion swapsift
void unde_nodo(int arr[], size_t tamanio, int nodo) {
  int hijoIzq = HIJO_IZQ(nodo);
  int hijoDer = HIJO_DER(nodo);
  int cantidadHijos = 0;
  if (hijoIzq < tamanio) {
    cantidadHijos++;
  }
  if (hijoDer < tamanio) {
    cantidadHijos++;
  }

  if (!cantidadHijos) {
    return;
  }

  if (cantidadHijos == 1) {
    if (arr[nodo] > arr[hijoIzq]) {
      intercambiar(&arr[nodo], &arr[hijoIzq]);
      unde_nodo(arr, tamanio, hijoIzq);
    }
  } else {
    if (arr[hijoDer] < arr[hijoIzq]) {
      if (arr[hijoIzq] < arr[nodo]) {
        intercambiar(&arr[nodo], &arr[hijoIzq]);
        unde_nodo(arr, tamanio, hijoIzq);
      }
    } else {
      if (arr[hijoDer] < arr[nodo]) {
        intercambiar(&arr[hijoDer], &arr[nodo]);
        unde_nodo(arr, tamanio, hijoDer);
      }
    }
  }
  return;
}

void subir_nodo(int arr[], size_t nodo) {
  int padre = PADRE(nodo);
  if (padre < 0) {
    return;
  }
  if (arr[nodo] < arr[padre]) {
    intercambiar(&arr[nodo], &arr[padre]);
  }
  subir_nodo(arr, nodo - 1);
}

void heapify(int arr[], size_t tamanio) { subir_nodo(arr, tamanio - 1); }

void imprimir_arreglo(int arr[], size_t tamanio) {
  for (size_t i = 0; i < tamanio; i++) {
    printf("%d ", arr[i]);
  }
  puts("");
}

int main(int argc, char *argv[]) {
  int arr[] = {1, 2, 3, 5, 8, 4, 9, 0, 7, 6};
  imprimir_arreglo(arr, LEN(arr));
  heapify(arr, LEN(arr));
  imprimir_arreglo(arr, LEN(arr));

  return 0;
}
