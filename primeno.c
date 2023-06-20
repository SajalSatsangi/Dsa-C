#include <stdio.h>
#include <math.h>

// find prime no between 2 to n

int primeno1(int i, int n, int comp)
{
    if (i == n)
    {
        printf("\n\tCOMPARISION :%d", comp + 1);
        return 0;
    }
    else if (n % i == 0)
    {
        printf("\n\tCOMPARISION :%d", comp + 1);
        return 1;
    }
    else return primeno1(i + 1, n, comp + 1);
}

int primeno2(int i, int n, int comp)
{
    if (i == n / 2)
    {
        printf("\n\tCOMPARISION :%d", comp + 1);
        return 0;
    }
    else if (n % i == 0)
    {
        printf("\n\tCOMPARISION :%d", comp + 1);
        return 1;
    }
    else
         return primeno2(i + 1, n, comp + 1);
}

int primeno3(int i, int n, int comp)
{
    if (i >= n / 2)
    {
        printf("\n\tCOMPARISION :%d", comp + 1);
        return 0;
    }
    else if (n % 2 == 0)
    {
        printf("\n\tCOMPARISION :%d", comp + 1);
        return 1;
    }
    else if (n % i == 0)
    {
        printf("\n\tCOMPARISION :%d", comp + 1);
        return 1;
    }
    else
        return primeno3(i + 2, n, comp + 1);
}

int primeno4(int i, int n, int comp)
{
    if (i >= sqrt(n))
    {
        printf("\n\tCOMPARISION :%d", comp + 1);
        return 0;
    }
    else if (n % i == 0)
    {
        printf("\n\tCOMPARISION :%d", comp + 1);
        return 1;
    }
    else
        return primeno4(i + 1, n, comp + 1);
}

int primeno5(int i, int n, int comp)
{
    if (i >= sqrt(n))
    {
        printf("\n\tCOMPARISION :%d", comp + 1);
        return 0;
    }
    else if (n % 2 == 0)
    {
        printf("\n\tCOMPARISION :%d", comp + 1);
        return 1;
    }
    else if (n % i == 0)
    {
        printf("\n\tCOMPARISION :%d", comp + 1);
        return 1;
    }
    else
        return primeno5(i + 2, n, comp + 1);
}


int main()
{
    int n;
    printf("\n\nENTER THE No : ");
    scanf("%d", &n);

    printf("\nFOR n");
    int x = primeno1(2, n, 0);
    if (x == 0)
        printf("\n\tNO IS PRIME\n\n");
    else
        printf("\n\tNO IS NOT PRIME\n\n");
  
    printf("FOR n/2");
    int y = primeno2(2, n, 0);
    if (y == 0)
        printf("\n\tNO IS PRIME\n\n");
    else
        printf("\n\tNO IS NOT PRIME\n\n");

    printf("FOR n/4");
    int z = primeno3(3, n, 0);
    if (z == 0)
        printf("\n\tNO IS PRIME\n\n");
    else
        printf("\n\tNO IS NOT PRIME\n\n");

    printf("FOR sqrt of n");
    int a = primeno4(2, n, 0);
    if (a == 0)
        printf("\n\tNO IS PRIME\n\n");
    else
        printf("\n\tNO IS NOT PRIME\n\n");

    printf("FOR sqrt of n/2");
    int b = primeno5(3, n, 0);
    if (b == 0)
        printf("\n\tNO IS PRIME\n\n");
    else
        printf("\n\tNO IS NOT PRIME\n\n");
}
