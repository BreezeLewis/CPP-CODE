#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 10010, M = 2 * N, INF = 0x3f3f3f3f;

int n;
int h[N], e[M], w[M], ne[M], idx;
int up[N], d1[N], d2[N], p1[N];
bool is_leaf[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dfs_d(int u, int father)
{
    d1[u] = d2[u] = -INF;

    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (j == father) continue;

        int d = dfs_d(j, u) + w[i];
        if (d >= d1[u])
        {
            d2[u] = d1[u], d1[u] = d;
            p1[u] = j;
        }
        else if (d > d2[u]) d2[u] = d;
    }

    if (d1[u] == -INF)
    {
        d1[u] = d2[u] = 0;
        is_leaf[u] = true;
    }

    return d1[u];
}

int dfs_u(int u, int father)
{
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (j == father) continue;

        if (p1[u] == j) up[j] = max(d2[u], up[u]) + w[i];
        else up[j] = max(d1[u], up[u]) + w[i];

        dfs_u(j, u);
    }
}

int main()
{
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }

    dfs_d(1, -1);

    dfs_u(1, -1);

    int res = d1[1];
    for (int i = 2; i <= n; i++)
        if (is_leaf[i]) res = min(res, up[i]);
        else res = min(res, max(up[i], d1[i]));

    cout << res;

    return 0;
}