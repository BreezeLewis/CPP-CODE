#include <iostream>

using namespace std;

const int MAXN = 1005;
int v[MAXN];    // ���
int w[MAXN];    // ��ֵ 
int f[MAXN][MAXN];  // f[i][j], j�����ǰi����Ʒ������ֵ 

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            //  ��ǰ��������װ������i����Ʒ�����ֵ����ǰi-1����Ʒ
            if (j < v[i])
                f[i][j] = f[i - 1][j];
            // ��װ������о����Ƿ�ѡ���i����Ʒ
            else
                f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i]);
        }

    cout << f[n][m] << endl;

    return 0;
}