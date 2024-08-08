#include <iostream>
#include <cstring>

using namespace std;

const int N = 100010;

int n, k;
int dist[N];
int q[N];

int bfs()
{
    int hh = 0, tt = 0;
    q[0] = n;
    dist[n] = 0;

    while (hh <= tt)
    {
        int t = q[hh++];

        if (t == k) return dist[k];

        if (t + 1 < N && dist[t + 1] == -1)
        {
            dist[t + 1] = dist[t] + 1;
            q[++tt] = t + 1;
        }
        if (t - 1 >= 0 && dist[t - 1] == -1)
        {
            dist[t - 1] = dist[t] + 1;
            q[++tt] = t - 1;
        }
        if (2 * t < N && dist[2 * t] == -1)
        {
            dist[2 * t] = dist[t] + 1;
            q[++tt] = 2 * t;
        }
    }
    return -1;
}

int main()
{
    memset(dist, -1, sizeof dist);

    cin >> n >> k;

    cout << bfs() << endl;

    return 0;
}