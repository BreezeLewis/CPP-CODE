#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX;

// ʹ��Floyd - Warshall�㷨�������·��
void floydWarshall(vector<vector<int>>& graph) {
    int n = (int)graph.size();
    // ��ʼ���������
    vector<vector<int>> dist = graph;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j && graph[i][j] == 0) {
                dist[i][j] = INF;
            }
        }
    }

    // Floyd - Warshall�㷨����
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // ������
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == INF) {
                cout << "INF ";
            }
            else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    // ��ʼ��ͼ���ڽӾ���
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        // �����رߣ�ֻ����Ȩֵ��С�ı�
        if (graph[u - 1][v - 1] == 0 || w < graph[u - 1][v - 1]) {
            graph[u - 1][v - 1] = w;
            graph[v - 1][u - 1] = w;
        }
    }

    floydWarshall(graph);
    return 0;
}