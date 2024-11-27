#include <iostream>
#include <algorithm>

using namespace std;

const int N = (int)1e5 + 10;

int n, res;
int a[N], s[N];

int main()
{
    cin >> n;

    for (int i = 0; i <= n; i++) cin >> a[i];

    for (int i = 0, j = 0; i < n; i++)
    {
        s[a[i]]++;
        while (s[a[i]] > 1) s[a[j++]]--;
        res = max(res, i - j + 1);
    }

    cout << res << endl;

    return 0;
}