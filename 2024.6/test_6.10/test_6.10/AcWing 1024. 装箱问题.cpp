#include <iostream>
#include <algorithm>

using namespace std;

const int N = 20010;

int n, m, f[N];

int main()
{
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        for (int j = m; j >= v; j--)
            f[j] = max(f[j], f[j - v] + v);
    }

    cout << m - f[m] << endl;
}