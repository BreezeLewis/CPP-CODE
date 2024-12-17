#include <iostream>
const int N = 10010;
const int M = 500010;
using namespace std;
int n, m, s;
// n��ʾ������m��ʾ������s��ʾ���
long long dist[N];
// dist[x]�洢1��x����̾���
struct Edge {
    int a, b, w;
} edges[M];
int bellman_ford() {
    for (int i = 1; i <= n; i++)
        dist[i] = (1 << 31) - 1;
    dist[s] = 0;
    for (int i = 0; i < n; i++) {
        bool relaxed = false;
        for (int j = 0; j < m; j++) {
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            if (dist[b] > dist[a] + w) {
                dist[b] = dist[a] + w;
                relaxed = true;
            }
        }
        if (!relaxed) break;
    }
    if (dist[n] > (1 << 30)) return -1;
    return dist[n];
}
int main() {
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edges[i] = { a,b,w };
    }
    int t = bellman_ford();
    for (int i = 1; i <= n; i++)
        printf("%d ", dist[i]);
}