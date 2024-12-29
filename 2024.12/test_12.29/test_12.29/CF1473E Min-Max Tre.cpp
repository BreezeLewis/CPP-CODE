#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
const int N = 2e5 + 10;
const ll INF = 1e18;

int n, m;
// ʹ���ڽӱ�洢ͼ��{Ŀ��ڵ�, ��Ȩֵ}
vector<pair<int, int>> adj[N];
// dp[i][j][k]��ʾ����ڵ�iʱ���Ѿ�ѡ�����ֵj�Σ���Сֵk�ε���С����
ll dist[N][2][2];

// Dijkstra�㷨�����·
void dijkstra() {
    // ��ʼ������Ϊ�����
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                dist[i][j][k] = INF;
            }
        }
    }

    // {���룬{�ڵ㣬״̬}}��ʹ�����ȶ����Ż�
    priority_queue<pair<ll, array<int, 3>>, vector<pair<ll, array<int, 3>>>, greater<>> pq;
    dist[1][0][0] = 0;
    pq.push({ 0, {1, 0, 0} });

    while (!pq.empty()) {
        auto [d, state] = pq.top();
        int u = state[0], max_used = state[1], min_used = state[2];
        pq.pop();

        // �����ǰ���������֪��̾��룬����
        if (d > dist[u][max_used][min_used]) continue;

        // ̰�Ĳ��ԣ������������ڱ�
        for (auto [v, w] : adj[u]) {
            // ��������״̬����ѡ/ѡ���/ѡ��С/��ѡ
            for (int new_max = 0; new_max < 2; new_max++) {
                if (new_max && max_used) continue;
                for (int new_min = 0; new_min < 2; new_min++) {
                    if (new_min && min_used) continue;

                    // �����µı�Ȩ
                    ll new_w = w;
                    if (new_max) new_w += w;  // ѡΪ���ֵʱ����Ȩֵ
                    if (new_min) new_w -= w;  // ѡΪ��Сֵʱ��ȥȨֵ

                    // ������̾���
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

    // ����������������е�Ľ��
    for (int i = 2; i <= n; i++) {
        cout << dist[i][1][1] << " ";
    }
    cout << "\n";

    return 0;
}