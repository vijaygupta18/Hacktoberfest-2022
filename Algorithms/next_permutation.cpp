#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<char> v;
    v.push_back('a');
    v.push_back('b');
    v.push_back('c');
    while(next_permutation(v.begin(),v.end()))
    cout<<v[0]<<v[1]<<v[2]<<endl;
    cout<<endl;
    cout<<v[0]<<v[1]<<v[2]<<endl;
    return 0;
}