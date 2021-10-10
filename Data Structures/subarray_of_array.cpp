// print all subarray of an array

#include<iostream>
#include<climits>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = i; k < j; k++)
            {
                cout<<a[k]<<" ";
            }
            cout<<endl;
        }
        
    }
 
    return 0;
}