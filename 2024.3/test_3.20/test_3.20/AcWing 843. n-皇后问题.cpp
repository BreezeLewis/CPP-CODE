#include <iostream>

using namespace std;

const int N = 10;
int n;
char g[N][N];
bool col[N], dg[N], udg[N];

void dfs(int u)
{
    if (u == n)
    {
        for (int i = 0; i < n; i++) puts(g[i]);
        puts("");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!col[i] && !dg[u + i] && !udg[u - i + n])
        {
            col[i] = dg[u + i] = udg[u - i + n] = true;
            g[u][i] = 'Q';
            dfs(u + 1);
            col[i] = dg[u + i] = udg[u - i + n] = false;
            g[u][i] = '.';
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = '.';

    dfs(0);

    return 0;
}

