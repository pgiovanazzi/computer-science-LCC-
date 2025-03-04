#include <stdio.h>
#include "bsortg.h"

#define NELEMS(a) (sizeof((a))/sizeof(int))

int compare(Carta a, Carta b){
	return a.num-b.num;
}


int main(void) {
	int arr[] = { 2, 4, 1, 3, 7, 8, 6 };
	int i;

	bsortg((void *)arr, NELEMS(arr), compare);

	for (i  = 0; i < NELEMS(arr); i++)
		printf("%d ", arr[i]);
	puts("");

  return 0;
}
