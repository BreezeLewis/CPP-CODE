#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

void dijkstra(const vector<vector<pair<int, int>>>& graph, int src, vector<int>& dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, src });
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const auto& [v, weight] : graph[u]) {
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({ dist[v], v });
            }
        }
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<pair<int, int>>> graph(V);

    cout << "Enter edges (u v weight):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].push_back({ v, weight });
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    vector<int> dist(V, INF);
    dijkstra(graph, src, dist);

    cout << "Shortest distances from source " << src << ":" << endl;
    for (int i = 0; i < V; ++i) {
        if (dist[i] == INF)
            cout << i << ": INF" << endl;
        else
            cout << i << ": " << dist[i] << endl;
    }

    return 0;
}
