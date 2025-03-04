#include "isort.h"

void isort(int arr[], int l)
{
	int i, j, tmp;
	for(i = 1; i < l; i++){
		tmp = arr[i];
		j = i - 1;
		while ((arr[j] > tmp) && (j >= 0)){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = tmp;
	}
}