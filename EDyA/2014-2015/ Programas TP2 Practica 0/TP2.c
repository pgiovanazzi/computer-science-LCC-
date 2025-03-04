#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Ejercicio 1
void valMem(void){
	int a = 0;
	char b[]= "hola";
	printf("variable entera valor en memoria: %p\narreglo de enteros valor en memoria: %p\nvalor en memoria del arreglo en el elemento 2: %p\n", &a, &b, &b[1]);
}

//Ejercicio 2
char *itoa(int i){
	int j = 1;
	static char buf[sizeof(int) + 2]; // sizeof(int) is the size of an int on the platform (duh)
	char *p = buf + sizeof(int) + 1;
	do {
		*--p = '0' + (abs(i / j) % 10); // '0' + a one-digit number = the ascii val of the number
		j *= 10;
	} while (i / j);
	if(i < 0) *--p = '-';
	return p;
}

//Ejercicio 2.1
char *itoa1(int n){
	int i = 0, j, a = n, b = n;
	n = abs(n);
	a = abs(a);
	while (a){
		a/=10;
		i++;
	}
	int digit[i];
	for (j = 0;j < i;j++){
		digit[j] = n % 10;
		n /= 10;
	}
	char *ch = malloc(sizeof(int)*i);
	for (j = 0; j < i;j++){
		*--ch = digit[j] + '0';
	}
	if (b < 0)
		*--ch = '-';
	return ch;
}

//Ejercicio 3
typedef enum {ORO = 1,COPA,BASTO,ESPADA} PALO; 
struct carta{
	int num;
	PALO palo;
};


struct carta llenarmazo(void){
	int i,c = 1;
	struct carta mazo = malloc(sizeof(struct carta)*48);
	for (i = 0; i < 12; i++){
		mazo[i].num = c++;
		mazo[i].palo = ORO;
	}
	c = 1;
	for (i = 12; i < 24; i++){
		mazo[i].num = c++;
		mazo[i].palo = COPA;
	}
	c = 1;
	for (i = 24; i < 36; i++){
		mazo[i].num = c++;
		mazo[i].palo = BASTO;
	}
	c = 1;
	for (i = 36; i < 48; i++){
		mazo[i].num = c++;
		mazo[i].palo = ESPADA;
	}
	//printf("Numero: %d, Palo: %d\n", mazo[3].num, mazo[3].palo);
	return mazo;
}

//Ejercicio 4
struct carta azar(struct carta m[], int n){
	struct carta m1;
	int num_car_azar,palo_car_azar;
	srand(time(NULL));
	m1.num = m[rand()%n].num;
	m1.palo = m[rand()%48].palo;
	printf("La carta al azar es: %d %d\n", m1.num, m1.palo);
	return m1;
}

void ingresar_mazo_n(void){
	int j;
	printf("Ingrese la longitud del mazo: ");
	scanf("%d", &j);
	struct carta mazo[48];
	mazo[0] = llenarmazo();
	azar(mazo, j);
}

//Ejercicio 5
/*
 a) f es un puntero a un arreglo de 3 entereros.
 b) f es un arreglo de 3 punteros a caracteres. 
 c) f es un arreglo de 3 que apunta a un entero.
 d) f es una funcion que apunta a un entero.
 e) f es un puntero a una funcion que debuelve un entero.*/

//Ejercicio 6
void setzerozero(int a[]){
	a[0] = 0;
	int i;
	for(i=0; i < sizeof(a)/4; i++){
		printf("%d", a[i]);
	printf("\n");
	}
}

//Ejercicio 7
/*El tipo de la funcion malloc es: void * malloc( unsigned numero_de_bytes ); 
donde la entrada es un numero representado en bytes que se le bloque de memoria
que va suministrar, y la salida void * devuelbe un puntero inespecífico, que no
apunta a un tipo de dato determinado.
Si la funcion no puede reservar el espacio solicitado retorna un puntero nulo (NULL).*/

//Ejercicio 8
typedef struct contacto{
	char nombre[15];
	char numTel[15];
	long edad;
}contacto_t;

//Ejercicio 9
contacto_t *crearcontacto(contacto_t *contact){
	printf("\n");
	
	//Asigmancion de valores
	fflush(stdin);
	printf("Ingrese el nombre: ");
	scanf("%s",contact->nombre);
	fflush(stdin);
	printf("Ingrese el Numero de telefono: ");
	scanf("%s",contact->numTel);
	fflush(stdin);
	printf("Ingrese la edad: ");
	scanf("%ld", &contact->edad);
	
	return contact;
}

