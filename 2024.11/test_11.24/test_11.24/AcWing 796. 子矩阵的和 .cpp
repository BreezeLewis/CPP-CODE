#include <iostream>

using namespace std;

const int N = 1010;

int a[N][N];

int main()
{
    int n, m, k;

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    for (int i = 1; i <= n; i++) a[i][1] += a[i - 1][1];
    for (int i = 1; i <= m; i++) a[1][i] += a[1][i - 1];

    for (int i = 2; i <= n; i++)
        for (int j = 2; j <= m; j++)
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];

    while (k--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        cout << a[x2][y2] - a[x2][y1 - 1] - a[x1 - 1][y2] + a[x1 - 1][y1 - 1] << endl;
    }

    return 0;
}