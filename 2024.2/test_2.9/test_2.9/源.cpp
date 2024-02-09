#include <iostream>

using namespace std;

const int N = (int)1e5 + 10;

int a[N], s[N];

int main()
{
    int n, m;

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];

    int l, r;

    while (m--)
    {
        cin >> l >> r;
        cout << s[r] - s[l - 1] << endl;
    }

    return 0;
}