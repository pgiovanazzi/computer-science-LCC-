#include "ssortl.h"
#include "SList.h"
#include <stdlib.h>

SList* ssortl(SList *list, VisitorFuncInt visit, int* extra_data)
{
	SList *lt = NULL;

	while(list){
		*extra_data = slist_data(list);
		slist_foreach(list, visit, extra_data);
		list = slist_remove(list, slist_index(list, *extra_data));
		lt = slist_append(lt, *extra_data);
	}

	list = lt;
	return list;
}