#include<stdio.h>
int main()
{
	int k,n;
	printf("Enter the value of n & k\n");
	scanf("%d%d",&n,&k);
    int c[n+1][k+1];
	for(int i=0;i<=n;i++)
    {
	    for(int j=0;j<=k;j++)
        {
	        c[i][j]=0;
        }
    }
	for(int i=0;i<=n;i++)
	{
		c[i][0]=1;
		c[i][i]=1;
	}
	for(int i=2;i<=n;i++)
    {
	    for(int j=1;j<=i-1;j++)
        {
	        c[i][j]=c[i-1][j-1]+c[i-1][j];
        }
    }
	printf("The binomial coefficient of C(%d,%d) is %d\n",n,k,c[n][k]);
	return 0;
}
