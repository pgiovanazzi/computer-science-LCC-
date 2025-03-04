#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "AStack.h"


int main(int argc, char const *argv[]){
	AStack *p = astack_create();

	astack_push(p,10);
	astack_push(p,20);
	astack_push(p,30);
	astack_push(p,40);
	astack_push(p,50);
	astack_push(p,60);
	astack_push(p,70);
	astack_push(p,80);

	astack_print(p);
	puts("");

	astack_reverse(p);
	astack_print(p);
	puts("");
	

	astack_destroy(p);
	return 0;
}