#include <iostream>
#include <algorithm>
using namespace std;

const int M = 200010;
const int N = 5010;

int n, m;
int p[N];

struct Edge {
    int a, b, w;
    bool operator< (const Edge& W)const {
        return w < W.w;
    }
}edges[M];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int kruskal() {
    sort(edges, edges + m);
    for (int i = 1; i <= n; i++)
        p[i] = i;
    int res = 0, cnt = 0;
    for (int i = 0; i < m; i++) {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a), b = find(b);
        if (a != b) {
            p[a] = b;
            res += w;
            cnt++;
        }
    }
    if (cnt < n - 1) return -1;
    return res;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edges[i] = { a, b, w };
    }
    int res = kruskal();
    if (res != -1)
        cout << res << endl;
    else
        cout << "orz" << endl;
    return 0;
}