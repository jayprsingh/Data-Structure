#include<stdio.h>
int max=10;
int s[10];
int top=-1;
void push(int [],int);
int pop();
void display();

int main()
{
    int i,n,p;
    printf("Enter your choice:\t");
    for(;;)
    {
        printf("\n1.PUSH\n2.POP\n3.DISPLAY\n\n\n");
        scanf("%d",&i);
        switch (i)
        {
            case 1: printf("\nEnter the no to be pushed\t");
                    scanf("%d",&n);
                    push(s,n);
                    break;

            case 2: p=pop();
                    if(p==-1)
                     printf("Stack Underflow");
                    else
                    printf("\n%d poped from stack\n",p);
                    break;

            case 3: display();
                    break;

            default : break;
        }
    }
}

void push(int s[], int n)
{

    if(top==max-1)
    {
        printf("Stack Overflow\n");
        return 0;
    }
    else
        top=top+1;
        s[top]=n;
}

int pop()
{
    int p;
    if(top==-1)
    {

        return -1;
    }
    else
        p=s[top];
    top=top-1;
    return p;
}

void display()
{

    int i;
    printf("Stack contains:\n");
    for(i=0;i<=top;i++)
    {
        printf("%d\t",s[i]);
    }
}
