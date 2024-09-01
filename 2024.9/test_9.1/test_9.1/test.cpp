#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> 

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    vector<vector<int>> dp(n, vector<int>(m, INT_MIN));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    dp[0][0] = (grid[0][0] == 2) ? 1 : (grid[0][0] == 1) ? -1 : 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i > 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + (grid[i][j] == 2 ? 1 : (grid[i][j] == 1 ? -1 : 0)));
            }
            if (j > 0) {
                dp[i][j] = max(dp[i][j], dp[i][j - 1] + (grid[i][j] == 2 ? 1 : (grid[i][j] == 1 ? -1 : 0)));
            }
        }
    }

    cout << dp[n - 1][m - 1] << endl;

    return 0;
}
