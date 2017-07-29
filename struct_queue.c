
#include<stdio.h>
#define max 5
struct queue{
int front;
int rear;
int q[max];
} qu;

void insert();
int deleteq();
void display();

int main()
{       qu.front=-1;
        qu.rear=-1;
        int i,p;
        printf("\nEnter your choice:\t");
        for(;;)
         {
        printf("\n1.INSERT\n2.DELETE\n3.DISPLAY\n\n\n");
        scanf("%d",&i);
        switch (i)
        {
            case 1:
                    insert();
                    break;

            case 2: p=deleteq();
                    if(p==-1)
                    printf("QUEUE Underflow");
                    else
                    printf("\n%d is Poped out from QUEUE\n",p);
                    break;

            case 3: display();
                    break;

            default : break;
}
    }
}

void insert()
{
    int num;
    if(qu.rear==max-1)
    {
        printf("QUEUE Overflow\n");
        return;
    }
    else
        if(qu.front=-1)
        {
            qu.front=0;
        }
        printf("Enter the no. insert\n");
        scanf("%d",&num);
        qu.rear=qu.rear+1;
        qu.q[qu.rear]=num;
}

int deleteq()
{   int p;
    if(qu.front>=qu.rear||qu.front==-1)
    {
                return -1;
    }
    else
    {
        p=qu.q[qu.front];
        qu.front=qu.front+1;
    }
    return p;
}

void display()
{
    int i;
    if(qu.front==-1)
    {
        printf("QUEUE UNDERFLOW\n");
    }
    else
    for(i=qu.front;i<=qu.rear;i++)
    {
        printf("%d\t",qu.q[i]);
    }
}

