#include <iostream>

using namespace std;

const int N = (int)1e6 + 10;

int a[N], s[N];

void insert(int l, int r, int x)
{
    a[l] += x;
    a[r + 1] -= x;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &s[i]), insert(i, i, s[i]);
    
    while (m--)
    {
        int l, r, c;
        scanf("%d%d%d", &l, &r, &c);
        insert(l, r, c);
    }
    
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i], printf("%d ", s[i]);
}