#include<iostream>
using namespace std;
int w[20010] = { 0 };
int dp[31][20010] = { 0 };
int main() {
    int V, n;
    cin >> V >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= V; j++) {
            if (j >= w[i])
                dp[i][j] = max(dp[i - 1][j - w[i]] + w[i], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << V - dp[n][V] << endl;
}
