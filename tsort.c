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

	free(tmp);
}//end swap

void isort(void **a, int start, int num, int sizeA, int (*cmp)(const void *, const void *)){

	int i, j;
	void* tmp = calloc(1, sizeA);

	for(i = num - 2; i >= start; i--)
	{
	memcpy(tmp, (*a + (i * sizeA)), sizeA);

		j = i;

		//move value to the corret spot
		while((cmp((*a + (j * sizeA)), (*a + ((j + 1) * sizeA))) < 0) && j < num - 1){

			swap((*a + (j * sizeA)), (*a + ((j + 1) * sizeA)), sizeA);
			j++;
		}//end inner loop

	memcpy((*a + (j * sizeA)), tmp, sizeA);

	}//end outer loop

	free(tmp);

}//end insert

void merge(void **a, size_t l, size_t m, size_t r, size_t sizeA, int (*cmp)(const void *, const void *)){

	int i = 0, j = 0, k = l;
	int val;
	int n1 = m - l + 1;
	int n2 = r - m;

	void* L = calloc(n1, sizeA);
	void* R = calloc(n2, sizeA);
	
	memcpy(L, (*a + (l * sizeA)), (n1 * sizeA));

	memcpy(R, (*a + ((m + 1) * sizeA)), (n2 * sizeA));

	//compare the values at the array and merge the one with the list
	while(i < n1 && j < n2){
		val = cmp((L + (i * sizeA)), (R + (j * sizeA)));

		//put the smallest value back in the original array
		if(val <= 0){
			memcpy((*a + (k * sizeA)), (L + (i * sizeA)), sizeA);
			i++;
		}
		else
		{
			memcpy((*a + (k * sizeA)), (R + (j * sizeA)), sizeA);
			j++;	
		}

		k++;

	}//end compare loop

	//merge remaander of the arrays
	while(i < n1){
		memcpy((*a + (k * sizeA)), (L + (i * sizeA)), sizeA);
		i++;
		k++;
	}//end merge L array

	//attach R to end of array
	while(j < n1){
		memcpy((*a + (k * sizeA)), (R + (j * sizeA)), sizeA);
		j++;
		k++;
	}//end merge L array

}//end merge

void tsort(void **a, int start, int num, int sizeA, int (*cmp)(const void *, const void *)){
	int m;
	int i;

	//divide up the list into smallest parts
	if((num - start) > 1000)
	{
		m = start + (num - start)/2;
		tsort(a, start, m, sizeA, cmp);
		tsort(a, m + 1, num, sizeA, cmp);
		merge(a, start, m, num, sizeA, cmp);

	}//end division check
	else
	{
		isort(a, start, num, sizeA, cmp);
	}

}//end msort



