#include<stdio.h>
#include<conio.h>
int factorial(int x,int y)
{
int i=0,fac1,fac2,fac3,ans;
fac1 = 1;
fac2 = 1;
fac3 = 1;
for(i=1;i<=x;i++)
{
fac1 = fac1*i;
}
for(i=1;i<=x-y;i++)
{
fac2 = fac2*i;
}
for(i=1;i<=y;i++)
{
fac3 = fac3*i;
}
ans = fac1/(fac2*fac3);
return(ans);
}

int PrintOutput()
{
    int n=0,r=0;
    for(n=1;n<=7;n++)
    {
    for(r=0;r<=n-1;r++)
    {
    printf("%3d",factorial(n-1,r));
    }
    printf("\n");
    }
    return(0);
}
int main()
{
int get=0;
get = PrintOutput();
getch();
return(0);
}