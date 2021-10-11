
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> vis(10001,0);
vector<int> in(10001,0);
vector<int> ad[10001];
ll n,m;
void kahn()
{
    priority_queue<ll , vector<ll>, greater<ll>> pq;
    vector<int> res;
    for(int i=1;i<n+1;i++)
    {
        if(in[i]==0){pq.push(i);}
 
    }
    while(!pq.empty())
    {
        ll fr=pq.top();
        pq.pop();
        for(auto x:ad[fr])
        {
            in[x]--;
            if(in[x]==0)pq.push(x);
        }
 
        res.push_back(fr);
    }
    if(res.size()==n)
        for(auto x:res) cout<<x<<" ";
    else cout<<"Not possible";
 
}

int main()
{
 
 
cin>>n>>m;
 
for(int i=0;i<m;i++)
{
    ll x,y;
    cin>>x>>y;
    ad[x].push_back(y);
    in[y]++;
 
}
kahn();
 
 
}
