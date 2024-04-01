#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n, m;
int g[N][N];
int dist[N];
bool vis[N];

int prim()
{
    memset(dist, 0x3f, sizeof dist);

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!vis[j] && (t == -1 || dist[t] > dist[j]))
                t = j;//用t找到不在集合内最短的边

        if (i && dist[t] == INF) return INF;
        if (i) res += dist[t];

        for (int j = 1; j <= n; j++) dist[j] = min(dist[j], g[t][j]);

        vis[t] = true;
    }

    return res;
}

int main()
{
    memset(g, 0x3f, sizeof g);

    cin >> n >> m;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }

    int t = prim();
    if (t == INF) puts("impossible");
    else cout << t << endl;

    return 0;
}




