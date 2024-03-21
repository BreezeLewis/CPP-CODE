#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
const int N = 110;

int g[N][N], d[N][N];
typedef pair<int, int> PII;
PII q[N * N];

int dfs()
{//0,1 1,0 -1,0 0,-1
    int hh = 0, tt = 0;
    q[0] = { 0, 0 };
    int dx[4] = { 0, 1, -1, 0 }, dy[4] = { 1, 0, 0, -1 };

    memset(d, -1, sizeof d);
    d[0][0] = 0;

    while (hh <= tt)
    {
        auto t = q[hh++];
        for (int i = 0; i < 4; i++)
        {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)
            {
                d[x][y] = d[t.first][t.second] + 1;
                q[++tt] = { x, y };
            }
        }
    }

    return d[n - 1][m - 1];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];

    cout << dfs() << endl;

    return 0;
}