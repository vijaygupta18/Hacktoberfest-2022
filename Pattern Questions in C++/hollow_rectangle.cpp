#include<iostream>
using namespace std;

int main() {

    int row, col, i;
    cout<<"Enter number of rows and columns: \n";
    cin>>row>>col;

    // // METHOD 1
    // for(i=0;i<col;i++)
    //     cout<<"*";

    // for(i=1;i<row-1;i++)
    //     cout<<"\n*  *";

    // cout<<endl;
    // for(i=0;i<col;i++)
    //     cout<<"*";

    // // METHOD 2
    // for(int i=1; i<=row; i++){
    //     if(i==1 || i==row){
    //         for(j=1; j<=col; j++){
    //             cout<<"*";
    //     }
    //     cout<<endl;
    //     }
    //     cout<<"*  *"\n;
    // }


    // // METHOD 3
    // for(int i=1; i<=row; i++){
    //     for(int j=1; j<=col; j++){
    //         if(i==1 || i==row)
    //             cout<<"*";
    //         else if(j==1 || j==col)
    //             cout<<"*";
    //         else
    //             cout<<" ";
    //     }
    //     cout<<endl;
    // }


    // // METHOD 4
    for(int i=1; i<=row; i++){
        for(int j=1; j<=col; j++){
            if(i==1 || i==row || j==1 || j==col)
                cout<<"*";
            else
                cout<<" ";
        }
        cout<<endl;
    }

    return 0;

}