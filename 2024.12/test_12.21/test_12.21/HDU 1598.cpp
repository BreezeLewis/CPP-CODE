#include <iostream>
#include <algorithm>
using namespace std;

const int M = 1010;
const int N = 210;

int n, m;
int p[N];

struct Edge {
    int a, b, w;
    bool operator< (const Edge& W) const {
        return w < W.w;
    }
} edges[M];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int solve(int start, int end) {
    int res = 0x3f3f3f3f;
    for (int i = 0; i < m; i++) {
        for (int j = 1; j <= n; j++) p[j] = j;
        for (int j = i; j < m; j++) {
            int a = edges[j].a, b = edges[j].b;
            a = find(a), b = find(b);
            if (a != b) p[a] = b;

            if (find(start) == find(end)) {
                res = min(res, edges[j].w - edges[i].w);
                break;
            }
        }
    }
    if (res < 0x3f3f3f3f) return res;
    return -1;
}

int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < m; i++) {
            int a, b, w;
            scanf("%d%d%d", &a, &b, &w);
            edges[i] = { a, b, w };
        }
        sort(edges, edges + m);
        int q;
        scanf("%d", &q);
        while (q--) {
            int start, end;
            scanf("%d%d", &start, &end);
            cout << solve(start, end) << endl;
        }
    }
    return 0;
}