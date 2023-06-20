#include <stdio.h>
#include <stdlib.h>

typedef struct record
{
    int value;
    struct record *next;
} node;

node *head = NULL;

node *createNode()
{
    node *newnode;

    newnode = (node *)malloc(sizeof(node));

    printf("Enter Node value : ");
    scanf("%d", &newnode->value);
    newnode->next = NULL;

    return newnode;
}

void display()
{
    node *tmp = head;

    if (tmp == NULL)
    {
        printf("\n\tLinked List Not Exists\n");
    }
    else
    {
        printf("\n\tLinked List : ");

        while (tmp != NULL)
        {
            printf("%d ", tmp->value);
            tmp = tmp->next;
        }
        printf("\n");
    }
}

void insertAtHead()
{
    node *ptr = createNode();
    if (head == NULL)
        head = ptr;
    else
    {
        ptr->next = head;
        head = ptr;
    }
    display();
}

void insertAfter(int p)
{
    node *tmp, *ptr;
    ptr = createNode();
    tmp = head;

    while (tmp == NULL && tmp->value != p)
        tmp = tmp->next;
    if (tmp == NULL)
        printf("NUMBER IS NOT IN THE LIST");
    else
    {
        ptr->next = tmp->next;
        tmp->next = ptr;
    }
    display();
}

void insertBefore(int p)
{
    node *tmp, *ptr;
    ptr = createNode();
    tmp = head;
    while (tmp == NULL && tmp->next->value != p)
        tmp = tmp->next;
    if (tmp == NULL)
        printf("NUMBER IS NOT IN THE LIST");
    else
    {
        ptr->next = tmp->next;
        tmp->next = ptr;
    }
    display();
}

node *search(int p)
{
    node *tmp, *ptr;
    tmp = head;
    while (tmp != NULL)
    {
        if (tmp->value == p)
            return tmp;
        tmp = tmp->next;
    }
    return 0;
}

void deleteAthead()
{
    if (head == NULL)
        printf("LINKED LIST IS EMPTY");
    else
    {
        node *tmp = head;
        head = head->next;
        free(tmp);
    }
    display();
}

void deleteAfter(int p)
{
    node *tmp, *ptr;
    tmp = head;
    while (tmp == NULL && tmp->value != p)
        tmp = tmp->next;
    if (tmp == NULL)
        printf("NUMBER IS NOT IN THE LIST");
    else
    {
        ptr = tmp->next;
        tmp->next = ptr->next;
        free(ptr);
    }
    display();
}

void deleteBefore(int p)
{
    node *tmp, *ptr;
    tmp = head;
    while (tmp == NULL && tmp->next->next->value != p)
        tmp = tmp->next;
    if (tmp == NULL)
        printf("NUMBER IS NOT IN THE LIST");
    else
    {
        ptr = tmp->next;
        tmp->next = ptr->next;
        free(ptr);
    }
    display();
}

int main()
{
    int choice, t;
    while (1)
    {
        printf("\n\nENTER 1. FOR INSERT AT HEAD");
        printf("\nENTER 2. FOR INSERT AT AFTER THE VALUE");
        printf("\nENTER 3. FOR INSERT AT BEFORE THE VALUE");
        printf("\nENTER 4. FOR SEARCH THE VALUE");
        printf("\nENTER 5. FOR DELETE AT HEAD");
        printf("\nENTER 6. FOR DELETE AT AFTER THE VALUE");
        printf("\nENTER 7. FOR DELETE AT BEFORE THE VALUE");
        printf("\nENTER 8. FOR EXIT");
        printf("\n\nENTER YOUR CHOICE : ");
        scanf("%d", &choice);
        if (choice == 1)
            insertAtHead();
        else if (choice == 2)
        {
            printf("ENTER THE VALUE : ");
            scanf("%d", &t);
            insertAfter(t);
        }
        else if (choice == 3)
        {
            printf("ENTER THE VALUE : ");
            scanf("%d", &t);
            insertBefore(t);
        }
        else if (choice == 4)
        {
            printf("ENTER THE VALUE : ");
            scanf("%d", &t);
            node *ptr = search(t);
            ptr == 0 ? printf("NUMBER NOT FOUND") : printf("NUMBER FOUND");
        }
        else if (choice == 5)
            deleteAthead();
        else if (choice == 6)
        {
            printf("ENTER THE VALUE : ");
            scanf("%d", &t);
            deleteAfter(t);
        }
        else if (choice == 7)
        {
            printf("ENTER THE VALUE : ");
            scanf("%d", &t);
            deleteBefore(t);
        }
        else if (choice == 8)
        {
            printf("\n\t~EXIT~");
            break;
        }
        else
            printf("PLEASE INPUT THE CORRECT VALUE");
    }
}