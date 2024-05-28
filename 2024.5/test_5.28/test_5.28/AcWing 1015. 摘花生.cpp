#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

int t;
int w[N][N], f[N][N];

int main()
{
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
                cin >> w[i][j];

        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
                f[i][j] = max(f[i - 1][j], f[i][j - 1]) + w[i][j];

        cout << f[r][c] << endl;
    }

    return 0;
}