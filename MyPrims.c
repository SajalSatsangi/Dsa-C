#include<stdio.h>
#define INFINITY 9999
#define MAX 20

void undir_graph(int adjMat[][20],int n)
{
    int edges=0,w,i,j,s=0,d=0;
    edges=n*(n-1)/2;

    for(i=1;i<=edges;i++)
    {
        printf("Enter edge %d (-1 -1 to quit): ",i);
        scanf("%d%d",&s,&d);

        if(s==-1 && d==-1)
        {
            break;
        }
        if(s>=n || d>=n || s<0 || d<0)
        {
            printf("Invalid edge!\n");
            i--;
        }
        else
        {
            printf("Enter Weight : ");
            scanf("%d",&w);
            adjMat[s][d] = w;
            adjMat[d][s] = w;
        }
    }
}

void display(int adjMat[][20],int n)
{
    int i,j;

    printf("\nThe adjacency matrix is :\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",adjMat[i][j]);
        }
        printf("\n");
    }
}

//Function to print the final MST stored in parent[]
void printMST(int parent[],int adjMat[][20],int n)
{
    int i,t=0;

    printf("\nMinimum Spanning Tree\n");
    for(i=1;i<n;i++)
    {
        printf("%d - %d -> %d\n",parent[i],i,adjMat[i][parent[i]]);
        t = t + adjMat[i][parent[i]];
    }

    printf("\nCost of MST : %d\n",t);
}

//Function to find the vertex with minimum cost value
int minWeight(int weight[],int visited[],int n)
{
    int min=INFINITY,minIndex=-1,i;

    for(i=0;i<n;i++)
    {
        if(visited[i]==0 && weight[i]<min)
        {
            min = weight[i];
            minIndex = i;
        }
    }

    return minIndex;
}

//Function to find the MST using adjacency cost matrix representation
void prims(int adjMat[][20],int n)
{
    int parent[n],weight[n],visited[n];
    int i,u,v;

    for(i=0;i<n;i++)
    {
        weight[i]=INFINITY;
        visited[i]=0;
        parent[i]=-1;
    }

    //Include first vertex in MST by setting its cost value to 0.
    weight[0]=0;

    //The MST will have maximum N-1 vertices
    for(i=0;i<n-1;i++)
    {
        // Finding the minimum weight vertex from the set of vertices not yet included in MST
        u = minWeight(weight,visited,n);
        visited[u] = 1;

        for(v=0;v<n;v++)
        {
            // visited[v] is 0 (false) for vertices not yet included in MST
            // weight[] gets updated only if adjMat[u][v] is smaller than weight[v]
            if(adjMat[u][v]!=0 && visited[v]==0 && adjMat[u][v] < weight[v])
            {
                parent[v] = u;
                weight[v] = adjMat[u][v];
            }
        }
    }

    //print the final MST
    printMST(parent,adjMat,n);
}

int main()
{
    int adjMat[MAX][MAX] = {0};
    int n;

    printf("Enter number of vertices : ");
    scanf("%d",&n);

    undir_graph(adjMat,n);

    display(adjMat,n);

    prims(adjMat,n);

    return 0;
}
