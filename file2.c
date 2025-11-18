#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 3
int count;
typedef struct {
    int item[MAXSIZE];
    //yoooooooooooooooooooooooooooooooooooo;
    int f, r;
}QUEUE;

int isfull (QUEUE q){
    if(q.f == (q.r+1)%MAXSIZE)
        return 1;
    return 0;
}
int isempty(QUEUE q){
    if(q.f == -1){
        return 1;
    }
    return 0 ;
}

void insert(QUEUE *q, int data){
    q->r = (q->r+1)%MAXSIZE;
    q->item[q->r] = data;
    printf("\n%d is inserted into the Queue", data);
    count++;
    if(q->f == -1)
        q->f = 0;
    
}

int delete(QUEUE *q ){
    int data = q->item[q->f];
    count--;
    if(q->f == q->r)
         q->f = q->r = -1;
    else 
    q->f = (q->f+1)%MAXSIZE;
    return data;
}

void display(QUEUE q){
    printf("\nQueue contents\nFront->");
    for(int i=1; i<=count; i++){
        printf("%d ->", q.item[q.f]);
        q.f = (q.f+1)%MAXSIZE;
    }
    printf("Rear");
}

int main(){
    QUEUE q;
    q.f = q.r = -1;
    int choice, no;
    while(1){
        printf("\n\n1:Insert\n2:Delete\n3:Display\n4:Exit\nEnter your choice :");
        scanf("%d", &choice);
        switch (choice){
            case 1: if(isfull(q))
                        printf("\nCircular Queue is overflow");
                    else {
                        printf("\nEnter the data  to be insert :");
                        scanf("%d", &no);
                        insert(&q, no);
                    }
                    break;
            case 2:if(isempty(q))
                        printf("\nCircular Queue is underflow");
                    else {
                        printf("\n%d is deleted form the queue", delete(&q));
                    }
                    break;
            case 3: if(isempty(q))
                        printf("\nQueue is empty");
                    else {
                        display(q);

                    }
                    break;
            case 4: exit(0);
            default : printf("\nInvalid choice");
        }
    }
    return 0;
}