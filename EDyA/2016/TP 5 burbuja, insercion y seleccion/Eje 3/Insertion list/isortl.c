#include "isortl.h"

#define SWAP(a,b)     {int t = a; a = b; b = t;}

void isortl(SList list){
   SList node = list;
   while (node) {
      SList nodePrev = node;
      SList nodeTarget = slist_next(nodePrev);
      while (nodeTarget) {
         if(slist_data(nodePrev) > slist_data(nodeTarget))
            SWAP(slist_data(nodePrev),slist_data(nodeTarget))
         else
            break;
         nodeTarget = nodePrev;
         nodePrev = list;
         if(nodeTarget == nodePrev) break;
         while (slist_next(nodePrev) != nodeTarget)
            nodePrev = slist_next(nodePrev);
      }
      node = slist_next(node);
   }
}
