#include <iostream>
#include <algorithm>

using namespace std;

const int N = 30010;

int n, m, f[N];

int main()
{
    cin >> m >> n;

    for (int i = 1; i <= n; i++)
    {
        int v, p;
        cin >> v >> p;
        p *= v;
        for (int j = m; j >= v; j--)
            f[j] = max(f[j], f[j - v] + p);
    }

    cout << f[m] << endl;

    return 0;
}