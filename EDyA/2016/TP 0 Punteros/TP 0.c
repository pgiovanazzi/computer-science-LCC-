#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Ejercicio 1

	void  decVar(){
		int x = 42;
		char ch = 'a';
		char str[] = "Hola mundo.";
		
		printf("La direccion de memoria de x = %d es %p\n", x, &x);
		printf("La direccion de memoria de ch = %c es %p\n", ch, &ch);
		printf("La direccion de memoria de str = %s es %p\n", str, str);
		printf("La direccion de memoria de str[1] = %c es %p\n", str[1], &str[1]);
		printf("La direccion de memoria de str[2] = %c es %p\n", str[2], &str[2]);
	
	}

	Ejercicio 2:
	
	char *itoa(int n){
		int count = 0, sign = n;
		
		if(n < 0) n = n*(-1); 
		
		int tmp = n;
		while(tmp){
			tmp /= 10;
			count++;
		}
		
		// count + 1 por el caracter nulo '\0'
		char *str = malloc(sizeof(char)*(count + 2)); // que es lo mismo char str[count+1];
		str[count+1] = '\0';
		
		int  i = count;
		
		while(n){
			//Almacena el numero en formato caracter de la tabla ASCCI
			str[i--] = (n % 10) + '0';
			n/=10;
		}
		
		if(sign < 0) {
			str[i] = '-'; 
			return str;
		}
		return str + 1;
	}

	Ejercicio 3:
	
	typedef enum {ORO = 1, COPA, BASTO, ESPADA} PALO;
	
	struct carta {
		int numero;
		PALO p;
	} mazo[48];
	
	void llenaMazo(){
		int i, num;
		for(i = 0, num = 1; i < 12; i++){
			mazo[i].numero = num++;
			mazo[i].p = ORO;
		}
		for(num = 1; i < 24; i++){
			mazo[i].numero = num++;
			mazo[i].p = COPA;
		}
		for(num = 1; i < 36; i++){
			mazo[i].numero = num++;
			mazo[i].p = BASTO;
		}
		for(num = 1; i < 48; i++){
			mazo[i].numero = num++;
			mazo[i].p = ESPADA;
		}
		
		for(i = 0; i < 48; i++)
			printf("Numero = %2d, Palo = %2d\n", mazo[i].numero, mazo[i].p);
	}
	
	
	Ejercicio 4:
	
	struct carta azar(struct carta cart[], int len){
		srand(time(NULL));
		int r = rand() % len;
		return cart[r];
	}
	
	Ejercicio 5:
	
	b)Es un arreglo de tres elementos que apuntan a la direccion de memoria de un entero
	e)Es un puntero que apunta a la direccion de memoria de una funcion de entrada void y salida 	int.
	
	Ejercicio 6
	
	void setzerozero(int n[]){
		n[0] = 0;
		printf("El primero valor de n[0] = %d\n", n[0]);
	}
	
	Pasa esto porque la funcion toma la dirreccion de memoria del arreglo, esto quiere decir
	que modifica el valor del arreglo en donde se encuentra almacenado el valor, en este caso
	n[0]. Los arreglos se pasan al parametro de la funcion la dirreccion de memoria donde esta
	almacenado, que es difenrete al resto de las variables, como por ejemplo un entero o un punto
	flotante que pasan por valor, lo que significa que la funcion hace una copia temporal para 
	trabajar con los valores.
	
	
	Ejercicio 7
	
	Sintaxis de la funcion malloc():
	
	#include <stdlib.h>
	void*malloc(size_t size);
	
	size es el numero de bytes que va almacenar en la memoria. size_t es un tipo de datos
	estructura que se encuentra definido en la libreria stdlib.h. malloc retorna la dirrecion
	de memoria de tipo void en donde se ubican los bytes reservados en memoria.
	En caso que no se pueda reservar el espacio en memoria returna un puntero nulo.
	
	Ejercicio 8
	
	typedef struct contacto{
		char nombre[20];
		char tel[20];
		unsigned int edad;
	} contacto_t;
	
	Ejercicio 9
	
	contacto_t *crearcontacto(void){
		contacto_t *newCon = malloc(sizeof(contacto_t));
		printf("Ingrese el nombre: ");
		scanf("%s", newCon->nombre);
		fflush(stdin);
		printf("Ingrese el telefono: ");
		scanf("%s", newCon->tel);
		fflush(stdin);
		printf("Ingrese la edad: ");
		scanf("%d", &newCon->edad);
		fflush(stdin);
		
		return newCon;
	}
	
	Ejercicio 10
	
	typedef struct punto{
		float x;
		float y;
	}punto_t;
	
	punto_t *puntoMedio(punto_t *par1, punto_t *par2){
		punto_t *pm = malloc(sizeof(punto_t));
		
		pm->x = (par1->x-par2->x)/2.0;
		pm->y = (par1->y-par2->y)/2.0;
		
		return pm;
	}
	
	Ejercicio 11
	
	void setin(int *n){
		(n != 0) ? *n = 1 : *n = 0;
	}
	
	Ejercicio 12
	
	void swap(int *n1, int *n2){
		int n3 = *n1;
		*n1 = *n2;
		*n2 = n3;
	}
	
	Ejercicio 13
	
	void swap(int *n1, int *n2){
		*n1 = *n1 ^ *n2; //Genera un C y lo guarda en *n1
		*n2 = *n1 ^ *n2; //Ahora B es igual a C ^ *n2, lo cual nos da *n1, osea en *n2 nos quedo *n1
	}
	
	Ejercicio 14
	
	char *getnewline(void){
		char *str = malloc(sizeof(char)*100);
		printf("Ingrese una linea de texto, para terminar precionar enter.\n");
		fgets(str,100,stdin);
		return str;
	}
	
	Ejercicio 15
	
	void actualizaredad(contacto_t *contact){
		printf("Ingrese el la nueva edad: ");
		scanf("%d", &contact->edad);
	}
	/*
	Ejercicio 16
	float prom(contacto_t *cont, int len){
		int i, acum;
		float prom;
		for(i = 0; i < len; i++)
			acum += cont[i].edad;
		prom = (float)acum/len;
		return prom;
	}
	
	int i;
	contacto_t arr_con[] = {{"Pau", "123", 27}, {"Iva","456", 27}, {"Cir","789", 26}};
	for(i = 0; i < 3; i++)
	printf("Los valores son\nNombre: %s\nTelefono: %s\nEdad: %d\n", arr_con[i].nombre,arr_con[i].tel,arr_con[i].edad);
	
	printf("El promedio de las dedades son: %.2f\n", prom(arr_con, 3));
	
	Un puntero a una estructura apunta a una direccion de memoria que se encuentra en alguna parte de la memoria,
	la diferencia del arreglo de estructuras es que las almacena en bloques de memoria una tras otra y tendran
	las dirrecciones de memoria seguidas unas tras otra dependiendo de la cantidad de bytes que ocupa la estructura.
	Un arreglo de estructuras apunta a una direccion de memoria donde se encuentran las estructuras almacenadas seguidas
	una tras otra.
	
	Ejercicio 17
	
	typedef struct agenda{
		contacto_t lCon[100];
		int len;
	} agenda_t;
	
	void listContatos(contacto_t *cont, int i){
		printf("---- Nro: %d ----\n", i+1);
		printf("Nombre: %s\nTelefono: %s\nEdad: %d\n", cont->nombre, cont->tel,cont->edad);
	}
	
	void proAgenda(agenda_t *ag){
		int k,l,i = 0, terminar = 1;
		char c;
		while(terminar){
			printf("\nAgregar contacto - 1\nCambiar edad - 2\nListar contactos - 3\nSalir - 0\n");
			scanf("%d",&k);
			switch(k){
				case 1:
					printf("Ingrese la cantidad de contactos que agregara: ");
					scanf("%d",&ag->len);
					for(; i < ag->len; i++){
						printf("\n--- Nuevo contacto ---\n\n");
						contacto_t *con = crearcontacto();
						ag->lCon[i] = *con;
					}
					break;
				case 2:
					i = 0;	
					printf("Cual contacto desea cambiarle la edad? Nro: %d - %d ", i+1, ag->len);
					scanf("%d", &i);
					actualizaredad(&ag->lCon[i-1]);
					printf("\n...Modificado!\n");
					break;
				case 3:
					i = 0;
					printf("--- DATOS ---\n");
					for(; i < ag->len; i++)
						listContatos(&ag->lCon[i], i);
					break;
				case 0: 
					terminar = 0;
					printf("... Hasta luego.\n");
					break;
				default:
					printf("...Error. Ingreso mal la opcion, intentelo de nuevo.\n");
					break;
			}
		}
		
	}
	
	Ejercicio 18
	
	void progfreeX2_100Bytes(){
		int *a = malloc(100);
		free(a);
		free(a);
	}
	
	Se produce un error de doble free() o de corrupcion de la varuable. (errores de memoria)
	
	Ejercicio 19
	
	int apply(int (*ret)(int n), int ns){
		return ret(ns);
	}
	
	int doble(int n){
		return n*2;	
	}
	
	int nu = 10;
	printf("apply(&doble,%d) = %d\n", nu,apply(&doble, nu));
	
	Ejercicio 20
	
	void applyin(int (*fun)(int n), int *x){
		*x = fun(*x);
	}
	
	int triplica(int n){
		return n*3;
	}
	
	Ejercicio 21
	
	void recorrer(void (*VisitorFun)(int n), int arr[], int n){
		int i;
		for(i = 0; i < n; i++)
			VisitorFun(arr[i]);
	}
	
	void VisitorFun(int n){
		printf("%d ", n);
	}
	
	Ejercicio 22*/

int main(int argc, char *argv[]){
	int i = 0;
	printf("La cantidad de argumentos recibidos son: %d\n", argc);
	printf("Los argumentos pasados son:\n");
	for(; argv[i]; i++)
		printf("%s ", argv[i]);
	puts("");
	
	return 0;
}





