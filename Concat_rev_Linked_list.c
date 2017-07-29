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
        printf("Allocation Failed!\n");
        return 0;
    }
    return temp;
}

NODE concate(NODE first,NODE second)
{
    NODE cur=first;
    if(first==NULL)
    {
        return second;
    }
    else if(second==NULL)
    {
        return first;
    }
    else
        while(cur->next!=NULL)
        {
            cur=cur->next;
        }
        first->next=second;
            return first;
}
void insert_order(int item)
{
    int ch;
    NODE con_node;
    NODE con_rev=getnode();
    NODE cur=head, pred=NULL;
    NODE newnode=getnode();
    NODE nextnode=getnode();
    printf("To which list you want to add?\n1.First List\t2.Second list\n");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:

    newnode->info=item;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
        printf("Added at beginning\n");
        return;
    }

    if(newnode->info<head->info)
    {
        newnode->next=head;
        head=newnode;
        return;
    }
    while(cur!=NULL&&newnode->info>cur->info)
    {
        pred=cur;
        cur=cur->next;
    }
    pred->next=newnode;
    newnode->next=cur;
    break;

case 2:

    nextnode->info=item;
    nextnode->next=NULL;
    if(head==NULL)
    {
        head=nextnode;
        printf("Added at beginning\n");
        return;
    }

    if(nextnode->info<head->info)
    {
        nextnode->next=head;
        head=nextnode;
        return;
    }
    while(cur!=NULL&&nextnode->info>cur->info)
    {
        pred=cur;
        cur=cur->next;
    }
    pred->next=nextnode;
    newnode->next=cur;
    break;

    case 3:return;
    }
    con_node=concate(newnode,nextnode);

}
void delete_pos(int pos)
{
    NODE cur=head, pred=NULL;
    int item,item2;
    int count=1;
    if(head==NULL)
    {
        printf("Empty List\n");
        return;
    }
    if(pos==1)
    {
        item=head->info;
        head->next=NULL;
        free(head);
        printf("Deleted Node at Pos=1 is %d\n",item);
        return;
    }
    while(cur!=NULL&&count!=pos)
    {
        count++;
        pred=cur;
        cur=cur->next;
    }
    if(cur==NULL)
    {
        printf("Invalid option\n");
        return;
    }
    item2=cur->info;
    pred->next=cur->next;
    free(cur);
    printf("Deleted info is %d\n",item2);
}

void insert_pos(int var,int pos)
{
    int count=1;
    NODE newnode, pred=NULL, cur=head;
    newnode=getnode();
    newnode->info=var;
    newnode->next=NULL;
    if(head==NULL&&pos==1)
    {
        printf("Inserted at beginning\n");
        head=newnode;
        return;
    }
    if(head==NULL)
    {
        printf("Invalid Option!\n");
        return;
    }
    while(cur!=NULL&&pos!=count)
    {
        count++;
        pred=cur;
        cur=cur->next;
    }
    if(pos==count){

    pred->next=newnode;
    newnode->next=cur;
    }
    else
        printf("Invalid Position!\n");
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
    int ch,item,pos,pos1;
    printf("\nEnter choice:\n");
    for(;;)
    {
        printf("\n1.INSERT ORDERED\n2.DELETE POSITION\n3.DISPLAY\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter no to insert:\t");
                    scanf("%d",&item);
                    insert_order(item);
                    break;
             /*
            case 1: printf("\nEnter no to insert:\t");
                    scanf("%d",&item);
                    printf("\nEnter the position to insert:\t");
                    scanf("%d",&pos1);
                    insert_pos(item,pos1);
                    break;
*/
            case 2: printf("Enter the position to delete:\n");
                    scanf("%d",&pos);
                    delete_pos(pos);
                    break;

            case 3: display();
                    break;

            default:return;
        }
    }
}
