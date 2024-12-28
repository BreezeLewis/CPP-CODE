#include<bits/stdc++.h>
using i64 = long long;
const int maxn = 1e5 + 10, B = 300;
i64 a[maxn];
int fa[maxn], dep[maxn];
std::vector<int> P[maxn];
i64 ans[maxn][B + 10];
int id[maxn];
bool vis[maxn];
inline i64 calc(int x, int y) {
    if (vis[dep[x]]) return ans[x][id[y]];
    return calc(fa[x], fa[y]) + a[x] * a[y];
}
int main() {
    int n, q; scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (int i = 2; i <= n; i++) scanf("%d", &fa[i]), P[dep[i] = dep[fa[i]] + 1].push_back(i);
    ans[1][1] = a[1] * a[1], vis[0] = 1, id[1] = 1;
    for (int i = 1; i <= n; i++) {
        if (P[i].size() > B) continue;
        int c = 0;
        for (int x : P[i]) id[x] = ++c;
        for (int x : P[i]) for (int y : P[i]) ans[x][id[y]] = calc(x, y);
        vis[i] = 1;
    }
    while (q--) {
        int x, y; scanf("%d%d", &x, &y);
        printf("%lld\n", calc(x, y));
    }
    return 0;
}
