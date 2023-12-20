#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

class Graph {
    int V; // 节点数
    vector<vector<int>> adj; // 邻接表

public:
    Graph(int V) : V(V) {
        adj.resize(V);
    }

    // 添加边（无向图）
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // 因为是无向图，所以要添加双向边
    }

    // 计算节点的度数序列
    vector<int> degreeSequence() {
        vector<int> degrees(V, 0);

        // 计算每个节点的度数
        for (int u = 0; u < V; ++u) {
            degrees[u] = adj[u].size();
        }

        // 对度数序列进行非递增排序
        sort(degrees.rbegin(), degrees.rend());

        return degrees;
    }
};

int main() {
    fstream file;
    file.open("D:\\cxdownload\\in2.txt", ios::in);

    int N; // 测试样例数目
    file >> N;

    while (N--) {
        int n, m; // 结点数和边数
        file >> n >> m;

        Graph g(n);

        // 读取每个结点对并添加边
        for (int i = 0; i < m; ++i) {
            int u, v;
            file >> u >> v;
            g.addEdge(u, v);
        }

        // 计算节点的度数序列
        vector<int> degrees = g.degreeSequence();

        // 输出节点的度数序列
        for (int degree : degrees) {
            cout << degree << " ";
        }
        cout << endl;
    }

    return 0;
}
