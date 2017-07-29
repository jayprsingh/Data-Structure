#include<stdio.h>
#include<malloc.h>

struct node
{
    int info;
    struct node *left;
    struct node *right;
};
typedef struct node *NODE;

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

NODE maketree(int x)
{
    NODE newnode;
    newnode=getnode();
    newnode->info=x;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

NODE root=NULL;
void inorder(NODE root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d\t",root->info);
        inorder(root->right);
    }
}
void preorder(NODE root)
{
    if(root!=NULL)
    {
        printf("%d\t",root->info);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(NODE root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->info);
    }
}
void create(int item)
{
    NODE newnode,cur,suc;
    root=maketree(item);
    cur=suc=root;


    while(item!=cur->info&&suc!=NULL)
    {
        cur=suc;
        if(item<cur->info){
            suc=cur->left;

            }

        else{

            suc=cur->right;
                }
    }
    if(item==cur->info)
    {
        printf("Duplicate No.\n");
        return;
    }
    if(item<cur->left)
        cur->left=root;
    else
        cur->right=root;
}
int main()
{
    int ch,item,pos,pos1;
    printf("\nEnter choice:\n");
    for(;;)
    {
        printf("\n1.CREATE TREE\n2.PREORDER\n3.INORDER\n4.POSTORDER\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter no to insert:\t");
                    scanf("%d",&item);
                    create(item);
                    break;

            case 2: printf("PREORDER TRAVERSAL\n");
                    preorder(root);
                    break;

            case 3: printf("INORDER TRAVERSAL\n");
                    inorder(root);
                    break;

            case 4: printf("POSTORDER TRAVERSAL\n");
                    postorder(root);
                    break;

            default:return;
        }
    }
}
