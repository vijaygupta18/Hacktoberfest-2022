// Reverse the array
// Time Complexity = O(n)

#include <bits/stdc++.h>
using namespace std;

void Reverse(int a[], int n, int start, int end)
{

    if (start >= end)
    {
        return;
    }

    swap(a[start], a[end]);

    Reverse(a, n, start + 1, end - 1);
}

int main(){

    int n;
    cin>>n;
    int a[n];

    for(int i=0; i < n; i++){
        cin>>a[i];
    }
    
    cout<<"\nBefore reversing the array is :\n";
    for (int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    

    int start = 0, end = n - 1;
    Reverse(a, n, start, end);

    cout<<"\nAfter reversing the array is :\n";
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }

    return 0;
}