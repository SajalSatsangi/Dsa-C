#include <stdio.h>

void printSparse(int sparse[5][6])
{
    int i, j;

    printf("\nSparse Matrix:\n");
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 6; j++)
        {
            printf("%d\t", sparse[i][j]);
        }
        printf("\n");
    }
}

int count(int sparse[][6])
{
    int count = 0, i, j, k = 0;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 6; j++)
        {
            if (sparse[i][j] != 0)
                count++;
        }
    }
    return count;
}

void sparsetotriplet(int sparse[5][6], int count, int triplet[][3])
{
    int i, j, k = 0;
    triplet[k][0] = 5;
    triplet[k][1] = 6;
    triplet[k][2] = count;
    k++;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 6; j++)
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
    printf("\n\nTriplet Matrix:\n");
    for (i = 0; i <= triplet[0][2]; i++)
    {
        printf("%d %d %d\n", triplet[i][0], triplet[i][1], triplet[i][2]);
    }
}

void simpleTranspose(int transpose[][3], int triplet[][3])
{
    int i, j, k = 1;

    transpose[0][0] = triplet[0][1];
    transpose[0][1] = triplet[0][0];
    transpose[0][2] = triplet[0][2];

    for (j = 0; j < triplet[0][1]; j++)
    {
        for (i = 1; i <= triplet[0][2]; i++)
        {
            if (triplet[i][1] == j)
            {
                transpose[k][0] = triplet[i][1];
                transpose[k][1] = triplet[i][0];
                transpose[k][2] = triplet[i][2];
                k++;
            }
        }
    }
    printf("\n\nTranspose Matrix:\n");
    for ( i = 0; i <= transpose[0][2]; i++)
    {
        printf("%d %d %d\n", transpose[i][0], transpose[i][1], transpose[i][2]);
    }
    
}

int main()
{
    int sparse[5][6] =
        {
            {0, 0, 0, 0, 9, 0},
            {0, 8, 0, 0, 0, 0},
            {4, 0, 0, 2, 0, 0},
            {0, 0, 0, 0, 0, 5},
            {0, 0, 2, 0, 0, 0}};
    printSparse(sparse);
    int nonzero = count(sparse);
    int triplet[nonzero + 1][3];
    sparsetotriplet(sparse, nonzero, triplet);
    int transpose[nonzero + 1][3];
    simpleTranspose(transpose, triplet);
}