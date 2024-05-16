/*
f[i][j]表示1~i中选，总和为j的方法数
看成完全背包问题，每个数可以选无数次，i可以选0~s个
f[i][j] = f[i - 1][j] + f[i - 1][j - i] + ... + f[i - 1][j - s * j]
f[i][j - i] =           f[i - 1][j - i] + ... + f[i - 1][j - s * j]
f[i][j] = f[i - 1][j] + f[i][j - i]
最后结果f[n][n]
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010, mod = 1e9 + 7;

int n, f[N];

int main()
{
    cin >> n;
    f[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            f[j] = (f[j] + f[j - i]) % mod;

    cout << f[n] << endl;

    return 0;
}