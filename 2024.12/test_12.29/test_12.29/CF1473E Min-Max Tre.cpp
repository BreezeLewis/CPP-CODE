#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
const int N = 2e5 + 10;
const ll INF = 1e18;

int n, m;
// 使用邻接表存储图，{目标节点, 边权值}
vector<pair<int, int>> adj[N];
// dp[i][j][k]表示到达节点i时，已经选择最大值j次，最小值k次的最小距离
ll dist[N][2][2];

// Dijkstra算法求最短路
void dijkstra() {
    // 初始化距离为无穷大
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                dist[i][j][k] = INF;
            }
        }
    }

    // {距离，{节点，状态}}，使用优先队列优化
    priority_queue<pair<ll, array<int, 3>>, vector<pair<ll, array<int, 3>>>, greater<>> pq;
    dist[1][0][0] = 0;
    pq.push({ 0, {1, 0, 0} });

    while (!pq.empty()) {
        auto [d, state] = pq.top();
        int u = state[0], max_used = state[1], min_used = state[2];
        pq.pop();

        // 如果当前距离大于已知最短距离，跳过
        if (d > dist[u][max_used][min_used]) continue;

        // 贪心策略：遍历所有相邻边
        for (auto [v, w] : adj[u]) {
            // 尝试四种状态：不选/选最大/选最小/都选
            for (int new_max = 0; new_max < 2; new_max++) {
                if (new_max && max_used) continue;
                for (int new_min = 0; new_min < 2; new_min++) {
                    if (new_min && min_used) continue;

                    // 计算新的边权
                    ll new_w = w;
                    if (new_max) new_w += w;  // 选为最大值时加上权值
                    if (new_min) new_w -= w;  // 选为最小值时减去权值

                    // 更新最短距离
                    int nxt_max = max_used | new_max;
                    int nxt_min = min_used | new_min;
                    ll new_dist = d + new_w;

                    if (new_dist < dist[v][nxt_max][nxt_min]) {
                        dist[v][nxt_max][nxt_min] = new_dist;
                        pq.push({ new_dist, {v, nxt_max, nxt_min} });
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }

    dijkstra();

    // 输出除了起点外的所有点的结果
    for (int i = 2; i <= n; i++) {
        cout << dist[i][1][1] << " ";
    }
    cout << "\n";

    return 0;
}