#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "SList.h"

#define QUIT "quit"
#define DELIMITERS " \n"

// All handler functions should have this type
typedef SList (*handler)(SList, char **);

typedef struct
{
	char *command;
	unsigned short num_args;
	handler fun;
} command;

// Struct to hold a 'named list'
typedef struct
{
	char *name;
	SList list;
} named_list;

/*  Here are the handler function definitions  */

SList create_handler(SList ml, char **args)
{
	// Crear nuevo nodo
	named_list *new_named_list = (named_list *)malloc(sizeof(named_list));
	new_named_list->name = (char *)malloc(sizeof(char) * strlen(args[0]));
	strcpy(new_named_list->name, args[0]);
	new_named_list->list = slist_nil();

	// Agregarlo a la lista maestra
	ml = slist_append(ml, new_named_list);

	// Devolvemos puntero a lista maestra
	return ml;
};

SList destroy_handler(SList ml, char **args)
{
	// TODO: implement
	printf("Deberiamos destruir la lista [%s]\n", args[0]);
	return ml;
};

SList add_end_handler(SList ml, char **args)
{
	// TODO: implement
	printf("Deberiamos agregar [%s] a la lista [%s]\n", args[1], args[0]);
	return ml;
};

/*
 * This structures captures the data for handling commands
 * and allows us to introduce new ones in a nice way
 */
static const command COMMAND_LIST[] = {
	 {"create",
	  1,
	  create_handler},
	 {"destroy",
	  1,
	  destroy_handler},
	 {"add_end",
	  2,
	  add_end_handler}};

static const int command_list_len = sizeof(COMMAND_LIST) / sizeof(command);

static void freeNamedList(void *data, void *extra_data)
{
	named_list *node = (named_list *)data;

	// Espacio usado por el nombre
	free(node->name);
	slist_destroy(node->list);

	return;
}

int main(int argc, char *argv[])
{
	SList master_list = slist_nil();
	SNode *aux = NULL;
	char *line = NULL;
	char *command = NULL;
	size_t line_len = 0;
	int i = 0;
	int j = 0;
	int num_args = 0;
	char **args = NULL;

	while (1)
	{
		printf("Ingrese un comando:\n");

		// Leemos linea desde entrada estandar (stdin)
		getline(&line, &line_len, stdin);
		command = strtok(line, DELIMITERS);

		// Tenemos que salir?
		if (!strcmp(command, QUIT))
		{
			break;
		}

		// Busquemos la informacion sobre el comando ingresado
		for (i = 0; i < command_list_len; i++)
		{
			if (!strcmp(command, COMMAND_LIST[i].command))
			{
				break;
			}
		}

		// Encontramos el comando?
		if (i == command_list_len)
		{
			// No!
			printf("Comando no valido!\n");
			free(line);
			line = NULL;
			continue;
		}

		// Si llegamos aca, es que encontramos el comando en la posicion i
		num_args = COMMAND_LIST[i].num_args;

		// Armamos un arreglo de punteros a char con los 'num_args 'argumentos
		if (num_args > 0)
		{
			args = (char **)malloc(sizeof(char *) * num_args);
			for (j = 0; j < num_args; j++)
			{
				args[j] = strtok(NULL, DELIMITERS);
				if (!args[j])
				{
					// No pudimos leer el argumento j-esimo
					printf("ERROR, el comando [%s] requiere %d argumentos\n", command, num_args);
					free(line);
					line = NULL;
					free(args);
					args = NULL;
					continue;
				}
			}

			// Llamamos al handler correspondiente
			master_list = COMMAND_LIST[i].fun(master_list, args);

			// Liberamos memoria usada por argumentos, linea leida
			free(line);
			line = NULL;
			free(args);
			args = NULL;
		}
	}

	// Liberamos memoria de listas almacenadas
	slist_foreach(master_list, freeNamedList, NULL);

	// Liberamos memoria de lista maestra
	slist_destroy(master_list);

	return 0;
};
