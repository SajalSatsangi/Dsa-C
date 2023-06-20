#include <stdio.h>
#define max 100

int stack[max], top = -1;

void push(int ele)
{
    stack[++top] = ele;
}

int pop()
{
    return stack[top--];
}

int isOverflow()
{
    if (top == max - 1)
        return 1;
    return 0;
}

int isUnderflow()
{
    if (top == -1)
        return 1;
    return 0;
}

void peekele()
{
    printf("\n\tPEEK ELEMENT No : %d\t", top + 1);
    printf("\n\tPEEK ELEMENT : %d\n", stack[top]);
}

void display()
{
    int i;
    printf("\tSTACK ELEMENTS : ");
    for (i = 0; i <= top; i++)
        printf("%d\t", stack[i]);
}

int main()
{
    int choice, ele;

    while (1)
    {
        printf("\n\n1. PUSH ELEMENT\n");
        printf("2. POP ELEMENT\n");
        printf("3. DISPLAY STACK\n");
        printf("4. EXIT\n");
        printf("\n\tENTER YOUR CHOICE : ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            if (isOverflow())
                printf("\n\tSTACK IS FULL\n");
            else
            {
                printf("\tENTER YOUR ELEMENT :");
                scanf("%d", &ele);
                push(ele);
                printf("%d ELEMENT SUCCESSFULLY INSERTED\n", ele);
            }
        }
        else if (choice == 2)
        {
            if (isUnderflow())
                printf("\n\tSTACK IS EMPTY\n");
            else
            {
                ele = pop();
                printf("  %d ELEMENT SUCCESSFULLY REMOVED\n", ele);
            }
        }
        else if (choice == 3)
        {
            peekele();
            if (isUnderflow())
                printf("\n\tSTACK IS EMPTY\n");
            else
                display();
        }
        else if (choice == 4)
        {
            printf("\n\t~ THANK YOU ~\n\n");
            break;
        }
        else
            printf("\n\tWRONG INPUT\n");
    }

    return 0;
}