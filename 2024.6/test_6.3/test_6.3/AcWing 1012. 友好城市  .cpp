#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 5010;

int n, f[N];
PII q[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> q[i].first >> q[i].second;

    sort(q + 1, q + n + 1);

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        f[i] = 1;
        for (int j = 1; j < i; j++)
            if (q[j].second < q[i].second)
                f[i] = max(f[i], f[j] + 1);

        res = max(res, f[i]);
    }

    cout << res;

    return 0;
}