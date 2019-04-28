#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dyna-array__int.h"

/***************************    AUX   ******************************/
int are_equals(DYNA_ARR *dyn, int *array, unsigned int size)
{
    if(dyn->size != size)
    {
        return -1;
    }
    for(int i = 0; i < size; i++)
    {
        if(dyn->array[i] != array[i])
        {
            return -1;
        }
    }
    return 0;
}
/*************************    END AUX   ****************************/

/**************************    PUSH   ******************************/
char* test_dyna_arr_push__1()
{
    DYNA_ARR dyn;
    dyna_arr_init(&dyn);
    if(dyna_arr_push(&dyn, 10) < 0) return "!!";
    return dyn.array[0] == 10 ? "OK" : "!!";
}

char* test_dyna_arr_push__2()
{
    int test_array[] = {10, 20, 30};
    unsigned size = 3;
    DYNA_ARR dyn;
    dyna_arr_init(&dyn);
    if(dyna_arr_push(&dyn, test_array[0]) < 0) return "!!";
    if(dyna_arr_push(&dyn, test_array[1]) < 0) return "!!";
    if(dyna_arr_push(&dyn, test_array[2]) < 0) return "!!";
    return are_equals(&dyn, test_array, size) == 0 ? "OK" : "!!";
}

char* test_dyna_arr_push__3()
{
    unsigned size = 10;
    DYNA_ARR dyn;
    dyna_arr_init(&dyn);
    int test_array[] = { -7, 1, 5, 132, -5137, 912, -13, -10981, 1923, 67 };
    for(int i = 0; i < size; i++)
        if(dyna_arr_push(&dyn, test_array[i]) < 0) return "!!";
    for(int i = 0; i < size; i++) 
        if(dyn.array[i] != test_array[i]) return "!!";
    return "OK";
}

char* test_dyna_arr_push__4()
{
    DYNA_ARR dyn;
    dyna_arr_init(&dyn);
    for(int i = 0; i < 1000; i++)
        if(dyna_arr_push(&dyn, i * 1000) < 0) return "!!";
    for(int i = 0; i < 1000; i++) 
        if(dyn.array[i] != i * 1000) return "!!";
    return "OK";
}
/************************    END PUSH   ****************************/


/********************    REMOVE ELEMENT AT   ***********************/
char* test_remove_element_at__1()
{
    DYNA_ARR dyn;
    dyna_arr_init(&dyn);
    if(dyna_arr_push(&dyn, 10) < 0) return "!!";
    return dyna_arr_remove_element_at(&dyn, 0) == 0 ? "OK" : "!!";
}

char* test_remove_element_at__2()
{
    DYNA_ARR dyn;
    dyna_arr_init(&dyn);
    if(dyna_arr_push(&dyn, 10) < 0) return "!!";
    if(dyna_arr_push(&dyn, 20) < 0) return "!!";
    if(dyna_arr_push(&dyn, 30) < 0) return "!!";
    return dyna_arr_remove_element_at(&dyn, 1) == 0 ? "OK" : "!!";
}

char* test_remove_element_at__3()
{
    DYNA_ARR dyn;
    dyna_arr_init(&dyn);
    if(dyna_arr_push(&dyn, 10) < 0) return "!!";
    if(dyna_arr_push(&dyn, 20) < 0) return "!!";
    if(dyna_arr_push(&dyn, 30) < 0) return "!!";
    if(dyna_arr_remove_element_at(&dyn, 1) < 0) return "!!";
    int test_array[] = {10, 30};
    return are_equals(&dyn, test_array, 2) == 0 ? "OK" : "!!";
}

char* test_remove_element_at__4()
{
    DYNA_ARR dyn;
    dyna_arr_init(&dyn);
    if(dyna_arr_push(&dyn, 10) < 0) return "!!";
    return dyna_arr_remove_element_at(&dyn, 1) < 0 ? "OK" : "!!";
}

