#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
int f[N][3];
int w[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> w[i];
    f[0][0] = f[0][1] = -0x3f3f3f3f, f[0][2] = 0;
    for (int i = 1; i <= n; i++)
    {
        f[i][0] = max(f[i - 1][0], f[i - 1][2] - w[i]);
        f[i][1] = f[i - 1][0] + w[i];
        f[i][2] = max(f[i - 1][2], f[i - 1][1]);
    }

    cout << max(f[n][1], f[n][2]);

    return 0;
}