#include "SList.h"

void swap(int *data1,int *data2){
  int t =  *data1;
  *data1 = *data2;
  *data2 = t;
}

void ssortl(SList list){
  SList node = list;
  SList nodePrev = list;
  SList nodeDataMin = list;
  while (nodePrev) {
    node = slist_next(nodePrev);
    while (node) {
      if(slist_data(nodeDataMin) > slist_data(node))
        nodeDataMin = node;
      node = slist_next(node);
    }
    swap(&slist_data(nodeDataMin),&slist_data(nodePrev));
    nodePrev = slist_next(nodePrev);
    nodeDataMin = nodePrev;
  }
}
