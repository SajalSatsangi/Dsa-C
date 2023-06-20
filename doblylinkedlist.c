#include <stdio.h>
#include <stdlib.h>

typedef struct record
{
    int value;
    struct record *pre;
    struct reccord *next;
} node;
node *startS = NULL; // start for simple doubly linked list
node *startC = NULL; // start for circular doubly linked list

node *creatNode()
{
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    newnode->next = NULL;
    newnode->pre = NULL;
    printf("ENTER THE VALUE : ");
    scanf("%d", &newnode->value);
    return newnode;
}

void addNodeSimAtStart() // add simple doubly node at start
{
    node *ptr;
    ptr = creatNode();
    if (startS == NULL)
    {
        ptr->next = NULL;
        ptr->pre = NULL;
    }
    else
    {
        ptr->next = startS;
        startS->pre = ptr;
    }
    startS = ptr;
}

void addNodeSimAtLast() // add simple doubly node at last
{
    node *ptr, *tmp;
    ptr = creatNode();
    if (startS == NULL)
    {
        ptr->next = NULL;
        ptr->pre = NULL;
        startS = ptr;
    }
    else
    {
        tmp = startS;
        while ((tmp->next) != NULL)
        {
            tmp = tmp->next;
        }
        ptr->pre = tmp;
        tmp->next = ptr;
    }
}

node *delNodeSimAtStart() // delete simple doubly node at start
{
    if (startS == NULL)
        printf("\nNODE IS EMPTY");
    else
    {
        node *tmp;
        tmp = startS;
        startS = startS->next;
        startS->pre = NULL;
        return tmp;
    }
}

node *delNodeSimAtLast() // delete simple doubly node at last
{
    if (startS == NULL)
        printf("\nNODE IS EMPTY");
    else
    {
        node *ptr, *tmp;
        tmp = startS;
        while ((tmp->next) != NULL)
        {
            tmp = tmp->next;
        }
        ptr = tmp->pre;
        ptr->next = NULL;
        return tmp;
    }
}

void addNodeSimAtPos() // add simple doubly node at position
{
    int pos, i;
    int x = countNodeSim();
    x++;
    printf("ENTER THE POSITION : ");
    scanf("%d", pos);
    if (pos > x)
        printf("ENTER VALID POSITION");
    else if (x == 1)
        addNodeSimAtStart();
    else if (x == pos)
        addNodeSimAtLast();
    else
    {
        node *ptr = startS;
        while (i <= pos)
        {
            ptr = ptr->next;
            i++;
        }
        node *newnode = creatNode();
        newnode->pre = ptr;
        node *tmp = ptr->next;
        newnode->next = tmp;
        ptr->next = newnode;
        tmp->pre = newnode;
    }
}

node *delNodeSimAtPos() // delete simple doubly node at position
{
    node *ptr;
    int pos, i;
    int x = countNodeSim();
    printf("ENTER THE POSITION : ");
    scanf("%d", pos);
    if (pos > x)
    {
        printf("ENTER VALID POSITION");
        return 0;
    }
    else if (x == 0)
    {
        printf("NODE IS EMPTY");
        return 0;
    }
    else if (x == 1)
        ptr = delNodeSimAtStart();
    else if (x == pos)
        ptr = delNodeSimAtLast();
    else
    {
        ptr = startS;
        while (i <= pos)
        {
            ptr = ptr->next;
            i++;
        }
        node *tmp = ptr->pre;
        node *tmp1 = ptr->next;
        tmp->next = tmp1;
        tmp1->pre = tmp;
    }
    return ptr;
}

int countNodeSim() // count simple doubly node
{
    if (startS == NULL)
        return 0;
    else
    {
        node *ptr;
        ptr = startS;
        int count = 1;
        while ((ptr->next) != NULL)
        {
            ptr = ptr->next;
            ++count;
        }
        return count;
    }
}

void displayNodeSim() // display simple doubly node with values
{
    if (startS == NULL)
        return 0;
    else
    {
        node *ptr;
        ptr = startS;
        while ((ptr->next) != NULL)
        {
            printf("\n\t%d node : %d\n", ptr->value);
            ptr = ptr->next;
        }
    }
}

