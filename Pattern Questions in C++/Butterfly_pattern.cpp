#include<iostream>
using namespace std;

int main() {

    int n;
    cout<<"Enter n: ";
    cin>>n;

    // //  METHOD 1
    // // Upper half
    // for(int i=1; i<=n; i++){
    //     // Left half
    //     for(int j=1; j<=n; j++){
    //         if(j<=i)
    //             cout<<"* ";
    //         else
    //             cout<<"  ";
    //     }
    //     // Right half
    //     for(int j=n; j>=1; j--){
    //         if(j<=i)
    //             cout<<"* ";
    //         else
    //             cout<<"  ";
    //     }
    //     cout<<endl;
    // }

    // // Lower half
    // for(int i=n; i>=1; i--){
    //     // Left half
    //     for(int j=1; j<=n; j++){
    //         if(j<=i)
    //             cout<<"* ";
    //         else
    //             cout<<"  ";
    //     }
    //     // Right half
    //     for(int j=n; j>=1; j--){
    //         if(j<=i)
    //             cout<<"* ";
    //         else
    //             cout<<"  ";
    //     }
    //     cout<<endl;
    // }



    //  METHOD 2
    for(int i=1; i<=n; i++){

        for(int j=1; j<=i; j++)
            cout<<"* ";
        
        int space = 2*n - 2*i;
        for(int j=1; j<=space; j++)
            cout<<"  ";
        
        for(int j=1; j<=i; j++)
            cout<<"* ";
        
        cout<<endl;
    }

    for(int i=n; i>=1; i--){
        
        for(int j=1; j<=i; j++)
            cout<<"* ";
        
        int space = 2*n - 2*i;
        for(int j=1; j<=space; j++)
            cout<<"  ";
        
        for(int j=1; j<=i; j++)
            cout<<"* ";
        
        cout<<endl;
    }
    return 0;
}