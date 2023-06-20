#include <stdio.h>
#include <stdlib.h>

typedef struct record
{
    int value;
    struct record *next;
} node;

node *start1 = NULL, *start2 = NULL;

node *createNode()
{
    node *newnode;

    newnode = (node *)malloc(sizeof(node));

    printf("Enter Node value : ");
    scanf("%d", &newnode->value);
    newnode->next = NULL;

    return newnode;
}

node *linkedlistinput1(int n)
{
    int i = 1;
    while (i <= n)
    {
        node *ptr = createNode();
        if (i == 1)
            start1 = ptr;
        printf("ENTER THE VALUE OF %d NODE : ",i);
        scanf("%d", ptr->value);
        ptr = ptr->next;
        i++;
    }
    return start1;
}

node *linkedlistinput2(int n)
{
    int i = 1;
    while (i <= n)
    {
        node *ptr = createNode();
        if (i == 1)
            start2 = ptr;
        printf("ENTER THE VALUE OF %d NODE : ",i);
        scanf("%d", ptr->value);
        ptr = ptr->next;
        i++;
    }
    return start2;
}

node *mergeLinkedList(node *start1, node *start2)
{
    node *start3, *ptr, *s1, *s2;

    if (start1->value < start2->value)
    {
        start3 = start1;
        start1 = start1->next;
    }
    else if (start1->value > start2->value)
    {
        start3 = start2;
        start2 = start2->next;
    }
    else
    {
        start3 = start2;
        start2 = start2->next;
        start1 = start1->next;
    }

    ptr = start3;

    while (start1 != NULL && start2 != NULL)
    {
        if (start1->value < start2->value)
        {
            ptr->next = start1;
            start1 = start1->next;
            ptr = ptr->next;
        }
        else if (start1->value > start2->value)
        {
            ptr->next = start2;
            start2 = start2->next;
            ptr = ptr->next;
        }
        else
        {
            ptr->next = start2;
            start2 = start2->next;
            start1 = start1->next;
            ptr = ptr->next;
        }
    }

    if (start1 != NULL)
    {
        ptr->next = start1;
    }

    if (start2 != NULL)
    {
        ptr->next = start2;
    }

    return start3;
}

node *mergeLLR(node *start1, node *start2)
{
    if (start1 == NULL)
        return start2;
    if (start2 == NULL)
        return start1;

    if (start1->value < start2->value)
    {
        start1->next = mergeLLR(start1->next, start2);
        return start1;
    }
    else if (start1->value > start2->value)
    {
        start2->next = mergeLLR(start1, start2->next);
        return start2;
    }
    else
    {
        start2->next = mergeLLR(start1->next, start2->next);
        return start2;
    }
}