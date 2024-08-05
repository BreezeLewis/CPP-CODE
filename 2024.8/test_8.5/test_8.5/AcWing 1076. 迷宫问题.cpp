#include <iostream>
#include <cstring>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 1010, M = N * N;

int n, g[N][N];
PII pre[N][N];
PII q[M];

int dx[] = { 0,0,1,-1 }, dy[] = { 1,-1,0,0 };

void bfs(int sx, int sy)
{
    int hh = 0, tt = 0;
    q[0] = { sx, sy };
    pre[sx][sx] = { 0, 0 };

    while (hh <= tt)
    {
        PII t = q[hh++];

        for (int i = 0; i < 4; i++)
        {
            int a = t.x + dx[i], b = t.y + dy[i];
            if (a < 0 || a >= n || b < 0 || b >= n) continue;
            if (g[a][b]) continue;
            if (pre[a][b].x != -1) continue;

            q[++tt] = { a, b };
            pre[a][b] = t;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];

    memset(pre, -1, sizeof pre);

    bfs(n - 1, n - 1);

    PII end(0, 0);

    while (true)
    {
        cout << end.x << ' ' << end.y << endl;
        if (end.x == n - 1 && end.y == n - 1) break;
        end = pre[end.x][end.y];
    }

    return 0;
}