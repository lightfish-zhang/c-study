#include <stdio.h>
#include "queue.h"

int main(int argc , char * argv[])
{
    QUEUE * queue;
    int key , i , a , b;
    do{
	    printf("-------------------------------\n");
        printf("    1 create queue \n");
        printf("    2 push queue \n");
        printf("    3 shilf queue \n");
        printf("    4 travers queue \n");
        printf("    0 exit \n");
	    printf("-------------------------------\n");
	    printf("    please choose number\n");
        scanf("%d",&key);

        switch(key){
            case 1:
                queue = que_create();
                printf("please input length of queue\n");
                scanf("%d",&a);
                for(i=0;i<a;i++){
                    scanf("%d",&b);
                    que_push(queue,b);
                }
                break;
            case 2:
                printf("please data you want to push\n");
                scanf("%d",&b);
                que_push(queue,b);
                break;
            case 3:
                a = que_shift(queue,&b);
                if(a)
                    printf("%d had been shilfed off\n",b);
                else
                    printf("queue is empty\n");
                break;
            case 4:
                que_traverse(queue);
                break;
        }

    }while(0!=key);
    return 0;
}