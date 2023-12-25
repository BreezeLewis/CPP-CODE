#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/*
8 9
1 2
1 3
1 4
2 5
2 6
3 7
4 7
4 8
7 8
*/

int start = 1;

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
	}

	void bfs()
	{
		vector<int> vis(V, 0);
		queue<int> q;
		q.push(start);
		vis[start] = true;
		

		while (!q.empty())
		{
			int node = q.front();
			cout << node << " ";
			q.pop();
			sort(adj[node].begin(), adj[node].end());

			for(int i: adj[node])
				if (!vis[i])
				{
					vis[i] = true;
					q.push(i);
				}
		}
		cout << endl;
	}

	void dfs(int node, vector<int>& vis)
	{
		cout << node << " ";
		vis[node] = true;
		sort(adj[node].begin(), adj[node].end());


		for(int i: adj[node])
			if (!vis[i])
				dfs(i, vis);
	}

	bool isTopoSequence(vector<int>& v)
	{
		vector<int> vis(V, 0);
		for (auto& e : v)
		{
			for (int i = 0; i < adj.size(); i++)
			{
				if (vis[i])
					continue;
				for (int j = 0; j < adj[i].size(); i++)
				{
					if (adj[i][j] == e)
						return false;
				}
			}
			vis[e] = 1;
		}
		return true;
	}

	bool isDAG(vector<int>& inDegree)
	{
		queue<int> q;

		for (int i = 0; i < V; i++)
		{
			if (inDegree[i] == 0)
				q.push(i);
		}

		int visited = 0;
		while (!q.empty())
		{
			int node = q.front();
			q.pop();
			visited++;

			for (int i : adj[node])
			{
				inDegree[i]--;
				if (inDegree[i] == 0)
					q.push(i);
			}
		}

		return visited == V;
	}
};

int main()
{
	int n, m;
	cin >> n >> m;

	Graph g(n);
	vector<int> inDegree(n, 0);

	int u, v;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		g.addEdge(u, v);
		inDegree[v]++;
	}

	cout << g.isDAG(inDegree) << endl;

	return 0;
}


/*
8 17
0 7
0 2
2 5
0 6
1 3
6 7
2 6
4 6
3 6
3 5
1 2
2 3
1 4
3 4
1 6
0 5
0 4
*/