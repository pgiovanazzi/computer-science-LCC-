#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DELIMITERS ", \n"

int main(int argc, char const *argv[])
{
	char *line = NULL;
	char *comm = NULL;
	size_t len = 0;
	char **strings = malloc(sizeof(char *) * 3);

	printf("Texto1:\n");
	getline(&line, &len, stdin);
	printf("Texto2:\n");
	getline(&line, &len, stdin);
	strings[0] = strtok(line, DELIMITERS);
	strings[1] = strtok(NULL, DELIMITERS);
	strings[2] = strtok(NULL, DELIMITERS);

	printf("%s\n", strings[0]);
	printf("%s\n", strings[1]);
	printf("%s\n", strings[2]);
	return 0;
}
