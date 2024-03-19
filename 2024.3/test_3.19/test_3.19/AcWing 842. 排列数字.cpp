#include <iostream>

using namespace std;

const int N = 10;
int n;
int a[N];
bool vis[N];

void dfs(int u)
{
    if (u == n)
    {
        for (int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i])
        {
            vis[i] = true;
            a[u] = i;
            dfs(u + 1);
            vis[i] = false;
        }
}

int main()
{
    cin >> n;

    dfs(0);

    return 0;
}