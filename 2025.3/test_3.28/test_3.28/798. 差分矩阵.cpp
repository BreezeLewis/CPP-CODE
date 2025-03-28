#include <iostream>

using namespace std;

const int N = (int)1e3 + 10;

int a[N][N], s[N][N];

int main()
{
    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> s[i][j], a[i][j] = s[i][j] - s[i - 1][j] - s[i][j - 1] + s[i - 1][j - 1];
    // s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];

    while (q--)
    {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        a[x1][y1] += c, a[x2 + 1][y1] -= c, a[x1][y2 + 1] -= c, a[x2 + 1][y2 + 1] += c;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j], cout << s[i][j] << ' ';
        cout << endl;
    }

    return 0;
}