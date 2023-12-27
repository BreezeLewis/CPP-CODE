#include <iostream>
#include <vector>
#include <queue>
#include <climits>
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
	}

	void shortestPath(int src)
	{
		vector<int> dist(V, INT_MAX);//初始化源点到每个点的距离
		dist[src] = 0;//
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;//优先队列

		pq.push({ 0, src });

		while (!pq.empty())
		{
			int distance = pq.top().first;
			int current = pq.top().second;

			pq.pop();

			for(int neighbor: adj[current])
				if (dist[neighbor] > distance + 1)
				{
					dist[neighbor] = distance + 1;
					pq.push({ dist[neighbor], neighbor });
				}
		}

		for(int i = 0; i < V; i++)
			if(dist[i] != INT_MAX)
				cout << src + 1 << "-" << i + 1 << ":" << dist[i] << endl;
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
		g.addEdge(u - 1, v - 1);
	}

	int src;
	cin >> src;

	g.shortestPath(src - 1);

	return 0;
}