/*
	This module takes a sotred array a
	and adds an element b to the array 
	in it's proper place.  Then, it 
	returns a pointer to that new array.
	The module requires five (5)
	perameters.  the sorted array, a;
	the element to be inserted, b;
	the number of elements in a, num; 
	the size of each element, sizeA;
	and finally, a compare function,
	cmp.
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "andy.h"

void insert(void **a, void* b, size_t num, size_t sizeA, int (*cmp)(const void *, const void *)){

	int i = 0, j = 0;
	int val = 0;

	//fine the spot where data should be entered
	while((val != 1) && (i < num)){
		//d = (Data*) ptr[i];
		val = cmp((*a + (i * sizeA)), b);
		if(val == 1){
			//printf("i: %d val: %p\n", i, &val);
		}
		i++;
	}//end find loop

	//make more space for the new element
	(*a) = realloc((*a), (num * sizeA + sizeA));


	//if that space exisis, move the remaining data and insert the element.


	j = num;

	while(j >= (i - 1)){
		memcpy((*a + ((j + 1) * sizeA)), (*a + (j * sizeA)), sizeA);
		j--;
	}//end while loop

	j++;
	
	memcpy((*a + (j * sizeA)), b, sizeA);

/*
	for(i = 0; i < num; i++)
		printf("%p\n", (char*)a[i]);
*/
}//end insert