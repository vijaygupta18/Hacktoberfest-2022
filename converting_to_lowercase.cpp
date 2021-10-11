#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
void main()
{
	string tex;
	int i;
	cout<<"Enter the text in Upper case: ";
	getline(cin,tex);
	for(i=0;i<tex.length();i++)
	{
		tex[i]=tolower(tex[i]);
	}
	cout<<"Lower case is :"<<tex;
	getch();
}