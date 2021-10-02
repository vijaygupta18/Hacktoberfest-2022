#include<bits/stdc++.h>
using namespace std;

bool check(int i, vector<vector<int>> graph, vector<int>& visited, vector<int>& reqstack)
{
    visited[i]=1;
    reqstack[i]=1;
    for(auto j:graph[i])
    {
        if(visited[j]==0)
        {
            if(check(j,graph, visited, reqstack))
            return 1;
        }
        else if(reqstack[j]==1)
        return 1;
    }
    reqstack[i]=0;
    return 0;
}

bool iscycle(vector<vector<int>> graph, int n)
{
    vector<int> visited(n,0);
    vector<int> reqstack(n,0);
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
            if(check(i, graph, visited, reqstack))
            return 1;
        }

    }
    return 0;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        u--;v--;
        graph[u].push_back(v);
    }

    cout<<iscycle(graph, n);
}