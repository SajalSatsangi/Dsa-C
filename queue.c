#include <stdio.h>
#define max 5
int queue[max];
int front, rear;

void add()
{
    int item;
    if (rear == max - 1)
        printf("\n\n\t Queue is full...,");
    else
    {
        printf("\n\n\t Enter the element to be inserted in the queue:-");
        scanf("%d", &item);
        ++rear;
        queue[rear] = item;
        if (front == -1)
            front = 0;
    }
}

void display()
{
    int i;
    if (front == -1)
        printf("sorry no element in the queue...,");
    else
    {
        printf("the element in the queue are....");
        for (i = front; i <= rear; i++)
            printf("\n\t %d", queue[i]);
    }
}

void del()
{
    int item;
    if (front == -1)
        printf("\n\n\t Sorry no elements to delete...,");
    else
    {
        item = queue[front];
        printf("\n\n\t The deleted item = %d", item);
        front++;
    }
    if (front == rear)
        front = rear = -1;
    else
        front++;
}

void main()
{
    front = rear = -1;
    int ch;
    while (1)
    {
        printf("\n\n\t Operations performed on a queue using array");
        printf("\n\n\t 1. add");
        printf("\n\n\t 2. delete");
        printf("\n\n\t 3. display");
        printf("\n\n\t 4. exit");
        printf("\n\n\t Enter your choice:- ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            add();
            break;
        case 2:
            del();
            break;
        case 3:
            display();
            break;
        case 4:
            goto label;
            break;
        default:
            printf("YOU HAVE ENTERED WRONG INPUT :");
            break;
        }
    }
    label:
        printf("Thank you for using");  
}