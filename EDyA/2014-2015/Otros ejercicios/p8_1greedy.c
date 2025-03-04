#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int size;
    int number;
}_file;

int cmpFiles_a(const void *p, const void *q)
{
    _file *fst = (_file *)p;
    _file *snd = (_file *)q;
    
    return fst->size - snd->size;
}

void solve_item_a(_file files[], int sz, int capacity) {
    int cant_files = 0;
    int memory_used=0;
    //int previous_file;
    int i;
    
    printf("\nOrdenamos ficheros de menor a mayor tamanio: \n");
    
    qsort(files, sz, sizeof(_file), cmpFiles_a);
    
    for(i=0; i<sz;i++) {
        printf("file %d with size %d \n", files[i].number, files[i].size);
    }
    
    
    for (i = 0; i < sz; i++) {
        if (memory_used + files[i].size <= capacity) {
            printf(" File %d must be saved in disquete\n", files[i].number);
            memory_used+=files[i].size;
            cant_files++;
        }
    }
    
    printf(".\nMemoria Utilizada: %d - Cantidad de ficheros guardados: %d\n", memory_used, cant_files);
}

int cmpFiles_b(const void *p, const void *q)
{
    _file *fst = (_file *)p;
    _file *snd = (_file *)q;
    
    return (-1)*(fst->size - snd->size);
}



void solve_item_b(_file files[], int sz, int capacity) {
    int cant_files = 0;
    int memory_used=0;
    //int previous_file;
    int i;
    
    printf("\nOrdenamos ficheros de mayor a menor tamanio: \n");
    
    qsort(files, sz, sizeof(_file),cmpFiles_b);
    
    for(i=0; i<sz;i++) {
        printf("file %d with size %d \n", files[i].number, files[i].size);
    }
    
    
    for (i = 0; i < sz; i++) {
        if (memory_used + files[i].size <= capacity) {
            printf(" File %d must be saved in disquete\n", files[i].number);
            memory_used+=files[i].size;
            cant_files++;
        }
    }
    
    printf(".\nMemoria Utilizada: %d - Cantidad de ficheros guardados: %d\n", memory_used, cant_files);
}

int main(void)
{
    int number_of_files;
    _file *files;
    int cap;
    int i;
    
    printf("Insert number of files: ");
    scanf("%d", &number_of_files);
	files = malloc(sizeof(_file) * number_of_files);
    
    printf("Capacidad del disquete: ");
    scanf("%d",&cap);
    
    for (i = 0; i < number_of_files; i++) {
        files[i].number=i;
        printf("file %d has size: ",files[i].number),
        scanf("%d",&files[i].size);
    }
    
    for(i=0; i<number_of_files;i++) {
        printf("file %d with size %d \n", files[i].number, files[i].size);
    }
    
	solve_item_a(files, number_of_files,cap);
    
    solve_item_b(files, number_of_files,cap);
    
	return 0;
}
