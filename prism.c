#include <stdio.h>
#define max 99999

int minWeight(int n, int visited[], int weight[])
{
    int minWeight, min;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] != 0)
        {
            if (weight[i] < minWeight)
            {
                minWeight == weight[i];
                min = i;
            }
        }
    }
    return min;
}

int main()
{
    int parant[max], weight[max], visited[max], n, v;
    printf("ENTER THE NO OF VERTAX :");
    scanf("%d", n);
    for (int i = 0; i < n - 1; i++)
    {
        int u = minWeight(n, visited, weight);
        visited[u] = 1;
        for (v = 0; v < n; v++)
        {
            if (visited[v] != 0)
            {
                parant[v] = u;
            }
        }
    }
}