#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "arr.h"

void arr_init(struct Arr * pArr , int max)
{
    pArr->pBase = (int *)malloc(sizeof(int) * max);
    if(NULL == pArr->pBase){
        fprintf(stdout,"malloc error\n");
        exit(-1);
    }else{
        pArr->max = max;
        pArr->length = 0;
    }
}

void arr_print(struct Arr * pArr)
{
    if(arr_is_empty(pArr)){
        fprintf(stdout,"Arr is empty\n");
    }else{
        int i;
        for(i=0; i<pArr->length ; i++){
            fprintf(stdout,"%d ",pArr->pBase[i]);
        }
        fprintf(stdout,"\n");
    }
}

int arr_is_empty(struct Arr * pArr){
    return (0==pArr->length);
}

int arr_is_full(struct Arr * pArr){
    return (pArr->length == pArr->max);
}

int arr_append(struct Arr * pArr , int value){
    if(arr_is_full(pArr)){
        return 0;
    }
    pArr->pBase[pArr->length ++] = value;
    return 1;
}

int arr_insert(struct Arr * pArr , int index , int value){
    if(arr_is_full(pArr)){
        return 0;
    }
    if(index <0 || index > pArr->max ){
        return 0;
    }
    int i;
    for( i=pArr->length ; i > index ; i-- ){
        pArr->pBase[i] = pArr->pBase[i-1]; 
    }
    pArr->pBase[index] = value;
    pArr->length ++;
    return 1;
}

int arr_delete(struct Arr * pArr , int index , int * pValue){
    if(arr_is_empty(pArr)){
        return 0;
    }
    if(index <0 || index > pArr->max ){
        return 0;
    }
    *pValue = pArr->pBase[index];
    int i;
    for( i=index ; i < pArr->length ; i++ ){
        pArr->pBase[i] = pArr->pBase[i+1]; 
    }
    pArr->length --;
    return 1;
}

void arr_inversion(struct Arr * pArr){
    int i = 0;
    int j= pArr->length -1;
    int tmp;
    while(i<j){
        tmp = pArr->pBase[i];
        pArr->pBase[i] = pArr->pBase[j];
        pArr->pBase[j] = tmp;
        i++;
        j--;
    }
}

void arr_sort(struct Arr * pArr){
    int i , j , tmp;
    for(i=0 ; i < pArr->length ; i++ ){
        for( j=i+1 ; j < pArr->length ; j++ ){
            if( pArr->pBase[i] > pArr->pBase[j] ){
                tmp = pArr->pBase[i];
                pArr->pBase[i] = pArr->pBase[j];
                pArr->pBase[j] = tmp;
            }
        }
    }
}

void arr_destory(struct Arr * pArr){
    free(pArr->pBase);
    pArr->pBase = NULL;
    pArr->length=0;
    pArr->max=0;
}