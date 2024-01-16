#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void dfs(unordered_map<int, vector<int>>& graph, unordered_set<int>& visited, int start) {
    visited.insert(start);
    for (int neighbor : graph[start]) {
        if (visited.find(neighbor) == visited.end()) {
            dfs(graph, visited, neighbor);
        }
    }
}

string has_connecting_path(int n, const vector<pair<int, int>>& edges) {
    unordered_map<int, vector<int>> graph;

    for (const auto& edge : edges) {
        int x = edge.first;
        int y = edge.second;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for (int i = 1; i <= n; ++i) {
        unordered_set<int> visited;
        dfs(graph, visited, i);
        if (visited.size() < n) {
            return "NO";
        }
    }

    return "YES";
}

int main() {
    int test_cases;
    cin >> test_cases;

    for (int t = 0; t < test_cases; ++t) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> edges(m);

        for (int i = 0; i < m; ++i) {
            cin >> edges[i].first >> edges[i].second;
        }

        string result = has_connecting_path(n, edges);
        cout << result << endl;
    }

    return 0;
}
