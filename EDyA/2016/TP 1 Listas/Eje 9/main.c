#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GList.h"

#define QUIT "quit"
#define DELIMITERS " \n"
#define LEN(X) (sizeof(X) / sizeof(*X))

// Todos las funciones handler deberian tener este tipo
typedef GList (*handler)(GList, char **);

typedef struct _Commands
{
	char *command;
	unsigned short numArgs;
	handler fun;
} Commands;

// Estructura para mantener el nombre de la lista
typedef struct _NamedList
{
	char *name;
	GList list;
} NamedList;

static void print_int(void *data, void *extra_data)
{
	printf("%d, ", *(int *)data);
}

int int_cmp(const void *x, const void *y)
{
	int a = *(int *)x;
	int b = *(int *)y;

	return a - b;
}

GList glist_clone(GList list)
{
	GList clone = NULL;
	for (; list != NULL; list = glist_next(list))
		clone = glist_append(clone, glist_data(list));
	return clone;
}
/* Aqui se encuentran las funciones handler definidas */

GList create_handler(GList masterL, char **args)
{
	NamedList *newNamedList = malloc(sizeof(NamedList));
	newNamedList->name = malloc(sizeof(char) * strlen(args[0]));
	strcpy(newNamedList->name, args[0]);
	newNamedList->list = glist_nil();

	masterL = glist_append(masterL, newNamedList);
	printf("Ha creado una nueva lista con el nombre [%s].\n", args[0]);

	return masterL;
}

GList destroy_handler(GList masterL, char **args)
{
	GList nodeTmp = masterL;
	size_t i = 0;

	while (nodeTmp && strcmp(((NamedList *)glist_data(nodeTmp))->name, args[0]))
	{
		nodeTmp = glist_next(nodeTmp);
		i++;
	}
	GList nt = (GList)glist_next(((NamedList *)glist_data(nodeTmp))->list);
	glist_destroy(nt);
	masterL = glist_remove(masterL, i);
	printf("Ha borrado la lista [%s].\n", args[0]);

	return masterL;
}

GList print_handler(GList masterL, char **args)
{
	GList nodeTmp = masterL;

	while (nodeTmp && strcmp(((NamedList *)glist_data(nodeTmp))->name, args[0]))
		nodeTmp = glist_next(nodeTmp);

	printf("Los elementos de la lista [%s] son:\n", args[0]);
	glist_foreach(((NamedList *)glist_data(nodeTmp))->list, print_int, NULL);
	puts("");

	return masterL;
}

GList add_end_handler(GList masterL, char **args)
{
	GList nodeTmp = masterL;
	int *num = malloc(sizeof(int));
	*num = atoi(args[1]);

	while (nodeTmp && strcmp(((NamedList *)glist_data(nodeTmp))->name, args[0]))
		nodeTmp = glist_next(nodeTmp);

	((NamedList *)glist_data(nodeTmp))->list = glist_append(((NamedList *)glist_data(nodeTmp))->list, num);
	printf("Ha agregado [%d] al final de la lista [%s]\n", *num, args[0]);

	return masterL;
}

GList add_beg_handler(GList masterL, char **args)
{
	GList nodeTmp = masterL;
	int *num = malloc(sizeof(int));
	*num = atoi(args[1]);

	while (nodeTmp && strcmp(((NamedList *)glist_data(nodeTmp))->name, args[0]))
		nodeTmp = glist_next(nodeTmp);

	((NamedList *)glist_data(nodeTmp))->list = glist_prepend(((NamedList *)glist_data(nodeTmp))->list, num);
	printf("Ha agregado [%d] al principio de la lista [%s]\n", *num, args[0]);

	return masterL;
}

GList add_pos_handler(GList masterL, char **args)
{
	GList nodeTmp = masterL;
	int *num = malloc(sizeof(int));
	*num = atoi(args[1]);
	int pos = atoi(args[2]);

	while (nodeTmp && strcmp(((NamedList *)glist_data(nodeTmp))->name, args[0]))
		nodeTmp = glist_next(nodeTmp);

	((NamedList *)glist_data(nodeTmp))->list = glist_insert(((NamedList *)glist_data(nodeTmp))->list, num, pos);
	printf("Ha agregado [%d] en la posicion [%d] de la lista [%s]\n", *num, pos, args[0]);

	return masterL;
}

GList length_handler(GList masterL, char **args)
{
	GList nodeTmp = masterL;

	while (nodeTmp && strcmp(((NamedList *)glist_data(nodeTmp))->name, args[0]))
		nodeTmp = glist_next(nodeTmp);

	printf("len [%s] = %d\n", args[0], glist_length(((NamedList *)glist_data(nodeTmp))->list));

	return masterL;
}

GList concat_handler(GList masterL, char **args)
{
	GList nodeTmp = masterL;

	while (nodeTmp && strcmp(((NamedList *)glist_data(nodeTmp))->name, args[0]))
		nodeTmp = glist_next(nodeTmp);

	GList cloneL1 = glist_clone(((NamedList *)glist_data(nodeTmp))->list);

	nodeTmp = masterL;

	while (nodeTmp && strcmp(((NamedList *)glist_data(nodeTmp))->name, args[1]))
		nodeTmp = glist_next(nodeTmp);

	GList cloneL2 = glist_clone(((NamedList *)glist_data(nodeTmp))->list);

	nodeTmp = masterL;

	while (nodeTmp && strcmp(((NamedList *)glist_data(nodeTmp))->name, args[2]))
		nodeTmp = glist_next(nodeTmp);

	((NamedList *)glist_data(nodeTmp))->list = glist_concat(cloneL1, cloneL2);
	printf("Se ha concatenado [%s]++[%s] y se ha guadado en [%s]\n", args[0], args[1], args[2]);

	return masterL;
}

