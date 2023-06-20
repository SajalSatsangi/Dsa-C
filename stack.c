#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

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
    if (top == MAX - 1)
        return 1;
    else
        return 0;
}

int isUnderflow()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

void display()
{
    int i;

    printf("Stack Elements : ");
    for (i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }

    printf("\n");
}

int main()
{
    int ch, ele;

    while (1)
    {
        printf("\n1. Push Element\n");
        printf("2. Pop Element\n");
        printf("3. Display Elements\n");
        printf("4. Exit\n");
        printf("Enter Your Choice : ");
        scanf("%d", &ch);

        if (ch == 1)
        {
            if (isOverflow())
            {
                printf("Stack is Full\n");
            }
            else
            {
                printf("Enter Your Element : ");
                scanf("%d", &ele);

                push(ele);
                printf("%d element successfully inserted\n", ele);
            }
        }
        else if (ch == 2)
        {
            if (isUnderflow())
            {
                printf("Stack is Empty\n");
            }
            else
            {
                ele = pop();
                printf("%d element successfully\n", ele);
            }
        }
        else if (ch == 3)
        {
            if (isUnderflow())
                printf("Stack is Empty\n");
            else
                display();
        }
        else if (ch == 4)
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