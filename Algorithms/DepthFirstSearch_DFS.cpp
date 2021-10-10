#include <iostream>
#include <vector>

using namespace std;

int n{}, m{};
vector<int> adj_list[100000];
bool visited[100000];

void reset()
{
	for (int i = 0; i < 100000; ++i)
	{
		visited[i] = false;
	}
}

void dfs(int s)
{
	visited[s] = 1;

	for (int i = 0; i < (int)adj_list[s].size(); ++i)
	{
		int t = adj_list[s][i];
		if(visited[t] == false)
			dfs(t);
	}
}


int main()
{
	int a{}, b{}, x{}, cnt_not_connected{0};

	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
	}

    // Root node to start DFS from
	cin >> x;

	reset();
	dfs(x);

    //Counting number of nodes not connected to root
	for (int i = 1; i <= n; ++i)
	{
		if(visited[i] == false)
			cnt_not_connected++;
	}

	cout << cnt_not_connected;
	return 0;
}