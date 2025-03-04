#include <stdio.h>
#include <stdlib.h>

#define DISK	1500

typedef struct{
	int l;
	char name[13];
} file;

int cmpFile(const void *p, const void *q)
{
	file *fst = (file *)p;
	file *snd = (file *)q;

	return fst->l - snd->l;
}

void solve(file f[], int sz) {
	int possible_files = 0;
	int i = 0, d = 0;

	printf("Archivos elegidos: ");

	qsort(f, sz, sizeof(file), cmpFile);

	for (i = 0; i < sz; i++) {
		if (d + f[i].l > DISK)
			break;
		printf("%s ", f[i].name);
		possible_files++;
		d += f[i].l;
	}

	printf(".\nTotal de Archivos máximos: %d.\n", possible_files);
}

int main(int argc, char const *argv[])
{
	int number_of_files, i;
	file *fs;

	printf("Ingrese la cantidad de archivos: ");
	scanf("%d", &number_of_files);
	fs = malloc(sizeof(file) * number_of_files);

	for(i = 0; i < number_of_files; i++){
		printf("Tamaño de archivo y nombre:\n");
		scanf("%d%s", &fs[i].l, &fs[i].name);
	}
	
	solve(fs, number_of_files);

	return 0;
}