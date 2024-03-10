#include <iostream>
#include <algorithm>

using namespace std;

int n;
const int N = 100010, M = 3000000;
int a[N], son[M][2], idx;

void insert(int x)
{
    int p = 0;
    for (int i = 30; ~i; i--)
    {
        int u = x >> i & 1;
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
}

int query(int x)
{
    int p = 0, res = 0;
    for (int i = 30; ~i; i--)
    {
        int u = x >> i & 1;
        if (son[p][!u])
        {
            res += 1 << i;
            p = son[p][!u];
        }
        else
            p = son[p][u];
    }
    return res;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        insert(a[i]);
    }

    int res = 0;

    for (int i = 0; i < n; i++) res = max(res, query(a[i]));

    cout << res << endl;
}