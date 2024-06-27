#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100010;

int n, f[N][2];

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        memset(f, 0, sizeof f);
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int w;
            cin >> w;
            f[i][0] = max(f[i - 1][0], f[i - 1][1]);
            f[i][1] = f[i - 1][0] + w;
        }

        cout << max(f[n][0], f[n][1]) << endl;
    }

    return 0;
}