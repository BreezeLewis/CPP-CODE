#include <iostream>
using namespace std;

typedef long long ll;

const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    ll buf[4];
    buf[0] = 4;   // dp[0]
    buf[1] = 4;   // dp[1]
    buf[2] = 12;  // dp[2]
    buf[3] = 36;  // dp[3]
    if (n <= 3) {
        cout << buf[n];
        return 0;
    }
    for (int i = 4; i <= n; i++) {
        ll term1 = (3 * buf[3]) % MOD;
        ll term2 = (2 * buf[0]) % MOD;
        ll current = (term1 - term2 + MOD) % MOD;
        buf[0] = buf[1];
        buf[1] = buf[2];
        buf[2] = buf[3];
        buf[3] = current;
    }
    cout << buf[3];
}
