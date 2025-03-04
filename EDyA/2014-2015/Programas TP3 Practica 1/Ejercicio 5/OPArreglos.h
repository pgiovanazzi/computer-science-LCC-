#ifndef __OPArreglos_H__
#define __OPArreglos_H__

typedef struct vetcor{
	unsigned int len;
	int	**data;
} vetcor_t;


#define vector_data(v,i)    (v)->dato[(i)]
#define vector_len(v)	  	(v)->leng

//Agrega un elemento al final de la lista.
void arr_append(vetcor_t * vetcor, int *data);

//Agrega un elemento al inicio de la lista.
void arr_prepend(vetcor_t * vetcor, int *data);

#endif