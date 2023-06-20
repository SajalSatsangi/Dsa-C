#include<stdio.h>
#include<stdlib.h>
#define max 20

int visited[max];

//struct Edge;

struct Vertex
{
	int info;
	struct Vertex *nextVertex;
	struct Edge *firstEdge;
}*start = NULL;

struct Edge
{
	struct Vertex *destVertex;
	struct Edge *nextEdge;
};

struct Vertex *findVertex(int u);
void insertVertex(int u);
void insertEdge(int u,int v);
void deleteEdge(int u,int v);
void deleteIncomingEdges(int u);
void deleteVertex(int u);
void display();
int outdegree(struct Vertex *tmp);
int indegree(struct Vertex *tmp);
void dfs(struct Vertex *tmp);
void bfs(struct Vertex *tmp);

main()
{
	int choice,u,origin,destin,v,i;

	while(1)
	{
		printf("\n1.Insert a Vertex\n");
		printf("2.Insert an Edge\n");
		printf("3.Delete a Vertex\n");
		printf("4.Delete an Edge\n");
		printf("5.Display\n");
		printf("6.Indegree and Outdegree of Vertices\n");
		printf("7.DFS Traversal\n");
		printf("8.BFS Traversal\n");
		printf("9.Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		 case 1:
			printf("Enter a vertex to be inserted : ");
			scanf("%d",&u);
			insertVertex(u);
			break;
		 case 2:
			printf("Enter an Edge to be inserted : ");
			scanf("%d %d",&origin,&destin);
			insertEdge(origin,destin);
			break;
		 case 3:
			printf("Enter a vertex to be deleted : ");
			scanf("%d",&u);
			deleteIncomingEdges(u);
			deleteVertex(u);
			break;
		 case 4:
			printf("Enter an edge to be deleted : ");
			scanf("%d %d",&origin,&destin);
			deleteEdge(origin,destin);
			break;
		 case 5:
			display();
			break;
         case 6:
         {
            struct Vertex *ptr;
            ptr=start;
            while(ptr!=NULL)
            {
                printf("\nVertext %d, Indegree : %d Outdegree %d",ptr->info,indegree(ptr),outdegree(ptr));
                ptr=ptr->nextVertex;
            }
            break;
         }
         case 7:
         {
            for(i=1; i<=max; i++)
            {
                visited[i]=0;
            }
            printf("Enter starting node for Depth First Search : ");
            scanf("%d",&v);
            dfs(findVertex(v));
            break;
         }
         case 8:
         {
            for(i=1; i<=max; i++)
            {
                visited[i]=0;
            }
            printf("Enter starting node for Breadth First Search : ");
            scanf("%d",&v);
            bfs(findVertex(v));
            break;
         }
		 case 9:
			exit(1);
		 default:
			printf("Wrong choice\n");
			break;
		 }
	}
}

void insertVertex(int u)
{
	struct Vertex *tmp,*ptr;
	tmp = malloc(sizeof(struct Vertex));
	tmp->info = u;
	tmp->nextVertex = NULL;
	tmp->firstEdge = NULL;

	if(start == NULL)
	{
		start = tmp;
	}
	else
    {
        ptr = start;
        while(ptr->nextVertex!=NULL)
        {
            ptr = ptr->nextVertex;
        }
        ptr->nextVertex = tmp;
    }
}

void deleteVertex(int u)
{
	struct Vertex *tmp,*q;
	struct Edge *p,*temporary;
	if(start == NULL)
	{
		printf("No vertices to be deleted\n");
		return;
	}
	if(start->info == u)/* Vertex to be deleted is first vertex of list*/
	{
		tmp = start;
		start = start->nextVertex;
	}
	else /* Vertex to be deleted is in between or at last */
	{
        q = start;
		while(q->nextVertex != NULL)
		{
			if(q->nextVertex->info == u)
				break;
			q = q->nextVertex;
		}
		if(q->nextVertex==NULL)
		{
			printf("Vertex not found\n");
			return;
		}
		else
		{
			tmp = q->nextVertex;
			q->nextVertex = tmp->nextVertex;
		}
	}
	/*Before freeing the node tmp, free all edges going from this vertex */
	p = tmp->firstEdge;
	while(p!=NULL)
	{
		temporary = p;
		p = p->nextEdge;
		free(temporary);
	}
	free(tmp);
}

