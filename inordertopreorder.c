#include<stdio.h>
#include<stdlib.h>

typedef struct xyz
{
    int value;
    struct xyz *left;
    struct xyz *right;
}node;

node * createNode(int ele)
{
    node *ptr;

    ptr = (node *)malloc(sizeof(node));
    ptr->value=ele;
    ptr->left=NULL;
    ptr->right=NULL;

    return ptr;
}

int preIndex=0;
node *createTree(int pre[],int in[],int is,int ie)
{
    int inIndex,i;

    if(is>ie)
    {
        return NULL;
    }

    node *ptr = createNode(pre[preIndex++]);

    for(i=is;i<=ie;i++)
    {
        if(in[i]==ptr->value)
        {
            inIndex=i;
            break;
        }
    }

    ptr->left = createTree(pre,in,is,inIndex-1);
    ptr->right = createTree(pre,in,inIndex+1,ie);

    return ptr;
}

void inOrder(node *root)
{
    if(root!=NULL)
    {
        inOrder(root->left);
        printf("%d ",root->value);
        inOrder(root->right);
    }
}

void preOrder(node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->value);
        inOrder(root->left);
        inOrder(root->right);
    }
}

int main()
{
    int in[]={10,15,17,18,20,25,30,35,38,40,50};
    int pre[]={20,15,10,18,17,30,25,40,35,38,50};
    int arrSize=11;
    node *root = createTree(pre,in,0,arrSize-1);
    printf("In-Order Traversal : ");
    inOrder(root);
    printf("\n\nPre-Order Traversal : ");
    preOrder(root);
    printf("\n");
    return 0;
}