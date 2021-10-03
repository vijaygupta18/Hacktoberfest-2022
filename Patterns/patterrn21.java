#include <bits/stdc++.h>

int main()
{
    // number of rows
    int n = 5;
    int i, j;

    for (i = 1; i <= n; i++)
    {
        // print space
        for (j = i; j < n; j++) {
            cout<<" "<<endl;
        }

        // print `n` stars
        for (j = 1; j <= n; j++) {
            cout<<"*"<<;
        }

        // move to the next row
        cout<<endl;
    }

    return 0;
}
