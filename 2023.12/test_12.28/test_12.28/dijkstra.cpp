#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Graph
{
	int V;
	vector<vector<pair<int, int>>> adj;
public:
	Graph(int V) : V(V)
	{
		adj.resize(V);
	}

	void dijkstra(int src)
	{
		vector<int> dist(V, INT_MAX);//src到每个点的距离
		dist[src] = 0;

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

		pq.push({ 0, src });

		while (!pq.empty())
		{
			int distance = pq.top().first;
			int current = pq.top().second;

			pq.pop();

			if (dist[current] < distance)
				continue;

			for (auto& edge : adj[current])//遍历当前在节点相邻的边
			{
				int neighbor = edge.first;
				int weight = edge.second;

				if (dist[neighbor] > distance + weight)
				{
					dist[neighbor] = distance + weight;
					pq.push({ dist[neighbor], neighbor });
				}
			}
		}

		for (int i = 0; i < V; i++)
		{
			if (dist[i] != INT_MAX)
				cout << src + 1 << "-" << i + 1 << ":" << dist[i] << endl;
		}
	}

	void addEdge(int u, int v, int w)
	{
		adj[u].push_back(make_pair(v, w));
	}


};

int main()
{
	int n, m;
	cin >> n >> m;

	Graph g(n);

	int u, v, w;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v >> w;
		g.addEdge(u - 1, v - 1, w);
	}

	int src;
	cin >> src;

	g.dijkstra(src - 1);

	return 0;
}