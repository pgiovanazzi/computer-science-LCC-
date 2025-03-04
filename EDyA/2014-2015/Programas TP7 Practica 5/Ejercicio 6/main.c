#include "APermutable.h"
#include <stdio.h>
#include <stdlib.h>

#define LEN(a)		sizeof((a))/sizeof(int)

int main(int argc, char const *argv[])
{
	int a1[] = {1,4,5,5,6}, a2[] ={6,1,5,5};
	
	printf("%d\n", are_permutable(a1, a2, LEN(a1)));

	return 0;
}