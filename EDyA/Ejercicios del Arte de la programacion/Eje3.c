#include <stdio.h>

int main(int argc, char *argv[]) {
	const char tablaDNI[] = "TRWAGMYFPDXBNJZSQVHLCKE";
	long int dni = 31415927;
	long int resto = dni % 23;
	// Calculo de la letra de un DNI dado.
	printf("EL DNI es %li-%c.\n", dni, tablaDNI[resto]);
	
	// DNI correcto.
	long int dni2 = 31415927;
	char l = 'C';
	if ( tablaDNI[dni2 % 23] == l )
		printf("DNI correcto.\n");
	else
		printf("DNI incorrecto.\n");

	return 0;
}