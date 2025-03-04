#include <stdio.h>
#include <stdlib.h>

#define len(a) (sizeof(a) / sizeof(*a))

// 1 a)
typedef struct _SONode
{
	int d;
	struct _SONode *next;
} SONode;

typedef SONode *SOList;

// b)
SOList solist_add(int n, SOList l)
{
	SOList newNode = malloc(sizeof(SONode));
	newNode->d = n;
	newNode->next = NULL;

	if (!l)
		return newNode;

	SOList node, nodePrev;
	node = l;
	while (node && node->d < newNode->d)
	{
		nodePrev = node;
		node = node->next;
	}
	if (node == l)
	{
		newNode->next = l;
		return newNode;
	}
	else if (!node)
	{
		nodePrev->next = newNode;
		return l;
	}
	else
	{
		newNode->next = node;
		nodePrev->next = newNode;
		return l;
	}
}

// c)
void solist_destroy(SOList l)
{
	while (l)
	{
		SOList node = l;
		l = l->next;
		free(node);
	}
}

// d)
void solist_print(SOList l)
{
	SOList node = l;
	while (node)
	{
		printf("%d, ", node->d);
		node = node->next;
	}
	puts("");
}

// e)
void print_ordered(int arr[], int sz)
{
	SOList l = NULL;
	for (size_t i = 0; i < sz; i++)
	{
		l = solist_add(arr[i], l);
	}
	solist_print(l);
	solist_destroy(l);
}

// 2)

typedef struct _foos
{
	int x, y;
} foos;

void foof(foos s)
{
	s.x = 42;
}

void arrf(int a[])
{
	a[0] = 42;
}

void f(void)
{
	foos s = {1, 2};
	int a[] = {1, 2};
	foof(s);
	arrf(a);
	printf("%d %d\n", s.x, a[0]);
}

int main(int argc, char const *argv[])
{
	int arr[] = {2, 3, 1, -1, 8, 5};
	printf("******* Ejercicio 1: ******\n");
	printf("Arr: ");
	for (size_t i = 0; i < len(arr); i++)
	{
		printf("%d, ", arr[i]);
	}
	printf("\n");
	print_ordered(arr, len(arr));

	printf("******* Ejercicio 2: ******\n");

	f();
	// imprime 1 42, 1 porque la estructura s pasa por valor a la funcion foof
	// por lo tanto hace una copia de la estructura y solo se modifica en la copia
	// dentro de la funcion por lo tanto fuera de la funcion la estructura s sigue igual.
	// 42 pasa por referencia por la funcion arrf por lo tanto no hace una copia de la variable -a- sino
	// que esta modificando desde la dirreccion de memoria donde se almacena por lo tanto se modifica.

	return 0;
}
