#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
const int N = 100010;
int h[N], e[N], ne[N], idx;
int d[N], q[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void toposort()
{
    int hh = 0, tt = -1;
    for (int i = 1; i <= n; i++)
        if (d[i] == 0)
            q[++tt] = i;

    while (hh <= tt)
    {
        int a = q[hh++];
        for (int i = h[a]; i != -1; i = ne[i])
        {
            int b = e[i];
            d[b]--;
            if (d[b] == 0)
                q[++tt] = b;
        }
    }

    if (tt == n - 1)
        for (int i = 0; i < n; i++)
            cout << q[i] << " ";
    else
        cout << -1;

}

int main()
{
    cin >> n >> m;

    memset(h, -1, sizeof h);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b]++;
    }

    toposort();

    return 0;
}