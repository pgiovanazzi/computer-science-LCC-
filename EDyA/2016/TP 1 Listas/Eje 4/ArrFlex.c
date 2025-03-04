#include<stdlib.h>
#include "ArrFlex.h"

AF af_append(AF arr, int data){
	if(af_len(arr) == -1){
		af_data(arr, ++af_len(arr)) = data;
		af_len(arr)++;
		return arr;
	}
	af_data(arr,af_len(arr)++) = data;
	return arr;
}

AF af_insert(AF arr, int data, int idx){
	if(idx < 0 || idx > af_len(arr))
		return af_nil();
	if(idx == af_len(arr)){
		af_len(arr)++;
		af_data(arr,idx) = data;
		return arr;
	}
	int i = idx, tmp[af_len(arr) - idx];
	for(; i < af_len(arr); i++)
		tmp[i-idx] = af_data(arr,i);
	af_len(arr)++;
	af_data(arr,idx) = data;
	for(i = idx + 1; i < af_len(arr); i++)
		af_data(arr, i) = tmp[i - 1 - idx];
	
	return arr;
}

void af_destroy(AF arr){
	af_len(arr) = -1;
	free(arr);
}

void af_foreach(AF arr, VisitorFuncInt visit, void *extra_data){
	int i = 0;
	for(; i < af_len(arr); i++)
		visit(af_data(arr,i),extra_data);
}
