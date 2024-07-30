#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 300010;

LL f[N], t[N], c[N];
int n, s, q[N];

int main()
{
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i] >> c[i];
        t[i] += t[i - 1];
        c[i] += c[i - 1];
    }

    int hh = 0, tt = 0;
    q[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        while (hh < tt && f[q[hh + 1]] - f[q[hh]] <= (t[i] + s) * (c[q[hh + 1]] - c[q[hh]])) hh++;

        int j = q[hh];
        f[i] = f[j] - (t[i] + s) * c[j] + t[i] * c[i] + s * c[n];

        while (hh < tt && (f[q[tt]] - f[q[tt - 1]]) * (c[i] - c[q[tt - 1]]) >= (f[i] - f[q[tt - 1]]) * (c[q[tt]] - c[q[tt - 1]])) tt--;

        q[++tt] = i;
    }

    cout << f[n] << endl;

    return 0;
}