void impr_contacto(contacto_t *impr_el_contacto){
	printf("\nNombre: %s\nNumero de telefono: %s\nEdad: %ld\n", impr_el_contacto->nombre, impr_el_contacto->numTel, impr_el_contacto->edad);
}

//Ejercicio 10
typedef struct plano{
	float x;
	float y;
}plano_t;

plano_t medio(plano_t p1, plano_t p2){
	plano_t pm;
	pm.x = (p1.x + p2.x)/2.f;
	pm.y = (p1.y + p2.y)/2.f;
	return pm;
}
void ingresar_puntos(void){
	plano_t pp1,pp2;
	printf("Ingrese el punto 1 ( , ): ");
	scanf("%f%f", &pp1.x, &pp1.y);
	printf("Ingrese el punto 2 ( , ): ");
	scanf("%f%f", &pp2.x, &pp2.y);
	plano_t ppm;
	ppm = medio(pp1,pp2);
	printf("El punto medio (%.2f , %.2f)\n", ppm.x, ppm.y );
}
//Ejercicio 11
/*int a = 0;
setin(&a);*/
void setin(int * n){
	if (*n != 0)
		*n = 1;
	printf("%d\n", *n);
}

//Ejercicio 12
/*int z = 3,y = 4;
	printf("z: %d, y: %d\n", z, y);
	swap(&z,&y);*/
void swap(int * a, int * b){
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("Intercambio es z: %d, y: %d\n", *a, *b);
}
//Ejercicio 13
/*A = A xor B 'Generamos un C y lo guardamos en A.
B = A xor B 'Ahora B es igual a C xor B, lo cual nos da A, o sea, en B nos quedó A
A = A xor B 'A era C, y B era A por todo lo que hicimos, así que C xor A, nos dió otra vez B, y quedó en A*/

void swap_1(int * a, int * b){
	*a^=*b;
	*b^=*a;
	*a^=*b;
	printf("Intercambio es z: %d, y y: %d\n", *a, *b);
}

//Ejercicio 14
char * getnewline(void){
	char c;
	char * pc = &c;
	printf("Dirc de la cadena: %p\n", &c);
	do{
		c = getchar();
	}while(c != '\n');
	printf("Dirc de la cadena: %c\n", *pc);
	printf("Puntero a la cadena: %p\n", pc);
	return pc;
}

//Ejercicio 15
void actualizaredad(struct contacto * edad_nueva){
	//struct contacto *persona1;
	//persona1->edad = 24;
	//printf("Eddad: %ld\n", persona1->edad );
	printf("Ingrese la nueva edad: ");
	scanf("%ld", &edad_nueva->edad);
	//actualizaredad(persona1);
	//impr_contacto(persona1);
}

//Ejercici 16
int prom(contacto_t *conta, int cant){
	conta = realloc(conta, cant);
	int acum = 0, i;
	for (i = 0;i < cant;i++){
		acum+=(conta+i)->edad;
	}
	return acum / cant;
}
void interaccionusser(void){
	char fl;
	int i = 0, N = 5;
	contacto_t *pppl = (contacto_t *)malloc(N*sizeof(contacto_t));
	
	while (fl != 'n'){
		printf("\nIngrese los datos de la persona.\n");
		crearcontacto(pppl+i);
		printf("¿Quiere agregar otros datos de otra persona s/n?");
		scanf("%s", &fl);
		i++;
	}
	i++;
	printf("El promedio de edades de las personas es: %d\n", prom(pppl, i));
	free(pppl);
}


//Ejercicio 17
typedef struct agenda{
	contacto_t ppl;
	int nppl;
}agenda_t;

void prog_agenda(void){
	
}

//Ejercicio 18
void mainfree(){
	int *p = malloc(100);
	free(p);
	free(p);//Tremendo Error!
}

//Ejercicio 19
int apply(int (*fuc)(int a), int n){
	return (*fuc)(n);
}

int pow2(int n){
	return n*n;
}

//Ejercicio 20
void applyin(int (*fuc)(int a), int *b){
	int c = *b;
	*b = (*fuc)(c);
}

//Ejercicio 21
typedef void (*VisitorFunc)(int);

void recorre(VisitorFunc f, int ls[], int n){
	int i;
	for (i = 0; i < n; i++)
		f(ls[i]);
	printf("\n");
}

void printints(int a){
	printf("%d, ", a);
}

//Ejercicio 22
void main(int argc, char *argv[]){
	int i;
	printf("argc: %d\n", argc);
	printf("argv[]: ");
	for(i = 0; i < argc; i++)
		printf("%s, ", argv[i]);
	printf("\n");
}