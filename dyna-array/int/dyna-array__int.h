#ifndef __DYNAARRINT_H__
#define __DYNAARRINT_H__

typedef struct
{
	int *array;
	unsigned int size;
} DYNA_ARR;

/*
 * Function: dyna_arr_init
 * ----------------------------
 *   Initialize dynamic array of integers empty
 *
 *   dyn: Memory address where dynamic array is located
 *
 *   returns: 0 if success
 * 			  negative number if failure
 */
int dyna_arr_init(DYNA_ARR *dyn);


/*
 * Function: dyna_arr_push
 * ----------------------------
 *   Appends the specified element to the end of the array.
 *
 *   dyn: Memory address where dynamic array is located
 *   element: element to be appended to this list
 *
 *   returns: 
 * 				0 if success
 * 			  	negative number if failure
 */
int dyna_arr_push(DYNA_ARR *dyn, int element);

/*
 * Function: dyna_arr_get_index
 * ----------------------------
 *   Returns the index of the first occurrence of the specified element in this list, or -1 if array does not contain the element.
 *
 *   dyn: Memory address where dynamic array is located
 *   element: Element that is going to be inserted
 *
 *   returns: 
 * 				0 if success
 * 			  	negative number if failure
 */
int dyna_arr_get_index(DYNA_ARR *dyn, int element);

/*
 * Function: dyna_arr_remove
 * ----------------------------
 *   Removes the first occurrence of the specified element from array, if it is present.
 *
 *   dyn: Memory address where dynamic array is located
 *   element: element to be removed from this array, if present
 *
 *   returns: 
 * 				0 if success
 * 			  	-1 if failure
 * 				-2 if element not found
 */
int dyna_arr_remove(DYNA_ARR *dyn, int element);

/*
 * Function: dyna_arr_remove
 * ----------------------------
 *   Removes the element at the specified position in this list. Shifts any subsequent elements to the left (subtracts one from their indices).
 *
 *   dyn: Memory address where dynamic array is located
 *   index: the index of the element to be removed
 *
 *   returns: 
 * 				0 if success
 * 				1 if element not found
 * 			  	-1 if failure
 */
int dyna_arr_remove_element_at(DYNA_ARR *dyn, unsigned int index);

/*
 * Function: dyna_arr_print
 * ----------------------------
 *   Prints size and elements of the array
 *
 *   dyn: Memory address where dynamic array is located
 */
void dyna_arr_print(DYNA_ARR *dyn);

#endif