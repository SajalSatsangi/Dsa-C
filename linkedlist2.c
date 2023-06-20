#include <stdio.h>
#include <stdlib.h>

typedef struct record
{
    int value;
    struct record *next;
} node;

node *start = NULL;

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
    node *tmp = start;

    if (tmp == NULL)
    {
        printf("Linked List Not Exists\n");
    }
    else
    {
        printf("Linked List : ");

        while (tmp != NULL)
        {
            printf("%d ", tmp->value);
            tmp = tmp->next;
        }

        printf("\n");
    }
}

int countNode()
{
    node *tmp = start;
    int c = 0;

    if (tmp == NULL)
        return c;

    while (tmp != NULL)
    {
        tmp = tmp->next;
        c++;
    }

    return c;
}

void addNodeAtPos(int p)
{
    node *tmp, *ptr;

    int c = countNode();
    if (p < 1 || p > c + 1)
    {
        printf("Invalid Position\n");
    }
    else
    {
        int i;
        ptr = createNode();
        tmp = start;

        for (i = 1; i < p - 1; i++)
        {
            tmp = tmp->next;
        }

        ptr->next = tmp->next;
        tmp->next = ptr;
    }
}

int main()
{
    int ch;

    while (1)
    {
        printf("\n\n1. Add Record");
        printf("\n2. Show Records");
        printf("\n3. Exit");
        printf("\nEnter Your Choice : ");
        scanf("%d", &ch);
        int n;
        if (ch == 1)
        {
            printf("enter the position :");
            scanf("%d",&n);
            addNodeAtPos(n);
        }
        else if (ch == 2)
        {
            display();
        }
        else if (ch == 3)
        {
            break;
        }
        else
        {
            printf("Wrong Input\n");
        }
    }

    return 0;
}