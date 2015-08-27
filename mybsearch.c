#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "andy.h"

int mybsearch(void **a, void* b, size_t sizeA, size_t low, size_t high, int (*cmp)(const void *, const void *)){
	size_t mid;
	int val;

	if(high < low){
		return -1;
	}

	mid = avg(low, high);
	val = cmp((*a + (mid * sizeA)), b);

	if(val > 0){
		return mybsearch(a, b, sizeA, low, (mid - 1), cmp);
	}
	else if(val < 0)
	{
		return mybsearch(a, b, sizeA, (mid + 1), high, cmp);
	}
	else
	{
		return mid;
	}

}//end insert