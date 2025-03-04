#include <stdio.h>
// 1
// g
#define SQUARE_VOL(X)	(X*X*X)

// 2
#define PI (3.14159)
#define VOL_ESFERA(R3) ((4 / 3) * PI * R3)

// 3
#define SUM(X, Y) (X + Y)

// 4
#define MINNUM2(A, B) ((A < B) ? A : B)

// 5
#define MINNUM3(A, B, C) ((C < MINNUM2(A, B)) ? C : MINNUM2(A, B))

// 6
#define PRINT(STR)         \
	{                       \
		printf("%s\n", STR); \
	}

// 7
#define PRINTARR(ARR, LEN)          \
	{                                \
		for (int i = 0; i < LEN; i++) \
			printf("%d ", ARR[i]);     \
	}

// 8
#define SUMARRAY(ARR, LEN)             \
	{                                   \
		int sum = 0;                     \
		for (int i = 0; i < LEN; i++)    \
			sum += ARR[i];                \
		printf("La suma es: %d\n", sum); \
	}

int main(int argc, char *argv[])
{
	int arr[] = {1, 2, 3, 4, 5};
	PRINTARR(arr, 5);
	puts("");
	SUMARRAY(arr, 5);

	return 0;
}