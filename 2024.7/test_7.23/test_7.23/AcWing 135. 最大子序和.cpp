#include <iostream>
#include <algorithm>

using namespace std;

const int N = 300010;

int s[N], q[N];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> s[i], s[i] += s[i - 1];
    int res = s[1];//s[1];
    int hh = 0, tt = 0;

    for (int i = 1; i <= n; i++)
    {
        if (q[hh] < i - m) hh++;
        res = max(res, s[i] - s[q[hh]]);
        while (hh <= tt && s[q[tt]] >= s[i]) tt--;
        q[++tt] = i;
    }

    cout << res;

    return 0;
}