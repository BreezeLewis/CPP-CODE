#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 55, mod = 1e9 + 7;
int n, m;
int f[N][N];
int ne[N];
char str[N];

int main()
{
    cin >> n >> str + 1;
    m = strlen(str + 1);

    for (int i = 2, j = 0; i <= m; i++)
    {
        while (j && str[i] != str[j + 1]) j = ne[j];
        if (str[i] == str[j + 1]) j++;
        ne[i] = j;
    }

    f[0][0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (char k = 'a'; k <= 'z'; k++)
            {
                int u = j;
                while (u && str[u + 1] != k) u = ne[u];
                if (str[u + 1] == k) u++;
                if (u < m) f[i + 1][u] = (f[i + 1][u] + f[i][j]) % mod;
            }

    int res = 0;
    for (int i = 0; i < m; i++) res = (res + f[n][i]) % mod;
    cout << res;

    return 0;
}