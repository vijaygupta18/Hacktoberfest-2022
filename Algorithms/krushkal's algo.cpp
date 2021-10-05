#include <bits/stdc++.h>

using namespace std;

const int N=1e5+6;
vector<int>parent(N);
vector<int>sz(N);

void make_pair(int v)
{
    parent[v]=v;
    sz[v]=1;
}

int find_set(int v)
{
    if(v==parent[v])
    {
        return v;
    }
    return parent[v]=find_set(parent[v]);
}
void union_set(int a,int b)
{
     a=find_set(a);
     b=find_set(b);
    if(a!=b)
    {
        if(sz[a] <sz[b])
        {
            swap(a,b);
        }
        parent[b]=a;
        sz[a]+=sz[b];
    }
}

int main()
{
   for(int i=0;i<N;i++)
   {
       make_pair(i);
   }
   int n,m;
   cout<<"enter no of nodes and no of edges"<<endl;
   cin>>n>>m;
   vector<vector<int>>edges;
   cout<<"enter nodes and weights between the nodes"<<endl;
   for(int i=0;i<m;i++)
   {
       int u,v,w;
       cin>>u>>v>>w;
       edges.push_back({w,u,v});
   }
   sort(edges.begin(),edges.end());
   int cost=0;
   for(auto x:edges)
   {
       int w=x[0];
       int u=x[1];
       int v=x[2];
       int x1=find_set(u);
       int y1=find_set(v);
       if(x1==y1)
       {
           continue;
       }
       else
       {
           cout<<u<<" "<<v<<endl;
           cost+=w;
           union_set(u,v);
       }
   }
   cout<<"minimum cost of a graph"<<" "<<cost<<endl;
   return 0;
}
