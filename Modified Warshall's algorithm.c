/*Program for Modified Warshall's algorithm to find shoretst path matrix */

#include<stdio.h>
#define infinity 9999
#define MAX 20

main()
{
	int i,j,k,n;
	int adj[MAX][MAX],path[MAX][MAX];

	printf("Enter number of vertices : ");
	scanf("%d",&n);

	printf("Enter weighted matrix :\n");
	for(i=0;i<n;i++)
	   for(j=0;j<n;j++)
		scanf("%d",&adj[i][j]);

	printf("Weighted matrix is :\n");
	display(adj,n);

	/*Replace all zero entries of adjacency matrix with infinity*/
	for(i=0;i<n;i++)
	   for(j=0;j<n;j++)
	   if(adj[i][j]==0)
		path[i][j]=infinity;
	   else
		path[i][j]=adj[i][j];

	for(k=0;k<n;k++)
	{
		printf("Q%d is :\n",k);
		display(path,n);
		for(i=0;i<n;i++)
		  for(j=0;j<n;j++)
		    path[i][j]=minimum( path[i][j] , path[i][k]+path[k][j] );
	}
	printf("Shortest path matrix Q%d is :\n",k);
	display(path,n);
}/*End of main() */

minimum(int a,int b)
{
	if(a<=b)
	  return a;
	else
	  return b;
}/*End of minimum()*/

display(int matrix[MAX][MAX],int n )
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%7d",matrix[i][j]);
		printf("\n");
	}
}/*End of display()*/

