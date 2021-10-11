/* Program for topological sorting */
#include<stdio.h>
#define MAX 20

int n,adj[MAX][MAX];
int front=-1,rear=-1,queue[MAX];

main()
{
	int i,j=0,k;
	int topsort[MAX],indeg[MAX];

	create_graph();
	printf("The adjacency matrix is :\n");
	display();
	/*Find the indegree of each node*/
	for(i=1;i<=n;i++)
	{
		indeg[i]=indegree(i);
		if( indeg[i]==0 )
			insert_queue(i);
	}

	while(front<=rear) /*Loop till queue is not empty */
	{
		k=delete_queue();
		topsort[j++]=k; /*Add node k to topsort array*/
		/*Delete all edges going fron node k */
		for(i=1;i<=n;i++)
		{
			if(  adj[k][i]==1  )
			{
				adj[k][i]=0;
				indeg[i]=indeg[i]-1;
				if(indeg[i]==0)
					insert_queue(i);
			}
		}/*End of for*/
	}/*End of while*/

	printf("Nodes after topological sorting are :\n");
	for(i=0;i<j;i++)
		printf( "%d ",topsort[i] );
	printf("\n");
}/*End of main()*/

create_graph()
{
	int i,max_edges,origin,destin;

	printf("Enter number of vertices : ");
	scanf("%d",&n);
	max_edges=n*(n-1);

	for(i=1;i<=max_edges;i++)
	{
		printf("Enter edge %d(0 0 to quit): ",i);
		scanf("%d %d",&origin,&destin);

		if((origin==0) && (destin==0))
			break;

		if( origin > n || destin > n || origin<=0 || destin<=0)
		{
			printf("Invalid edge!\n");
			i--;
		}
		else
			adj[origin][destin]=1;
	}/*End of for*/
}/*End of create_graph()*/

display()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf("%3d",adj[i][j]);
		printf("\n");
	}
}/*End of display()*/

insert_queue(int node)
{
	if (rear==MAX-1)
		printf("Queue Overflow\n");
	else
	   {
		if (front==-1)  /*If queue is initially empty */
			front=0;
		rear=rear+1;
		queue[rear] = node ;
	   }
}/*End of insert_queue()*/

delete_queue()
{
	int del_item;
	if (front == -1 || front > rear)
	{
		printf("Queue Underflow\n");
		return ;
	}
	else
	{
		del_item=queue[front];
		front=front+1;
		return del_item;
	}
}/*End of delete_queue() */

int indegree(int node)
{
	int i,in_deg=0;
	for(i=1;i<=n;i++)
		if( adj[i][node] == 1 )
			in_deg++;
	return in_deg;
}/*End of indegree() */
