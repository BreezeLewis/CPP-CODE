#include <iostream>
using namespace std;

typedef long long ll;

const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if (n == 0) {
        cout << 1;
        return 0;
    }

    if (n == 1) {
        cout << 4;
        return 0;
    }
    if (n == 2) {
        cout << 12;
        return 0;
    }
    if (n == 3) {
        cout << 36;
        return 0;
    }
    ll dp0 = 1;
    ll dp1 = 4;
    ll dp2 = 12;
    ll dp3 = 36;
    ll current;
    for (int t = 4; t <= n; t++) {
        current = (2 * dp3 % MOD + 2 * dp2 % MOD + dp1 % MOD) % MOD;
        dp0 = dp1;
        dp1 = dp2;
        dp2 = dp3;
        dp3 = current;
    }
    cout << dp3;
}