void deleteIncomingEdges(int u)
{
	struct Vertex *ptr;
	struct Edge *q,*tmp;

	ptr = start;
	while(ptr!=NULL)
	{
		if(ptr->firstEdge == NULL)
		{
			ptr = ptr->nextVertex;
			continue; /* continue searching in other Edge lists */
		}

		if(ptr->firstEdge->destVertex->info == u)
		{
			tmp = ptr->firstEdge;
			ptr->firstEdge = ptr->firstEdge->nextEdge;
			free(tmp);
			continue; /* continue searching in other Edge lists */
		}
		q = ptr->firstEdge;
		while(q->nextEdge!= NULL)
		{
			if(q->nextEdge->destVertex->info == u)
			{
				tmp = q->nextEdge;
				q->nextEdge = tmp->nextEdge;
				free(tmp);
				continue;
			}
			q = q->nextEdge;
		}
		ptr = ptr->nextVertex;
	}
}


struct Vertex *findVertex(int u)
{
	struct Vertex *ptr,*loc;
	ptr = start;
	while(ptr!=NULL)
	{
		if(ptr->info == u )
		{
			loc = ptr;
			return loc;
		}
		else
			ptr = ptr->nextVertex;
	}

	return NULL;
}

void insertEdge(int u,int v)
{
	struct Vertex *locu,*locv;
	struct Edge *ptr,*tmp;

	locu = findVertex(u);
	locv = findVertex(v);

	if(locu == NULL || locv == NULL)
	{
		printf("Start OR End vertex not present, first insert vertex %d\n",u);
		return;
	}

	tmp = (struct Edge *)malloc(sizeof(struct Edge));
	tmp->destVertex = locv;
	tmp->nextEdge = NULL;

	if(locu->firstEdge == NULL)
	{
		 locu->firstEdge = tmp;
	}
	else
    {
        ptr = locu->firstEdge;
        while(ptr->nextEdge!=NULL)
        {
            ptr = ptr->nextEdge;
        }
        ptr->nextEdge = tmp;
    }
}

void deleteEdge(int u,int v)
{
	struct Vertex *locu;
	struct Edge *tmp,*q;

	locu = findVertex(u);

	if(locu == NULL )
	{
		printf("Start vertex not present\n");
		return;
	}
	if(locu->firstEdge == NULL)
	{
		printf("Edge not present\n");
		return;
	}

	if(locu->firstEdge->destVertex->info == v)
	{
		tmp = locu->firstEdge;
		locu->firstEdge = locu->firstEdge->nextEdge;
		free(tmp);
		return;
	}
	q = locu->firstEdge;
	while(q->nextEdge != NULL)
	{
		if(q->nextEdge->destVertex->info == v)
		{
			tmp = q->nextEdge;
			q->nextEdge = tmp->nextEdge;
			free(tmp);
			return;
		}
		q = q->nextEdge;
	}
	printf("This Edge not present in the graph\n");
}

void display()
{
	struct Vertex *ptr;
	struct Edge *q;

	ptr = start;
	while(ptr!=NULL)
	{
		printf("%d ->",ptr->info);
		q = ptr->firstEdge;
		while(q!=NULL)
		{
			printf(" - %d",q->destVertex->info);
			q = q->nextEdge;
		}
		printf("\n");
		ptr = ptr->nextVertex;
	 }
}/*End of display()*/

int outdegree(struct Vertex *tmp)
{
	struct Edge *q;
	int count=0;

    q = tmp->firstEdge;
    while(q!=NULL)
    {
			q = q->nextEdge;
			count++;
    }
    return count;
}

int indegree(struct Vertex *tmp)
{
	struct Vertex *ptr;
	struct Edge *q;
	int count=0;

	ptr = start;
	while(ptr!=NULL)
	{
		q = ptr->firstEdge;
		while(q!=NULL)
		{
			if(q->destVertex->info==tmp->info)
            {
                count++;
            }
			q = q->nextEdge;
		}
		ptr = ptr->nextVertex;
	 }
	 return count;
}

void dfs(struct Vertex *tmp)
{
	struct Edge *q;
    int j,x;
    x=tmp->info;
    visited[x]=1;
    printf("The node visited id %d\n",x);
    q=tmp->firstEdge;
    while(q!=NULL)
    {
        j=q->destVertex->info;
        if(visited[j]==0)
        {
            dfs(q->destVertex);
        }
        q=q->nextEdge;
    }
}

void bfs(struct Vertex *tmp)
{
    struct Edge *q;
    int i,front,rear,x;
    int que[20];
    front=rear= -1;

    x=tmp->info;
    visited[x]=1;
    printf("The node visited id %d",x);
    rear++;
    front++;
    que[rear]=x;

    while(front<=rear)
    {
        x=que[front];
        front++;
        tmp=findVertex(x);
        q=tmp->firstEdge;
        while(q!=NULL)
        {
            x=q->destVertex->info;
            if(visited[x]==0)
            {
                printf(" %d ",x);
                visited[x]=1;
                rear++;
                que[rear]=x;
             }
            q=q->nextEdge;
        }
    }
}
