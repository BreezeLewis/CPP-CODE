#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1010;

int n, m;
int f[N];

struct Good
{
    int v, w;
};

int main()
{
    cin >> n >> m;
    vector<Good> goods;

    for (int i = 0; i < n; i++)
    {
        int v, w, s;
        cin >> v >> w >> s;
        for (int i = 0; i < s; i++)
            goods.push_back({ v, w });
    }

    for (auto good : goods)
        for (int j = m; j >= good.v; j--)
            f[j] = max(f[j], f[j - good.v] + good.w);

    cout << f[m] << endl;
}