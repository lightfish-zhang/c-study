#include <stdio.h>
#include <stdlib.h>
#define ELEMENT_TYPE int

typedef struct node
{
    ELEMENT_TYPE data;
    struct node *next;
    struct node *last;
} NODE;

typedef struct queue
{
    NODE * head;
    NODE * tail;
} QUEUE;

NODE * que_node()
{
    NODE *  node = ( NODE * )malloc(sizeof(NODE));
    if(NULL == node)
        exit(-1);
    return node;
}

QUEUE * que_create()
{
    QUEUE * queue = ( QUEUE * )malloc(sizeof(QUEUE));
    if(NULL == queue)
        exit(-1);
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

void que_destory(QUEUE * queue)
{
    NODE * n1;
    NODE * n2;
    n1 = queue->head;
    while(NULL != n1){
       n2 = n1->next;
       free(n1);
       n1 = n2; 
    }
    free(queue);
}

void que_push(QUEUE * queue , ELEMENT_TYPE data)
{
    NODE * node = que_node();
    node->data = data;
    node->next = NULL;
    node->last = queue->tail;
    if(NULL == queue->head){
        queue->head = node;
    }else{
        queue->tail->next = node;
    }
    queue->tail = node;
}

int que_shift(QUEUE * queue , ELEMENT_TYPE * data)
{
    if(NULL == queue->head){
        return 0;
    }else{
        *data = queue->head->data;
        NODE * n = queue->head->next;
        free(queue->head);
        queue->head = n;
        if(NULL == n){
            queue->tail = NULL;
        }
        return 1;
    }
}

int que_pop(QUEUE * queue , ELEMENT_TYPE * data)
{
    if(NULL == queue->tail){
        return 0;
    }else{
        *data = queue->tail->data;
        NODE * n = queue->tail->last;
        free(queue->tail);
        queue->tail = n;
        if(NULL == n){
            queue->head = NULL;
        }
        return 1;
    }
}

void que_traverse(QUEUE * queue)
{
    if(NULL == queue->head){
        fprintf(stdout,"queue is empty");
    }
    NODE * n;
    n = queue->head;
    while(NULL != n){
        fprintf(stdout,"%d ",n->data);
        n = n->next;
    }
    printf("\n");
}