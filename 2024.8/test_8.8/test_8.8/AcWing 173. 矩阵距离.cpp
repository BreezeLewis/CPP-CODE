#include <iostream>
#include <cstring>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 1010, M = N * N;

int n, m;
char g[N][N];
int dist[N][N];
PII q[M];

void bfs()
{
    int dx[] = { 0, 0, 1, -1 }, dy[] = { 1, -1, 0, 0 };

    memset(dist, -1, sizeof dist);

    int hh = 0, tt = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (g[i][j] == '1')
            {
                q[++tt] = { i, j };
                dist[i][j] = 0;
            }

    while (hh <= tt)
    {
        PII t = q[hh++];

        for (int i = 0; i < 4; i++)
        {
            int a = t.x + dx[i], b = t.y + dy[i];
            if (a < 0 || a >= n || b < 0 || b >= m) continue;
            if (dist[a][b] != -1) continue;

            dist[a][b] = dist[t.x][t.y] + 1;
            q[++tt] = { a, b };
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> g[i];

    bfs();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << dist[i][j] << ' ';
        puts("");
    }

    return 0;
}