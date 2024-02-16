#include<iostream>
using namespace std;

const int N = 1010;

int n, m;
int f[N][N], v[N], w[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (v[i] <= j)
                f[i][j] = max(f[i - 1][j], f[i][j - v[i]] + w[i]);
            else
                f[i][j] = f[i - 1][j];
        }
    }
    cout << f[n][m] << endl;
}
