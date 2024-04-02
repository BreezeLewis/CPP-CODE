#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 200010;

int n, m, res, cnt;
int p[N];

struct Edge
{
    int a, b, w;

    bool operator <(const Edge& W)const
    {
        return w < W.w;
    }
}edges[N];

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void kruscal()
{
    for (int i = 0; i < m; i++)
    {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a), b = find(b);

        if (a != b)
        {
            p[a] = b;
            res += w;
            cnt++;
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++) p[i] = i;

    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = { a, b, w };
    }

    sort(edges, edges + m);

    kruscal();

    if (cnt < n - 1) puts("impossible");
    else cout << res << endl;

    return 0;
}