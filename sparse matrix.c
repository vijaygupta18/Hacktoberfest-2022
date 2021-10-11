/* Program of sparse matrix for 3-tuple method using array*/
#include<stdio.h>
#define srow 50
#define mrow 20
#define mcolumn 20

main()
{
	int mat[mrow][mcolumn],sparse[srow][3];
	int i,j,nzero=0,mr,mc,sr,s;
	printf("Enter number of rows : ");
	scanf("%d",&mr);
	printf("Enter number of columns : ");
	scanf("%d",&mc);

	for(i=0;i<mr;i++)
	   for(j=0;j<mc;j++)
	   {
		printf("Enter element for row %d,column %d : ",i+1,j+1);
		scanf("%d",&mat[i][j]);
	   }
	printf("Entered matrix is : \n");
	for(i=0;i<mr;i++)
	{
		for(j=0;j<mc;j++)
		{
			printf("%6d",mat[i][j]);
			if(mat[i][j]!=0)
				nzero++;
		}
		printf("\n");
	}

	sr=nzero+1;
	sparse[0][0]=mr;
	sparse[0][1]=mc;
	sparse[0][2]=nzero;
	s=1;

	for(i=0;i<mr;i++)
	   for(j=0;j<mc;j++)
	   {
		if(mat[i][j]!=0)
		{
			sparse[s][0]=i+1;
			sparse[s][1]=j+1;
			sparse[s][2]=mat [i][j];
			s++;
		}
	   }
	printf("Sparse matrix is :\n");
	for(i=0;i<sr;i++)
	{
		for(j=0;j<3;j++)
			printf("%5d",sparse[i][j]);
		printf("\n");
	}
}/*End of main()*/


