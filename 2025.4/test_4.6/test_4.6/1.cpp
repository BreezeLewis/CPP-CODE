#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// 边的结构体
struct Edge {
    int dest;       // 目标节点
    int weight;     // 边的权重

    Edge(int d, int w) : dest(d), weight(w) {}
};

// 比较函数，用于优先队列
struct CompareDistance {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second > p2.second; // 小顶堆
    }
};

class Graph {
private:
    int V;                          // 顶点数量
    vector<vector<Edge>> adjList;   // 邻接表

public:
    Graph(int vertices) : V(vertices) {
        adjList.resize(V);
    }

    // 添加边
    void addEdge(int src, int dest, int weight) {
        adjList[src].push_back(Edge(dest, weight));
    }

    // Dijkstra算法实现
    vector<int> dijkstra(int src) {
        // 初始化距离数组
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        // 记录节点是否已处理
        vector<bool> processed(V, false);

        // 优先队列 <顶点, 距离>
        priority_queue<pair<int, int>, vector<pair<int, int>>, CompareDistance> pq;
        pq.push(make_pair(src, 0));

        while (!pq.empty()) {
            // 获取当前距离最小的顶点
            int u = pq.top().first;
            pq.pop();

            // 如果已处理则跳过
            if (processed[u]) continue;
            processed[u] = true;

            // 检查所有邻居
            for (const Edge& edge : adjList[u]) {
                int v = edge.dest;
                int weight = edge.weight;

                // 松弛操作
                if (!processed[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(v, dist[v]));
                }
            }
        }

        return dist;
    }

    // 打印图
    void printGraph() {
        for (int i = 0; i < V; i++) {
            cout << "顶点 " << i << " 的邻接表: ";
            for (const Edge& edge : adjList[i]) {
                cout << "(" << edge.dest << ", " << edge.weight << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    // 创建测试图 (5个顶点)
    Graph g(5);

    // 添加边
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 1, 2);
    g.addEdge(2, 3, 5);
    g.addEdge(3, 4, 3);
    g.addEdge(1, 4, 7);

    cout << "图的邻接表表示:" << endl;
    g.printGraph();

    // 从顶点0运行Dijkstra算法
    vector<int> distances = g.dijkstra(0);

    cout << "\n从源点0到各顶点的最短距离:" << endl;
    for (int i = 0; i < distances.size(); i++) {
        cout << "顶点 " << i << ": ";
        if (distances[i] == INT_MAX)
            cout << "不可达";
        else
            cout << distances[i];
        cout << endl;
    }

    return 0;
}