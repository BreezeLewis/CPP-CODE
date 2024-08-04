#include <iostream>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 1010;

int n, h[N][N];
bool st[N][N];
PII q[N * N];

void bfs(int sx, int sy, bool& is_higher, bool& is_lower)
{
    int hh = 0, tt = 0;
    q[0] = { sx, sy };
    st[sx][sy] = true;

    while (hh <= tt)
    {
        PII t = q[hh++];

        for (int i = t.x - 1; i <= t.x + 1; i++)
            for (int j = t.y - 1; j <= t.y + 1; j++)
            {
                if (i < 1 || i > n || j < 1 || j > n) continue;
                if (h[i][j] != h[t.x][t.y])
                {
                    if (h[i][j] > h[t.x][t.y]) is_higher = true;
                    else is_lower = true;
                }
                else if (!st[i][j])
                {
                    st[i][j] = true;
                    q[++tt] = { i, j };
                }
            }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> h[i][j];

    int peak = 0, valley = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (!st[i][j])
            {
                bool is_higher = false, is_lower = false;

                bfs(i, j, is_higher, is_lower);
                if (!is_higher) peak++;
                if (!is_lower) valley++;
            }

    cout << peak << ' ' << valley << endl;

    return 0;
}