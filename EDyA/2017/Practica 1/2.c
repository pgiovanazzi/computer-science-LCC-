#include <stdio.h>

// Retorna la longitud de unba cadena.
int string_len(char *str)
{
	size_t i;
	for (i = 0; str[i]; i++)
		;
	return i;
}
// Invierte la cadena dada.
void string_reverse(char *str)
{
	int buffer, len = string_len(str);
	for (size_t i = 0; i < len / 2; i++)
	{
		buffer = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = buffer;
	}
}

// Copia la cadena str2 al final de la cadena str1, hasta un máximo de max
// caracteres en str1. Retorna el número de caracteres copiados.
size_t string_concat(char *str1, char *str2, size_t max)
{
	size_t i, j;
	for (i = 0; str1[i]; i++)
		;
	for (j = 0; j < max && max <= string_len(str2); i++, j++)
		str1[i] = str2[j];
	str1[i] = '\0';

	return j;
}

// Compara en orden lexicográfico las dos cadenas dadas y retorne -1,
// si str1 es menor a str2, 0 si son iguales, y 1 si str1 es mayor a str2.
int string_compare(char *str1, char *str2)
{
	int len1 = string_len(str1);
	int len2 = string_len(str2);

	for (size_t i = 0; i < len1 && i < len2; i++)
	{
		if (str1[i] < str2[i])
			return -1;
		if (str1[i] > str2[i])
			return 1;
	}
	return 0;
}

// Dado un arreglo de cadenas, las concatene (guardando el resultado en res),
// separándolas con la cadena sep.
void string_unir(char *arregloStrings[], size_t capacidad, char *sep, char *res)
{
	size_t i, j, plusOne = 0;
	for (i = 0; i < capacidad; i++)
	{
		for (j = 0; arregloStrings[i][j]; j++, plusOne++)
			res[plusOne] = arregloStrings[i][j];
		if (i != capacidad - 1)
			for (j = 0; sep[j]; j++, plusOne++)
				res[plusOne] = sep[j];
	}
	res[plusOne] = '\0';
}

int main(int argc, char *argv[])
{
	char str1[30], str2[] = "mid";
	char *fraces[] = {"Frace1", "Frace2", "Frace3"};
	string_unir(fraces, 3, str2, str1);
	printf("%s\n", str1);
	return 0;
}