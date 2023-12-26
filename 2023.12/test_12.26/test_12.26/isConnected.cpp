#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Graph
{
	int V;
	vector<vector<int>> adj;
public:
	Graph(int V) : V(V)
	{
		adj.resize(V);
	}

	void addEdge(int u, int v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	void dfs(int node, vector<int>& vis)
	{
		vis[node] = 1;
		for (int i : adj[node])
			if (!vis[i])
				dfs(i, vis);
	}

	bool isConnected()
	{
		vector<int> vis(V, 0);
		int components = 0;
		for(int i = 0; i < V; i++)
			if (!vis[i])
			{
				dfs(i, vis);
				++components;
			}

		if (components == 1) 
			cout << "YES, 1 component." << endl;		
		else 
			cout << "NO, " << components << " components." << endl;
		//components == 1说明图是连通的
		return components == 1;
	}
};

int main()
{
	int n, m;
	cin >> n >> m;
	Graph g(n);

	int u, v;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		u--, v--;
		g.addEdge(u, v);
	}

	cout << (g.isConnected() ? "YES" : "NO") << endl;

	return 0;
}

/*
3
3
2 1
3 1
3 2
*/