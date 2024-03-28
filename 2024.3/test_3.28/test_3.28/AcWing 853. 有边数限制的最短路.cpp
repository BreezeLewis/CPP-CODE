#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m, k;
const int N = 510, M = 10010;

int dist[N], backup[N];

struct Edge
{
    int a, b, w;
}edge[M];

void bellman_ford()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for (int i = 0; i < k; i++)
    {
        memcpy(backup, dist, sizeof dist);

        for (int j = 0; j < m; j++)
        {
            int a = edge[j].a, b = edge[j].b, w = edge[j].w;
            dist[b] = min(dist[b], backup[a] + w);
        }
    }

}

int main()
{
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++)
        cin >> edge[i].a >> edge[i].b >> edge[i].w;

    bellman_ford();

    if (dist[n] > 0x3f3f3f3f / 2) puts("impossible");
    else cout << dist[n] << endl;

    return 0;
}







