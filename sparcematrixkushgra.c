// #include <stdio.h>
// typedef struct
// {
//     int row;
//     int col;
//     int value;
// } sparse_mat_term;
// int pa = 0, pb = 0, na, nb, padd = 1, i, j, k, n, sum, r, c, v;
// sparse_mat_term a[10], b[10], add[20];
// void insert(int, int, int, int);
// void print(sparse_mat_term, int);

// void addition();
// void insert(int r, int c, int val, int ch)
// {
//     switch (ch)
//     {
//     case 1:
//         a[pa].row = r;
//         a[pa].col = c;
//         a[pa++].value = val;
//         break;
//     case 2:
//         b[pb].row = r;
//         b[pb].col = c;
//         b[pb++].value = val;
//         break;
//     case 3:
//         add[padd].row = r;
//         add[padd].col = c;
//         add[padd++].value = val;
//         break;
//     }
// }
// void printMat(sparse_mat_term mat[], int n)
// {
//     printf("Row\tCol\tValue\n");
//     for (i = 0; i <= n; i++)
//         printf("%d\t%d\t%d\n", mat[i].row, mat[i].col, mat[i].value);
// }
// void addition()
// {
//     add[0].row = a[0].row;
//     add[0].col = a[0].col;
//     if (a[0].row != b[0].row || a[0].col != b[0].col)
//         printf("Matrices can't be added");
//     else
//     {
//         pa = 1;
//         pb = 1;
//         while (pa <= na && pb <= nb)
//         {
//             if (a[pa].row > b[pb].row || (a[pa].row == b[pb].row && a[pa].col > b[pb].col))
//             {
//                 insert(b[pb].row, b[pb].col, b[pb].value, 3);
//                 pb++;
//             }
//             else if (a[pa].row < b[pb].row || (a[pa].row == b[pb].row && a[pa].col < b[pb].col))

//             {
//                 insert(a[pa].row, a[pa].col, a[pa].value, 3);
//                 pa++;
//             }
//             else
//             {
//                 sum = 0;
//                 sum = a[pa].value + b[pb].value;
//                 if (sum != 0)
//                     insert(a[pa].row, a[pa].col, sum, 3);
//                 pa++;
//                 pb++;
//             }
//         }
//         while (pa <= na)
//         {
//             insert(a[pa].row, a[pa].col, a[pa].value, 3);
//             pa++;
//         }
//         while (pb <= nb)
//         {
//             insert(b[pb].row, b[pb].col, b[pb].value, 3);
//             pb++;
//         }
//     }
//     add[0].value = padd - 1;
// }

// void main()
// {
//     for (k = 1; k <= 2; k++)
//     {
//         printf("Input for Sparse matrix %d\n", k);
//         printf("Enter the no. of rows, columns and the no. of non-zero elements in the sparse matrix \n");
//         scanf("%d%d%d", &r, &c, &v);
//         insert(r, c, v, k);
//         n = v;
//         for (i = 1; i <= n; i++)
//         {
//             printf("Enter the row, col and value of the %d element \n", i);
//             scanf("%d%d%d", &r, &c, &v);
//             insert(r, c, v, k);
//         }
//     }
//     na = a[0].value;
//     nb = b[0].value;
//     printf("\nSparse Matrix A");
//     printMat(a, na);
//     printf("\nSparse Matrix B");
//     printMat(b, nb);
//     addition();
//     printf("\nAddition Matrix");
//     printMat(add, add[0].value);
// }

#include <stdio.h>
typedef struct
{
    int row;
    int col;
    int value;
} sparse_mat_term;

void main()
{
    int i, j, n, pb;
    sparse_mat_term a[10], b[10];
    printf("Enter the no. of rows, columns and the no. of non-zero elements\n");
    scanf("%d%d%d", &a[0].row, &a[0].col, &a[0].value);
    n = a[0].value;
    for (i = 1; i <= n; i++)
    {
        printf("Enter the row, col and value of the element %d\n", i);
        scanf("%d%d%d", &a[i].row, &a[i].col, &a[i].value);
    }
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = a[0].value;
    if (n > 0)
    {
        pb = 1;
        for (i = 0; i < a[0].col; i++)
            for (j = 1; j <= n; j++)
            {
                if (a[j].col == i)
                {
                    b[pb].row = a[j].col;
                    b[pb].col = a[j].row;
                    b[pb].value = a[j].value;
                    pb++;
                }
            }
        printf("Row\tCol\tValue\n");
        for (i = 0; i <= n; i++)
            printf("%d\t%d\t%d\n", b[i].row, b[i].col, b[i].value);
    }
}