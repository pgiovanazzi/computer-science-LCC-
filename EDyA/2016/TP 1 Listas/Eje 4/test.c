#include <stdio.h>
#include <stdlib.h>
#include "ArrFlex.h"

void printData(const int data, void *extra_data){
	printf("%i,", data);
}

void printArr(AF arr){
	printf("<");
	af_foreach(arr, printData, NULL);
	printf(">");
	puts("");
}

int main(){
	AF arr = malloc(sizeof(AF));
	af_len(arr) = -1;
	
	arr = af_append(arr,5);
	arr = af_append(arr,4);
	arr = af_append(arr,10);
	arr = af_append(arr,43);
	arr = af_append(arr,15);
	
	printf("arr: ");
	
	printArr(arr);
	
	printf("af_insert(arr,9,2): ");
	arr = af_insert(arr,9,2); printArr(arr);
	printf("af_insert(arr,99,6): ");
	arr = af_insert(arr,99,6); printArr(arr);
	
	af_destroy(arr);

	return 0;
}
