#include <stdio.h>
#include <stdlib.h>
#include "hsort.h"

#define len(a)    (sizeof(a)/sizeof(*a))

void printArr(int data[], int l){
  printf("< ");
  for (int i = 0; i < l; i++) {
    printf("%d, ", data[i]);
  }
  puts(">");
}

int main(int argc, char const *argv[]) {
  int arr[] = { 2, 4, 6, 1, 2, 7, 8, 3 };
  int *ptr_arr_sorted = malloc(sizeof(int)*len(arr));

  printf("Arr: ");
  printArr(arr,len(arr));

  ptr_arr_sorted = hsort(arr, len(arr));

  printf("hsort(Arr): ");
  printArr(ptr_arr_sorted,len(arr));

  free(ptr_arr_sorted);

  return 0;
}
