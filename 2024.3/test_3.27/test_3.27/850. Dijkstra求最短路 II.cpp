#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
//#include <vector>

using namespace std;

typedef pair<int, int> PII;

const int N = 150010;

int n, m;
int h[N], e[N], ne[N], w[N], idx;
int dist[N];
bool vis[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({ 0, 1 });

    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();
        int num = t.second, distance = t.first;

        if (vis[num]) continue;
        vis[num] = true;
        for (int i = h[num]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > distance + w[i])
            {
                dist[j] = distance + w[i];
                heap.push({ dist[j], j });
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main()
{
    memset(h, -1, sizeof h);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    cout << dijkstra() << endl;

    return 0;
}