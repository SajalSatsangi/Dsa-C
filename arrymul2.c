#include <stdio.h>

int main()
{
    int N;
    printf("Enter The Value Of N - ");
     scanf("%d" , &N);

    int a[N],b[N],c[2*N],i,j,carry=0;

    for(i=0; i<2*N; i++)
        c[i] = 0;

    printf("Enter The Value Of 1 Array:\n");
    for(i=0; i<N; i++)
    {
        printf(" %d Element - ",i+1);
        scanf("%d", &a[i]);
    }
    printf("Enter The Value Of 2 Array:\n");
    for(i=0; i<N; i++)
    {
        printf(" %d Element - ",i+1);
        scanf("%d", &b[i]);
    }
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            c[j+i] = c[j+i]+ (a[i]*b[j]+carry)%10;
            carry = (a[i]*b[j]+carry)/10;
            if(c[j+i] > 9)
            {
                c[j+i] = c[j+i]%10;
                carry=carry+1;
            }
        }

     c[j+i] = carry;
     carry=0;
    }
    printf("\n  Answer = ");
    for(i=2*N-1; i>=0; i--)
    {
        printf("%d", c[i]);

    }
}