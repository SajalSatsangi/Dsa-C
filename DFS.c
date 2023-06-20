// // DFS algorithm in C

// #include <stdio.h>
// #include <stdlib.h>

// struct node
// {
//     int vertex;
//     struct node *next;
// };

// struct node *createNode(int v);

// struct Graph
// {
//     int numVertices;
//     int *visited;

//     // We need int** to store a two dimensional array.
//     // Similary, we need struct node** to store an array of Linked lists
//     struct node **adjLists;
// };

// // DFS algo
// void DFS(struct Graph *graph, int vertex)
// {
//     struct node *adjList = graph->adjLists[vertex];
//     struct node *temp = adjList;

//     graph->visited[vertex] = 1;
//     printf("Visited %d \n", vertex);

//     while (temp != NULL)
//     {
//         int connectedVertex = temp->vertex;

//         if (graph->visited[connectedVertex] == 0)
//         {
//             DFS(graph, connectedVertex);
//         }
//         temp = temp->next;
//     }
// }

// // Create a node
// struct node *createNode(int v)
// {
//     struct node *newNode = malloc(sizeof(struct node));
//     newNode->vertex = v;
//     newNode->next = NULL;
//     return newNode;
// }

// // Create graph
// struct Graph *createGraph(int vertices)
// {
//     struct Graph *graph = malloc(sizeof(struct Graph));
//     graph->numVertices = vertices;

//     graph->adjLists = malloc(vertices * sizeof(struct node *));

//     graph->visited = malloc(vertices * sizeof(int));

//     int i;
//     for (i = 0; i < vertices; i++)
//     {
//         graph->adjLists[i] = NULL;
//         graph->visited[i] = 0;
//     }
//     return graph;
// }

// // Add edge
// void addEdge(struct Graph *graph, int src, int dest)
// {
//     // Add edge from src to dest
//     struct node *newNode = createNode(dest);
//     newNode->next = graph->adjLists[src];
//     graph->adjLists[src] = newNode;

//     // Add edge from dest to src
//     newNode = createNode(src);
//     newNode->next = graph->adjLists[dest];
//     graph->adjLists[dest] = newNode;
// }

// // Print the graph
// void printGraph(struct Graph *graph)
// {
//     int v;
//     for (v = 0; v < graph->numVertices; v++)
//     {
//         struct node *temp = graph->adjLists[v];
//         printf("\n Adjacency list of vertex %d\n ", v);
//         while (temp)
//         {
//             printf("%d -> ", temp->vertex);
//             temp = temp->next;
//         }
//         printf("\n");
//     }
// }

// int main()
// {
//     struct Graph *graph = createGraph(4);
//     addEdge(graph, 0, 1);
//     addEdge(graph, 0, 2);
//     addEdge(graph, 1, 2);
//     addEdge(graph, 2, 3);
//     printGraph(graph);
//     DFS(graph, 2);
//     return 0;
// }

// #include <stdio.h>
// #include <conio.h>

// int a[20][20], reach[20], n;
// void dfs(int v)
// {
//     int i;
//     reach[v] = 1;
//     for (i = 1; i <= n; i++)
//         if (a[v][i] && !reach[i])
//         {
//             printf("\n %d->%d", v, i);
//             dfs(i);
//         }
// }
// void main()
// {
//     int i, j, count = 0;
//     clrscr();
//     printf("\n Enter number of vertices:");
//     scanf("%d", &n);
//     for (i = 1; i <= n; i++)
//     {
//         reach[i] = 0;
//         for (j = 1; j <= n; j++)
//             a[i][j] = 0;
//     }
//     printf("\n Enter the adjacency matrix:\n");
//     for (i = 1; i <= n; i++)
//         for (j = 1; j <= n; j++)
//             scanf("%d", &a[i][j]);
//     dfs(1);
//     printf("\n");
//     for (i = 1; i <= n; i++)
//     {
//         if (reach[i])
//             count++;
//     }
//     if (count == n)
//         printf("\n Graph is connected");
//     else
//         printf("\n Graph is not connected");
//     getch();
// }

// #include <stdio.h>

// void DFS(int);
// int G[10][10], visited[10], n; // n is no of vertices and graph is sorted in array G[10][10]
// void main()
// {
//     int i, j;
//     printf("Enter number of vertices:");

//     scanf("%d", &n);
//     // read the adjecency matrix
//     printf("\nEnter adjecency matrix of the graph:");

//     for (i = 0; i < n; i++)
//         for (j = 0; j < n; j++)
//             scanf("%d", &G[i][j]);
//     // visited is initialized to zero
//     for (i = 0; i < n; i++)
//         visited[i] = 0;
//     DFS(0);
// }
// void DFS(int i)
// {
//     int j;
//     printf("\n%d", i);
//     visited[i] = 1;
//     for (j = 0; j < n; j++)
//         if (!visited[j] && G[i][j] == 1)
//             DFS(j);
// }

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *next;
    int vertex;
} node;
node *G[20];
// heads of linked list
int visited[20];
int n;
void read_graph();
// create adjacency list
void insert(int, int);
// insert an edge (vi,vj) in te adjacency list
void DFS(int);
void main()
{
    int i;
    read_graph();
    // initialised visited to 0

    for (i = 0; i < n; i++)
        visited[i] = 0;
    DFS(0);
}
void DFS(int i)
{
    node *p;

    printf("\n%d", i);
    p = G[i];
    visited[i] = 1;
    while (p != NULL)
    {
        i = p->vertex;

        if (!visited[i])
            DFS(i);
        p = p->next;
    }
}
void read_graph()
{
    int i, vi, vj, no_of_edges;
    printf("Enter number of vertices:");

    scanf("%d", &n);
    // initialise G[] with a null

    for (i = 0; i < n; i++)
    {
        G[i] = NULL;
        // read edges and insert them in G[]

        printf("Enter number of edges:");
        scanf("%d", &no_of_edges);
        for (i = 0; i < no_of_edges; i++)
        {
            printf("Enter an edge(u,v):");
            scanf("%d%d", &vi, &vj);
            insert(vi, vj);
        }
    }
}
void insert(int vi, int vj)
{
    node *p, *q;

    // acquire memory for the new node
    q = (node *)malloc(sizeof(node));
    q->vertex = vj;
    q->next = NULL;
    // insert the node in the linked list number vi
    if (G[vi] == NULL)
        G[vi] = q;
    else
    {
        // go to end of the linked list
        p = G[vi];

        while (p->next != NULL)
            p = p->next;
        p->next = q;
    }
}