#include <iostream>
using namespace std;

typedef long long ll;

const int mod = (int)1e9 + 7;
const int N = (int)1e5 + 10;

int a[N];
ll dp_plus[N], dp_minus[N], dp_plus_n[N], dp_minus_n[N];

int mo(ll x)
{
    return (x % mod + mod) % mod;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    dp_plus[1] = a[1], dp_plus_n[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp_plus_n[i] = mo(dp_plus_n[i - 1] + dp_minus_n[i - 1]);
        dp_minus_n[i] = dp_plus_n[i - 1];
    }

    for (int i = 2; i <= n; i++)
    {
        //dp_plus[i] = (dp_plus[i - 1] + a[i] * dp_plus_n[i - 1]) + (dp_minus[i - 1] + a[i] * dp_minus_n[i - 1]);
        dp_plus[i] = mo(mo(dp_plus[i - 1] + dp_minus[i - 1]) +
            mo((ll)a[i] * mo(dp_plus_n[i - 1] + dp_minus_n[i - 1])));
        dp_minus[i] = mo(dp_plus[i - 1] - mo((ll)a[i] * dp_plus_n[i - 1]));
    }

    cout << mo(dp_plus[n] + dp_minus[n]) << endl;
    
    return 0;
}
