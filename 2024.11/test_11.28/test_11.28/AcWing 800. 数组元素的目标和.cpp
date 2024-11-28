#include <iostream>

using namespace std;

const int N = (int)1e5 + 10;

int a[N], b[N];

int n, m, x;

int main()
{
    cin >> n >> m >> x;

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    int j = m - 1;
    for (int i = 0; i < n; i++)
    {
        while (j > 0 && a[i] + b[j] > x) j--;
        if (a[i] + b[j] == x)
            cout << i << ' ' << j << endl;
    }

    return 0;
}