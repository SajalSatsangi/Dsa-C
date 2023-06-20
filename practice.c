#include <stdio.h>

typedef struct record
{
    int value;
    struct record *left;
    struct record *right;
} node;
node *root = NULL;

void max()
{
    if (root==NULL)
        printf("BST IS EMPTY");
    else
    {
        node *ptr = root;
        while (ptr->right != NULL)
            ptr = ptr -> right;
        printf("MAXIMUM NO. IS %d",ptr->value);
        
    }
}

void min()
{
    if (root == NULL)
        printf("BST IS EMPTY");
    else
    {
        node *ptr = root;
        while(ptr->left != NULL)
            ptr = ptr -> left;
        printf("MINIMUM NO. IS %d",ptr->value);
    }
    
}