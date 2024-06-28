#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 100010, M = 110;

int n, k;
int f[N][M][2];//前i天进行了j笔交易，此时手中有股票还是没股票的最大利润
int w[N];

int main()
{
    cin >> n >> k;

    memset(f, -0x3f, sizeof f);
    for (int i = 0; i <= n; i++) f[i][0][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
        for (int j = 1; j <= k; j++)
        {
            //f[i][j][0] = max(f[i - 1][j - 1][1] + w[i], f[i - 1][j][0]);
            //f[i][j][1] = max(f[i - 1][j][0] - w[i], f[i - 1][j][1]);
            f[i][j][0] = max(f[i - 1][j][1] + w[i], f[i - 1][j][0]);
            f[i][j][1] = max(f[i - 1][j - 1][0] - w[i], f[i - 1][j][1]);
        }
    }

    int res = 0;
    for (int i = 1; i <= k; i++) res = max(res, f[n][i][0]);

    cout << res;

    return 0;
}