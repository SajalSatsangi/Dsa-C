#include <stdio.h>
#include <stdlib.h>

typedef struct record
{
    int value;
    struct record *pre;
    struct reccord *next;
} node;

// node *dummy = 10000000;

node *creatlinkedlist(int arr[], int n)
{
    node *dummyNode;
    dummyNode->value = 1000000;
    dummyNode->next = NULL;
    dummyNode->pre = NULL;

    for (int i = 0; i < n; i++)
    {
        node *newnode = (node *)malloc(sizeof(node));
        newnode->next = NULL;
        newnode->pre = NULL;
        newnode->value = arr[i];

        node *ptr = dummyNode->next;
        newnode->next = ptr;
        ptr->pre = newnode;
        dummyNode->next = newnode;
        newnode->pre = dummyNode;
    }

    node *ptr;
    ptr = dummyNode->next;
    while (ptr != NULL)
    {
        printf("\n\t%d node : %d\n", ptr->value);
        ptr = ptr->next;
    }
    return dummyNode;
}


int main()
{
    int ls1[] = {12, 34, 56, 32, 1, 98, 5}, n = 7;
    node *list1 = creatlinkedlist(ls1, n);
}