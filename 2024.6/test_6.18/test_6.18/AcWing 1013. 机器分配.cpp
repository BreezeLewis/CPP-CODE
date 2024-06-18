/*f[i][j] = */
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 15, M = 20;
int n, m;
int f[N][M], w[N][M];
int way[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> w[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int k = 0; k <= j; k++)
                f[i][j] = max(f[i][j], f[i - 1][j - k] + w[i][k]);

    cout << f[n][m] << endl;

    int j = m;
    for (int i = n; i; i--)
        for (int k = 0; k <= j; k++)
            if (f[i][j] == f[i - 1][j - k] + w[i][k])
            {
                j -= k;
                way[i] = k;
                break;
            }

    for (int i = 1; i <= n; i++) cout << i << ' ' << way[i] << endl;

    return 0;
}s