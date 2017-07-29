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
void insert_rear(int item)
{
    NODE cur=head;
    NODE nextnode;
    nextnode=getnode();
    nextnode->info=item;
    nextnode->next=NULL;
    if(head==NULL)
    {
        head=nextnode;
        printf("Added at beginning\n");
        return;
    }
    while(cur->next!=NULL)
        cur=cur->next;

        cur->next=nextnode;
        printf("Added to List\n");

}
void delete_front()
{
    int item;
    NODE cur=head;
    if(head==NULL)
    {
        printf("Empty List\n");
        return;
    }
    item=cur->info;
    head=cur->next;
    cur->next=NULL;
    free(cur);
    printf("Deleted node is %d\n",item);

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
        printf("\n1.INSERT REAR\n2.DELETE FRONT\n3.DISPLAY\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter no to insert:\t");
                    scanf("%d",&item);
                    insert_rear(item);
                    break;

            case 2: delete_front();
                    break;

            case 3: display();
                    break;

            default:return;
        }
    }
}
