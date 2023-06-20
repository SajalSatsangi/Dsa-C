#include <stdio.h>
#include <stdlib.h>

struct record
{
    int roll;
    char name[20];
    struct record *next;
};
typedef struct record node;

node *start = NULL;

void addRecord()
{
    node *ptr, *tmp;

    ptr = (node *)malloc(sizeof(node));

    printf("Enter Roll No. : ");
    scanf("%d", &ptr->roll);

    printf("Enter Name : ");
    scanf("%s", ptr->name);

    ptr->next = NULL;

    if (start == NULL)
    {
        start = ptr;
    }
    else
    {
        tmp = start;

        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }

        tmp->next = ptr;
    }
}

void display()
{
    if (start == NULL)
    {
        printf("Records Not Found\n");
    }
    else
    {
        node *tmp = start;

        printf("All Records\n");

        while (tmp != NULL)
        {
            printf("Roll No.: %d and Name : %s\n", tmp->roll, tmp->name);
            tmp = tmp->next;
        }
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

        if (ch == 1)
        {
            addRecord();
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
}