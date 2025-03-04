#include "isortl.h"
#include <stdlib.h>

void isortl(SList *list)
{
	SList * node, * listTMP = NULL;
	int idx;

	while(list){
		node = listTMP;
		for(idx = 0; idx < slist_length(listTMP); idx++){
			if(slist_data(list) <= slist_data(node)){
				listTMP = slist_insert(listTMP, slist_data(list), idx);
				break;
			}
			node = slist_next(node);
		}
		if(!node)
			listTMP = slist_append(listTMP, slist_data(list));
		list = slist_remove(list, 0);
	}

	list = listTMP;
	return;
}