#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

#define DELIMITERS ", \n"
#define QUIT "quit"

int equals(void *key1, void *key2)
{
	int *p = key1;
	int *q = key2;

	return *p == *q;
}

unsigned int stringtonat(char c[])
{
	int i = 0, nat = 0;
	for (; c[i]; i++)
		nat += c[i] * 128 ^ (i);

	return nat;
}

unsigned int hashnat(unsigned int nat, unsigned int size)
{
	return nat % size;
}

unsigned int hashstring(char key[], unsigned int size)
{
	return hashnat(stringtonat(key), size);
}

unsigned int hash(void *key, unsigned int size)
{
	int *p = key;
	return *p % size;
}

int main(int argc, char const *argv[])
{
	int hash_sotre = 10;
	Hashtable *ht = hashtable_new(hash_sotre, hash, equals);
	unsigned int hs;
	size_t lenLine = 0;

	while (1)
	{
		char **args = malloc(sizeof(char *) * 3);
		char *line = NULL;
		char *comm = NULL;
		char name[80] = "";
		int option = -1;

		printf("Ingrese Comando:\n");
		getline(&line, &lenLine, stdin);

		comm = strtok(line, DELIMITERS);

		if (!strcmp(comm, QUIT))
		{
			hashtable_destroy(ht);
			free(line);
			break;
		}

		args[0] = strtok(NULL, DELIMITERS);
		args[1] = strtok(NULL, DELIMITERS);
		strcat(name, args[0]);
		strcat(name, " ");
		strcat(name, args[1]);

		hs = hashstring(name, hash_sotre);

		if (!strcmp(comm, "insert"))
			option = 1;
		else if (!strcmp(comm, "delete"))
			option = 2;
		else if (!strcmp(comm, "search"))
			option = 3;

		switch (option)
		{
		case 1:
			args[2] = strtok(NULL, DELIMITERS);
			hashtable_insert(ht, &hs, args[2]);
			printf("...Agrego a %s\n\n", name);
			break;
		case 2:
			hashtable_delete(ht, &hs);
			printf("...Ha borrado a %s\n\n", name);
			break;
		case 3:
			if (hashtable_lookup(ht, &hs))
				printf("Tel: %s\n", ((char *)hashtable_lookup(ht, &hs)));
			else
				printf("El Nombre no existe.\n");
			break;
		default:
			printf("Commando invalido...\n");
			break;
		}
		free(args);
		free(line);
	}

	return 0;
}
