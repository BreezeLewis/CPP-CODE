#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> garbage(n);
    vector<int> robots(m);

    for (int i = 0; i < n; i++) {
        cin >> garbage[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> robots[i];
    }

    // dp[i][j] means the number of ways to collect the first i pieces of garbage with the first j robots
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Base case: there's 1 way to collect 0 garbage with any number of robots
    for (int j = 0; j <= m; j++) {
        dp[0][j] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i][j - 1]; // not using the j-th robot
            if (robots[j - 1] >= garbage[i - 1]) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD; // using the j-th robot
            }
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}
