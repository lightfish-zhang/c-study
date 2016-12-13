#include <stdio.h>
#include "arr.c"

int main(int argc,char * argv[])
{
    SA arr;
    arr_init(&arr,20);
    arr_print(&arr);
    arr_append(&arr,1);
    arr_append(&arr,2);
    arr_append(&arr,4);
    arr_print(&arr);
    arr_insert(&arr,2,3);
    arr_print(&arr);
    int tmp;
    arr_delete(&arr,1,&tmp);
    arr_print(&arr);
    printf("%d\n",tmp);
    arr_append(&arr,5);
    arr_append(&arr,6);
    arr_print(&arr);
    arr_inversion(&arr);
    arr_print(&arr);

    srand(time(0));
    arr_append(&arr,rand() % 10);
    arr_append(&arr,rand() % 10);
    arr_append(&arr,rand() % 10);
    arr_append(&arr,rand() % 10);
    arr_append(&arr,rand() % 10);
    arr_append(&arr,rand() % 10);
    arr_print(&arr);
    arr_sort(&arr);
    arr_print(&arr);


    arr_destory(&arr);
    return 0;
}