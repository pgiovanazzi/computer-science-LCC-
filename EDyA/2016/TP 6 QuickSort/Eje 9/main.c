#include <stdio.h>

#define dad(X)          (((X)-1)/2)
#define childLeft(X)    (2*(X) + 1)
#define childRigth(X)   (2*(X) + 2)
#define SWAP(a,b)       {int t = a; a = b; b = t;}
#define LEN(a)          (sizeof(a)/sizeof(*a))

void upper(int *arr, int idx){
  int posDad = dad(idx);
  //caso base.
  if( posDad == idx ) return;
  //caso general.
  if( arr[posDad] < arr[idx] ){
    SWAP(arr[posDad], arr[idx]);
    upper(arr, posDad);
  }
  return;
}

void heapify(int *arr, int sz){

  for (int i = 0; i < sz; i++) {
    upper(arr, i);
  }
}

void deeper(int *arr, int sz, int daddy){
  //Inicializa los hijos
  int childL = childLeft(daddy);
  int childR = childRigth(daddy);
  int num_child = 0;
  //Cuenta los hijos
  if( childL <= sz-1 )
    num_child++;
  if( childR <= sz-1 )
    num_child++;

  //Caso base, no tiene hijos
  if ( num_child == 0 ) return;

  //Caso general, hijo = 1
  if ( num_child == 1 ) {
    if( arr[daddy] < arr[childL] ) {
      SWAP( arr[daddy], arr[childL]);
      deeper( arr, sz, childL);
    }
  }
  //Caso general, hijo = 2
  if ( num_child == 2 ) {
    if ( arr[childL] < arr[childR] ) {
      if ( arr[daddy] < arr[childR] ) {
        SWAP( arr[daddy], arr[childR] );
        deeper( arr, sz, childR);
      }
    }
    else {
      if ( arr[daddy] < arr[childL] ) {
        SWAP( arr[daddy], arr[childL] );
        deeper( arr, sz, childL);
      }
    }
  }

  return;
}

void swapsift(int *arr, int sz){
  //Intercambia el primer elemento con el ultimo.
  SWAP( arr[sz - 1], arr[0]);
  //Se restaura la propiedad de heap sin el ultimo elemento.
  deeper( arr, sz-1, 0);
  return;
}

void hsort(int *arr, int sz){
  //tranformaos el arreglo en un max-heap.
  heapify(arr, sz);

  //Quitamos los elementos del heap uno a uno.
  for (int i = 0; i < sz; i++) {
    swapsift(arr, sz-i); //pasamos el tamaño actualizado.
  }
}

int main(int argc, char const *argv[]) {
  int arr[] = {4, 5, 1, 2, 3, 8, 4, 10};

  printf("Arr: < ");
  for (int i = 0; i < LEN(arr); i++) {
    printf("%d, ", arr[i]);
  }
  puts(">");

  hsort(arr, LEN(arr));

  printf("hsort(Arr): < ");
  for (int i = 0; i < LEN(arr); i++) {
    printf("%d, ", arr[i]);
  }
  puts(">");

  return 0;
}
