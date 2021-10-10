#include<iostream>
#include<conio.h>
using namespace std;
void main()
{
int mat[4][5],i,j;
cout<<“Enter matrix values:\n”;
for(i=0;i<4;i++)
{
for(j=0;j<5;j++)
{
cin>>mat[i][j];
}
}
cout<<endl;
for(i=0;i<4;i++)
{
cout<<“[ “;
for(j=0;j<5;j++)
{
cout<<mat[i][j]<<” “;
}
cout<<“]”<<endl;
}
cout<<” \nTranspose of the matrix is:\n”;
for(i=0;i<5;i++)
{
cout<<“[ “;
for(j=0;j<4;j++)
{
cout<<mat[j][i]<<” “;
}
cout<<“]”<<endl;
}
getch();
}