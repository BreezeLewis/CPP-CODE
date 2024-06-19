#include <iostream>
#include <algorithm>
#include <vector>

#define v first
#define w second

using namespace std;

typedef pair<int, int> PII;

const int N = 60, M = 32010;

int n, m;
PII master[N];
vector<PII> servant[N];
int f[M];

int main()
{
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        int v, p, q;
        cin >> v >> p >> q;
        if (q == 0) master[i] = { v, v * p };
        else servant[q].push_back({ v, v * p });
    }

    for (int i = 1; i <= n; i++)
        for (int u = m; u >= 0; u--)
            for (int j = 0; j < 1 << servant[i].size(); j++)
            {
                int v = master[i].v, w = master[i].w;
                for (int k = 0; k < servant[i].size(); k++)
                    if (j >> k & 1)
                        v += servant[i][k].v, w += servant[i][k].w;
                if (u >= v) f[u] = max(f[u], f[u - v] + w);
            }

    cout << f[m] << endl;

    return 0;
}