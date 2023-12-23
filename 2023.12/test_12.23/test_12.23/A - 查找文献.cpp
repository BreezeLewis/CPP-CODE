#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int start = 1;

class Graph
{
	int V;
	vector<vector<int>> adj;
public:

	Graph(int V) : V(V + 1)
	{
		adj.resize(V + 1);
	}

	void addEdge(int u, int v)
	{
		adj[u].push_back(v);
	}

	void DFS(int node, vector<int>& vis)
	{
		
		vis[node] = true;
		cout << node << " ";
		sort(adj[node].begin(), adj[node].end());
		for (int i : adj[node])
		{
			if (!vis[i])
				DFS(i, vis);
		}

	}

	void BFS()
	{
		queue<int> q;
		q.push(start);
		vector<int> vis(V + 1, 0);
		vis[start] = true;

		while (!q.empty())
		{
			int i = q.front();
			q.pop();
			cout << i << " ";
			sort(adj[i].begin(), adj[i].end());
			for (auto e : adj[i])
			{
				if (!vis[e])
				{
					vis[e] = true;
					q.push(e);
				}
			}
		}

		cout << endl;
	}

};

int main()
{
	int n, m;
	cin >> n >> m;

	Graph g(n);

	int u, v;
	for(int i = 0; i < m; i++)
	{
		cin >> u >> v;
		g.addEdge(u, v);
	}

	vector<int> vis(n + 1, 0);
	g.DFS(start, vis); 
	cout << endl;
	g.BFS(); 

	return  0;
}