#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	void **array;
	unsigned int size;
	size_t allocated;
} DYNA_ARR;

void dyna_arr_init(DYNA_ARR *dyn)
{
	dyn->array = (void *)malloc(0);
	dyn->size = 0;
	dyn->allocated = 0;
}

int dyna_arr_push(DYNA_ARR *dyn, void *element, size_t length)
{
	void **temp = realloc(dyn->array, (length + dyn->allocated));
	if(!temp)
	{
		printf("ERROR ");
		return -1;
	}
	dyn->array = temp;
	dyn->array[dyn->size] = element;
	dyn->size++;
	dyn->allocated += length;
	return 0;
}

void dyna_arr_print_str(DYNA_ARR *dyn)
{
	int i;
	printf("Size: %d -> ", dyn->size);
	for(i = 0; i < dyn->size; i++) {
		printf(" %s ", (char *)dyn->array[i]);
	}
	printf("\n");
}

void dyna_arr_print_int(DYNA_ARR *dyn)
{
	// This function currently doesnt work
	// We need to cast to int
	int i;
	printf("Size: %d -> ", dyn->size);
	for(i = 0; i < dyn->size; i++) {
		printf(" %d ", &dyn->array[i]);
	}
	printf("\n");
}

int dyna_arr_test()
{
	DYNA_ARR dyn;
	dyna_arr_init(&dyn);
	dyna_arr_push(&dyn, "HOLA1", strlen("HOLA1"));
	dyna_arr_push(&dyn, "HOLA2", strlen("HOLA2"));
	dyna_arr_push(&dyn, "HOLA3", strlen("HOLA3"));
	dyna_arr_print_str(&dyn);

	DYNA_ARR dyna;
	dyna_arr_init(&dyna);
	int i = 10;
	dyna_arr_push(&dyna, &i, sizeof(int));
	dyna_arr_push(&dyna, &i, sizeof(int));
	dyna_arr_push(&dyna, &i, sizeof(int));
	dyna_arr_print_int(&dyna);
	
}

/** TODO:
 *  	- indexOf
 *  	- printArray
 *    	- change names to "push" and "pop"
 * 	- add comments
 */


// MAIN IS ONLY FOR DEV
void main()
{
	dyna_arr_test();
}