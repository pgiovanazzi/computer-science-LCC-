#include <stdio.h>

#define childLeft(X)    (2*(X) + 1)
#define childRigth(X)   (2*(X) + 2)
#define SWAP(A,B)       {int t = A; A = B; B = t;}
#define LEN(A)          (sizeof(A)/sizeof(*A))

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


int main(int argc, char const *argv[]) {
  //El arreglo tiene que ser un max-heap, por ejemplo
  int arr[] = {10, 8, 5, 4, 3, 1, 4, 2,};

  printf("Arr: ");
  for (int i = 0; i < LEN(arr); i++)
    printf("%d, ", arr[i]);

  swapsift( arr, LEN(arr));

  printf("\nswapsift(Arr): ");
  for (int i = 0; i < LEN(arr); i++)
    printf("%d, ", arr[i]);
  puts("");
  
  return 0;
}
