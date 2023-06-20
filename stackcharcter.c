#include <stdio.h>
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

#include<string.h>
#define MAX 100

int stack[MAX];
int top=-1;

void push(int ele)
{
stack[++top]=ele;
}

int pop()
{
return stack[top--];
}

void calc(char op)
{
int a,b,c;

a=pop();
b=pop();

if(op=='+')
{
c=b+a;
}
else if(op=='-')
{
c=b-a;
}
else if(op=='*')
{
 c=b*a;
}
else if(op=='/')
{
c=b/a;
}

push(c);
}

int main()
{
char postfix[100],ch;
int i;

printf("Enter valid postfix expression : ");
scanf("%s",postfix);

for(i=0;i<strlen(postfix);i++)
{
ch=postfix[i];

if(ch>='0'&&ch<='9')
{
push(ch-48);
}
else if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
{
calc(ch);
}
else
{
printf("Invalid Expression\n");
break;
}
}

printf("Your Expression Answer : %d\n",stack[top]);

return 0;
}

int main()
{
    char infix[MAX], postfix[MAX], ch, x;
    int i, j = 0;

    printf("Enter valid infix expression : ");
    scanf("%s", infix);

    push('#');

    for (i = 0; i < strlen(infix); i++)
    {
        ch = infix[i];

        if (ch >= 'a' && ch <= 'z')
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

    return 0;
}