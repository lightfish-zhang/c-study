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

NODE * que_node();
QUEUE * que_create();
void que_destory(QUEUE * queue);
void que_push(QUEUE * queue , ELEMENT_TYPE data);
int que_shift(QUEUE * queue , ELEMENT_TYPE * data);
int que_pop(QUEUE * queue , ELEMENT_TYPE * data);
void que_traverse(QUEUE * queue);