#include<iostream>
using namespace std;

int main() {

    int n, c=1;
    cout<<"Enter n: ";
    cin>>n;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<<c<<" ";
            c++;
        }
        cout<<endl;
    }
    return 0;

}