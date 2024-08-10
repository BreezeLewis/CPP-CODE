#include <iostream>
#include <cstring>
#include <deque>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 510, M = N * N;

int n, m;
char g[N][N];
int dist[N][N];
bool st[N][N];

int bfs()
{
    memset(st, 0, sizeof st);
    memset(dist, 0x3f, sizeof dist);

    deque<PII> q;
    q.push_front({ 0, 0 });
    dist[0][0] = 0;

    char cs[] = "\\/\\/";
    int dx[] = { -1, -1, 1, 1 }, dy[] = { -1, 1, 1, -1 };
    int ix[] = { -1, -1, 0, 0 }, iy[] = { -1, 0, 0, -1 };

    while (q.size())
    {
        PII t = q.front();
        q.pop_front();

        int x = t.x, y = t.y;
        if (st[x][y]) continue;
        st[x][y] = true;
        for (int i = 0; i < 4; i++)
        {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a > n || b < 0 || b > m) continue;

            int ga = x + ix[i], gb = y + iy[i];
            int m = (g[ga][gb] != cs[i]);

            int d = dist[x][y] + m;
            if (d < dist[a][b])
            {
                dist[a][b] = d;

                if (m) q.push_back({ a, b });
                else q.push_front({ a, b });
            }
        }
    }
    return dist[n][m];
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++) cin >> g[i];

        if (n + m & 1) puts("NO SOLUTION");
        else cout << bfs() << endl;
    }

    return 0;
}

