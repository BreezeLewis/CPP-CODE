/*
状态表示f[i][j]，i表示已经走过的点,共2^n个状态，j表示当前在的点
f[i][j] = min(f[i][j], f[i - (1 << j)][k] + weight[k][j])
结果f[(1 << n) - 1][n - 1]表示走过n - 1个点，当前在第n个点的最短路径
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 20, M = 1 << N;
int w[N][N];
int f[M][N];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> w[i][j];

    memset(f, 0x3f, sizeof f);

    f[1][0] = 0;//走过第一个点且在第一个点，最短路径为0

    for (int i = 0; i < 1 << n; i++)
        for (int j = 0; j < n; j++)
            if (i >> j & 1)
                for (int k = 0; k < n; k++)
                    if (i >> k & 1)
                        f[i][j] = min(f[i][j], f[i - (1 << j)][k] + w[k][j]);

    cout << f[(1 << n) - 1][n - 1];

    return 0;
}