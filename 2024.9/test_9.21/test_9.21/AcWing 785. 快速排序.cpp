#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

const int N = (int)1e6 + 10;

int n;
int q[N];

void quick_sort(int q[], int l, int r)
{
    if (l >= r) return;

    int x = q[(l + r) >> 1], i = l - 1, j = r + 1;

    while (i < j)
    {
        while (q[++i] < x);
        while (q[--j] > x);

        if (i < j) swap(q[i], q[j]);
    }

    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d", &q[i]);

    quick_sort(q, 0, n - 1);

    for (int i = 0; i < n; i++) printf("%d ", q[i]);

    return 0;
}