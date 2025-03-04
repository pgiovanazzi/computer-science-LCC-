/*Trabajo practico 1 Estructura de datos y algoritmo*/
#include <stdio.h>

//Ejercicio 1
float abss(float h){
	float abs2;
	if (h >= 0)
		abs2 = h;
	else
		abs2 = -h;
	return abs2;
}

//Ejercicio 2
float eval(float a, float b, float c, float x){
	float pol = a*x*x + b*x + c;
	return pol;
}

//Ejercicio 3
int hasroot(float a,float b,float c){
	float disc = b*b - 4*a*c;
	if (disc < 0)
		return 0;
	if (disc == 0)
		return 1;
	if (disc > 0)
		return 2;
}

//Ejercicio 4
int sum(int n){
	int i,suma = 0;
	for (i; i <= n; i++)
		suma += i;
	return suma;
}

//Ejercicio 5 factorial iterativa
int factoriali(int n){
	int acu = 1;
	while (n != 0)
		acu*= n--;
	return acu;
}

//Ejercicio 5 factorial recursiva
int factorialr(int n){
	if (n == 0)
		return 1;
	else
		return n * factorialr(n-1);
}

//Ejercicio 6
int fib(int n){
	if (n < 2)
		return n;
	else
		return fib(n-1) + fib(n-2);
}

//Ejercicio 7
int bisiesto(int a){
	return(a % 4 == 0 && (a % 100 != 0 || a % 400 == 0));
}

//Ejercicio 8
int isprime(int n){
	int i, con = 0;
	for (i = 1; i <= n; i++){
		if (n % i == 0)
			con++;
	}
	return (con == 2);
}

//Ejercicio 9
int tablaCF(void){
	printf("Tabla de equivalencias entre grados Celsius y grados Fahrenheit:\n");
	float C;
	for (C = 0; C <= 300; C+=20)
		printf("%5.1f ºC____%5.1f ºF\n", C, 9*C /5 + 32);
}

//Ejercicio 10
hola(void){
	puts("Hola mundo");
}

//Ejercicio 11
int lc(void){
	int c,con = 0;
	while ((c = getchar()) != EOF)
		if (c == '\n')
			++con;
		return con;
}

//Ejercicio 12
void echo(){
	int c;
	while ((c = getchar()) != EOF)
		putchar(c);
}

//Ejercicio 13
void simplecaesar(){
	int c;
	while ((c = getchar()) != EOF)
		switch (c){
			case 'a': c = 'u';putchar(c);
				break;
			case 'e': c = 'o';putchar(c);
				break;
			case 'o': c = 'e';putchar(c);
				break;
			case 'u': c = 'a';putchar(c);
				break;
			default: putchar(c);
		}
}

//Ejercicio 14
int euclid(int a, int b){
	if (b == 0)
		return a;
	else
		return euclid(b, a%b);
}

//Ejercicio 15
int invertir(long numero){
	int digit;
	printf("El numero invertido es: ");
	while(numero > 0){
		digit = numero % 10;
		numero /= 10;
		printf("%d", digit);
	}
	printf("\n");
}

//Ejercicio 16
float prom(int a[], int l){
	int acum = 0,i = 0;
	float pro;
	for(i; i < l; i++){
		acum+=a[i];
	}
	pro = acum / l;
	return pro;
}

//Ejercicio 17
void printints(int a[], int b){
	int i = 0;
	printf("Los elementos la lista son:\n");
	for (i; i < b; i++)
		printf("%d\t", a[i]);
	printf("\n");
}

//Ejercicio 18
int isin(int a[],int b, int c){
	int i = 0;
	for (i; i < b; i++){
		if (a[i] == c)
			return 1;
	}
	return 0;
}


//Ejercicio 19
int lenstr(char *a){
	if (*a == '\0') 
		return 0;
	else 
		return 1 + lenstr(a+1);
}

