#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void solve() {
    int n, k, z;
    cin >> n >> k >> z;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // dp[i][j] represents maximum sum after i moves with j left moves used
    vector<vector<ll>> dp(k + 1, vector<ll>(z + 1, -1e18));
    dp[0][0] = a[0];

    // For each step
    for (int steps = 0; steps < k; steps++) {
        // For each number of left moves used
        for (int left_used = 0; left_used <= z; left_used++) {
            if (dp[steps][left_used] == -1e18) continue;

            int pos = steps - left_used + left_used;  // current position

            // Can go right if not at the end
            if (pos < n - 1) {
                dp[steps + 1][left_used] = max(dp[steps + 1][left_used],
                    dp[steps][left_used] + a[pos + 1]);
            }

            // Can go left if haven't used all left moves and not at start
            if (left_used < z && pos > 0 && steps + 2 <= k) {
                dp[steps + 2][left_used + 1] = max(dp[steps + 2][left_used + 1],
                    dp[steps][left_used] + a[pos - 1] + a[pos]);
            }
        }
    }

    ll ans = 0;
    for (int left_used = 0; left_used <= z; left_used++) {
        ans = max(ans, dp[k][left_used]);
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}