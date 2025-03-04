#include <stdio.h>
#include <stdlib.h>

/* 
	1 a)
	int findMax(BHeap *heap);
	1 - Leer el heap
	2 - Dividir la longitud del arreglo que reprecenta al heap (cantidad de elementos sz ) por la mitad m = sz/2
	3 - Recorrer el arreglo (el heap) desde la mitad (m) hacia el final (sz) buscando el maximo
	4 - Guardar el maximo si lo encuentra
	5 - Retornar el maximo

	b )

	int findMax(BHeap *heap)
	{
		int mid = heap->nelems/2, max = 0;
		
		for(int i = mid; i < heap->nelems; i++)
			if ( heap->data[max] < heap->data[i] )
				max = i;
		return max;
	}

	int bheap_erase_max(BHeap *heap)
	{
		int iMax = findMax(heap);
		int maxElem = heap->data[iMax];
		heap->data[iMax] = heap->data[--heap->nelems];
		int goUp = iMax, p = (goUp - 1) / 2;
		while ( goUp > -1 && heap->data[goUp] < heap->data[p])
		{
			tmp = heap->data[p];
			heap->data[p] = heap->data[goUp];
			heap->data[goUp] = tmp;
			goUp = p;
			p = (goUp - 1)/2;
		}
		return maxElem;
	}

	Otra forma es:
	void toBeHeap(BHeap *h, int up)
	{
		if(up && h->data[up] < h->data[(up-1)/2])
		{
			int tmp = h->data[up];
			h->data[up] = h->data[(up-1)/2];
			h->data[(up-1)/2] = tmp;
			toBeHeap(h, (up-1)/2);
		}
	}

	int bheap_erase_max(BHeap *heap)
	{
		int iMax = findMax(heap);
		int maxElem = heap->data[iMax];
		heap->data[iMax] = heap->data[--heap->nelems];
		toBeHeap(heap, iMax);
		return maxElem;
	}

	2 a)
	El arbol utilizado para heaps binarios a diferencia de el arbol binario completo ordenado
	es que cada elemento del nodo del arbol es menor que el sus hijos, mientras que el arbol
	binario completo ordenado el hijo izquiero es menor y el derecho es mayor.
	b )
		typedef struct _BSCT
		{
			int data[30];
			int nelems;
		} BSCT;

	c )
							9
					6				12
				4		8    10      13
			3		5

		arr[] = {9, 6, 12, 4, 8, 10, 13, 3, 5}

	d)
		int cmp(const void *x, const void *y)
		{
			return *(int *)x - *(int *)y;
		}

		bsct_foreach(BHeap *h, VisitorFuncInt visit, void *extra_deta)
		{
			int arr[h->nelems];
			for (int i = 0; i < h->nelems; i++)
				arr[i] = h->data[i];
			qsort(arr,h->nelems, sizeof(int), cmp);
			for (int i = 0; i < h->nelems; i++);
				visit(arr[i], extra-data);
		}

	e )
		
 */

typedef struct _BSCT
{
	int data[30];
	int nelems;
} BSCT;

int cmp(const void *x, const void *y)
{
	return *(int *)x - *(int *)y;
}

int main(int argc, char const *argv[])
{
	BSCT *tree = malloc(sizeof(BSCT));
	tree->data[0] = 9;
	tree->data[1] = 6;
	tree->data[2] = 12;
	tree->data[3] = 4;

	tree->nelems = 4;

	int *arr = tree->data;
	qsort(arr, tree->nelems, sizeof(int), cmp);

	for (int i = 0; i < tree->nelems; i++)
	{
		printf("%d, ", arr[i]);
	}

	free(tree);

	return 0;
}
