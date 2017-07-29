
#include<stdio.h>
#define max 5

int front=-1;
int rear=-1;
int q[max];
int count=0;


void insert();
int deleteq();
void display();

int main()
{
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
                     printf("Stack Underflow");
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
    if(count==max)
    {
        printf("QUEUE Overflow\n");
        return;
    }
    else
        if(front=-1)
        {
            front=0;
        }
        printf("Enter the no. insert\n");
        scanf("%d",&num);
        rear=(rear+1)%max;
        q[rear]=num;
        count=count+1;
}

int deleteq()
{   int p;
    if(count==0)
    {
        printf("QUEUE Underflow\n");
    }
    else
    {
        p=q[front];
        front=(front+1)%max;
        count=count-1;
    }
    return p;
}

void display()
{
    int i;
    if(count==0)
    {
        printf("QUEUE UNDERFLOW\n");
    }
    else
    for(i=0;i<count;i++)
    {
        printf("%d\t",q[i]);
    }
}

