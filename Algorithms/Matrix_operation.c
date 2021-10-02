/*
Sample : 

Input matrix
  4   6   5
  7   8   3
  2   5   6

resultant matrix
  4   6   5  15
  7   8   3  18
  2   5   6  13
 13  19  14  92

*/
#include<stdio.h>
#include<conio.h>
void main()
{
    int i,j,a=20,b=20,n,m,sum=0,mat[a][b];
    printf("enter the dimension of matrix\n");
    scanf("%d%d",&n,&m);
    printf("enter elements of %d×%d matrix\n",n,m);
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            scanf("%d",&mat[i][j]);
        }
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            sum = sum + mat[i][j];
        }
        mat[i][m] = sum;
        sum = 0;
    }
    for(j = 0; j < m; j++)
    {
        for(i = 0; i < n; i++)
        {
            sum = sum + mat[i][j];
        }
        mat[n][j] = sum;
        sum = 0;
    }
    for(j = 0; j<m; j++)
    {
        sum = sum + mat[n][j];
    }
    for(i = 0; i<n; i++)
    {
        sum = sum + mat[i][m];
    }
    mat[n][m] = sum;
    printf("resultant matrix\n");
    for(i = 0; i<=n; i++)
    {
        for(j = 0; j<=m; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}
