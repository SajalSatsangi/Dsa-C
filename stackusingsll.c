#include <stdio.h>
#include <stdlib.h>

typedef struct record
{
    int value;
    struct reccord *next;
} node;
node *top = NULL;

node *creatNode()
{
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    newnode->next = NULL;
    printf("\tENTER THE VALUE : ");
    scanf("%d", &newnode->value);
    return newnode;
}

void push()
{
    node *ptr = creatNode();
    if (top == NULL)
        top = ptr;
    else
    {
        ptr->next = top;
        top = ptr;
    }
    printf("\t%d IS ADDED", top->value);
}

node *pop()
{
    node *ptr;
    ptr = top;
    top = top->next;
    printf("\t%d IS REMOVED", ptr->value);
    free(ptr);
}

void display()
{
    if (top == NULL)
        printf("\n\tSTACK IS EMPTY");
    else
    {
        node *ptr = top;
        printf("\n\n");
        while (ptr != NULL)
        {
            printf("\t%d ", ptr->value);
            ptr = ptr->next;
        }
    }
}

int main()
{
    int choice, ele;

    while (1)
    {
        printf("\n\n1. PUSH ELEMENT\n");
        printf("2. POP ELEMENT\n");
        printf("3. EXIT\n");
        printf("\n\tENTER YOUR CHOICE : ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            push();
            display();
        }
        else if (choice == 2)
        {
            if (top != NULL)
                pop();
            display();
        }
        else if (choice == 3)
        {
            printf("\n\t~ THANK YOU ~\n\n");
            break;
        }
        else
            printf("\n\tWRONG INPUT\n");
    }

    return 0;
}