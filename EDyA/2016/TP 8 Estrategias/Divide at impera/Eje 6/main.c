#include <stdio.h>
#include <stdlib.h>

#define LEN(X) (sizeof(X) / sizeof(*X))

int *solve(int arr[], int sz)
{
	int *twoMax = malloc(sizeof(int) * 2);
	int mid = sz / 2;
	int *s1, *s2;

	if (sz == 1)
	{
		twoMax[0] = arr[0];
		twoMax[1] = arr[0];
		return twoMax;
	}

	s1 = solve(arr, mid);
	s2 = solve(arr + mid, sz - mid);

	if (s1[0] > s1[1])
		twoMax[0] = s1[0];
	else
		twoMax[0] = s1[1];
	if (s2[0] > s2[1])
		twoMax[1] = s2[0];
	else
		twoMax[1] = s2[1];

	return twoMax;
}

int main(int argc, char const *argv[])
{
	int arr[] = {3, 1, 30, 11, 20, 40, 5, 30};
	int *maximos = solve(arr, LEN(arr));

	printf("Los maximos son %d y %d\n", maximos[0], maximos[1]);

	free(maximos);

	return 0;
}
