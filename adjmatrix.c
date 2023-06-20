#include <stdio.h>
#include <stdlib.h>
#define max 20
int adj[max][max],visited[max],distance[max],n;

void undir_graph();
void dir_graph();
void display();
int outdegree(int);
int indegree(int);
void dfs(int x);
void iBFS(int v);
void insert_node();
void insert_edge();
void delete_node();
void delete_edge();
int connectedComponents();
void shortestPathUG(int s);

void push(int ele);
int pop();
int stack[max],top=-1;

void enqueue(int ele);
int dequeue();
int queue[max],front=-1,rear=-1;

void main()
{
   int ch,i,v;
   while(1)
   {
        printf("\n1. Directed Graph ");
        printf("\n2. Un-Directed Graph ");
        printf("\n3. Display Adj. Matrix ");
        printf("\n4. Indegree and Outdegree of Vertices");
        printf("\n5. Depth First Search Traversal");
        printf("\n6. Breath First Search Traversal");
        printf("\n7. Insert a node");
        printf("\n8. Insert an edge");
        printf("\n9. Delete a node");
        printf("\n10. Delete an edge");
        printf("\n11. Exit");
        printf("\n12. Count Connected Components");
        printf("\n13. Shortest Path from source to every vertex");
        printf("\nSelect a proper option : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                dir_graph();
                break;
            case 2:
                undir_graph();
                break;
            case 3:
                display();
                break;
            case 4:
            {
                for(i=1;i<=n;i++)
                {
                    printf("\n\n Vertext %d, Indegree : %d Outdegree %d",i,indegree(i),outdegree(i));
                }
                break;
            }
            case 5:
            {
                for(i=1; i<=n; i++)
                {
                    visited[i]=0;
                }
                printf("Enter starting node for Depth First Search : ");
                scanf("%d",&v);
                dfs(v);
                break;
            }
            case 6:
            {
                for(i=1; i<=n; i++)
                {
                    visited[i]=0;
                }

                printf("Enter starting node for Breadth First Search : ");
                scanf("%d",&v);
                iBFS(v);

                break;
            }
            case 7:
            {
                insert_node();
                break;
            }
            case 8:
            {
                insert_edge();
                break;
            }
            case 9:
            {
                delete_node();
                break;
            }
            case 10:
            {
                delete_edge();
                break;
            }
            case 11:
            {
                exit(0);
            }
            case 12:
            {
                for(i=1; i<=n; i++)
                {
                    visited[i]=0;
                }
                i=connectedComponents();
                printf("\nNo. of Connected Components in Graph : %d",i);
                break;
            }
            case 13:
            {
                for(i=1; i<=n; i++)
                {
                    visited[i]=0;
                    distance[i]=-1;
                }

                printf("Enter Source Value : ");
                scanf("%d",&v);
                shortestPathUG(v);
                break;
            }
            default:
            {
                printf("\nWrong Option\n");
            }
        }
    }
}

void dir_graph()
{
    int edges=0,i,j,origin=0,destin=0;
    printf("Enter number of nodes : ");
    scanf("%d",&n);
    edges=n*(n-1);

    for(i=1;i<=edges;i++)
    {
        printf("Enter edge %d( 0 0 to quit ) : ", i );
        scanf( "%d %d", &origin, &destin );
        if ( ( origin == 0 ) && ( destin == 0 ) )
        {
            break;
        }
        if ( origin > n || destin > n || origin <= 0 || destin <= 0 )
        {
            printf("Invalid edge!\n");
            i--;
        }
        else
        {
            adj[origin][destin]=1;
        }
    }
}

void undir_graph()
{
    int edges=0,i,j,origin=0,destin=0;
    printf("Enter number of nodes : ");
    scanf("%d",&n);
    edges=n*(n-1)/2;

    for ( i = 1;i <=edges;i++ )
    {
        printf( "Enter edge %d( 0 0 to quit ) : ", i );
        scanf( "%d %d", &origin, &destin );
        if ( ( origin == 0 ) && ( destin == 0 ) )
        {
            break;
        }
        if ( origin > n || destin > n || origin <= 0 || destin <= 0 )
        {
            printf( "Invalid edge!\n" );
            i--;
        }
        else
        {
            adj[ origin ][ destin ] = 1;
            adj[ destin ][ origin ] = 1;
        }
    }
}

