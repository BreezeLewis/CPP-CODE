#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int min_sort_time(int n, int A, int B, vector<int>& arr) {
    vector<int> dp(n, INT_MAX);
    dp[0] = 0; // 没有信件时不需要时间

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[j] < arr[i]) {
                dp[i] = min(dp[i], dp[j] + A);
            }
            else {
                dp[i] = min(dp[i], dp[j] + B);
            }
        }
    }

    // 找出dp数组中的最小值
    int result = *min_element(dp.begin(), dp.end());
    return result;
}

int main() {
    // 示例使用
    int n = 5;
    int A = 2;
    int B = 3;
    vector<int> arr = { 4, 3, 1, 5, 2 };

    cout << "最小排序时间: " << min_sort_time(n, A, B, arr) << endl;
    return 0;
}
