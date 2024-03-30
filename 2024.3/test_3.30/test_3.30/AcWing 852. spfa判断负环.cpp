#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 2010, M = 10010;

int n, m;
int h[N], e[M], ne[M], w[M], idx;
bool vis[N];
int dist[N], cnt[N];//cnt[x]表示 当前1-x的最短路边数

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool spfa()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
        q.push(i), vis[i] = true;

    while (q.size())
    {
        int t = q.front();
        q.pop();
        vis[t] = false;

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n)
                    return true;

                if (!vis[j])
                    q.push(j), vis[j] = true;
            }
        }
    }

    return false;
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    if (spfa()) puts("Yes");
    else puts("No");

    return 0;
}


