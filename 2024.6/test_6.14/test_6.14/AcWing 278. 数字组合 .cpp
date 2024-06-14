#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10010;

int n, m;
int f[N];

int main()
{
    cin >> n >> m;
    f[0] = 1;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        for (int j = m; j >= x; j--)
            f[j] += f[j - x];
    }

    cout << f[m] << endl;

    return 0;
}