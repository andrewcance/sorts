#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "andy.h"

int lsearch(void **a, void* b, size_t num, size_t sizeA, int (*cmp)(const void *, const void *)){

	int i = 0;
	int val = 0;
	bool isFound = FALSE;

	while((!isFound) && (i < num)){

		//checi if the element is found
		if(val == 1){
			isFound = TRUE;
		}else{
			i++;	
			val = cmp((*a + (i * sizeA)), b);
		}//end check if isFound		
	}//end find loop

	//if not found, return -1
	if(!isFound){
		i = -1;
	}
	else{
		i--;
	}//end error check
	
	printint("in lsearch i: ", i, ".");
	return i;

}//end insert