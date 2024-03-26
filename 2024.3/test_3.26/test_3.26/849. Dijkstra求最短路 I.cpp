#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510;

int g[N][N];
int dist[N];
int n, m;
bool vis[N];//是否已经确定从1到该点的距离

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!vis[j] && (t == -1 || dist[j] < dist[t]))
                t = j;

        vis[t] = true;

        for (int j = 1; j <= n; j++)
            dist[j] = min(dist[j], dist[t] + g[t][j]);
    }

    if (dist[n] == 0x3f3f3f3f) return -1;//1~n不联通
    return dist[n];
}

int main()
{
    memset(g, 0x3f, sizeof g);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
    }

    cout << dijkstra() << endl;

    return 0;
}