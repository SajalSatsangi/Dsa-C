#include <stdio.h>
#include <stdlib.h>

typedef struct record
{
    int value;
    struct record *left;
    struct record *right;
} node;
node *start = NULL;

node *creatNode()
{
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    newnode->left = NULL;
    newnode->right = NULL;
    printf("ENTER THE VALUE : ");
    scanf("%d", &newnode->value);
    return newnode;
}

void bst()
{
    int i, cheack = 0;
    if (start == NULL)
    {
        start = creatNode();
        printf("%d IS ADDED", start->value);
    }
    else
    {
        node *ptr = start, *tmp;
        tmp = creatNode();
        int n = tmp->value;
        while ((ptr->left) != NULL || (ptr->right) != NULL)
        {
            if (n < (ptr->value))
            {
                if ((ptr->left) == NULL)
                    break;
                ptr = ptr->left;
            }
            else if ((ptr->value) < n)
            {
                if ((ptr->right) != NULL)
                    break;
                ptr = ptr->right;
            }
            else
            {
                printf(" ~THIS VALUE IS ALREADY EXIST~ ");
                cheack = 1;
                break;
            }
        }
        if (cheack != 1)
        {
            if (n < (ptr->value))
                ptr->left = tmp;
            else
                ptr->right = tmp;
            printf("%d IS ADDED", tmp->value);
        }
    }
}

void display()
{
    if (start == NULL)
        printf("YOUR BST IS EMPTY");
    else
    {
        node *ptr = start, *tmp;
        printf("BST ELEMENTS ARE : ");
        while ((ptr->left) != NULL)
            ptr = ptr->left;
        printf("%d", ptr->value);
        tmp = ptr;
        ptr = start;
        while (start != tmp)
        {
            while (ptr->left != tmp && ptr->right != tmp)
            {
                if ((ptr->left) < (ptr->right))
                    ptr = ptr->left;
                else
                    ptr = ptr->right;
            }
            printf(" %d", ptr->value);
            tmp = ptr;
            ptr = start;
        }
    }
}

int main()
{
    int n;
    while (1)
    {
        printf("\n\nENTER 1 FOR ADDING VALUE\n");
        printf("ENTER 2 FOR BINARY SEARCH TREE DISPLAY\n");
        printf("ENTER 3 FOR EXIT\n");
        printf("\nENTER THE CHOICE :");
        scanf("%d", &n);
        if (n == 1)
            bst();
        else if (n == 2)
            display();
        else if (n == 3)
        {
            printf("\n\n~THANK YOU~\n\n");
            break;
        }
        else
            printf(" ~PLEASE INPUT THE CORRECT CHOICE~ ");
    }
}