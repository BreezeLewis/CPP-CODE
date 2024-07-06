#include <iostream>
#include <algorithm>

using namespace std;

const int N = 210;

int n, w[N];
int f[N][N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
        w[i + n] = w[i];
    }

    for (int len = 3; len <= n + 1; len++)
        for (int l = 1; l + len - 1 <= 2 * n; l++)
        {
            int r = l + len - 1;
            for (int k = l + 1; k < r; k++)
                f[l][r] = max(f[l][r], f[l][k] + f[k][r] + w[l] * w[k] * w[r]);
        }

    int res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, f[i][i + n]);

    cout << res;

    return 0;
}