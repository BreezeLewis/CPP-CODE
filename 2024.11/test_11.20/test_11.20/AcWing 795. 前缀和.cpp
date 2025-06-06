#include <iostream>

using namespace std;

const int N = (int)1e5 + 10;

int n, m;
int a[N], s[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i - 1];

    while (m--)
    {
        int l, r;
        cin >> l >> r;
        cout << a[r] - a[l - 1] << endl;
    }

    return 0;
}