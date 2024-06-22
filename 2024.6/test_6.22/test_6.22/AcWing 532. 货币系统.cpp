#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 110, M = 25010;

int a[N];
bool f[M];
int n;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);

        int m = a[n - 1];
        memset(f, 0, sizeof f);
        f[0] = true;

        int k = 0;
        for (int i = 0; i < n; i++)
        {
            if (!f[a[i]]) k++;
            for (int j = a[i]; j <= m; j++)
                f[j] |= f[j - a[i]];
        }

        cout << k << endl;
    }
}