//Ejercicio 19.1
int lenstr1(char a[]){
	int i,cont=0;
	for(i=0; a[i] != '\0'; i++)
		cont++;
	return cont;
}

//Ejercicio 20
int cmpstr(char *a, char *b){
	if (*a == '\0' && *b == '\0')
		return 1;
	else{
		if (*a != *b)
			return 0;
		else
			cmpstr(a+1, b+1);
	}
}

//Ejercicio 21
void password(void){
	#define USER "paulo"
	#define PASS "123"
	char u[50],p[24];
	printf("Ingrese el nombre de usuario: ");
	scanf("%s", u);
	printf("Ingrese la contraseña: ");
	scanf("%s", p);
	printf("...");
	if (cmpstr(USER,u) && cmpstr(PASS,p))
		printf("¡Bienvenido!\n");
	else
		printf("Error, contraseña o usuario incorrecto.\n");
}

//Ejercicio 22
void impArray(int *d, int c){
	int i = 0;
	for(i; i < c ; i++){
		printf("%i\t", *d);
		d++;
	}
	printf("\n");
}
void convocales(void){
	int c,a=0,e=0,i=0,o=0,u=0;
	int b[] = {a,e,i,o,u};
	while ((c = getchar()) != EOF)
		switch (c){
			case 'a': ++a; b[0] = a;
					break;
			case 'e': ++e; b[1] = e;
					break;
			case 'i': ++i; b[2] = i;
					break;
			case 'o': ++o; b[3] = o;
					break;
			case 'u': ++u; b[4] = u;
					break;
		}
	impArray(b,5);
}

//Ejercicio 23
int atoi(char *str){
	int c = 0; 
 
	if ( str ){
		while ( *str && *str <= '9' && *str >= '0' ){
			c = (c * 10) + (*str - '0');
			str++;
		}
	}
	return c; 
}

//Ejercicio 23.1
int atoi1(char str[]){
	int i = 0,c = 0;
	for(; str[i] != '\0'; i++)
		c = (c * 10) + (str[i] - '0');
	return c;
}

//Ejercicio 24
void Eje24(void){
	int c;
	while((c=getchar())!=EOF){
		if (c == '/'){
			c = getchar();
			if (c == '*'){
				do{
					c = getchar();
				}while(c != '*');
				c = getchar();
				if (c == '/'){
					c = getchar();
					putchar(c);
				}
			}
			else {
				if( c == '/'){
					do{
						c = getchar();
					}while(c != '\n');
					c = getchar();
					putchar(c);
				}
				else
					putchar(c);
			}
		}
		else
			putchar(c);
	}
}

//Ejercicio 24.1

void Eje24_1(){  /*Abre main */
				/*Comentario*/
int Estatus = 0; 
/*La variable estatus indica si se esta dentro (1)
  o fuera (0) de un comentario. Se inicia fuera */
int c; /*La variable c guardara los caracteres recibidos*/

/*Este ciclo while recibe los caracteres*/

while( (c = getchar()) != EOF ){ /*Abre while */
	/*OPCION 1: FUERA DE UN COMENTARIO*/
	if (0 == Estatus){  /*Abre if Estatus == 0*/
		if ( c != '/') 
			putchar(c);
		else{ /*Abre else*/
			c = getchar();
			if ( '*' == c )
				Estatus = 1;
			else{/*Abre else anidado*/
				printf("/");
				putchar(c);
			} /*Cierra else anidado*/
		} /*Cierra else*/
	}  /*Cierra if Estatus == 0*/

/*OPCION 2: DENTRO DE UN COMENTARIO*/ 
	if (1 == Estatus){  /*Abre if Estatus == 1*/
		if ( '*' == c)
			if ((c = getchar()) == '/')
				Estatus = 0;
	}  /*Cierra if Estatus = 1*/
} /*Cierra while*/
}  /*Cierra main*/


int main(void){
	Eje24_1();
	return 0;
}