GList remove_handler(GList masterL, char **args)
{
	GList nodeTmp = masterL;
	int pos = atoi(args[1]);

	while (nodeTmp && strcmp(((NamedList *)glist_data(nodeTmp))->name, args[0]))
		nodeTmp = glist_next(nodeTmp);

	((NamedList *)glist_data(nodeTmp))->list = glist_remove(((NamedList *)glist_data(nodeTmp))->list, pos);
	printf("Se ha borrado el elemento de la posision [%d] de la lista [%s]\n", pos, args[0]);

	return masterL;
}

GList contains_handler(GList masterL, char **args)
{
	GList nodeTmp = masterL;
	int num = atoi(args[1]);

	while (nodeTmp && strcmp(((NamedList *)glist_data(nodeTmp))->name, args[0]))
		nodeTmp = glist_next(nodeTmp);

	if (glist_contains(((NamedList *)glist_data(nodeTmp))->list, &num, int_cmp))
		printf("SI\n");
	else
		printf("NO\n");

	return masterL;
}

GList index_handler(GList masterL, char **args)
{
	GList nodeTmp = masterL;
	int num = atoi(args[1]);

	while (nodeTmp && strcmp(((NamedList *)glist_data(nodeTmp))->name, args[0]))
		nodeTmp = glist_next(nodeTmp);

	GList lTmp = ((NamedList *)glist_data(nodeTmp))->list;
	printf("La posicion del elemento [%d] en al lista [%s] es [%d]\n", num, args[0], glist_index(lTmp, &num, int_cmp));

	return masterL;
}

GList intersec_handler(GList masterL, char **args)
{
	GList nodeTmp1 = masterL;
	GList nodeTmp2 = masterL;
	GList nodeTmp3 = masterL;

	while (nodeTmp1 && strcmp(((NamedList *)glist_data(nodeTmp1))->name, args[0]))
		nodeTmp1 = glist_next(nodeTmp1);

	while (nodeTmp2 && strcmp(((NamedList *)glist_data(nodeTmp2))->name, args[1]))
		nodeTmp2 = glist_next(nodeTmp2);

	while (nodeTmp3 && strcmp(((NamedList *)glist_data(nodeTmp3))->name, args[2]))
		nodeTmp3 = glist_next(nodeTmp3);

	GList l1 = ((NamedList *)glist_data(nodeTmp1))->list;
	GList l2 = ((NamedList *)glist_data(nodeTmp2))->list;
	 
	((NamedList *)glist_data(nodeTmp3))->list = glist_intersect(l1, l2, int_cmp);
	printf("Se ha intesecado [%s]++[%s] y se guardo en [%s].\n", args[0], args[1], args[2]);

	return masterL;
}

GList sort_handler(GList masterL, char **args)
{
	GList nodeTmp = masterL;

	while (nodeTmp && strcmp(((NamedList *)glist_data(nodeTmp))->name, args[0]))
		nodeTmp = glist_next(nodeTmp);

	((NamedList *)glist_data(nodeTmp))->list = glist_sort(((NamedList *)glist_data(nodeTmp))->list, int_cmp);
	printf("Lista [%s] ordenada.\n", args[0]);

	return masterL;
}

Commands COMMAND_SET[] = {
	 {"create", 1, create_handler},
	 {"destroy", 1, destroy_handler},
	 {"print", 1, print_handler},
	 {"add_end", 2, add_end_handler},
	 {"add_beg", 2, add_beg_handler},
	 {"add_pos", 3, add_pos_handler},
	 {"length", 1, length_handler},
	 {"concat", 3, concat_handler},
	 {"remove", 2, remove_handler},
	 {"contains", 2, contains_handler},
	 {"index", 2, index_handler},
	 {"intersec", 3, intersec_handler},
	 {"sort", 1, sort_handler}};

int main(int argc, char *argv[])
{
	unsigned short CommandSetLen = LEN(COMMAND_SET);
	GList masterL = glist_nil();
	char *line = NULL;
	char **args = NULL;
	char *comm = NULL;
	size_t numArgs = 0;
	size_t lineLen = 0;
	short i = 0;
	short j = 0;

	while (1)
	{
		printf("Ingrese comando:\n");

		getline(&line, &lineLen, stdin);
		comm = strtok(line, DELIMITERS);

		// Salir?
		if (!strcmp(comm, QUIT))
			break;

		// Busca comando
		for (i = 0; i < CommandSetLen; i++)
		{
			if (!strcmp(comm, COMMAND_SET[i].command))
				break;
		}

		// Encontramos el comando?
		if (i == CommandSetLen)
		{
			// No!
			printf("Comando no valido!\n");
			free(line);
			line = NULL;
			continue;
		}
		// Guardamos el numero de argumentos, ya que se encontro el comando
		numArgs = COMMAND_SET[i].numArgs;

		if (numArgs > 0)
		{
			args = malloc(sizeof(char *) * numArgs);
			for (j = 0; j < numArgs; j++)
			{
				args[j] = strtok(NULL, DELIMITERS);
				if (!args[j])
				{
					// No pudimos leer el argumento i-esimo
					printf("ERROR, el comando [%s] requiere %d argumentos\n", comm, numArgs);
					free(line);
					line = NULL;
					free(args);
					args = NULL;
					continue;
				}
			}

			// Llamamos la funcion handler correspondiente
			masterL = COMMAND_SET[i].fun(masterL, args);

			// Liberamos memoria usada por argumentos, linea leida
			free(line);
			line = NULL;
			free(args);
			args = NULL;
		}
	}

	return 0;
}