#include<stdio.h>
#define max 10


struct stack{

int top;
int s[max];
} st;

void push();
int pop();
void display();

int main()
{

    st.top=-1;
     printf("Enter your choice:\t");
    for(;;)
    {   int i,n,p;
        printf("\n1.PUSH\n2.POP\n3.DISPLAY\n\n\n");
        scanf("%d",&i);
        switch (i)
        {
            case 1:
                    push();
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

void push()
{
    int num;
    printf("\nEnter the no. to be pushed:\t");
        scanf("%d",&num);
    if(st.top==max-1)
    {
        printf("Stack Overflow\n");
        return 0;
    }
    else

        st.top=st.top+1;
        st.s[st.top]=num;
}

int pop()
{
    int p;
    if(st.top==-1)
    {

        return -1;
    }
    else
        p=st.s[st.top];
    st.top=st.top-1;
    return p;
}

void display()
{

    int i;
    printf("Stack contains:\n");
    for(i=0;i<=st.top;i++)
    {
        printf("%d\t",st.s[i]);
    }
}
