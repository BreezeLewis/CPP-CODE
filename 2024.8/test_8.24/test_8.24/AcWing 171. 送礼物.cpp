#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

const int N = 1 << 24;

int n, m, k;
int g[50], weights[N];
int cnt = 0;
int ans;


void dfs(int u, int s)
{
    if (u == k)
    {
        weights[cnt++] = s;
        return;
    }


    dfs(u + 1, s);
    if ((LL)s + g[u] <= m) dfs(u + 1, s + g[u]);
}


void dfs2(int u, int s)
{
    if (u == n)
    {
        int l = 0, r = cnt - 1;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (weights[mid] + (LL)s <= m) l = mid;
            else r = mid - 1;
        }
        if (weights[l] + (LL)s <= m) ans = max(ans, weights[l] + s);

        return;
    }


    dfs2(u + 1, s);
    if ((LL)s + g[u] <= m) dfs2(u + 1, s + g[u]);
}



int main()
{
    cin >> m >> n;

    for (int i = 0; i < n; i++) cin >> g[i];

    sort(g, g + n);
    reverse(g, g + n);

    k = n / 2;

    dfs(0, 0);

    sort(weights, weights + cnt);
    cnt = unique(weights, weights + cnt) - weights;

    dfs2(k, 0);

    cout << ans << endl;

    return 0;
}