#include <iostream>

using namespace std;

const int N = 55;

int n, a[N], up[N], down[N], ans;

void dfs(int u, int su, int sd)
{
    if (su + sd >= ans) return;
    if (u == n)
    {
        ans = su + sd;
        return;
    }

    int k = 0;
    while (k < su && up[k] >= a[u]) k++;
    int t = up[k];
    up[k] = a[u];
    if (k < su) dfs(u + 1, su, sd);
    else dfs(u + 1, su + 1, sd);
    up[k] = t;

    k = 0;
    while (k < sd && down[k] <= a[u]) k++;
    t = down[k];
    down[k] = a[u];
    if (k < sd) dfs(u + 1, su, sd);
    else dfs(u + 1, su, sd + 1);
    down[k] = t;
}

int main()
{
    while (cin >> n, n)
    {
        for (int i = 0; i < n; i++) cin >> a[i];

        ans = n;

        dfs(0, 0, 0);

        cout << ans << endl;
    }

    return 0;
}