char* test_remove_element_at__5()
{
    DYNA_ARR dyn;
    dyna_arr_init(&dyn);
    if(dyna_arr_push(&dyn, 10) < 0) return "!!";
    return dyna_arr_remove_element_at(&dyn, -1) < 0 ? "OK" : "!!";
}

char* test_remove_element_at__6()
{
    DYNA_ARR dyn;
    dyna_arr_init(&dyn);
    for(int i = 0; i < 1000; i++)
        if(dyna_arr_push(&dyn, i * 1000) < 0) return "!!";
    for(int i = 0; i < 1000; i++) 
        if(dyna_arr_remove_element_at(&dyn, 0) < 0) return "!!";
    return "OK";
}

char* test_remove_element_at__7()
{
    DYNA_ARR dyn;
    dyna_arr_init(&dyn);
    for(int i = 0; i < 1000; i++)
        if(dyna_arr_push(&dyn, i * 1000) < 0) return "!!";
    if(dyna_arr_remove_element_at(&dyn, 999) < 0) return "!!";
    if(dyna_arr_remove_element_at(&dyn, 999) == 0) return "!!";
    return "OK";
}
/******************    END REMOVE ELEMENT AT   *********************/


/***********************    GET INDEX   ****************************/
char* test_dyna_arr_get_index__1()
{
    DYNA_ARR dyn;
    dyna_arr_init(&dyn);
    if(dyna_arr_push(&dyn, 10) < 0) return "!!";
    return dyna_arr_get_index(&dyn, 10) == 0 ? "OK" : "!!";
}

char* test_dyna_arr_get_index__2()
{
    DYNA_ARR dyn;
    dyna_arr_init(&dyn);
    if(dyna_arr_push(&dyn, 10) < 0) return "!!";
    if(dyna_arr_push(&dyn, 20) < 0) return "!!";
    if(dyna_arr_push(&dyn, 30) < 0) return "!!";
    return dyna_arr_get_index(&dyn, 20) == 1 ? "OK" : "!!";
}

char* test_dyna_arr_get_index__3()
{
    DYNA_ARR dyn;
    dyna_arr_init(&dyn);
    int test_array[] = { -7, 1, 5, 132, -5137, 912, -13, -10981, 1923, 67 };
    unsigned int size = 10;
    for(int i = 0; i < size; i++)
        if(dyna_arr_push(&dyn, test_array[i]) < 0) return "!!"; 
    int test_array_indexes[10];
    for(int i = 0; i < size; i++)
        test_array_indexes[i] = dyn.array[dyna_arr_get_index(&dyn, test_array[i])];
    return are_equals(&dyn, test_array_indexes, size) == 0 ? "OK" : "!!";
}

char* test_dyna_arr_get_index__4()
{
    DYNA_ARR dyn;
    dyna_arr_init(&dyn);
    if(dyna_arr_push(&dyn, 10) < 0) return "!!";
    return dyna_arr_get_index(&dyn, 99) == -1 ? "OK" : "!!";
}

char* test_dyna_arr_get_index__5()
{
    DYNA_ARR dyn;
    dyna_arr_init(&dyn);
    int test_array[] = { -7, 1, 5, 132, -5137, 912, -13, -10981, 1923, 67 };
    unsigned int size = 10;
    for(int i = 0; i < size; i++)
        if(dyna_arr_push(&dyn, test_array[i]) < 0) return "!!";
    int test_array_indexes[10];
    for(int i = 0; i < size; i++)
        test_array_indexes[i] = dyn.array[dyna_arr_get_index(&dyn, test_array[i])];
    test_array_indexes[4] = 10;
    return are_equals(&dyn, test_array_indexes, size) < 0 ? "OK" : "!!";
}
/*********************    END GET INDEX   **************************/


/************************    REMOVE   ******************************/
char* test_remove__1()
{
    DYNA_ARR dyn;
    dyna_arr_init(&dyn);
    if(dyna_arr_push(&dyn, 10) < 0) return "!!";
    return dyna_arr_remove(&dyn, 10) == 0 ? "OK" : "!!";
}

