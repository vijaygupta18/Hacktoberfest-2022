#include <bits/stdc++.h> 
using namespace std; 

//Without Recursion
void Sort(int a[],int n) 
{ 
	int i,j,k; 
	for(i=1;i<n;i++) 
	{ 
		k=a[i]; 
		j=i-1; 
		while(j>=0&&a[j]>k) 
		{ 
			a[j+1]=a[j]; 
			j=j-1; 
		} 
		a[j+1]=k; 
	} 
}  
//Recursion
void Recursive(int a[],int n) 
{ 
    if(n<=1) 
        return; 
  
    Recursive(a,n-1); 
  
    int l,j;
	l=a[n-1]; 
    j=n-2; 
  
    while(j>=0&&a[j]>l) 
    { 
        a[j+1]=a[j]; 
        j--; 
    } 
    a[j+1]=l; 
} 

int main() 
{ 
	int a[100],n,i;

    cout<<"Enter size of the array";
    cin>>n;
    cout<<"Enter elements of the array";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

	Recursive(a,n); 
	
	for(i=0;i<n;i++)
    {
        cout<<a[i];
    }
	return 0; 
} 
