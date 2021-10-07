#include <iostream>
using namespace std;

void kthsmallest(int a[], int n, int k)
{
  sort(a, a+n);
  cout<<a[k-1]<<" "<<a[n-k+1];
}

int main()
{
	int n,k;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
	    cin>>a[i];
	}
    cin>>k;
	kthsmallest(a,n,k);
	return 0;
}
