#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010, mod = 1e9 + 7;

int n, m;
int f[N], g[N];

int main()
{
    cin >> n >> m;
    for (int i = 0; i <= m; i++) g[i] = 1;

    for (int i = 1; i <= n; i++)
    {
        int v, w;
        cin >> v >> w;
        for (int j = m; j >= v; j--)
        {
            int value = f[j - v] + w;
            if (value > f[j])
                f[j] = value, g[j] = g[j - v];
            else if (value == f[j])
                g[j] = (g[j] + g[j - v]) % mod;
        }
    }

    cout << g[m] << endl;

    return 0;
}