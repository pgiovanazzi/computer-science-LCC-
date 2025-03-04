#include <stdio.h>
#include <stdlib.h>

#define len(a)    (sizeof(a)/sizeof(*a))

// Busca el mayor de un arreglo en forma recursiva.
int max_r(int arr[], int sz, int *m){
  if (sz == 1)
    return arr[*m];
  if (arr[sz] > arr[*m])
    *m = sz;

  return max_r(arr, sz-1, m);
}

// Busca los dos mayores de un arreglo en forma recursiva.(no divide and conquer)
void max_rv2(int arr[], int sz, int max[], int idx){
  if ( idx < sz ) {
    if ( idx < 2 ) {
      max[0] = arr[0];
      max[1] = arr[1];
      max_rv2(arr, sz, max, idx + 2);
    }
    else
      if ( arr[idx] > max[0] && arr[idx] > max[1] )
        if ( max[0] > max[1] ) {
          max[1] = arr[idx];
          max_rv2( arr, sz, max, idx + 1 );
        }
        else {
          max[0] = arr[idx];
          max_rv2( arr, sz, max, idx + 1 );
        }
      else
        if ( arr[idx] > max[0] ) {
          max[0] = arr[idx];
          max_rv2( arr, sz, max, idx + 1 );
        }
        else
          if ( arr[idx] > max[1] ) {
            max[1] = arr[idx];
            max_rv2( arr, sz, max, idx + 1 );
          }
          else
            max_rv2( arr, sz, max, idx + 1 );
  }
}

// Busca el mayor de un arreglo en forma iterativa.
int max_i(int arr[], int sz){
  int max_tmp = 0;
  for (int i = 1; i < sz; i++) {
    if (arr[i] > arr[max_tmp]) {
      max_tmp = i;
    }
  }
  return arr[max_tmp];
}

int main(int argc, char const *argv[]) {
  int arr[] = { 1, 4, 6, 3, 2, 10, 7, 11 };
  int *max = malloc(sizeof(int)*2);

  max_rv2( arr, len(arr), max, 0 );

  printf("Los mayores son: %d y %d\n", max[0], max[1] );

  return 0;
}
