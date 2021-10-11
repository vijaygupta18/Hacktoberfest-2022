#include<iostream>
using namespace std;

int main() {

int n;
cout<<"Enter n: ";
cin>>n;

// // METHOD 1
// for(int i=1; i<=n; i++){
//     for(int j=n; j>i; j--){
//         cout<<" ";
//     }
//     for(int j=1; j<=i; j++){
//         cout<<"*";
//     }
//     cout<<endl;
// }

// METHOD 2
for(int i=1; i<=n; i++){
    for(int j=0; j<=n; j++){
        if (j<=(n-i))
            cout<<"  ";
        else    
            cout<<"* ";
    }
    cout<<endl;
}

    return 0;
}