char* test_remove__2()
{
    DYNA_ARR dyn;
    dyna_arr_init(&dyn);
    if(dyna_arr_push(&dyn, 10) < 0) return "!!";
    return dyna_arr_remove(&dyn, 20) < 0 ? "OK" : "!!";
}

char* test_remove__3()
{
    DYNA_ARR dyn;
    dyna_arr_init(&dyn);
    if(dyna_arr_push(&dyn, 10) < 0) return "!!";
    if(dyna_arr_push(&dyn, 20) < 0) return "!!";
    if(dyna_arr_push(&dyn, 30) < 0) return "!!";
    return dyna_arr_remove(&dyn, 20) == 0 ? "OK" : "!!";
}

char* test_remove__4()
{
    DYNA_ARR dyn;
    dyna_arr_init(&dyn);
    if(dyna_arr_push(&dyn, 10) < 0) return "!!";
    if(dyna_arr_push(&dyn, 20) < 0) return "!!";
    if(dyna_arr_push(&dyn, 30) < 0) return "!!";
    return dyna_arr_remove(&dyn, 30) == 0 ? "OK" : "!!";
}
/**********************    END REMOVE   ****************************/


void test_push()
{
    printf("\n\t+----------  TEST PUSH  ----------+\n");
    printf("\t|      Test 1     |       %s      |\n", test_dyna_arr_push__1());
    printf("\t|      Test 2     |       %s      |\n", test_dyna_arr_push__2());
    printf("\t|      Test 3     |       %s      |\n", test_dyna_arr_push__3());
    printf("\t|      Test 4     |       %s      |\n", test_dyna_arr_push__4());
    printf("\t+--------  END TEST PUSH  --------+\n\n");
}

void test_remove_element_at()
{
    printf("\n\t+---  TEST REMOVE ELEMENT AT   ---+\n");
    printf("\t|      Test 1     |       %s      |\n", test_remove_element_at__1());
    printf("\t|      Test 2     |       %s      |\n", test_remove_element_at__2());
    printf("\t|      Test 3     |       %s      |\n", test_remove_element_at__3());
    printf("\t|      Test 4     |       %s      |\n", test_remove_element_at__4());
    printf("\t|      Test 5     |       %s      |\n", test_remove_element_at__5());
    printf("\t|      Test 6     |       %s      |\n", test_remove_element_at__6());
    printf("\t|      Test 7     |       %s      |\n", test_remove_element_at__7());
    printf("\t+-  END TEST REMOVE ELEMENT AT   -+\n\n");
}

void test_get_index_of()
{
    printf("\n\t+-----  TEST GET INDEX OF   ------+\n");
    printf("\t|      Test 1     |       %s      |\n", test_dyna_arr_get_index__1());
    printf("\t|      Test 2     |       %s      |\n", test_dyna_arr_get_index__2());
    printf("\t|      Test 3     |       %s      |\n", test_dyna_arr_get_index__3());
    printf("\t|      Test 4     |       %s      |\n", test_dyna_arr_get_index__4());
    printf("\t|      Test 5     |       %s      |\n", test_dyna_arr_get_index__5());
    printf("\t+--------  END TEST PUSH  --------+\n\n");
}

void test_remove()
{
    printf("\n\t+--------  TEST REMOVE   ---------+\n");
    printf("\t|      Test 1     |       %s      |\n", test_remove__1());
    printf("\t|      Test 2     |       %s      |\n", test_remove__2());
    printf("\t|      Test 3     |       %s      |\n", test_remove__3());
    printf("\t|      Test 4     |       %s      |\n", test_remove__4());
    printf("\t+-------  END TEST REMOVE  -------+\n\n");
}

void main ()
{
    test_push();
    test_remove_element_at();
    test_get_index_of();
    test_remove();
}