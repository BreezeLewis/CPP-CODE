/*
f[i][j]��ʾ1~i��ѡ���ܺ�Ϊj�ķ�����
������ȫ�������⣬ÿ��������ѡ�����Σ�i����ѡ0~s��
f[i][j] = f[i - 1][j] + f[i - 1][j - i] + ... + f[i - 1][j - s * j]
f[i][j - i] =           f[i - 1][j - i] + ... + f[i - 1][j - s * j]
f[i][j] = f[i - 1][j] + f[i][j - i]
�����f[n][n]
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