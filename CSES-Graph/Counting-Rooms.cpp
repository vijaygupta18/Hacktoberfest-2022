#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<bool> vis(1000000);
char Map[1000][1000];
int n, m, rooms = 0;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int encode(int i, int j)
{
    return i*m+j;
}
void dfs(int i, int j)
{
   if(i < 0 || j < 0 || i >= n || j >= m || Map[i][j] == '#')
   return;

   vis[encode(i,j)] = true;
   
   for(int idx = 0; idx < 4; idx++)
   {   if(i+dx[idx] < 0 || j+dy[idx] < 0)
        continue;  
       if(vis[encode(i+dx[idx],j+dy[idx])])
       continue;    
       dfs(i+dx[idx],j+dy[idx]);
   }
}
int main()
{   
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> Map[i][j];
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {  if(!vis[encode(i,j)] && Map[i][j] == '.')
            { 
              dfs(i,j);
              rooms++;
            }
        }
    } 
    cout << rooms;
}
