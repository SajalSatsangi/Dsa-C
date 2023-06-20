#include <stdio.h>
#define n 1
int main()
{
    int a[n], b[n], c[2 * n], f[2 * n], e[2 * n], d, i, j, k = 0, l = 0;
    printf("Enter The Value Of 1 Array - ");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter The Value Of 2 Array - ");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &b[i]);
    }

    int m = n;
    for (i = n; i > n - 1; i--)
    {
        if (i != n)
        {
            for (i = n; i > m; i--)
            {
                c[i] = 0;
            }
        }
       int p = m;
        for (j = n; j > 0; j--)
        {
            c[m] = (a[i] * b[j] + l) % 10;
            l = (a[i] * b[j]) / 10;
            m--;
        }
        c[m] = l;
        for (j = 0; j <= n; j++)
        {
            printf("%d", c[j]);
        }

        l = 0;
        m = p;
        //     if (i != n)
        //     {
        //         for (i = n; i > 0; i--)
        //         {
        //             e[m] = f[m] + c[m];
        //         }
        //     }
        //     for (i = n; i > 0; i--)
        //     {
        //         f[i] = c[i];
        //     }
        //     m = p - 1;
        // }
        // for ( i = 1; i <=2* n; i++)
        // {
        //     printf("%d",e[m]);
    }
}