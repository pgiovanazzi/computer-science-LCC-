#include <stdio.h>
#include <stdlib.h>

void buble_sort(float arreglo[], size_t longitud)
{
	for (size_t iter = 0; iter < longitud - 1; iter++)
	{
		for (size_t i = 0; i < longitud - iter - 1; i++)
		{
			if (arreglo[i] > arreglo[i + 1])
			{
				float aux = arreglo[i];
				arreglo[i] = arreglo[i + 1];
				arreglo[i + 1] = aux;
			}
		}
	}
}

float *copy_array(float *array, size_t len)
{
	float *newArray = malloc(sizeof(float) * len);
	for (size_t i = 0; i < len; i++)
	{
		newArray[i] = array[i];
	}
	return newArray;
}

float mediana(float *arreglo, size_t longitud)
{
	int m1, m2;
	float result;
	float *buffer = copy_array(arreglo, longitud);

	buble_sort(buffer, longitud);

	if (longitud % 2)
	{
		m1 = longitud / 2;
		return buffer[m1];
	}
	m1 = longitud / 2;
	m2 = longitud / 2 - 1;
	result = (buffer[m1] + buffer[m2]) / 2;
	
	free(buffer);
	
	return result;
}

int main(int argc, char *argv[])
{
	float arr1[] = {3, 4, 6, 1, 2, 8};
	float arr2[] = {3, 4, 7, 5, 10};

	printf("La mediana de arr1 = %.2f y arr2 = %.2f\n", mediana(arr1, 6), mediana(arr2, 5));

	return 0;
}