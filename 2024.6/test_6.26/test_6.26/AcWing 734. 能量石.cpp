#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10010;

int n, f[N];
struct Stone
{
    int s, e, l;
    bool operator<(const Stone& W)const
    {
        return s * W.l < W.s * l;
    }
}stone[N];

int main()
{
    int T;
    cin >> T;
    for (int C = 1; C <= T; C++)
    {
        cin >> n;
        int m = 0;
        for (int i = 0; i < n; i++)
        {
            int s, e, l;
            cin >> s >> e >> l;
            stone[i] = { s, e, l };
            m += s;
        }

        sort(stone, stone + n);

        memset(f, 0, sizeof f);
        for (int i = 0; i < n; i++)
        {
            int s = stone[i].s, e = stone[i].e, l = stone[i].l;
            for (int j = m; j >= s; j--)
                f[j] = max(f[j], f[j - s] + e - (j - s) * l);
        }

        int res = 0;
        for (int i = 0; i <= m; i++) res = max(res, f[i]);
        printf("Case #%d: %d\n", C, res);
    }
    return 0;
}