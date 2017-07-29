#include<stdio.h>
#include<malloc.h>

struct node
{
    int info;
    struct node *next;
};
typedef struct node *NODE;
NODE head=NULL;

NODE getnode()
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Allocation Failed\n");
        return;
    }
    return temp;
}

void insert_front(int item)
{
    NODE nextnode;
    nextnode=getnode();
    nextnode->info=item;
    nextnode->next=NULL;
    nextnode->next=head;
    head=nextnode;
}

void delete_rear()
{
    NODE pred=NULL, cur=head;
    if(head==NULL)
    {
        printf("Empty list\n");
        return;
    }
    if(head->next==NULL)
    {
        printf("Info of deleted node=%d\n",head->info);
        free(head);
        head=NULL;
        return;
    }
    while(cur->next!=NULL)
    {

        pred=cur;
        cur=cur->next;
    }
    printf("Info of deleted node=%d\n",cur->info);
    free(cur);
    pred->next=NULL;
}

void display()
{
    NODE cur=head;
    if(head==NULL)
    {
        printf("Empty List\n");
        return;
    }
    else
        printf("List Content\n");
    while(cur!=NULL)
    {
        printf("%d\t",cur->info);
        cur=cur->next;
    }
}

int main()
{
    int ch,item;
    printf("\nEnter choice:\n");
    for(;;)
    {
        printf("\n1.INSERT FRONT\n2.DELETE REAR\n3.DISPLAY\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter no to insert:\t");
                    scanf("%d",&item);
                    insert_front(item);
                    break;

            case 2: delete_rear();
                    break;

            case 3: display();
                    break;

            default:return;
        }
    }
}
