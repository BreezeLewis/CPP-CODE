#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isDAG(int n, vector<vector<int>>& edges) {
    vector<int> inDegree(n, 0);
    vector<vector<int>> adjList(n, vector<int>());

    // 构建邻接表和入度数组
    for (auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adjList[u].push_back(v);
        inDegree[v]++;
    }

    queue<int> q;

    // 将入度为0的节点加入队列
    for (int i = 0; i < n; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    int visited = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        visited++;

        // 对于每个与当前节点相邻的节点，将其入度减1
        for (int v : adjList[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    // 如果访问的节点数与图中节点数相等，则是DAG
    return visited == n;
}

int main() {
    int n = 5; // 图中节点的数量
    vector<vector<int>> edges = { {0, 1}, {1, 2}, {2, 3}, {3, 4} }; // 图的边

    if (isDAG(n, edges)) {
        cout << "The graph is a DAG." << endl;
    }
    else {
        cout << "The graph is not a DAG." << endl;
    }

    return 0;
}
