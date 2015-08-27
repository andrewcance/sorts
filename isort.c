#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "andy.h"

//swap two array elements
void swap(void* a, void* b, size_t sizeA){
	void* tmp = calloc(1, sizeA);

	tmp = memcpy(tmp, a, sizeA);
	a = memcpy(a, b, sizeA);
	b = memcpy(b, tmp, sizeA);
}//end swap

void isort(void **a, size_t num, size_t sizeA, int (*cmp)(const void *, const void *)){

	int i = 0, j = 0;
	int val = 0;
	void* tmp = calloc(1, sizeA);

	for(i = num - 2; i >= 0; i--)
	{
		tmp = memcpy(tmp, (a + (i * sizeA)), sizeA);
		
		j = i;

		val = cmp((*a + (j * sizeA)), (*a + ((j + 1) * sizeA)));

		//move value to the corret spot
		while(val < 0 && j < num - 1){
			swap((*a + (j * sizeA)), (*a + ((j + 1) * sizeA)), sizeA);
			val = cmp((*a + (j * sizeA)), (*a + ((j + 1) * sizeA)));
			j++;
		}//end inner loop

	memcpy((a + (j * sizeA)), tmp, sizeA);

	}//end outer loop

}//end insert