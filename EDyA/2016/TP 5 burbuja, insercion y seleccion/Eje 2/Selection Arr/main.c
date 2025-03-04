#include <stdio.h>
#include "ssort.h"

#define NELEMS(a)   (sizeof(a) / sizeof(int))

void printArr(int arr[], int sz){
  printf("< ");
  for (size_t i = 0; i < sz; i++) {
    printf("%d, ", arr[i]);
  }
  printf(" >\n");
}

int main(int argc, char const *argv[]) {
  int arr[] = { 1,3,4,65,7,9,0,24,42,7 };

  printArr(arr,NELEMS(arr));

  ssort(arr,NELEMS(arr));

  printf("ssort(arr,sz): ");
  printArr(arr,NELEMS(arr));

  return 0;
}
