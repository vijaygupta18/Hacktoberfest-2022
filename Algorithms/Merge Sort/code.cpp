#include <bits/stdc++.h> 
using namespace std; 

void merge(int a[],int l,int m,int r) 
{ 
	int i,j,k; 
	int ls=m-l+1; 
	int rs=r-m; 

	int leftarray[ls],rightarray[rs]; 

	for(i=0;i<ls;i++)
    {
        leftarray[i]=a[l+i];
    }	 
	for(j=0;j<rs;j++) 
    {
        rightarray[j]=a[m+1+j]; 
    }
	i=0;  
	j=0; 
	k=l;  
	while(i<ls&&j<rs) 
    { 
		if (leftarray[i]<=rightarray[j]) 
        { 
			a[k]=leftarray[i]; 
			i++; 
		} 
		else 
        { 
			a[k]=rightarray[j]; 
			j++; 
		} 
		k++; 
	} 

	while(i<ls) { 
		a[k]=leftarray[i]; 
		i++; 
		k++; 
	} 

	while(j<rs) { 
		a[k]=rightarray[j]; 
		j++; 
		k++; 
	} 
}

void Sort(int a[],int l,int r) 
{ 
	if (l<r){ 
		int m=l+(r-l)/2; 
		Sort(a,l,m); 
		Sort(a,m+1,r); 
		merge(a,l,m,r); 
	} 
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

	Sort(a,0,n-1); 
	
	for(i=0;i<n;i++)
    {
        cout<<a[i];
    }
	return 0; 
} 
