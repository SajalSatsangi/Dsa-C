#include <stdio.h>
#include <stdlib.h>

typedef struct record
{
    int value;
    struct record *right;
    struct record *left;
} node;
node *root = NULL;

typedef struct queuenode
{
    int value;
    struct queuenode *next;
} queue;
queue *front = NULL;
queue *rear = NULL;

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

void enqueue(int ele)
{
    queue *ptr;
    ptr = (queue *)malloc(sizeof(queue));
    ptr->next = NULL;
    ptr->value = ele;
    if (front == NULL)
    {
        front = ptr;
        rear = ptr;
    }
    else
    {
        rear->next = ptr;
        rear = ptr;
    }
}

queue *dequeue()
{
    queue *ptr;
    ptr = front;
    if (front == rear)
        front = rear = NULL;
    else
        front = front->next;
    return ptr;
}

void levelOrderQ(node *root)
{
    if (root == NULL)
        return;
    enqueue(root);

    while ((front != NULL && rear != NULL))
    {
        node *ele = dequeue();
        printf("%d", ele->value);

        if (ele->left != NULL)
            enqueue(ele->left);
        if (ele->right != NULL)
            enqueue(ele->right);
    }
}