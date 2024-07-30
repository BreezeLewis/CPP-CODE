#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;

const int N = 5010;

LL f[N], sumC[N], sumT[N];
int n, s;

int main()
{
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        int t, c;
        cin >> t >> c;
        sumT[i] = sumT[i - 1] + t;
        sumC[i] = sumC[i - 1] + c;
    }

    memset(f, 0x3f, sizeof f);

    f[0] = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 0; j < i; j++)
            f[i] = min(f[i], f[j] + sumT[i] * (sumC[i] - sumC[j]) + s * (sumC[n] - sumC[j]));

    cout << f[n] << endl;

    return 0;
}