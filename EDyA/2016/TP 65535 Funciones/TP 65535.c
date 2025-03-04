#include <stdio.h>

/* Ejercicio 1:
	
	float abss(float n){
		return (n < 0) ? -n : n;
	}

	Ejercicio 2:
 	
 	float eval(float a, float b, float c, float x){
 		return a*x*x+b*x+c;
 	}
 
	Ejercicio 3:
	
	int hasroot(float a, float b, float c){
		float delt = b*b - 4*a*c;
		return (delt > 0) ? 2 : (delt == 0) ? 1 : 0;
	}
	
	Ejercicio 4:
	
	unsigned int sum(unsigned int n){
		return (n == 0) ? 0 : sum(n-1) + n;
	}
	
	Ejercicio 5:
	
	//Iterativa:
	unsigned int factorial(unsigned int n){
		int i, prod = 1;
		for(i = 1; i <= n ; i++)
			prod *=i;
		return prod;
	}
	
	//Recurciva:
	unsigned int rfactorial(unsigned int n){
		return (n == 0) ? 1 : rfactorial(n - 1) * n;
	}
	
	Ejercicio 6:
	
	unsigned int fib(unsigned int n){
		return (n < 2) ? 1 : fib(n-1) + fib(n-2);
	}
	
	Ejercicio 7:
	
	unsigned int bisiesto(unsigned int year){
		return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 1 : 0;
	}
	
	/*
	Ejercicio 8:
	
	unsigned int isPrime(unsigned int n){
		int i;
		for( i = 2; i < n; i++)
			if( n % i == 0) return 0;
		return 1;
	}
	
	Ejercicio 9:
	
	void tablaGradFarg(void){
		int i;
		printf("TABLA DE COMVERCION DE GRADOS.\n");
		printf("Grados Celsius       Grados Fahrenheit\n");
		for(i = 100; i <= 260 ; i+=10)
			printf("%4d                %8.2f\n", i, (9/5.0)*i+32);
	}
	
	Ejercicio 10:
	
	void hMundo(void){
		//una forma
		puts("Hola Mundo.");
		//otra forma
		putc('H', stdout);
		putc('o',stdout);
		putc('l',stdout);
		putc('a',stdout);
		putc(' ',stdout);
		putc('m',stdout);
		putc('u',stdout);
		putc('n',stdout);
		putc('d',stdout);
		putc('o',stdout);
		puts("");
	}
	
	Ejercicio 11:
	
	int lc(void){
		char c;
		int count = 0;
		while((c = getchar()) != EOF)
			if(c == '\n')
				count++;
		return count;
	}
	
	Ejercicio 12:
	
	void echo(void){
		char c;
		while((c = getchar()) != EOF){
			putchar(c);
		}
	}
	
	Ejercicio 13:
	
	void simplecaesar(){
		char c;
		while((c = getchar()) != EOF)
			switch (c) {
				case 'a': putchar('u'); break;
				case 'e': putchar('o'); break;
				case 'o': putchar('e'); break;
				case 'u': putchar('a'); break;
				default: putchar(c);
			}
	}
	
	Ejercicio 14
	
	int euclid(int a, int b){
		int rest, dividendo = a, divisor = b, mcd, tmp;
		
		if(a <= b){
			dividendo = b;
			divisor = a;
		}
		
		do{			
			mcd = divisor;
			tmp = dividendo;
			while(tmp >= divisor)
				tmp -= divisor;
			rest = tmp;
			if(rest) {
				dividendo = divisor;
				divisor = rest;
			}
		}while(rest);
		
		return mcd;
	}
	
	
	Ejercicio 15
	
	int invertir(int n){
		int unity, newn = 0, i = 0, tmp = n;
		
		while(tmp){
			tmp/=10;
			i++;
		}
		
		int position[i], j = 0;
		
		while(n){
			unity = n % 10;
			n/=10;
			position[j++] = unity;
		}
		
		unity = 1;
		for(j = i-1; j >=0 ; j--){
			newn += position[j]*unity;
			unity *=10;
		}
		
		return newn;
	}
	
	Ejercicio 16
	
	float prom(int arr[], int l){
		int sum = 0,i;
		for(i = 0; i < l; i++)
			sum += arr[i];
		
		return sum/l;
	}
	
	Ejercicio 17:
	
	void printints(int arr[], int l){
		int i;
		for(i = 0; i < l; i++)
			printf("%d\t", arr[i]);
	}
	
	Ejercicio 18
	
	int isin(int arr[], int l, int n){
		int i;
		
		for(i = 0; i < l; i++)
			if(arr[i] == n) return 1;
	
		return 0;
	}
	
	Ejercicio 19:
	
	int lenstr(char str[]){
		int i, len = 0;
		for(i = 0; str[i]; i++)
			len++;
		return len;
	}
	
	Ejercicio 20
	
	int cmpstr(char arr1[], char arr2[]){
		int i;
		for(i = 0; arr1[i] || arr2[i] ; i++)
			if(arr1[i] != arr2[i]) return 0;
		
		return 1;
	}
	
	//Ejercicio 21:
	
	void pass(){
		#define USSER "Paulo"
		#define PWS "1234"
		char name[20], con[10];
		printf("Ingrese el nombre: ");
		scanf("%s",name);
		printf("Ingrese la password: ");
		scanf("%s",con);
		printf("...");
		if(cmpstr(USSER,name) && cmpstr(PWS,con))
			printf("Bienvenido!.\n");
		else
			printf("Error. La contrasenia o usuario son incorrectos.\n");	
	}
	
	Ejercicio 22
	
	void cantVocal(){
		char c;
		int arr[] = {0,0,0,0,0}, i;
		printf("Ingrese el texto.\n");
		while((c = getchar()) != EOF)
			switch(c){
				case 'a': arr[0]++; break;
				case 'e': arr[1]++; break;
				case 'i': arr[2]++; break;
				case 'o': arr[3]++; break;
				case 'u': arr[4]++; break;
				default:;
			}
		printf("La cantidad de vocales de cada una son:\n");
		printf("Vocal a		Vocal e		Vocal i		Vocal o		Vocal u\n");
		printf("%4d		%4d		%4d		%4d		%4d\n",arr[0],arr[1],arr[2],arr[3],arr[4]);
	}
	
	Ejercicio 23
	
	int atoi(char str[]){
		int i, num = 0;
		for(i = 0; str[i]; i++){
			//    unidad     + digito en entero
			num = (num * 10) + (str[i]-'0');
		}
		return num;
	}
	
	Ejercicio 24*/
	
	void comentsDelete(){
		char c, j;
		printf("Ingrese el programa de C.\n");
		while((c = getchar()) != EOF)
			if(c == '/' && (c = getchar()) == '*')
				while((c = getchar()) != '/');
			else if (c == '/')
				while((c = getchar()) != '\n');
			else
				putchar(c);
	}
	
int main(){
	comentsDelete();
	return 0;
}










