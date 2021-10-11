/* Program to find path matrix by Warshall's algorithm */
#include<stdio.h>
#define MAX 20
main()
{
	int i,j,k,n;
	int w_adj[MAX][MAX],adj[MAX][MAX],path[MAX][MAX];

	printf("Enter number of vertices : ");
	scanf("%d",&n);

	printf("Enter weighted adjacency matrix :\n");
	for(i=0;i<n;i++)
	   for(j=0;j<n;j++)
		scanf("%d",&w_adj[i][j]);

	printf("The weighted adjacency matrix is :\n");
	display(w_adj,n);

	/* Make weighted adjacency matrix into boolean adjacency matrix*/
	for(i=0;i<n;i++)
	   for(j=0;j<n;j++)
		if(w_adj[i][j]==0)
			adj[i][j]=0;
		else
			adj[i][j]=1;

	printf("The adjacency matrix is :\n");
	display(adj,n);

	for(i=0;i<n;i++)
	   for(j=0;j<n;j++)
		path[i][j]=adj[i][j];

	for(k=0;k<n;k++)
	{
		printf("P%d is :\n",k);
		display(path,n);
		for(i=0;i<n;i++)
		  for(j=0;j<n;j++)
		      path[i][j]=( path[i][j] || ( path[i][k] && path[k][j] ) );
	}
	printf("Path matrix P%d of the given graph is :\n",k);
	display(path,n);
}/*End of main() */

display(int matrix[MAX][MAX],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%3d",matrix[i][j]);
		printf("\n");
	}

}/*End of display()*/
