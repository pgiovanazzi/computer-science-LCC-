#ifndef __RTree_H__
#define __RTree_H__

typedef struct _SList{
	void data;
	struct _SList *node;
} SList;

typedef struct _RTree{
	void data;
	SList *node;
} RTree;


#endif