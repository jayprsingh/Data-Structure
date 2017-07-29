
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
    int pos;
    if(rear==max-1)
    {
        printf("QUEUE Overflow\n");
        return;
    }

    else
    {   if(front==-1)
    {
        front=0;
    }
        printf("Enter the no:\t");
        scanf("%d",&num);
        pos=rear;
        while(pos>=0&&num<q[pos])
        {
            q[pos+1]=q[pos];
            pos--;
        }
        q[pos+1]=num;
        rear++;
    }

        }

int deleteq()
{   int p;
    if(front>rear)
    {
        printf("QUEUE Underflow\n");
    }
    else
    {
        p=q[front];
        front=(front+1);

    }
    return p;
}

void display()
{
    int i;
    if(front>rear)
    {
        printf("QUEUE UNDERFLOW\n");
    }
    else
    for(i=front;i<=rear;i++)
    {
        printf("%d\t",q[i]);
    }
}

