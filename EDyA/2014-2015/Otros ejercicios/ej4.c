
typedef struct {

  int head_index;
  int info[];
  int next[];
  int used[];
  int n_elems;

} FinList;

FinList* finList_create(int n_elems){
  FinList* l = malloc(sizeof(FinList));
  l->info = (int*) malloc(sizeof(int) * n_elems);
  l->next = (int*) malloc(sizeof(int) * n_elems);
  // used lo inicializamos con 0s
  l->used = (int*) calloc(sizeof(int) * n_elems);
  l->n_elems = n_elems;
  l->head_index = -1;
  return l;
}


int finList_append(FinList* l, int elem){

  // Caso lista vacia
  if (l->head_index == -1) {
    l->head_index = 0;
    l->info[0] = elem;
    l->used[0] = 1;
    l->next[0] = -1;
    return 0;
  }

  // Busco un lugar libre
  int free_pos = 0;
  for ( ; l->used[free_pos] && free_pos < l->size; free_pos++)
    ;
  
  if (free_pos == l->size) {
    // No hay lugar libre
    return -1;
  }

  // Busco el ultimo elemento de la lista
  int last_index = l->head_index;
  for( ; l->next[last_index] != -1; last_index = l->next[last_index])
    ;

  // Inserto el elemento!
  l->next[lastindex] = free_pos;
  l->info[free_pos] = elem;
  l->used[free_pos] = 1;
  l->next[free_pos] = -1;

  return 0;
}
