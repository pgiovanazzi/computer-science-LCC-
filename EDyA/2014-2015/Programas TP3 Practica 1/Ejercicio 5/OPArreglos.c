#include <stlib.h>
#include "OPArreglos.h"


void arr_append(vetcor_t *vetcor, int *data){
	if (vetcor->data == NULL)
		vetcor_data(vetcor, 0) = data;
	else{
		vetcor_data(vetcor, vetcor_len(vetcor)) = data;
		vetcor_len(vetcor)++; 
	}
}