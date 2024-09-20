#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n, m;
int g[N][N];
int dist[N];
bool st[N];

/*
×ÜÈ¨ÖØ = 4463600 + 4300123 + 4689017 + 4103953 + 4761375 = 22318068

6 8
1 3 4463600
1 2 4300123
3 5 4689017
4 6 4103953
2 4 4761375
1 4 6037864
2 5 7862913
3 6 9025613
*/

int prim()
{
    memset(dist, 0x3f, sizeof dist);

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;

        if (i && dist[t] == INF) return INF;

        if (i) res += dist[t];
        st[t] = true;

        for (int j = 1; j <= n; j++) dist[j] = min(dist[j], g[t][j]);
    }

    return res;
}


//int main()
//{
//    scanf("%d%d", &n, &m);
//
//    memset(g, 0x3f, sizeof g);
//
//    while (m--)
//    {
//        int a, b, c;
//        scanf("%d%d%d", &a, &b, &c);
//        g[a][b] = g[b][a] = min(g[a][b], c);
//    }
//
//    int t = prim();
//
//    if (t == INF) puts("impossible");
//    else printf("%d\n", t);
//
//    return 0;
//}

int main()
{
    int a;
    scanf("%d\n", &a);

    return 0;
}