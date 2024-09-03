#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = -1;

int main() {
    int n, m, t;
    cin >> n >> m >> t;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));
    dp[1][0] = 1;  

    vector<vector<pair<int, int>>> adj(n + 1);  

    for (int i = 0; i < t; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].emplace_back(y, z);
        adj[y].emplace_back(x, z);
    }

    for (int time = 0; time <= m; ++time) {
        for (int u = 1; u <= n; ++u) {
            if (dp[u][time] != INF) {
                for (auto& edge : adj[u]) {
                    int v = edge.first, cost = edge.second;
                    if (time + cost <= m) {
                        dp[v][time + cost] = max(dp[v][time + cost], dp[u][time] + 1);
                    }
                }
            }
        }
    }

    int max_scenic = dp[n][m];
    if (max_scenic == INF) {
        cout << -1 << endl;
    }
    else {
        cout << max_scenic << endl;
    }

    return 0;
}
