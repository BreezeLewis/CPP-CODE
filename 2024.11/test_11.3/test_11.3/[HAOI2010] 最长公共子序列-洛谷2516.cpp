#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int mod = 1e8;
int dp[2][5001];
int num[2][5001];

int main() {
    string str1, str2;
    while (cin >> str1 >> str2) {
        int n = str1.size();
        int m = str2.size();
        int t = 0;
        for (int i = 0; i < n; i++)
            num[0][i] = 1;
        num[1][0] = 1;

        for (int i = 1; i < n; i++, t ^= 1) {
            for (int j = 1; j < m; j++) {
                num[t ^ 1][j] = 0;
                if (str1[i - 1] == str2[j - 1]) {
                    dp[t ^ 1][j] = dp[t][j - 1] + 1;
                    num[t ^ 1][j] += num[t][j - 1] % mod;
                }
                else
                    dp[t ^ 1][j] = max(dp[t][j], dp[t ^ 1][j - 1]);
                if (dp[t ^ 1][j] == dp[t][j])
                    num[t ^ 1][j] += num[t][j] % mod;
                if (dp[t ^ 1][j] == dp[t ^ 1][j - 1])
                    num[t ^ 1][j] += num[t ^ 1][j - 1] % mod;
                if (str1[i - 1] != str2[j - 1] && dp[t ^ 1][j] == dp[t][j - 1])
                    num[t ^ 1][j] -= num[t][j - 1];

            }
        }
        cout << dp[t][m - 1] << endl << num[t][m - 1] << endl;
    }
}