void addNodeCirAtStart() // add circular doubly node at start
{
    node *ptr, *tmp;
    ptr = creatNode();
    if (startC == NULL)
    {
        ptr->next = ptr;
        ptr->pre = ptr;
    }
    else
    {
        tmp = startC;
        while ((tmp->next) != startC)
        {
            tmp = tmp->next;
        }
        ptr->pre = tmp;
        tmp->next = ptr;
        ptr->next = startS;
        startS->pre = ptr;
    }
    startC = ptr;
}

void addNodeCirAtLast() // add circular doubly node at last
{
    node *ptr, *tmp;
    ptr = creatNode();
    if (startC == NULL)
    {
        ptr->next = ptr;
        ptr->pre = ptr;
        startC = ptr;
    }
    else
    {
        tmp = startC;
        while ((tmp->next) != startC)
        {
            tmp = tmp->next;
        }
        ptr->pre = tmp;
        tmp->next = ptr;
        ptr->next = startC;
        startC->pre = ptr;
    }
}

node *delNodeCirAtStart() // delete circular doubly node at start
{
    node *ptr, *tmp;
    if (startC == NULL)
        printf("\nNODE IS EMPTY");
    else
    {
        tmp = startC;
        ptr = startC;
        startC = startC->next;
        while ((tmp->next) != startC)
        {
            tmp = tmp->next;
        }
        startC->pre = tmp;
        tmp->next = startC;
        return ptr;
    }
}

int delNodeCirAtLast() // delete circular doubly node at last
{
    node *ptr, *tmp;
    if (startC == NULL)
        printf("\nNODE IS EMPTY");
    else
    {
        tmp = startC;
        while ((tmp->next) != startC)
        {
            tmp = tmp->next;
        }
        ptr = tmp->pre;
        startC->pre = ptr;
        ptr->next = startC;
        return tmp;
    }
}
void addNodeCirAtPos() // add circular doubly node at position
{
    int pos, i;
    int x = countNodeSim();
    x++;
    printf("ENTER THE POSITION : ");
    scanf("%d", pos);
    if (pos > x)
        printf("ENTER VALID POSITION");
    else if (x == 1)
        addNodeCirAtStart();
    else if (x == pos)
        addNodeCirAtLast();
    else
    {
        node *ptr = startC;
        while (i <= pos)
        {
            ptr = ptr->next;
            i++;
        }
        node *newnode = creatNode();
        newnode->pre = ptr;
        node *tmp = ptr->next;
        newnode->next = tmp;
        ptr->next = newnode;
        tmp->pre = newnode;
    }
}

node *delNodeCirAtPos() // delete circular doubly node at position
{
    node *ptr;
    int pos, i;
    int x = countNodeSim();
    printf("ENTER THE POSITION : ");
    scanf("%d", pos);
    if (pos > x)
    {
        printf("ENTER VALID POSITION");
        return 0;
    }
    else if (x == 0)
    {
        printf("NODE IS EMPTY");
        return 0;
    }
    else if (x == 1)
        ptr = delNodeCirAtStart();
    else if (x == pos)
        ptr = delNodeCirAtLast();
    else
    {
        ptr = startC;
        while (i <= pos)
        {
            ptr = ptr->next;
            i++;
        }
        node *tmp = ptr->pre;
        node *tmp1 = ptr->next;
        tmp->next = tmp1;
        tmp1->pre = tmp;
    }
    return ptr;
}

int countNodeCir() // count circular doubly node
{
    if (startC == NULL)
        return 0;
    else
    {
        node *ptr;
        ptr = startC;
        int count = 0;
        while ((ptr->next) != startC)
        {
            ptr = ptr->next;
            count++;
        }
        return count;
    }
}

void displayNodeCir() // display simple doubly node with values
{
    if (startC == NULL)
        return 0;
    else
    {
        node *ptr;
        ptr = startC;
        while ((ptr->next) != startC)
        {
            printf("%d node : %d\n", ptr->value);
            ptr = ptr->next;
        }
    }
}

