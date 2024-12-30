#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 205;  // 根据题目限制设置
vector<int> red, green, blue;
ll dp[MAXN][MAXN][MAXN];  // 使用三维数组代替哈希表

ll dfs(int r, int g, int b) {
    // 基础情况
    if ((r == red.size() && g == green.size()) ||
        (g == green.size() && b == blue.size()) ||
        (r == red.size() && b == blue.size())) {
        return 0;
    }

    // 如果已经计算过，直接返回
    if (dp[r][g][b] != -1) return dp[r][g][b];

    ll maxArea = 0;

    // 尝试所有可能的组合
    if (r < red.size() && g < green.size()) {
        maxArea = max(maxArea, (ll)red[r] * green[g] + dfs(r + 1, g + 1, b));
    }

    if (g < green.size() && b < blue.size()) {
        maxArea = max(maxArea, (ll)green[g] * blue[b] + dfs(r, g + 1, b + 1));
    }

    if (r < red.size() && b < blue.size()) {
        maxArea = max(maxArea, (ll)red[r] * blue[b] + dfs(r + 1, g, b + 1));
    }

    return dp[r][g][b] = maxArea;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, G, B;
    cin >> R >> G >> B;

    red.resize(R);
    for (int i = 0; i < R; i++) cin >> red[i];

    green.resize(G);
    for (int i = 0; i < G; i++) cin >> green[i];

    blue.resize(B);
    for (int i = 0; i < B; i++) cin >> blue[i];

    // 对木棍进行降序排序
    sort(red.begin(), red.end(), greater<int>());
    sort(green.begin(), green.end(), greater<int>());
    sort(blue.begin(), blue.end(), greater<int>());

    // 初始化dp数组为-1
    memset(dp, -1, sizeof(dp));

    cout << dfs(0, 0, 0) << "\n";

    return 0;
}