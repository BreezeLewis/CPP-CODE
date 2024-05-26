#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n, a[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    int res = 0;

    sort(a, a + n);

    for (int i = 0; i < n; i++) res += abs(a[i] - a[n / 2]);

    cout << res;

    return 0;
}