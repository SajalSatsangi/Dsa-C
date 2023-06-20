// This code is created by sajal satsangi

// C program to add two numbers
// represented by linked list
#include <stdio.h>
#include <stdlib.h>

/* Linked list node */
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

/* Function to create a
new node with given data */
Node *newNode(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

/* Function to insert a node at the
beginning of the Singly Linked List */
void push(Node **head_ref, int new_data)
{
    /* allocate node */
    Node *new_node = newNode(new_data);
    /* link the old list off the new node */
    new_node->next = (*head_ref);
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

/* Adds contents of two linked lists and
return the head node of resultant list */
Node *addTwoLists(Node *first, Node *second)
{
    // res is head node of the resultant list
    Node *res = NULL;
    Node *temp, *prev = NULL;
    int carry = 0, sum;

    // while both lists exist
    while (first != NULL || second != NULL)
    {
        // Calculate value of next digit in resultant list.
        // The next digit is sum of following things
        // (i) Carry
        // (ii) Next digit of first list (if there is a next digit)
        // (ii) Next digit of second list (if there is a next digit)
        sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
        // update carry for next calculation
        carry = (sum >= 10) ? 1 : 0;
        // update sum if it is greater than 10
        sum = sum % 10;
        // Create a new node with sum as data
        temp = newNode(sum);
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
        temp->next = newNode(carry);
    // return head of the resultant list
    return res;
}

Node *reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    // reverse the rest list and put the first element at the end
    Node *rest = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    // fix the head pointer
    return rest;
}

// A function to print a linked list
void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main(void)
{
    int n1, n2;
    Node *res = NULL;
    Node *first = NULL;
    Node *second = NULL;

    // create first list 7->5->9->4->6
    printf("\nENTER THE FIRST NO : ");
    scanf("%d", &n1);
    while (n1 % 10 != 0)
    {
        int r = n1 % 10;
        n1 = n1 / 10;
        push(&first, r);
    }
    
    printf("First list is ");
    printList(first);

    // create second list 8->4
    printf("\nENTER THE FIRST NO : ");
    scanf("%d", &n2);
    while (n2 % 10 != 0)
    {
        int r = n2 % 10;
        n2 = n2 / 10;
        push(&second, r);
    }
    printf("Second list is ");
    printList(second);

    // reverse both the lists
    first = reverse(first);
    second = reverse(second);
    // Add the two lists
    res = addTwoLists(first, second);

    // reverse the res to get the sum
    res = reverse(res);
    printf("Resultant list is ");
    printList(res);
    return 0;
}

// This code is created by sajal satsangi