#include <iostream>
using namespace std;

int main() {
    int n;         
    cout<<"enter n"<<endl;   //numer upto which prime has to be checked
    cin>>n;
    int count=0;
    int arr[1000];
    bool sieve[n+1];
    memset(sieve,true,sizeof(sieve));
    for(int i=2;i*i<=n;i++)
    {
     if(sieve[i]==true)
     {
         for(int j=i*i;j<=n;j+=i)
         {
             sieve[j]=false;
         }
     }
    }
    for(int i=2;i<=n;i++)
    {
    	if(sieve[i]==true)   //print all the prime number 
        cout<<i<<" ";
	}
	return 0;
}