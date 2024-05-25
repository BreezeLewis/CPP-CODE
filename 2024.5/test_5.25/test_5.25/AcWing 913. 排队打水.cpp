#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 100010;

int n, a[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);
    reverse(a, a + n);

    LL res = 0;

    for (int i = 0; i < n; i++) res += a[i] * i;

    cout << res << endl;

    return 0;
}