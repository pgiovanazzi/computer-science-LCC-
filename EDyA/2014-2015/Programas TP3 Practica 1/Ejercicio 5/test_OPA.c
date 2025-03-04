#include <stdlib.h>
#include <stdio.h>
#include "OPArrgelos.h"

int main(void){
	int i;
	vector_t v1;
	vector_len(v1) = 5;

	v1->data = malloc(sizeof(vector_t)*vector_len(v1))
	for (i = 0; i < ;)
		vector_data(v1, i) = i*2;



	free(v1);
	return 0;
}