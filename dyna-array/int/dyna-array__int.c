#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIBRARY_NAME "DYNA_ARR_INT"

const char *ERR_OUT_OF_RANGE = "Index out of range in the array\n";
const char *ERR_ELEMENT_NOT_IN_LIST = "Element is not in the array\n";

typedef struct{
	int *array;
	unsigned int size;
} DYNA_ARR;

void dyna_arr_init(DYNA_ARR *dyn){
	dyn->array = (void *)malloc(0);
	dyn->size = 0;
}

/** Pushes the element in the array
 *  returns 0 if success or -1 if failure
 */
int dyna_arr_push(DYNA_ARR *dyn, int element){
	dyn->size++;
    dyn->array = (int *)realloc(dyn->array, dyn->size * sizeof(dyn->array));
    if (!dyn->array[dyn->size - 1])
        return -1;
    dyn->array[dyn->size - 1] = element;
    return 0;
}

/** Remove the element in a specific index
 *  returns 0 if success or -1 if failure
 */
int dyna_arr_remove_element_at(DYNA_ARR *dyn, int index_to_remove){
	if(dyn->size < index_to_remove) {
		fprintf(stderr, "%s: %s", LIBRARY_NAME, ERR_OUT_OF_RANGE);
		return -1;
	}

    dyn->size--;
    int *temp = (int *)malloc(dyn->size * sizeof(*dyn->array));

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

/** Retrieves the index of an element if it exist
 *  returns the index of the element or -1 if the
 *  element doesn't exist in the array
 */
int dyna_arr_get_index(DYNA_ARR *dyn, int element){
	int i;
	for(i = 0; i < dyn->size; i++){
		if(dyn->array[i] == element) {
			return i;
		}
	}
	return -1;
}

/** TODO
 */
void dyna_arr_remove(DYNA_ARR *dyn, int element){
	int index;
	if((index = dyna_arr_get_index(dyn, element)) < 0){
		fprintf(stderr, "%s: %s", LIBRARY_NAME, ERR_ELEMENT_NOT_IN_LIST);
		return;
	}
}

/** Prints all elements in the array
 */
void dyna_arr_print(DYNA_ARR *dyn){
	int i;
	printf("Size: %d -> ", dyn->size);
	for(i = 0; i < dyn->size; i++) {
		printf(" %d ", dyn->array[i]);
	}
	printf("\n");
}

int dyna_arr_test(){
	DYNA_ARR dyna;
	dyna_arr_init(&dyna);
	dyna_arr_push(&dyna, 10);
	dyna_arr_push(&dyna, 20);
	dyna_arr_push(&dyna, 30);
	dyna_arr_print(&dyna);
	dyna_arr_remove_element_at(&dyna, 2);
	dyna_arr_print(&dyna);
}

// MAIN IS ONLY FOR DEV
// TODO
//	- Add testing
//	- Add comments
void main(){
	dyna_arr_test();
}
