#include "qsort_.h"
#include <time.h>

void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int particionar(int data[], int init, int last, PIVOT sp)
{
	int pividx, i = init - 1, j = init, 
	pv1 = init, pv2 = (int)(init + (last - init)/2), pv3 = last;
	switch (sp){
		case 1:
			srand(time(NULL));
			pividx = init + rand()%(init - last);
			break;
		case 2:
			pividx = last;
			break;
		case 3:
			pividx = (int)(init + (last - init)/2);
			break;
		case 4:
			if (data[pv1] > data[pv2])
				if (data[pv1] > data[pv2])
					if (data[pv2] > data[pv3])
						pividx = pv2;
					else
						pividx = pv3;
				else
					pividx = pv1;
			else
				if (data[pv1] > data[pv3])
					pividx = pv1;
				else
					if (data[pv2] > data[pv3])
						pividx = pv3;
					else
						pividx = pv2;
			break;
		default:
			puts("Seleccion de pivote incorrecto.");
			break;
	}

	swap(&data[pividx], &data[last]);
	pividx = last;
	
	for(j; j <= last-1; j++){
		if(data[j] <= data[pividx]){
			i++;
			swap(&data[i], &data[j]);
		}
	}
	
	swap(&data[i+1], &data[pividx]);
	return i+1;
}


void qsort_(int data[], int init, int last, PIVOT sp)
{
	int pivot;

	if (init < last) {
		pivot = particionar(data, init, last, sp);
		qsort_(data, init, pivot-1, sp);
		qsort_(data, pivot + 1, last, sp);
	}
}