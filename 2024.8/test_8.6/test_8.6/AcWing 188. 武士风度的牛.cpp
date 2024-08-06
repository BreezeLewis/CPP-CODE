#include <iostream>
#include <cstring>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 160, M = N * N;

char g[N][N];
int n, m;
PII q[M];
int dist[N][N];

int dx[] = { 1, 1, 2, 2, -1, -1, -2, -2 }, dy[] = { 2, -2, 1, -1, 2, -2, 1, -1, };

int bfs(int sx, int sy)
{
    int hh = 0, tt = 0;
    q[0] = { sx, sy };

    memset(dist, -1, sizeof dist);
    dist[sx][sy] = 0;

    while (hh <= tt)
    {
        PII t = q[hh++];

        for (int i = 0; i < 8; i++)
        {
            int a = t.x + dx[i], b = t.y + dy[i];
            if (a < 0 || a >= n || b < 0 || b >= m) continue;
            if (g[a][b] == '*') continue;
            if (dist[a][b] != -1) continue;
            if (g[a][b] == 'H') return dist[t.x][t.y] + 1;

            dist[a][b] = dist[t.x][t.y] + 1;
            q[++tt] = { a, b };
        }
    }

    return -1;
}

int main()
{
    cin >> m >> n;

    for (int i = 0; i < n; i++) cin >> g[i];

    PII start;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (g[i][j] == 'K')
                start = { i, j };

    int res = bfs(start.x, start.y);

    cout << res;

    return 0;
}