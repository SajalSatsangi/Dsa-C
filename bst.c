#include <stdio.h>

typedef struct record
{
    int value;
    struct record *left;
    struct record *right;
} node;
node *root = NULL;

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

void insert(node *root, node *newnode)
{
    if (root == NULL)
        root = newnode;
    else if (newnode->value < root->value)
    {
        if (root->left == NULL)
            root->left = newnode;
        else
            insert(root->left, newnode);
    }
    else
    {
        if (root->right == NULL)
            root->right = newnode;
        else
            insert(root->right, newnode);
    }
}

node *max(node *root)
{
    if (root->right == NULL)
        return root;
    else
        return min(root->right);
}

node *min(node *root)
{
    if (root->left == NULL)
        return root;
    else
        return min(root->left);
}

node *deletenode(node *root, int key)
{
    if (root == NULL)
        return root;
    else if (key < root->value)
        root->left = deletenode(root->left, key);
    else if (key > root->value)
        root->right = deletenode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            node *temp = min(root->right);
            root->value = temp->value;
            root->right = deletenode(root->right, temp->value);
        }
    }
    return root;
}

int main()
{
    int n;
    while (1)
    {
        printf("\n\nENTER 1 FOR ADDING VALUE\n");
        printf("ENTER 2 FOR FIND MIN\n");
        printf("ENTER 3 FOR FIND MAX\n");
        printf("ENTER 4 FOR DELETE VALUE\n");
        printf("ENTER 5 FOR EXIT\n");
        printf("\nENTER THE CHOICE :");
        scanf("%d", &n);
        if (n == 1)
        {
            node *newnode = creatNode();
            insert(root, newnode);
        }
        else if (n == 2)
        {
            node *minnode = min(root);
            printf("MIN VALUE :%d", minnode->value);
        }
        else if (n == 3)
        {
            node *maxnode = max(root);
            printf("MAX VALUE :%d", maxnode->value);
        }
        else if (n == 4)
        {
            int key;
            printf("ENTER THE VALUE FOR DELETE :");
            scanf("%d",key);
            node *deletednode = deletenode(root, key);
        }
        else if (n == 5)
        {
            printf("\n\n~THANK YOU~\n\n");
            break;
        }
        else
            printf(" ~PLEASE INPUT THE CORRECT CHOICE~ ");
    }
}