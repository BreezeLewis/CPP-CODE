#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

class Graph {
    int V; // 节点数
    vector<vector<int>> adj; // 邻接表

public:
    Graph(int V) : V(V) {
        adj.resize(V);
    }

    // 添加边
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    // 拓扑排序
    vector<int> topologicalSort() {
        // 记录节点入度
        vector<int> inDegree(V, 0);
        for (int u = 0; u < V; ++u) {
            for (int v : adj[u]) {
                inDegree[v]++;
            }
        }

        // 将入度为 0 的节点加入队列
        queue<int> q;
        for (int i = 0; i < V; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> result;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            result.push_back(u);

            // 减少相邻节点的入度，并将入度为 0 的节点加入队列
            for (int v : adj[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return result;
    }
};

int main() {
    int V, T, n;
    fstream file;
    file.open("D:\\cxdownload\\in2.txt", ios::in);
    file >> n;
    while (n--)
    {
        file >> V >> T;
        Graph g(V);

        while (T--)
        {
            int a, b;
            file >> a >> b;
            g.addEdge(a, b);
        }


        // 进行拓扑排序
        vector<int> result = g.topologicalSort();

        // 输出排序结果
        cout << "拓扑排序结果：" << endl;
        for (int node : result) {
            cout << node << " ";
        }
        cout << endl;
    }
   
    
    
    

    

    

    return 0;
}
