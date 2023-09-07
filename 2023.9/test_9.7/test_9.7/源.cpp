#include <iostream>

using namespace std;

const int N = (int)1e6 + 10;

int n, q[N];

void quick_sort(int q[], int l, int r)
{
    if (l >= r)
        return;

    int x = q[(l + r) >> 1], i = l - 1, j = r + 1;

    while (i < j)
    {
        while (q[++i] < x);
        while (q[--j] > x);

        if (i < j)
            swap(q[i], q[j]);
    }

    printf("%d %d\n", i, j);
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> q[i];

    quick_sort(q, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << q[i] << " ";

    return 0;
}