#include<bits/stdc++.h>
using namespace std;

    int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, arr[n], element, fail=0;
    int size = sizeof(arr)/sizeof(element);

    cout<<"Enter the number of elements to be stored in array:"<<endl;
    cin>>n;
    cout<<"Enter the elements of array"<<endl;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Enter the element for navigating"<<endl;
    cin>>element;

    for(int i=0;i<n;i++){
        if(element==arr[i]){
            cout<<"Element is at index "<<i<<endl;
        }
        else{
            fail++;
        }
    }

    if(fail==n){
        cout<<"Element does not exist";
    }

    return 0;
} 