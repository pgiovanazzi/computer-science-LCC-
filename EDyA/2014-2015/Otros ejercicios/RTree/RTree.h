#ifndef RTREE_H
#define RTREE_H

/* SList Declarations */
#define slist_data(l)       (l)->data
#define slist_next(l)       (l)->next

typedef void (*VisitorFuncInt) (void* data, void *extra_data);

/**
 * Los campos son privados, y no deberian ser accedidos
 * desde el codigo cliente.
 */
typedef struct _SList {
        void          *data;
        struct _SList *next;
} SList;


/* Type Declarations */
typedef void (*rtree_visitor_func)(void* data, void* extra_data);

typedef struct RTree_ {
  void  *data;
  SList *children;
} RTree;


/* Prototypes */
RTree* createNode(void* data);
void   rtreeAddChild(RTree* parent, RTree* child);
void   rtreeForeach(RTree*, rtree_visitor_func, void*);

SList *slist_append(SList *list, void* data);



#endif
