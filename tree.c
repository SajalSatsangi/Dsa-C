#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *right;
    struct node *left;
}node;

node * createnode(int ele)
{
    node * ptr= (node *)malloc(sizeof(node));
    ptr->data = ele;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;    
}

node * insert(node * root, node * newnode)
{
  if(root->data < newnode->data)
        { 
        if(root->right  == NULL)
            root->right = newnode;
        else
            insert(root->right, newnode);
        }   
  else
        {
          if(root->left  == NULL)
            root->left = newnode;
        else
           insert(root->left, newnode);
        }
  return root;
}

void inorder(node * root)
{
    while(root != NULL)
    {
        inorder(root->left);
        printf("%d", root->data);
        inorder(root->right);
    }
}

void preorder(node * root)
{
    while(root != NULL)
    {
        printf("%d", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node * root)
{
    while(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d", root->data);
    }
}

void search(node * root, int ele)
{   if(root == NULL)
    {
      printf("Element not found");
      return;
    }
    if(root->data == ele)
    {printf("Element found");
      return;
    }
    else if(root->data > ele)
        return search(root->left, ele);
    else if(root->data <  ele)
        return search(root->right, ele);
}
int main() 
{
    int ch;
    int ele;
    node * root = NULL;
    while(1)
    {
        printf("\n1. Insert");
        printf("\n3. Inorder");
        printf("\n4. Preorder");
        printf("\n5. Postorder");
        printf("\n14. Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        
        if(ch == 1)
        {
          int ch1;
            do{
              if(root == NULL)
              {
                printf("Enter the element");
                scanf("%d", &ele);
                node *ptr = createnode(ele);
                root = ptr;             
                printf("DYWTC(0/1)");
                scanf("%d", &ch1);
                }
              else
              {
                printf("Enter the element");
                scanf("%d", &ele);
                node *ptr = createnode(ele);
                root = insert(root, ptr);
                printf("root: %d\n", root->data);
                printf("DYWTC(0/1)");
                scanf("%d", &ch1);
              }
              // printf("function has been fired\n");
            }while(ch1 != 0);
            printf("All the elements inserted");
            printf("root: %d root right %d root left %d", root->data, root->left->data, root->right->data);
        }
        else if(ch == 3)
          inorder(root);
        else if(ch == 4)
          preorder(root);
        else if(ch == 5)
          postorder(root);
        else if(ch == 6)
          search(root, ele);
        else if(ch == 14)
          break;
    }
    return 0;
}