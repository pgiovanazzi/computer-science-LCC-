#ifndef __QSORT__H__
#define __QSORT__H__

typedef enum { Pivote_eleatorio  = 1, 
	Pivote_ultimo_elemento, 
	Pivote_elemento_medio, 
	Pivote_mediana } PIVOT;

void qsort_(int [], int, int, PIVOT);

#endif /*__QSORT__H__*/