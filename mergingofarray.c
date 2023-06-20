#include <stdio.h>
int main()
{
    int n1, n2, n3; // Array Size Declaration
    int a[10000], b[10000], c[20000];
    printf("Enter the size of first array: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++)
    {
        printf("Enter the %d elements: ", i + 1);
        scanf("%d", &a[i]);
    }
    printf("Enter the size of second array: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++)
    {
        printf("Enter the %d elements: ", i + 1);
        scanf("%d", &b[i]);
    }
    n3 = n1 + n2;
    for (int i = 0; i < n1; i++)
        c[i] = a[i];
    for (int i = 0; i < n2; i++)
        c[i + n1] = b[i];

    printf("The merged array: ");
    for (int i = 0; i < n3; i++)
        printf("%d ", c[i]); // Print the merged array

    printf("\nFinal array after sorting: ");
    for (int i = 0; i < n3; i++)
    {
        int temp;
        for (int j = i + 1; j < n3; j++)
        {
            if (c[i] > c[j])
            {
                temp = c[i];
                c[i] = c[j];
                c[j] = temp;
            }
        }
    }

    for (int i = 0; i < n3; i++) // Print the sorted Array
        printf(" %d ", c[i]);
    
    int k = 0;   
    for (int i = 0; i < n3-1-k; i++)
    {
        if (c[i+1] == c[i])
        {
            k++;
            for (int j = i + 1; j < n3-k; j++)
            {
                c[j] = c[j + 1];
            }
        }
    }

    printf("\nFinal array after sorting: ");
    for (int i = 0; i < n3-k; i++) // Print the sorted Array
        printf(" %d ", c[i]);
    return 0;
}