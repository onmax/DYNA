#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dyna-array__int.h"

int dyna_arr_init(DYNA_ARR *dyn)
{
	dyn->array = (void *)malloc(0);
	dyn->size = 0;
	return 0;
}

int dyna_arr_push(DYNA_ARR *dyn, int element)
{
	dyn->size++;
    dyn->array = (int *)realloc(dyn->array, dyn->size * sizeof(dyn->array));
	if (dyn->array == NULL)
	{
        return -1;
	}
		
    dyn->array[dyn->size - 1] = element;
    return 0;
}

int dyna_arr_remove_element_at(DYNA_ARR *dyn, unsigned int index)
{
	if(dyn->size <= index) {
		return -1;
	}

    dyn->size--;
    int *temp = (int *)malloc(dyn->size * sizeof(*dyn->array));

	if(temp == NULL)
	{
		return -2;
	}
    memmove(
        temp,
        dyn->array,
        (index + 1) * sizeof(*dyn->array));

    memmove(
        temp + index,
        dyn->array + index + 1,
        (dyn->size - index) * sizeof(*dyn->array));

    free(dyn->array);
    dyn->array = temp;
    return 0;
}

int dyna_arr_get_index(DYNA_ARR *dyn, int element)
{
	int i;
	for(i = 0; i < dyn->size; i++)
	{
		if(dyn->array[i] == element) {
			return i;
		}
	}
	return -1;
}

int dyna_arr_remove(DYNA_ARR *dyn, int element)
{
	unsigned int index;
	if((index = dyna_arr_get_index(dyn, element)) < 0)
	{
		return -1;
	}

	if(dyna_arr_remove_element_at(dyn, index) == 0)
	{
		return 0;
	}

	return -2;
}

void dyna_arr_print(DYNA_ARR *dyn)
{
	int i;
	printf("Size: %d -> ", dyn->size);
	for(i = 0; i < dyn->size; i++) {
		printf(" %d ", dyn->array[i]);
	}
	printf("\n");
}