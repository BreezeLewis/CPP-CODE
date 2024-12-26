#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

const int N = (int)2e5 + 10;
int n, m;
char s[N];

struct Node {
    int s, res;
    int lmax, rmin;
    int mv, lv, rv;
} tr[N * 4];

void pushup(int u) {
    tr[u].s = tr[u << 1].s + tr[u << 1 | 1].s;
    tr[u].lmax = max(tr[u << 1].lmax, tr[u << 1].s + tr[u << 1 | 1].lmax);
    tr[u].rmin = min(tr[u << 1 | 1].rmin, tr[u << 1 | 1].s + tr[u << 1].rmin);
    tr[u].mv = max(tr[u << 1].mv + tr[u << 1 | 1].s, tr[u << 1 | 1].mv - tr[u << 1].s);
    tr[u].lv = max(tr[u << 1].lv, max(tr[u << 1 | 1].lv - tr[u << 1].s, tr[u << 1].mv + tr[u << 1 | 1].lmax));
    tr[u].rv = max(tr[u << 1 | 1].rv, max(tr[u << 1].rv + tr[u << 1 | 1].s, tr[u << 1 | 1].mv - tr[u << 1].rmin));
    tr[u].res = max(max(tr[u << 1].res, tr[u << 1 | 1].res),
        max(tr[u << 1 | 1].lv - tr[u << 1].rmin, tr[u << 1].rv + tr[u << 1 | 1].lmax));
}

void change(int u, int l, int r, int x) {
    if (l == r) {
        tr[u].s = (s[x] == '(' ? 1 : -1);
        tr[u].mv = tr[u].lv = tr[u].rv = tr[u].res = 1;
        tr[u].rmin = min(0, tr[u].s), tr[u].lmax = max(0, tr[u].s);
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) change(u << 1, l, mid, x);
    else change(u << 1 | 1, mid + 1, r, x);
    pushup(u);
}

void Swap(char& x, char& y) { char z = x; x = y; y = z; }

int main() {
    scanf("%d%d%s", &n, &m, s + 1);
    n = (n - 1) * 2;
    for (int i = 1; i <= n; i++) change(1, 1, n, i);
    printf("%d\n", tr[1].res);
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (s[a] != s[b]) Swap(s[a], s[b]), change(1, 1, n, a), change(1, 1, n, b);
        printf("%d\n", tr[1].res);
    }
    return 0;
}
