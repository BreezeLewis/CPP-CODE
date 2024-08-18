#include <iostream>

using namespace std;

const int N = 11;

int n, p[N];
int group[N][N];
bool st[N];
int ans = N;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

bool check(int group[], int gc, int i)
{
    for (int j = 0; j < gc; j++)
        if (gcd(p[group[j]], p[i]) > 1)
            return false;
    return true;
}

void dfs(int g, int gc, int tc, int start)
{
    if (g >= ans) return;
    if (tc == n) ans = g;

    bool flag = true;
    for (int i = start; i < n; i++)
        if (!st[i] && check(group[g], gc, i))
        {
            st[i] = true;
            group[g][gc] = i;
            dfs(g, gc + 1, tc + 1, i + 1);
            st[i] = false;

            flag = false;
        }
    if (flag) dfs(g + 1, 0, tc, 0);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> p[i];

    dfs(1, 0, 0, 0);

    cout << ans << endl;

    return 0;
}