#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "list.h"


PNODE list_create()
{
    int total , i;
    printf("please input total of the node\n");
    scanf("%d",&total);

    if( total<0 ){
        printf("total of the node at least 0\n");
        exit(-2);
    }
    
    PNODE pHead = NULL , pTail;
    for( i=0 ; i<total ; i++){
        if( 0==i){
            pHead = list_node();
            pTail = pHead; 
        }else{
            pTail->pNext = list_node();
            pTail = pTail->pNext;
        }
        printf("please input value of  %d th node\n",i+1);
        scanf("%d",&(pTail->data));
    }
    return pHead;
}

PNODE list_node()
{
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    if( NULL == pNew ){
        printf("malloc error\n");
        exit(-2);
    }
    pNew->pNext = NULL;
    return pNew;
}

void list_traverse(PNODE pHead)
{
    if(list_is_empty(pHead)){
        printf("list is empty\n");
        return ;
    }
    while( NULL != pHead){
        printf("%d ",pHead->data);
        pHead = pHead->pNext;
    };
    printf("\n");
}

int list_is_empty(PNODE pHead)
{
    return ( NULL == pHead);
}

int list_count(PNODE pHead)
{
    int i = 0;
    while(NULL != pHead){
        i ++;
        pHead = pHead->pNext;
    }
    return i;
}

void list_sort_quick(PNODE pHead)
{
    int total = list_count(pHead);
    if(total<2) 
        return;
    int i , j , tmp;
    PNODE p = pHead;
    for(i=total-1 ; i>0 ; i-- ){
        for(j=0;j<i;j++){
            if( p->data > p->pNext->data ){
                tmp = p->data;
                p->data = p->pNext->data;
                p->pNext->data = tmp;
            }
            p = p->pNext;
        }
        p = pHead;
    }
}

void list_sort_bubble(PNODE pHead)
{
    int total = list_count(pHead);
    if(total<2) 
        return;
    PNODE pArr[total];

    PNODE p1 = pHead;
    int i = 0;
    while(NULL != p1){
        pArr[i++] = p1;
        p1 = p1->pNext;
    }
    int j , tmp;
    for( i=0 ; i<total ; i++ ){
        for( j=i+1 ; j<total ; j++ ){
            if(pArr[i]->data > pArr[j]->data){
                tmp = pArr[i]->data;
                pArr[i]->data = pArr[j]->data;
                pArr[j]->data = tmp;
            }
        }
    }
}

void list_destory(PNODE pHead)
{
    PNODE p1 = pHead;
    PNODE p2 = pHead;
    while(NULL != p1){
        p2 = p1->pNext;
        free(p1);
        p1 = p2;
    }
    pHead = NULL;
}

void list_insert(PNODE pHead , int index , int value)
{
    if(index<0){
        return;
    }
    PNODE p1 = list_get_node(pHead , index);
    PNODE p2 = list_node();
    p2->data = p1->data;
    p2->pNext = p1->pNext;
    p1->data = value;
    p1->pNext = p2;
}

PNODE list_get_node( PNODE pHead , int index)
{
    if(index<0){
        PNODE pNode;
        pNode = NULL;
        return pNode;
    }
    
    int i=0;
    while(i!=index){
        i++;
        if( NULL == pHead){
            return pHead;
        }else{
            pHead = pHead->pNext;
        }
    }
    return pHead;
}

void list_delete_node(PNODE * ppHead , int index)
{
    if(index<0){
        return;
    }
    PNODE pHead = *ppHead;
    if(0 == index && NULL == pHead->pNext){
        free(pHead);
        *ppHead = NULL;
        return;
    }
    PNODE p1 = list_get_node(pHead,index);
    p1->data = p1->pNext->data;
    PNODE p2 = p1->pNext->pNext;
    free(p1->pNext);
    p1->pNext = p2;
}