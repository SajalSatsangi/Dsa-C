#include <stdio.h>
#include <stdlib.h>

typedef struct record
{
    int value;
    struct record *next;
} node;

node *start1 = NULL;
node *start2 = NULL;
node *start3 = NULL;
int z = 0;

node *createNode(int k)
{
    node *newnode;

    newnode = (node *)malloc(sizeof(node));
    newnode->value = k;
    newnode->next = NULL;

    return newnode;
}

void displayll1()
{
    node *tmp = start1;

    if (tmp == NULL)
    {
        printf("\tNumber 1 Not Exists\n");
    }
    else
    {
        printf("\tNUumber 1 : ");

        while (tmp != NULL)
        {
            printf("%d ", tmp->value);
            tmp = tmp->next;
        }
        printf("\n");
    }
}

void displayll2()
{
    node *tmp = start2;

    if (tmp == NULL)
    {
        printf("\tNumber 2 Not Exists\n");
    }
    else
    {
        printf("\tNumber 2 : ");

        while (tmp != NULL)
        {
            printf("%d ", tmp->value);
            tmp = tmp->next;
        }
        printf("\n");
    }
}

void displayll3()
{
    node *tmp = start3;

    if (tmp == NULL)
    {
        printf("\nAddition Not Exists\n");
    }
    else
    {
        printf("\tAddition : ");

        while (tmp != NULL)
        {
            printf("%d ", tmp->value);
            tmp = tmp->next;
        }
        printf("\n");
    }
}

void creatlinkedlist1(int n)
{
    while (n % 10 != 0)
    {
        int r = n % 10;
        n = n / 10;
        node *ptr = createNode(r);
        if (start1 == NULL)
            start1 = ptr;
        else
        {
            ptr->next = start1;
            start1 = ptr;
        }
    }
    displayll1();
}

void creatlinkedlist2(int n)
{
    while (n % 10 != 0)
    {
        int r = n % 10;
        n = n / 10;
        node *ptr = createNode(r);
        if (start2 == NULL)
            start2 = ptr;
        else
        {
            ptr->next = start2;
            start2 = ptr;
        }
    }
    displayll2();
}

void creatlinkedlist3(node *ptr1, node *ptr2)
{
    int n = ptr1->value + ptr2->value + z;
    int r = n % 10;
    z = n / 10;
    node *ptr3 = createNode(r);

    if (start3 == NULL)
        start3 = ptr3;
    else
    {
        ptr3->next = start3;
        start3 = ptr3;
    }
}

// void addintegers()
// {
//     node *ptr1 = start1;
//     node *ptr2 = start2;
//     node *tmp1 = ptr1;
//     node *tmp2 = ptr2;

//     while (tmp1->next != NULL && tmp2->next != NULL)
//     {
//         while (ptr1->next->next != NULL)
//             ptr1 = ptr1->next;
//         while (ptr2->next->next != NULL)
//             ptr2 = ptr2->next;

//         node *del1 = ptr1->next;
//         node *del2 = ptr2->next;
//         creatlinkedlist3(del1, del2);
//         ptr1->next = NULL;
//         ptr2->next = NULL;
//         ptr1 = tmp1;
//         ptr2 = tmp2;
//     }
//     ptr1 = tmp1;
//     ptr2 = tmp2;
//     node *del1 = tmp1;
//     node *del2 = tmp2;
//     while (tmp1->next != NULL)
//         tmp1 = tmp1->next;
//     while (tmp2->next != NULL)
//         tmp2 = tmp2->next;
//     creatlinkedlist3(tmp1, tmp2);

//     // while (del1->next->next != NULL)
//     //     del1 = del1->next;
//     // del1->next = NULL;
//     // while (del2->next->next != NULL)
//     //     del2 = del2->next;
//     // del2->next = NULL;

//     if (ptr1->next != NULL)
//     {
//         node *ptr = ptr1;
//         while (ptr1->next != NULL)
//             ptr1 = ptr1->next;
//         ptr1->next = start3;
//         ptr1->value = ptr1->value + z;
//         start3 = ptr;
//     }
//     else if (ptr2->next != NULL)
//     {
//         node *ptr = ptr2;
//         while (ptr2->next != NULL)
//             ptr2 = ptr2->next;
//         ptr2->value = ptr2->value + z;
//         ptr2->next = start3;
//         start3 = ptr;
//     }
//     else
//     {
//         node *ptr = createNode(z);
//         ptr->next = start3;
//         start3 = ptr;
//     }
//     displayll3();
// }

node *addTwoLists()
{
    node *first = start1, *second = start2;
    // res is head node of the resultant list
    node *res = start3;
    node *temp, *prev = NULL;
    int carry = 0, sum;

    // while both lists exist
    while (first != NULL || second != NULL)
    {
        // Calculate value of next digit in resultant list.
        // The next digit is sum of following things
        // (i) Carry
        // (ii) Next digit of first list (if there is a next digit)
        // (ii) Next digit of second list (if there is a next digit)
        sum = carry + (first ? first->value : 0) + (second ? second->value : 0);
        // update carry for next calculation
        carry = (sum >= 10) ? 1 : 0;
        // update sum if it is greater than 10
        sum = sum % 10;
        // Create a new node with sum as value
        temp = createNode(sum);
        // if this is the first node then set it as head of the resultant list
        if (res == NULL)
            res = temp;
        // If this is not the first node then connect it to the rest.
        else
            prev->next = temp;

        // Set prev for next insertion
        prev = temp;

        // Move first and second pointers to next nodes
        if (first)
            first = first->next;
        if (second)
            second = second->next;
    }
    if (carry > 0)
        temp->next = createNode(carry);
    // return head of the resultant list
    start3 = res;
    displayll3();
}

int main()
{
    int n1, n2;
    printf("\nENTER THE FIRST NO : ");
    scanf("%d", &n1);
    creatlinkedlist1(n1);
    printf("\nENTER THE SECOND NO : ");
    scanf("%d", &n2);
    creatlinkedlist2(n2);
    addTwoLists();
}