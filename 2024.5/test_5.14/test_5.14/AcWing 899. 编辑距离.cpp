#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1010, M = 15;
int n, m, x;
char a[N][M];
char b[M];
int f[M][M];

int main()
{
    cin >> n >> m;

    for (int k = 1; k <= n; k++) cin >> (a[k] + 1);

    for (int i = 0; i <= M; i++) f[0][i] = f[i][0] = i;

    while (m--)
    {
        cin >> (b + 1) >> x;
        int res = 0;
        for (int k = 1; k <= n; k++)
        {
            int u = strlen(a[k] + 1), v = strlen(b + 1);
            for (int i = 0; i <= u; i++) f[0][i] = i;
            for (int i = 0; i <= v; i++) f[i][0] = i;

            for (int i = 1; i <= u; i++)
                for (int j = 1; j <= v; j++)
                {
                    f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
                    if (a[k][i] == b[j]) f[i][j] = min(f[i][j], f[i - 1][j - 1]);
                    else f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
                }
            if (f[u][v] <= x) res++;
        }
        cout << res << endl;
    }

    return 0;
}