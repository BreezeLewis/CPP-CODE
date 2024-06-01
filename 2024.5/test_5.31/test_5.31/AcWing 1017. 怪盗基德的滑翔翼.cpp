#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

int k, n;
int h[N], f[N];

int main()
{
    cin >> k;
    while (k--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> h[i];
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            f[i] = 1;
            for (int j = 1; j < i; j++)
                if (h[j] > h[i])
                    f[i] = max(f[i], f[j] + 1);
            res = max(res, f[i]);
        }

        for (int i = 1; i <= n; i++)
        {
            f[i] = 1;
            for (int j = 1; j < i; j++)
                if (h[j] < h[i])
                    f[i] = max(f[i], f[j] + 1);
            res = max(res, f[i]);
        }

        cout << res << endl;
    }

    return 0;
}
