#include <stdio.h>
#include "isortl.h"
#include "SList.h"

void printInt(int data, void *extra_data) {
   printf("%d, ", data);
}

int main(int argc, char const *argv[]) {
   SList list = NULL;
   list = slist_append(list,1);
   list = slist_append(list,7);
   list = slist_append(list,-1);
   list = slist_append(list,3);
   list = slist_append(list,5);

   printf("list: < ");
   slist_foreach(list, printInt, NULL);
   printf(" >\n");
   isortl(list);
   printf("isortl(list): < ");
   slist_foreach(list, printInt, NULL);
   printf(" >\n");

   slist_destroy(list);

   return 0;
}
