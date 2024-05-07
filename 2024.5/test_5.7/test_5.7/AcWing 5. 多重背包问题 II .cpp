#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Good
{
    int v, w;
};

int n, m;
const int N = 2010;

int f[N];

int main()
{
    cin >> n >> m;
    vector<Good> goods;

    for (int i = 0; i < n; i++)
    {
        int v, w, s;
        cin >> v >> w >> s;
        for (int k = 1; k <= s; k <<= 1)
        {
            s -= k;
            goods.push_back({ k * v, k * w });
        }

        if (s) goods.push_back({ s * v, s * w });
    }

    for (auto good : goods)
        for (int j = m; j >= good.v; j--)
            f[j] = max(f[j], f[j - good.v] + good.w);

    cout << f[m] << endl;

    return 0;
}