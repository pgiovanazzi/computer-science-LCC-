#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SLStack.h"


int main(int argc, char const *argv[]){
	int i, result = 0;
	char cadena[10];
	SLStack newPila;

	scanf("%s", cadena);

	i = 0;
	while(cadena[i] != '\0'){
		if(cadena[i] != '+' && cadena[i] != '-' && cadena[i] != '*' && cadena[i] != '/')
			slstack_push(&newPila, (cadena[i])-48);
		else{
			switch(cadena[i]){
				case '+':
					result = slstack_top(&newPila);
					slstack_pop(&newPila);
					result = slstack_top(&newPila) + result;
					slstack_pop(&newPila);
					slstack_push(&newPila, result);
					break;
				case '-':
					result = slstack_top(&newPila);
					slstack_pop(&newPila);
					result = slstack_top(&newPila) - result;
					slstack_pop(&newPila);
					slstack_push(&newPila, result);
					break;
				case '*':
					result = slstack_top(&newPila);
					slstack_pop(&newPila);
					result = slstack_top(&newPila) * result;
					slstack_pop(&newPila);
					slstack_push(&newPila, result);
					break;
				case '/':
					result = slstack_top(&newPila);
					slstack_pop(&newPila);
					result = slstack_top(&newPila) / result;
					slstack_pop(&newPila);
					slstack_push(&newPila, result);
					break;
				default:break;
			}
		}
		i++;
	}

	printf("El resultado es: %d\n", result);

	return 0;
}