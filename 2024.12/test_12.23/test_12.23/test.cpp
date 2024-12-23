#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1005;

int n, m, k;
int dist[MAXN][MAXN];
vector<pair<int, int>> deliveries;
vector<pair<pair<int, int>, int>> edges;

// Floyd-Warshall算法预处理所有点对最短路
void floyd() {
    // 初始化距离矩阵
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    // 添加边
    for (auto& e : edges) {
        int u = e.first.first;
        int v = e.first.second;
        int w = e.second;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }

    // Floyd算法
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

// 计算当前配送总成本
int calculateTotalCost() {
    int total = 0;
    for (auto& d : deliveries) {
        total += dist[d.first][d.second];
    }
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    // 读入边
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({ {u, v}, w });
    }

    // 读入配送需求
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        deliveries.push_back({ x, y });
    }

    floyd();  // 预处理原图最短路
    int original_cost = calculateTotalCost();
    int ans = original_cost;

    // 尝试每条边作为优化边
    for (auto& e : edges) {
        int u = e.first.first;
        int v = e.first.second;
        int w = e.second;

        // 临时保存原始距离
        vector<vector<int>> temp_dist(n + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                temp_dist[i][j] = dist[i][j];
            }
        }

        // 将边权重设为0并更新受影响的最短路
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][u] != INF && dist[v][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][u] + dist[v][j]);
                }
                if (dist[i][v] != INF && dist[u][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][v] + dist[u][j]);
                }
            }
        }

        ans = min(ans, calculateTotalCost());

        // 恢复原始距离
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = temp_dist[i][j];
            }
        }
    }

    cout << ans << '\n';
    return 0;
}