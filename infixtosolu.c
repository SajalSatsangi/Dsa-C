#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char ele)
{
    stack[++top] = ele;
}

char pop()
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

int getPriority(char op)
{
    if (op == '/' || op == '*')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

int isOperator(char op)
{
    if (op == '+' || op == '*' || op == '-' || op == '/')
        return 1;
    else
        return 0;
}

void push2(int ele)
{
    stack[++top] = ele;
}

int pop2()
{
    return stack[top--];
}

void calc(char op)
{
    int a, b, c;

    a = pop2();
    b = pop2();

    if (op == '+')
    {
        c = b + a;
    }
    else if (op == '-')
    {
        c = b - a;
    }
    else if (op == '*')
    {
        c = b * a;
    }
    else if (op == '/')
    {
        c = b / a;
    }

    push2(c);
}

int main()
{
    char infix[MAX], postfix[MAX], ch, x;
    int i, j = 0, cheack = 1;

    printf("Enter valid infix expression : ");
    scanf("%s", infix);

    push('#');

    for (i = 0; i < strlen(infix); i++)
    {
        ch = infix[i];

        if (ch >= '0' && ch <= '9')
        {
            postfix[j++] = ch;
        }
        else if (isOperator(ch))
        {
            while (getPriority(ch) <= getPriority(stack[top]))
            {
                postfix[j++] = pop();
            }

            push(ch);
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            x = pop();
            while (x != '(')
            {
                postfix[j++] = x;
                x = pop();
            }
        }
    }

    while ((x = pop()) != '#')
    {
        postfix[j++] = x;
    }

    postfix[j] = '\0';

    printf("Postfix Expression : %s\n", postfix);

    for (i = 0; i < strlen(postfix); i++)
    {
        ch = postfix[i];

        if (ch >= '0' && ch <= '9')
        {
            push2(ch - 48);
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            calc(ch);
        }
        else
        {
            printf("Invalid Expression\n");
            cheack = 0;
            break;
        }
    }
    if (cheack)
        printf("Your Expression Answer : %d\n", stack[top]);

    return 0;
}