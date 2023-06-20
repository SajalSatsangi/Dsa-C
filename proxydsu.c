#include <stdio.h>
#include <stdlib.h>
#define INFT 99
#define MAX 20

int parent[9] = {0};

void fillMaxValue(int adjMat[][20], int n)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            adjMat[i][j] = INFT;
        }
    }
}

void undir_graph(int adjMat[][20], int n)
{
    int edges = 0, w, i, j, s = 0, d = 0;
    edges = n * (n - 1) / 2;

    for (i = 1; i <= edges; i++)
    {
        printf("Enter edge %d (-1 -1 to quit): ", i);
        scanf("%d%d", &s, &d);

        if (s == -1 && d == -1)
        {
            break;
        }
        if (s >= n || d >= n || s < 0 || d < 0)
        {
            printf("Invalid edge!\n");
            i--;
        }
        else
        {
            printf("Enter Weight : ");
            scanf("%d", &w);
            adjMat[s][d] = w;
            adjMat[d][s] = w;
        }
    }
}

void display(int adjMat[][20], int n)
{
    int i, j;

    printf("\nThe adjacency matrix is :\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", adjMat[i][j]);
        }
        printf("\n");
    }
}

int find(int i)
{
    while (parent[i])
    {
        i = parent[i];
    }

    return i;
}

int uni(int u, int v)
{
    if (u != v)
    {
        parent[v] = u;
        return 1;
    }

    return 0;
}

int main()
{
    int adjMat[MAX][MAX];
    int i, j, k, a, b, u, v, n, ne = 0;
    int min, mincost = 0;

    printf("Enter number of vertices : ");
    scanf("%d", &n);

    fillMaxValue(adjMat, n);

    undir_graph(adjMat, n);

    display(adjMat, n);

    printf("\nThe edges of Minimum Weight Spanning Tree are\n");
    while (ne < n - 1)
    {
        min = INFT;

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (adjMat[i][j] < min)
                {
                    min = adjMat[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if (uni(u, v))
        {
            printf("Edge %d - %d and Weight: %d\n", a, b, min);
            mincost += min;
        }

        adjMat[a][b] = adjMat[b][a] = INFT;
        ne++;
    }

    printf("\nTotal Minimum Weight = %d\n\n\n\n", mincost);

    return 0;
}