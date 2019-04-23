#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIBRARY_NAME "DYNA_ARR_STRING"

const char *ERR_OUT_OF_RANGE = "Index out of range in the array\n";
const char *ERR_ELEMENT_NOT_IN_LIST = "Element is not in the array\n";

typedef struct
{
	char **array;
	unsigned int size;
} DYNA_ARR;

void dyna_arr_init(DYNA_ARR *dyn)
{
	dyn->array = (char **)malloc(0);
	dyn->size = 0;
}

int dyna_arr_push(DYNA_ARR *dyn, char *element)
{
	dyn->size++;
    dyn->array = (char **)realloc(dyn->array, dyn->size * sizeof(*dyn->array));
	dyn->array[dyn->size - 1] = (char *)malloc(strlen(element) * sizeof(*dyn->array[dyn->size - 1]));

    if (!dyn->array[dyn->size - 1])
        return -1;
    
    strcpy(dyn->array[dyn->size - 1], element);
    return 0;
}

int dyna_arr_remove_element_at(DYNA_ARR *dyn, unsigned int index_to_remove)
{
	if(dyn->size <= index_to_remove || index_to_remove < 0) {
		fprintf(stderr, "%s: %s", LIBRARY_NAME, ERR_OUT_OF_RANGE);
		exit(-1);
	}
    dyn->size--;
    char **temp = (char **)malloc(dyn->size * sizeof(*dyn->array));

    memmove(
        temp,
        dyn->array,
        (index_to_remove + 1) * sizeof(*dyn->array));

    memmove(
        temp + index_to_remove,
        dyn->array + index_to_remove + 1,
        (dyn->size - index_to_remove) * sizeof(*dyn->array));

    free(dyn->array);
    dyn->array = temp;
    return 0;
}

int dyna_arr_get_index(DYNA_ARR *dyn, char *element)
{
	int i;
	for(i = 0; i < dyn->size; i++)
	{
		if(strcmp(dyn->array[i], element) == 0) {
			return i;
		}
	}
	return -1;
}

void dyna_arr_remove(DYNA_ARR *dyn, char *element)
{
	int index;
	if((index = dyna_arr_get_index(dyn, element)) < 0)
	{
		fprintf(stderr, "%s: %s", LIBRARY_NAME, ERR_ELEMENT_NOT_IN_LIST);
		return;
	}
	dyna_arr_remove_element_at(dyn, index);
}

void dyna_arr_print(DYNA_ARR *dyn)
{
	int i;
	printf("Size: %d -> ", dyn->size);
	for(i = 0; i < dyn->size; i++) {
		printf(" %s ", dyn->array[i]);
	}
	printf("\n");
}

int dyna_arr_test()
{
	DYNA_ARR dyna;
	dyna_arr_init(&dyna);
	dyna_arr_push(&dyna, "pedro");
	dyna_arr_push(&dyna, "juan");
	dyna_arr_push(&dyna, "maria");
	dyna_arr_push(&dyna, "victor");
	dyna_arr_print(&dyna);
	dyna_arr_remove(&dyna, "pedro");
	dyna_arr_print(&dyna);
}

// MAIN IS ONLY FOR DEV
// TODO
//	- Add testing
//	- Add comments
void main()
{
	dyna_arr_test();
}