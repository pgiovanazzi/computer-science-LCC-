#include <stdlib.h>
#include "ASList.h"

 ASList aslist_create(){
	 ASList newList = malloc(sizeof(ArrSList));
	 newList->data = malloc(sizeof(int)*STORE);
	 aslist_len(newList) = -1;
	 return newList;
 }

ASList aslist_append(ASList list, int data){
	if (aslist_len(list) + 1 > STORE) {
		STORE *=2;
		list->data = realloc(list->data,sizeof(int)*STORE);
	}
	if (aslist_len(list) == -1) {
		aslist_data(list, ++aslist_len(list)) = data;
		aslist_len(list)++;
		return list;
	}
	aslist_data(list,aslist_len(list)++) = data;
	return list;
}

ASList aslist_insert(ASList list, int data, int idx){
	if (aslist_len(list) + 1 > STORE) {
		STORE *=2;
		list->data = realloc(list->data,sizeof(int)*STORE);
	}
	if(idx < 0 || idx > aslist_len(list))
		return aslist_nil();
	if(idx == aslist_len(list)){
		aslist_len(list)++;
		aslist_data(list,idx) = data;
		return list;
	}
	int i = idx, tmp[aslist_len(list) - idx];
	for(; i < aslist_len(list); i++)
		tmp[i-idx] = aslist_data(list,i);
	aslist_len(list)++;
	aslist_data(list,idx) = data;
	for(i = idx + 1; i < aslist_len(list); i++)
		aslist_data(list, i) = tmp[i - 1 - idx];

	return list;
}

void aslist_destroy(ASList list){
	free(list->data);
	free(list);
}

void aslist_foreach(ASList list, VisitorFuncInt visit, void *extra_data){
	int i = 0;
	for(; i < aslist_len(list); i++)
		visit(aslist_data(list,i),extra_data);
}
