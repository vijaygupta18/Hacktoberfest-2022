#include<iostream>
#include<unordered_set>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    unordered_set<int> s;
    int curr_sum=0;

    for(int i=0;i<n;i++)
    {
        curr_sum+=a[i];
        if(curr_sum==0)
        {
            cout<<"Yes";
            return 0;
        }

        if(s.find(curr_sum)==s.end())
            s.insert(curr_sum);
        else
        {
            cout<<"Yes";
            return 0;
        }
    }
    cout<<"No";
    return 0;

}