int main()
{
    int t, c;
    printf("\n\n\n");
    while (1)
    {
        printf("ENTER 1 FOR SIMPLE DOUBLY NODE\n");
        printf("ENTER 2 FOR CIRCULAR DOUBLY NODE\n");
        printf("ENTER 3 FOR EXIT\n");
        printf("\n");
        printf("ENTER YOUR CHOICE : ");
        scanf("%d", &t);
        if (t == 1)
        {
            printf("\n\n");
            while (1)
            {
                int count = countNodeSim();
                printf(" ~DOUBLY SIMPLE NODE~\n\n");
                printf("NUMBER OF NODES IN LINKED LIST : %d\n", count);
                printf("ENTER 1 FOR ADD NODE AT START\n");
                printf("ENTER 2 FOR ADD NODE AT LAST\n");
                printf("ENTER 3 FOR ADD NODE AT POSITION\n");
                printf("ENTER 4 FOR DELETE NODE AT START\n");
                printf("ENTER 5 FOR DELETE NODE AT LAST\n");
                printf("ENTER 6 FOR DELETE NODE AT POSITION\n");
                printf("ENTER 7 FOR BACK TO MAIN MENUE\n\n");
                printf("ENTER YOUR CHOICE : ");
                scanf("%d", &c);
                if (c == 1)
                {
                    addNodeSimAtStart();
                    displayNodeSim();
                }
                else if (c == 2)
                {
                    addNodeSimAtLast();
                    displayNodeSim();
                }
                else if (c == 3)
                {
                    addNodeSimAtPos();
                    displayNodeSim();
                }
                else if (c == 4)
                {
                    node *ptr = delNodeSimAtStart();
                    printf("REMOVED :%d", ptr->value);
                    free(ptr);
                    displayNodeSim();
                }
                else if (c == 5)
                {
                    node *ptr = delNodeSimAtLast();
                    printf("REMOVED :%d", ptr->value);
                    free(ptr);
                    displayNodeSim();
                }
                else if (c == 6)
                {
                    node *ptr = delNodeSimAtPos();
                    if (ptr != 0)
                    {
                        printf("REMOVED :%d", ptr->value);
                        free(ptr);
                        displayNodeSim();
                    }
                }
                else if (c == 7)
                    break;
                else
                {
                    printf("\n");
                    printf(" 'PLEASE INPUT CORRECT CHOICE'");
                }

                printf("\n\n");
            }
        }
        else if (t == 2)
        {
            printf("\n\n");
            while (1)
            {
                printf(" ~DOUBLY CIRCULAR NODE~\n\n");
                int count = countNodeCir();
                printf("NUMBER OF NODES IN LINKED LIST : %d\n", count);
                printf("ENTER 1 FOR ADD NODE AT START\n");
                printf("ENTER 2 FOR ADD NODE AT LAST\n");
                printf("ENTER 3 FOR ADD NODE AT POSITION\n");
                printf("ENTER 4 FOR DELETE NODE AT START\n");
                printf("ENTER 5 FOR DELETE NODE AT LAST\n");
                printf("ENTER 6 FOR DELETE NODE AT POSITION\n");
                printf("ENTER 7 FOR BACK TO MAIN MENUE\n\n");
                printf("ENTER YOUR CHOICE : ");
                scanf("%d", &c);
                if (c == 1)
                {
                    addNodeCirAtStart();
                    displayNodeCir();
                }
                else if (c == 2)
                {
                    addNodeCirAtLast();
                    displayNodeCir();
                }
                else if (c == 3)
                {
                    addNodeCirAtPos();
                    displayNodeCir();
                }
                else if (c == 4)
                {
                    node *ptr = delNodeCirAtStart();
                    printf("REMOVED :%d", ptr->value);
                    free(ptr);
                    displayNodeCir();
                }
                else if (c == 5)
                {
                    node *ptr = delNodeCirAtLast();
                    printf("REMOVED :%d", ptr->value);
                    free(ptr);
                    displayNodeCir();
                }
                else if (c == 6)
                {
                    node *ptr = delNodeCirAtPos();
                    if (ptr != 0)
                    {
                        printf("REMOVED :%d", ptr->value);
                        free(ptr);
                        displayNodeCir();
                    }
                }
                else if (c == 7)
                    break;
                else
                {
                    printf("\n");
                    printf(" 'PLEASE INPUT CORRECT CHOICE'");
                }
                printf("\n\n");
            }
        }
        else if (t == 3)
        {
            printf("\n");
            printf(" ~THANK YOU~\n\n");
            break;
        }
        else
        {
            printf("\n");
            printf(" 'PLEASE INPUT CORRECT CHOICE'");
        }
        printf("\n\n");
    }
    return 0;
}