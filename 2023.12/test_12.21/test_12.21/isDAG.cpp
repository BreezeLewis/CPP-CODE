#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isDAG(int n, vector<vector<int>>& edges) {
    vector<int> inDegree(n, 0);
    vector<vector<int>> adjList(n, vector<int>());

    // �����ڽӱ���������
    for (auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adjList[u].push_back(v);
        inDegree[v]++;
    }

    queue<int> q;

    // �����Ϊ0�Ľڵ�������
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

        // ����ÿ���뵱ǰ�ڵ����ڵĽڵ㣬������ȼ�1
        for (int v : adjList[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    // ������ʵĽڵ�����ͼ�нڵ�����ȣ�����DAG
    return visited == n;
}

int main() {
    int n = 5; // ͼ�нڵ������
    vector<vector<int>> edges = { {0, 1}, {1, 2}, {2, 3}, {3, 4} }; // ͼ�ı�

    if (isDAG(n, edges)) {
        cout << "The graph is a DAG." << endl;
    }
    else {
        cout << "The graph is not a DAG." << endl;
    }

    return 0;
}
