/*
״̬��ʾf[i][j]��i��ʾ�Ѿ��߹��ĵ�,��2^n��״̬��j��ʾ��ǰ�ڵĵ�
f[i][j] = min(f[i][j], f[i - (1 << j)][k] + weight[k][j])
���f[(1 << n) - 1][n - 1]��ʾ�߹�n - 1���㣬��ǰ�ڵ�n��������·��
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

    f[1][0] = 0;//�߹���һ�������ڵ�һ���㣬���·��Ϊ0

    for (int i = 0; i < 1 << n; i++)
        for (int j = 0; j < n; j++)
            if (i >> j & 1)
                for (int k = 0; k < n; k++)
                    if (i >> k & 1)
                        f[i][j] = min(f[i][j], f[i - (1 << j)][k] + w[k][j]);

    cout << f[(1 << n) - 1][n - 1];

    return 0;
}