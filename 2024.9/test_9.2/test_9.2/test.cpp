#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> dp(N + 1, 0);

    for (int i = 0; i < M; ++i) {
        int x, y, z;
        cin >> x >> y >> z;

        if (z == 0) {
            for (int j = x; j <= N; ++j) {
                dp[j] = max(dp[j], dp[j - x] + y);
            }
        }
        else { 
            for (int j = N; j >= x; --j) {
                dp[j] = max(dp[j], dp[j - x] + y);
            }
        }
    }

    cout << dp[N] << endl;

    return 0;
}
