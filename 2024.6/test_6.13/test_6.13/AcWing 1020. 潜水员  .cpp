#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100;
int f[N][N];
int V1, V2;
int n;

int main()
{
    cin >> V1 >> V2 >> n;
    memset(f, 0x3f, sizeof f);
    f[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        for (int j = V1; j >= 0; j--)
            for (int k = V2; k >= 0; k--)
                f[j][k] = min(f[j][k], f[max(0, j - v1)][max(0, k - v2)] + w);
    }

    cout << f[V1][V2] << endl;

    return 0;
}