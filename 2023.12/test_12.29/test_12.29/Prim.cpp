/*
5
5
5 3 2
5 1 3
3 1 5
4 2 5
4 3 5

*/

/*
7
13
4 5 5
3 6 4
2 6 5
5 7 1
3 7 3
5 3 1
7 4 5
6 1 1
7 2 1
3 4 4
3 2 6
1 5 7
4 2 6
*/

/*
5
4
1 2 1
2 3 2
3 4 3
4 5 4
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
	int V;
	vector<vector<pair<int, int>>> adj;
public:
	Graph(int V) :V(V)
	{
		adj.resize(V);
	}

	int prim()
	{
		vector<bool> inMST(V, false);
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
		int totalWeight = 0;

		pq.push({ 0, 0 });

		while (!pq.empty())
		{
			int weight = pq.top().first;
			int node = pq.top().second;
			pq.pop();

			if (inMST[node])
				continue;

			inMST[node] = true;
			totalWeight += weight;

			for (const auto& edge : adj[node])
				if (!inMST[edge.first])
					pq.push({ edge.second, edge.first });
		}

		return totalWeight;
	}

	void addEdge(int u, int v, int w)
	{
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
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

	cout << g.prim() << endl;

	return 0;
}