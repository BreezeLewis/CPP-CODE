#include <iostream>
#include <algorithm>

using namespace std;

const int N = 20;

int n, m, ans = N;
int w[N];
int sum[N];

void dfs(int u, int k)//下标为u，有k辆车
{
    if (k >= ans) return;
    if (u == n)
    {
        ans = k;
        return;
    }

    for (int i = 0; i < k; i++)
        if (sum[i] + w[u] <= m)
        {
            sum[i] += w[u];
            dfs(u + 1, k);
            sum[i] -= w[u];
        }

    sum[k] = w[u];
    dfs(u + 1, k + 1);
    sum[k] = 0;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> w[i];

    sort(w, w + n);
    reverse(w, w + n);

    dfs(0, 0);

    cout << ans << endl;
}