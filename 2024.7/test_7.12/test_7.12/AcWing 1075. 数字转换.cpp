#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 50010;

int n;
int h[N], e[N], ne[N], idx;
int sum[N];
bool st[N];
int ans;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u)
{
    st[u] = true;

    int dist = 0;
    int d1 = 0, d2 = 0;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (!st[j])
        {
            int d = dfs(j);
            dist = max(dist, d);
            if (d >= d1) d2 = d1, d1 = d;
            else if (d > d2) d2 = d;
        }
    }

    ans = max(ans, d1 + d2);

    return dist + 1;
}

int main()
{
    cin >> n;
    memset(h, -1, sizeof h);

    for (int i = 1; i <= n; i++)
        for (int j = 2; j <= n / i; j++)
            sum[i * j] += i;

    for (int i = 1; i <= n; i++)
        if (sum[i] < i)
            add(sum[i], i);

    for (int i = 1; i <= n; i++)
        if (!st[i])
            dfs(i);

    cout << ans;

    return 0;
}