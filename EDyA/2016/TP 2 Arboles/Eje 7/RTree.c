#include <stdlib.h>
#include "RTree.h"
#include "GList.h"

RTree rtree_createNode(void *data){
  RTree newNode = malloc(sizeof(RTNode));
  rtree_data(newNode) = data;
  rtree_children(newNode) = rtree_nil();
  return newNode;
}

void rtree_addChild(RTree rt, RTree children){
  rtree_children(rt) = glist_append(rtree_children(rt),children);
  return;
}

void rtree_foreach(RTree rt, rtree_visitor_func visit, void *extra_data){
  if(rt){
    visit(rtree_data(rt),extra_data);
    void *nodel = rtree_children(rt);
    while(nodel){
      rtree_foreach(glist_data((GList)nodel),visit,extra_data);
      nodel = glist_next((GList)nodel);
    }
  }
  return;
}
