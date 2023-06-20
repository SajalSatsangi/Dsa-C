#include <stdio.h>
#include <stdlib.h>

// Insertion sort in C
void insertionsort(int a[], int N, int choice)
{
    switch (choice)
    {
    case 1:
        for (int i = 1; i < N; i++)
        {
            int temp = a[i];
            int j = i - 1;
            while (j >= 0 && a[j] > temp)
            {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = temp;
        }
        break;
    case 2:
        for (int i = 1; i < N; i++)
        {
            int temp = a[i];
            int j = i - 1;
            while (j >= 0 && a[j] < temp)
            {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = temp;
        }
        break;
    }

    printf("\nSORTED ARRAY (INSERTION SORT) :\n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
    }
}

// Bubble sort in C
void bubblesort(int a[], int N, int choice)
{
    switch (choice)
    {
    case 1:
        for (int i = N - 1; i > 0; i--)
        {
            for (int j = 0; j < i; j++)
            {
                if (a[j] > a[j + 1])
                {
                    int c = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = c;
                }
            }
        }
        break;
    case 2:
        for (int i = N - 1; i > 0; i--)
        {
            for (int j = 0; j < i; j++)
            {
                if (a[j] < a[j + 1])
                {
                    int c = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = c;
                }
            }
        }
    }

    printf("\nSORTED ARRAY (BUUBLE SORT) :\n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
    }
}

void selectionsort(int a[], int N, int choice)
{
    switch (choice)
    {
    case 1:
        for (int i = 0; i < N - 1; i++)
        {
            int min = i;
            for (int j = i; j < N; j++)
            {
                if (a[j] < a[min])
                {
                    min = j;
                }
            }
            if (min != i)
            {
                int c = a[i];
                a[i] = a[min];
                a[min] = c;
            }
        }
        break;
    case 2:
        for (int i = 0; i < N - 1; i++)
        {
            int max = i;
            for (int j = i; j < N; j++)
            {
                if (a[j] > a[max])
                {
                    max = j;
                }
            }
            if (max != i)
            {
                int c = a[i];
                a[i] = a[max];
                a[max] = c;
            }
        }
    }  
    printf("\nSORTED ARRAY (SELSCTION SORT) :\n");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
    }
}

int main()
{
    int N, choice, i = 0;
    printf("\nENTER THE NO OF ELEMENTS :");
    scanf("%d", &N);
    printf("\nENTER 1. FOR ASSENDING ORDER");
    printf("\nENTER 2. FOR DESENDING ORDER");
    printf("\n\n\tENTER YOUR CHOICE : ");
    scanf("%d", &choice);
    if (choice != 2 && choice != 1)
    {
        printf("\n\tYOU HAVE ENTERED WRONG INPUT\n\n");
        exit(0);
    }
    int a[N];
    while (i < N)
    {
        printf("ENTER %d ELEMENT :", i + 1);
        scanf("%d", &a[i]);
        i++;
    }
    insertionsort(a, N, choice);
    bubblesort(a, N, choice);
    selectionsort(a, N, choice);
}