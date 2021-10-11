#include<iostream>
#include<conio.h>
using namespace std;
void main()
{
int i,no,fact=1;
cout<<” Enter Any No.: “;
cin>>no;
for(i=no;i>=1;i–)
{
fact=fact*i;
}
cout<<“\n Factorial of given No. is: “<<fact;
getch();
}