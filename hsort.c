#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "andy.h"

//swap two array elements
void swap(void* a, void* b, size_t sizeA){
	void* temp = calloc(1, sizeA);

	temp = memcpy(temp, a, sizeA);
	a = memcpy(a, b, sizeA);
	b = memcpy(b, temp, sizeA);
}//end swap

void siftdown(void **a, size_t start, size_t end, size_t sizeA, int (*cmp)(const void *, const void *))
{
	int root = start;
	int val;
	int child = 2 * root + 1;

    while(root * 2 + 1 < end)
    {

		val = cmp((*a + (child * sizeA)), (*a + ((child + 1) * sizeA)));

        if ((child + 1 < end) && (val < 0)) {
            child += 1;
        }

		val = cmp((*a + (root * sizeA)), (*a + (child * sizeA)));

        if(val < 0) 
        {
            swap((*a + (root * sizeA)), (*a + (child * sizeA)), sizeA);
            root = child;

			//val = cmp((*a + (root * sizeA)), (*a + (child * sizeA)));
        }//end if else
        else//else break out the lloop
        	return;
    }//end while loop

}//end siftdown

void heapify(void **a, size_t num, size_t sizeA, int (*cmp)(const void *, const void *))
{
	int start;

	//mobe through the array and heapify the values
	for(start = (num - 2)/2; start >= 0; start--){
		siftdown(a, start, num, sizeA, cmp);
	}//end first heapify loop

}//end heapify

void hsort(void **a, size_t num, size_t sizeA, int (*cmp)(const void *, const void *)){

	int end;

	heapify(a, num, sizeA, cmp);

	//sort loop
	for(end = (num - 1); end > 0; end--)
	{
		swap((*a + (end * sizeA)), *a, sizeA);
		siftdown(a, 0, end, sizeA, cmp);
	}//end sort loop

}//end heapsort