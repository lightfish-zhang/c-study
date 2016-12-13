#include <stdio.h>
#include "list.c"

 int main(int argc , char * argv[])
 {
     PNODE pHead = list_create();
     list_traverse(pHead);

     int total = list_count(pHead);
     printf("total of the list is %d\n",total);

     list_sort_quick(pHead);
     list_traverse(pHead);

     int index;
     printf("please input index of node that you want\n");
     scanf("%d",&index);
     PNODE pNode = list_get_node(pHead,index);
     if( NULL != pNode){
        printf("data of the node is %d\n",pNode->data);
        printf("please input value to insert before it\n");
        int value;
        scanf("%d",&value);
        list_insert(pHead , index , value);
        list_traverse(pHead);
     }else{
         printf("node is NULL\n");
     }
     
     
    int index2;
    printf("please input index of node you want to delete\n");
    scanf("%d",&index2);
    list_delete_node(&pHead,index2);
    list_traverse(pHead);

    
    printf("please input index of node you want to delete\n");
    scanf("%d",&index2);
    list_delete_node(&pHead,index2);
    list_traverse(pHead);

    list_destory(pHead);
    return 0;
 }