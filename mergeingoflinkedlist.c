#include <stdio.h>
#include <stdlib.h>

typedef struct record
{
    int value;
    struct reccord *next;
} node;

node *head1 = NULL;
node *head2 = NULL;
node *tail1 = NULL;
node *tail2 = NULL;

node *creatNode()
{
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    newnode->next = NULL;
    return newnode;
}

void creatlikedlist1()
{
    int i = 0;
    int a[] = {1, 3, 5, 7, 9, 15};
    while (i < 6)
    {
        node *ptr = creatNode();
        ptr->value = a[i];
        if (head1 == NULL)
            head1 = tail1 = ptr;
        else
        {
            tail1->next = ptr;
            tail1 = tail1->next;
        }
        i++;
    }

    node *ptr = head1;
    printf("\nLINKEDLIST1 :");
    while (ptr != NULL)
    {
        printf(" %d", ptr->value);
        ptr = ptr->next;
    }
}

void creatlikedlist2()
{
    int i = 0;
    int a[] = {2, 4, 6, 8, 10, 11, 12, 13, 18, 19, 20};
    while (i < 11)
    {
        node *ptr = creatNode();
        ptr->value = a[i];
        if (head2 == NULL)
            head2 = tail2 = ptr;
        else
        {
            tail2->next = ptr;
            tail2 = tail2->next;
        }
        i++;
    }
    printf("\nLINKEDLIST2 :");
    node *ptr = head2;
    while (ptr != NULL)
    {
        printf(" %d", ptr->value);
        ptr = ptr->next;
    }
}

void mergeoflinkedlist()
{
    node *head, *ptr1 = head1, *ptr2 = head2, *ptr3;

    if (ptr1->value < ptr2->value)
    {
        ptr3 = ptr1;
        ptr1 = ptr1->next;
    }
    else
    {
        ptr3 = ptr2;
        ptr2 = ptr2->next;
    }
    head = ptr3;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->value < ptr2->value)
        {
            ptr3->next = ptr1;
            ptr3 = ptr3->next;
            ptr1 = ptr1->next;
        }
        else
        {
            ptr3->next = ptr2;
            ptr3 = ptr3->next;
            ptr2 = ptr2->next;
        }
    }

    if (ptr1 != NULL)
    {
        ptr3->next = ptr1;
        ptr3 = ptr3->next;
    }
    else
    {
        ptr3->next = ptr2;
        ptr3 = ptr3->next;
    }

    printf("\nMERGED LINKEDLIST :");
    node *ptr = head;
    while (ptr != NULL)
    {
        printf(" %d", ptr->value);
        ptr = ptr->next;
    }
}

int main()
{
    creatlikedlist1();
    creatlikedlist2();
    mergeoflinkedlist();
}