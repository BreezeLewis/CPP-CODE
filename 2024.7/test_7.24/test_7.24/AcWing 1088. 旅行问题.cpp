#include <iostream>

using namespace std;

typedef long long LL;

const int N = 2e6 + 10;

int o[N], d[N];
LL s[N];
int q[N];
bool ans[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> o[i] >> d[i];

    for (int i = 1; i <= n; i++) s[i] = s[i + n] = o[i] - d[i];

    for (int i = 1; i <= 2 * n; i++) s[i] += s[i - 1];

    int hh = 0, tt = -1;
    for (int i = 2 * n; i; i--)//顺时针的时候s[i]~s[i + n - 1]的前缀和都大于等于0，也就是s[q[hh]] >= s[i - 1]
    {
        if (q[hh] > i + n - 1) hh++;

        while (hh <= tt && s[q[tt]] >= s[i]) tt--;

        q[++tt] = i;

        if (i <= n && s[q[hh]] >= s[i - 1]) ans[i] = true;
    }

    d[0] = d[n];
    for (int i = 1; i <= n; i++) s[i] = s[i + n] = o[i] - d[i - 1];

    for (int i = 2 * n; i; i--) s[i] += s[i + 1];

    hh = 0, tt = -1;
    for (int i = 1; i <= 2 * n; i++)
    {
        if (q[hh] < i - n + 1) hh++;

        while (hh <= tt && s[q[tt]] >= s[i]) tt--;

        q[++tt] = i;

        if (i > n && s[q[hh]] >= s[i + 1]) ans[i - n] = true;
    }

    for (int i = 1; i <= n; i++)
        if (ans[i]) puts("TAK");
        else puts("NIE");

    return 0;
}