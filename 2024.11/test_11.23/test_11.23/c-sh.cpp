#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int root, sizes, ans1, ans2;
struct data
{
    int l, r, v, rnd, id, w;
}tr[110000];
void rturn(int& k)
{
    int t = tr[k].l; tr[k].l = tr[t].r; tr[t].r = k;
    k = t;
}
void lturn(int& k)
{
    int t = tr[k].r; tr[k].r = tr[t].l; tr[t].l = k;
    k = t;
}
void insert(int& k, int x, int id)
{
    if (k == 0)
    {
        sizes++; k = sizes;
        tr[k].rnd = rand(); tr[k].v = x; tr[k].id = id;
        return;
    }
    if (x > tr[k].v)
    {
        insert(tr[k].r, x, id);
        if (tr[tr[k].r].rnd < tr[k].rnd) lturn(k);
    }
    else
    {
        insert(tr[k].l, x, id);
        if (tr[tr[k].l].rnd < tr[k].rnd) rturn(k);
    }
}
void query_pro(int k, int x)
{
    if (k == 0) return;
    if (tr[k].v < x)
    {
        ans1 = k; query_pro(tr[k].r, x);
    }
    else
        query_pro(tr[k].l, x);
}
void query_sub(int k, int x)
{
    if (k == 0) return;
    if (tr[k].v > x)
    {
        ans2 = k; query_sub(tr[k].l, x);
    }
    else query_sub(tr[k].r, x);
}
int cal(int x, int y)
{
    return x > y ? x - y : y - x;
}
int main()
{
    int n;
    while (~scanf("%d", &n) && n)
    {
        int k, g;
        sizes = 0, root = 0;
        for (int i = 0; i < 110000; i++)//³õÊ¼»¯
        {
            tr[i].l = 0;
            tr[i].r = 0;
        }
        insert(root, 1000000000, 1);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d", &k, &g);
            insert(root, g, k);
            ans1 = 0, ans2 = 0;
            query_pro(root, g); query_sub(root, g);
            if (ans1 == 0) printf("%d %d\n", k, tr[ans2].id);
            else
            {
                if (g - tr[ans1].v > tr[ans2].v - g)
                    printf("%d %d\n", k, tr[ans2].id);
                else printf("%d %d\n", k, tr[ans1].id);
            }
        }
    }
    return 0;
}