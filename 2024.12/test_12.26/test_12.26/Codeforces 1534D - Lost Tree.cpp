#include "stdc++.h"
using namespace std;

class Solution {
private:
    int n;
    vector<vector<int>> edges; // 存储最终的树边
    vector<int> color;         // 用于二分图染色
    vector<int> parent;        // 并查集的父节点数组
    vector<vector<int>> dist;  // 存储询问得到的距离

    // 并查集：查找父节点
    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    // 并查集：合并两个集合
    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px != py) parent[px] = py;
    }

public:
    void solve() {
        // 读入节点数
        cin >> n;
        edges.clear();
        color.resize(n + 1, -1);
        parent.resize(n + 1);
        dist.resize(n + 1, vector<int>(n + 1));

        // 初始化并查集
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        // 第一步：询问节点1的所有距离，用于二分图染色
        cout << "? 1" << endl;
        vector<int> d(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> d[i];
            dist[1][i] = d[i];
            dist[i][1] = d[i];
        }

        // 使用距离的奇偶性进行二分图染色
        color[1] = 0;
        vector<vector<int>> levels(2); // 按奇偶距离分组
        for (int i = 2; i <= n; i++) {
            color[i] = d[i] % 2;
            levels[color[i]].push_back(i);
        }

        // 选择较小的颜色集合进行询问
        vector<int>& queryNodes = levels[levels[0].size() < levels[1].size() ? 0 : 1];

        // 对选定的节点集合进行询问
        for (int node : queryNodes) {
            cout << "? " << node << endl;
            for (int i = 1; i <= n; i++) {
                cin >> d[i];
                dist[node][i] = d[i];
                dist[i][node] = d[i];
            }
        }

        // 使用Kruskal算法重建树
        vector<tuple<int, int, int>> allEdges; // {distance, u, v}
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (dist[i][j] == 1) { // 只考虑直接相连的边
                    allEdges.push_back({ 1, i, j });
                }
            }
        }

        // Kruskal算法：按边权排序
        sort(allEdges.begin(), allEdges.end());

        // 重建树结构
        for (auto [d, u, v] : allEdges) {
            if (find(u) != find(v)) {
                unite(u, v);
                edges.push_back({ u, v });
            }
        }

        // 输出结果
        cout << "!" << endl;
        for (const auto& edge : edges) {
            cout << edge[0] << " " << edge[1] << endl;
        }
    }
};

int main() {
    Solution solution;
    solution.solve();
    return 0;
}