void display()
{
    int i,j;
    printf( "The adjacency matrix is :\n");
    for(i=1;i<=n;i++)
    {
        for ( j = 1;j <= n;j++ )
        {
                printf(" %d ",adj[i][j]);
        }
        printf("\n");
    }
}

int outdegree(int x)
{
    int i, count =0;
    for(i=1;i<=n;i++)
    {
        if( adj[x][i] ==1)
        {
            count++;
        }
    }
    return(count);
}

int indegree(int x)
{
    int i, count =0;
    for(i=1;i<=n;i++)
    {
        if( adj[i][x] ==1)
        {
            count++;
        }
    }
    return(count);
}

void insert_node()
{
    int i;
    n++;
    printf("\nThe inserted node is : %d",n);
    for(i=1;i<=n;i++)
    {
            adj[i][n]=0;
            adj[n][i]=0;
    }
}

void insert_edge()
{
        int origin=0,destin=0;
        printf("\nEnter an edge to be inserted : ");
        scanf( "%d %d", &origin, &destin );
        if ( origin > n || destin > n || origin <= 0 || destin <= 0 )
        {
            printf( "Invalid edge!\n" );
        }
        else
        {
            adj[ origin ][ destin ] = 1;
        }
}

void delete_node()
{
    int i=0,j=0,u;
    printf("\nEnter a node to be deleted : ");
    scanf("%d",&u);
    if (n==0)
    {
        printf("Graph is empty\n" );
        return;
    }
    if(u>n)
    {
            printf("This node is not present in the graph\n" );
            return;
    }
    for(i=u;i<=n-1;i++)
    {
        for (j=1;j<=n;j++)
        {
                adj[ j ][ i ] = adj[ j ][ i + 1 ]; /* Shift columns left */
                adj[ i ][ j ] = adj[ i + 1 ][ j ]; /* Shift rows up */
        }
    }
    n--;
}

void delete_edge()
{
        int origin=0,destin=0;
        printf("Enter an edge to be deleted : ");
        scanf("%d %d", &origin, &destin );
        if (origin>n || destin > n || adj[origin][destin] == 0)
        {
            printf( "This edge does not exist\n" );
            return ;
        }
        adj[origin][destin]=0;
}

void dfs(int x)
{
    int j;
    printf("%d ",x);
    visited[x] = 1;
    for(j=1;j<=n;j++)
    {
        if(adj[x][j] ==1 && visited[j] ==0)
        {
            dfs(j);
        }
    }
}

int connectedComponents()
{
    int i,count=0;
    for(i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            dfs(i);
            count++;
        }
    }
    return count;
}


//Shortest path from source to every vertex (Unweighted graph)
void shortestPathUG(int s)
{
    int i;
    distance[s]=0;
    visited[s]=1;
    enqueue(s);

    while(front!=-1)
    {
        s=dequeue();
        for(i=1;i<=n;i++)
        {
            /* Check for adjacent unvisited nodes */
            if( adj[s][i]==1 && visited[i]==0)
            {
                distance[i]= distance[s] + 1;
                visited[i]=1;
                enqueue(i);
            }
        }
    }

    printf("\nDistance from source %d to Every Vertex\n",s);
    for(i=1;i<=n;i++)
    {
        printf("Vertex : %d, Distance : %d\n",i,distance[i]);
    }
}


void iBFS(int v)
{
    int i;
    visited[v]=1;
    enqueue(v);

    while(front!=-1)
    {
        v=dequeue();
        printf("%d ",v);
        for(i=1;i<=n;i++)
        {
            /* Check for adjacent unvisited nodes */
            if( adj[v][i]==1 && visited[i]==0)
            {
                visited[i]=1;
                enqueue(i);
            }
        }
    }
}


void enqueue(int ele)
{
    if(front==-1)
        front=0;

    queue[++rear]=ele;
}

int dequeue()
{
    if(rear==0||front==rear)
    {
        int ele = queue[front];
        rear=-1;
        front=-1;
        return ele;
    }
    return queue[front++];
}

int pop()
{
    return stack[top--];
}

void push(int ele)
{
    stack[++top]=ele;
}
