#include <stdio.h>
#define max 100

int nonzerocount(int sparse[][6], int row, int column)
{
    int nz = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (sparse[i][j] != 0)
            {
                nz++;
            }
        }
    }
    return nz;
}

void printtriplet(int triplet[][3])
{
    for (int i = 0; i <= triplet[0][2]; i++)
        printf("%d %d %d\n", triplet[i][0], triplet[i][1], triplet[i][2]);
}

void builttripletzero(int triplet[][3])
{
    for (int i = 0; i <= 36; i++)
        for (int j = 0; j < 3; j++)
            triplet[i][j] = 0;
}

void maketriplet(int sparse[][6], int row, int column, int triplet[][3], int nz)
{
    int k = 1;
    triplet[0][0] = row;
    triplet[0][1] = column;
    triplet[0][2] = nz;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (sparse[i][j] != 0)
            {
                triplet[k][0] = i;
                triplet[k][1] = j;
                triplet[k][2] = sparse[i][j];
                k++;
            }
        }
    }
}

void addition(int triplet1[][3], int triplet2[][3], int triplet3[][3])
{
    int k = 1;
    int i = 1;
    int j = 1;

    while (triplet1[0][2] >= i && triplet2[0][2] >= j)
    {
        if (triplet1[i][0] == triplet2[j][0])
        {
            if (triplet1[i][1] == triplet2[j][1])
            {
                triplet3[k][0] = triplet1[i][0];
                triplet3[k][1] = triplet1[i][1];
                triplet3[k][2] = triplet1[i][2] + triplet2[j][2];
                k++;
                i++;
                j++;
            }
            else if (triplet1[i][1] > triplet2[j][1])
            {
                triplet3[k][0] = triplet2[j][0];
                triplet3[k][1] = triplet2[j][1];
                triplet3[k][2] = triplet2[j][2];
                k++;
                j++;
            }
            else
            {
                triplet3[k][0] = triplet1[i][0];
                triplet3[k][1] = triplet1[i][1];
                triplet3[k][2] = triplet1[i][2];
                k++;
                i++;
            }
        }
        else if (triplet1[i][0] > triplet2[j][0])
        {

            triplet3[k][0] = triplet2[j][0];
            triplet3[k][1] = triplet2[j][1];
            triplet3[k][2] = triplet2[j][2];
            k++;
            j++;
        }
        else
        {

            triplet3[k][0] = triplet1[i][0];
            triplet3[k][1] = triplet1[i][1];
            triplet3[k][2] = triplet1[i][2];
            k++;
            i++;
        }
    }

    triplet3[0][0] = 6;
    triplet3[0][1] = 6;
    triplet3[0][2] = k - 1;
}

void multiplication(int triplet1[][3], int triplet2[][3], int triplet4[][3])
{
    int k = 1;
    for (int i = 0; i <= triplet1[0][2]; i++)
    {
        triplet4[k][2] = 0;
        for (int j = 0; j <= triplet2[0][2]; j++)
        {
            if (triplet1[i][0] == triplet2[j][1] && triplet1[i][1] == triplet2[j][0])
            {
                triplet4[k][2] = triplet4[k][2] + triplet1[i][2] * triplet2[j][2];
            }
        }
        k++;
    }

    printf("\n\nMULTIPLICATION OF MATRIX :\n");
    printtriplet(triplet4);
}

int main()
{
    /* this is applicable only when column in the matrix is known to use before the execution of the program since during passsing the array in the fucntion we need to define what is the number of column present in the matrix

    int matrix[max][max];
    int row, column;

    printf("Enter the no of rows in the matrix");
    scanf("%d", &row);

    printf("Enter the no of rows in the matrix");
    scanf("%d", &column);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("Enter the %d,%d element of matrix", i,j);
            scanf("%d", matrix[i][j]);
        }
    }
    */

    int sparse1[6][6] =
        {
            {0, 0, 0, 0, 9, 0},
            {0, 8, 0, 0, 0, 0},
            {4, 0, 0, 2, 0, 0},
            {0, 0, 0, 0, 0, 5},
            {0, 0, 0, 0, 0, 5},
            {0, 0, 2, 0, 0, 0}};

    int sparse2[6][6] =
        {
            {0, 0, 0, 0, 9, 0},
            {0, 8, 0, 0, 0, 0},
            {4, 0, 0, 2, 0, 0},
            {2, 0, 0, 0, 0, 5},
            {0, 0, 0, 0, 0, 5},
            {0, 0, 2, 0, 0, 0}};

    int row = 6;
    int column = 6;
    int nz1 = nonzerocount(sparse1, row, column);
    int nz2 = nonzerocount(sparse2, row, column);
    int triplet1[nz1 + 1][3];
    int triplet2[nz2 + 1][3];
    int triplet3[36 + 1][3]; // stores the addition of the triplet
    // int triplet
    builttripletzero(triplet3);

    maketriplet(sparse1, row, column, triplet1, nz1);
    printf("\n First triplet is: \n");
    printtriplet(triplet1);

    maketriplet(sparse2, row, column, triplet2, nz2);
    printf("\n Second triplet is: \n");
    printtriplet(triplet2);

    addition(triplet1, triplet2, triplet3);
    printf("\n Addition of the triplet is: \n");
    printtriplet(triplet3);

    multiplication(triplet1, triplet2, triplet3);
    return 0;
}