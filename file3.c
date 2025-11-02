#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 3
typedef struct {
    char item[MAXSIZE];
    int f, r;
}QUEUE;

int isfull(QUEUE q){
    if(q.r == MAXSIZE-1)
        return 1;
return 0;
}

int isempty(QUEUE q){
    if(q.f == -1)
        return 1;
return 0;
}

void insert(QUEUE *q, char data){
    q->item[++q->r] = data;
    printf("\ncahrecter \'%c\' is inserted into queue", data);
    if(q->f == -1)
        q->f = 0;
}

char delet(QUEUE *q){
    char ch = q->item[q->f];
    if(q->f== q->r)
        q->f = q->r = -1;
    else
        q->f++;
    return ch;

}

void display(QUEUE q){
    printf("\nQueue contents\nFront->");
    for(int i=q.f; i<=q.r; i++){
        printf("%c -> ",q.item[i]);
    }
    printf("Rear");
}

int main(){
    QUEUE q;
    q.f = q.r = -1;
    int choice;
    char data;
    while(1){
        printf("\n\n1:Insert\n2:Delete\n3:Display\n4:exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: if(isfull(q))
                        printf("\nQueue is overflow");
                    else{
                        printf("\nEnter the cahrecter to insert to Queue : ");
                        getchar();
                        scanf("%c", &data);
                        insert(&q, data);
                    }
                    break;
            case 2: if(isempty(q))
                        printf("\nQueue is underflow!!");
                    else{
                        printf("\nCharecter \'%c\' is Deleted from the Queue", delet(&q));
                    }
                    break;
            case 3: if(isempty(q))
                        printf("\nQueue is empty!!");
                    else{
                        display(q);
                    }
                    break;
            case 4: exit(0);
            default: printf("\nInvalid choice");
        }
    }
    return 0;
}