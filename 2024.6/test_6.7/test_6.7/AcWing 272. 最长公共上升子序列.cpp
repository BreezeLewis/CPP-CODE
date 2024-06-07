#include <iostream>
#include <algorithm>

using namespace std;

const int N = 3010;

int n, a[N], b[N], f[N][N];//a序列从1~i，b序列从1~j，以b[j]为结尾的所有公共上升子序列的最大值

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    for (int i = 1; i <= n; i++)
    {
        int maxv = 1;
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = f[i - 1][j];
            if (a[i] == b[j]) f[i][j] = max(f[i][j], maxv);
            if (b[j] < a[i]) maxv = max(maxv, f[i - 1][j] + 1);
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++) res = max(res, f[n][i]);

    cout << res;

    return 0;
}