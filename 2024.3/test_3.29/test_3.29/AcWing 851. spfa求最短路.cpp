#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int n, m;
const int N = 100010;
int h[N], e[N], ne[N], idx;
bool vis[N];
int dist[N], w[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void spfa()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    queue<int> q;
    q.push(1);
    vis[1] = true;

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
                if (!vis[j])
                {
                    q.push(j);
                    vis[j] = true;
                }
            }
        }
    }
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

    spfa();
    if (dist[n] == 0x3f3f3f3f) puts("impossible");
    else cout << dist[n] << endl;

    return 0;
}



