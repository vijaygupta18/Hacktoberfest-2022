// Minimum Spanning in c++
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7, inf = 1000;

void add_edge(vector<pair<int, int>>vec[], int u, int v, int weight) {
    vec[u].push_back(make_pair(v, weight));
    vec[v].push_back(make_pair(u, weight));
}

class node
{
    int u, v, wt;
public:
    int getU() { 
        return u; 
    }
    int getV() { 
        return v; 
    }
    int getWt() { 
        return wt; 
    }
    node(int first, int second, int weight) {
        u = first; 
        v = second;
        wt = weight;
    }
};

class Compare
{
public:
    bool operator() (node node1, node node2) {
        return node1.getWt() > node2.getWt();
    }
};

void dijkstra(vector<pair<int, int>>vec[], int v, int source) {
    vector<int>dist(v, inf);
    vector<bool>visited(v, false);
    vector<int>parent(v, -1);

    visited[source] = true;
    dist[source] = 0;

    priority_queue<node, vector<node>, Compare>pq;

    node imagionary(-1, source, 0);
    pq.push(imagionary);

    while(pq.empty() == false) {
        node current = pq.top();
        pq.pop();
        int first_node = current.getU();
        int second_node = current.getV();
        int weight = current.getWt();

        visited[second_node] = true;

        for(int i = 0;i<vec[second_node].size();i++) {
            int adjacent_node = vec[second_node][i].first;
            int adjacent_weight = vec[second_node][i].second;

            if(visited[adjacent_node] == false && adjacent_weight < dist[adjacent_node]) {
                dist[adjacent_node] = adjacent_weight;
                parent[adjacent_node] = second_node;
                node curr(second_node, adjacent_node, dist[adjacent_node]);
                pq.push(curr);
            }
        }
    }
    cout<<"Minimum Distances are : "<<endl;
    for(int i=0; i<v;i++) {
        cout<<dist[i]<<endl;
    }
    cout<<endl<<"Parent Array/ Edges Present in MST are : "<<endl;
    for(int i=0; i<v; i++) {
        if(i != source) {
            cout<<i<<" "<<parent[i]<<endl;
        }
    }
    return ;
}

int main()
{
    int v = 4;
    vector<pair<int ,int>>vec[v];
    add_edge(vec, 0, 1, 5);
    add_edge(vec, 0, 2, 8);
    add_edge(vec, 1, 2, 9);
    add_edge(vec, 1, 3, 2);
    add_edge(vec, 2, 3, 6);

    int source = 0;

    dijkstra(vec, v, source);
    return 0;
}
