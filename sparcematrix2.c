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

void printTriplet(int triplet[][3])
{
    int i;

    for (i = 0; i <= triplet[0][2]; i++)
    {
        printf("%d\t%d\t%d\n", triplet[i][0], triplet[i][1], triplet[i][2]);
    }
}

int countNonZero(int sparse[5][6])
{
    int nz = 0, i, j;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 6; j++)
        {
            if (sparse[i][j] != 0)
                nz++;
        }
    }

    return nz;
}

void makeTriplet(int triplet[][3], int sparse[5][6], int nz)
{
    int i, j, k = 1;

    triplet[0][0] = 5;
    triplet[0][1] = 6;
    triplet[0][2] = nz;

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
}

void fastTranspose(int f_transpose[][3], int triplet[][3])
{
    int i, j, loc, col_no;
    int total[triplet[0][1]];
    int index[triplet[0][1] + 1];

    for (i = 0; i < triplet[0][1]; i++)
    {
        total[i] = 0;
    }

    for (i = 1; i <= triplet[0][2]; i++)
    {
        col_no = triplet[i][1];
        total[col_no]++;
    }

    index[0] = 1;

    for (i = 1; i <= triplet[0][1]; i++)
    {
        index[i] = index[i - 1] + total[i - 1];
    }

    f_transpose[0][0] = triplet[0][1];
    f_transpose[0][1] = triplet[0][0];
    f_transpose[0][2] = triplet[0][2];

    for (i = 1; i <= triplet[0][2]; i++)
    {
        col_no = triplet[i][1];
        loc = index[col_no];
        f_transpose[loc][0] = triplet[i][1];
        f_transpose[loc][1] = triplet[i][0];
        f_transpose[loc][2] = triplet[i][2];
        index[col_no]++;
    }
}

void addSparse(int addition[][3], int triplet1[][3], int triplet2[][3])
{
    int nz1, nz2, i = 1, j = 1, k = 1;

    nz1 = triplet1[0][2];
    nz2 = triplet2[0][2];

    addition[0][0] = triplet1[0][0];
    addition[0][1] = triplet1[0][1];

    while (i <= nz1 && j <= nz2)
    {
        if (triplet1[i][0] == triplet2[j][0])
        {
            if (triplet1[i][1] == triplet2[j][1])
            {
                addition[k][0] = triplet1[i][0];
                addition[k][1] = triplet1[i][1];
                addition[k][2] = triplet1[i][2] + triplet2[j][2];
                i++;
                j++;
                k++;
            }
            else
            {
                if (triplet1[i][1] < triplet2[j][1])
                {
                    addition[k][0] = triplet1[i][0];
                    addition[k][1] = triplet1[i][1];
                    addition[k][2] = triplet1[i][2];
                    i++;
                    k++;
                }
                else
                {
                    addition[k][0] = triplet2[j][0];
                    addition[k][1] = triplet2[j][1];
                    addition[k][2] = triplet2[j][2];
                    j++;
                    k++;
                }
            }
        }
        else
        {
            if (triplet1[i][0] < triplet2[j][0])
            {
                addition[k][0] = triplet1[i][0];
                addition[k][1] = triplet1[i][1];
                addition[k][2] = triplet1[i][2];
                i++;
                k++;
            }
            else
            {
                addition[k][0] = triplet2[j][0];
                addition[k][1] = triplet2[j][1];
                addition[k][2] = triplet2[j][2];
                j++;
                k++;
            }
        }
    }

    while (i <= nz1)
    {
        addition[k][0] = triplet1[i][0];
        addition[k][1] = triplet1[i][1];
        addition[k][2] = triplet1[i][2];
        i++;
        k++;
    }

    while (j <= nz2)
    {
        addition[k][0] = triplet2[j][0];
        addition[k][1] = triplet2[j][1];
        addition[k][2] = triplet2[j][2];
        j++;
        k++;
    }

    addition[0][2] = k - 1;
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

    int nonzero, i, j, k;

    // Counting Non-Zero Elements
    nonzero = countNonZero(sparse);

    // Sparse to Triplet Conversion
    int triplet[nonzero + 1][3];

    makeTriplet(triplet, sparse, nonzero);

    printf("\nTriplet Representation:\n");
    printTriplet(triplet);

    // Triplet to Sparse Conversion
    int newSparse[5][6] = {0};
    for (i = 1; i <= triplet[0][2]; i++)
    {
        newSparse[triplet[i][0]][triplet[i][1]] = triplet[i][2];
    }

    printSparse(newSparse);

    // simple transpose operation
    int transpose[nonzero + 1][3];

    simpleTranspose(transpose, triplet);

    printf("\nSimple Triplet Transpose:\n");
    printTriplet(transpose);

    // fast transpose operation
    int f_transpose[nonzero + 1][3];

    fastTranspose(f_transpose, triplet);

    printf("\nFast Triplet Transpose:\n");
    printTriplet(f_transpose);

    /* .::Sparse Matrix Addition Code Start ::. */

    int sparse2[5][6] =
        {
            {0, 0, 2, 0, 4, 0},
            {0, 8, 0, 0, 0, 0},
            {4, 0, 0, 1, 2, 0},
            {0, 3, 0, 0, 0, 6},
            {0, 0, 4, 0, 0, 0}};

    // Counting Non-Zero Elements
    nonzero = countNonZero(sparse2);

    // Sparse to Triplet Conversion
    int triplet2[nonzero + 1][3];

    makeTriplet(triplet2, sparse2, nonzero);

    printf("\nTriplet 1 Representation:\n");
    printTriplet(triplet);

    printf("\nTriplet 2 Representation:\n");
    printTriplet(triplet2);

    int addition[100][3];

    // Sparse triplet addition
    addSparse(addition, triplet, triplet2);

    printf("\nAddition Result Triplet Representation:\n");
    printTriplet(addition);

    return 0;
}