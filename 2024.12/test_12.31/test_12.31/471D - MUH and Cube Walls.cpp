#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// KMP部分：计算next数组
vector<int> buildNext(const vector<int>& pattern) {
    int m = pattern.size();
    vector<int> next(m + 1);
    next[0] = -1;
    int i = 0, j = -1;

    while (i < m) {
        // 贪心策略：尽可能利用已知信息
        if (j == -1 || pattern[i] == pattern[j]) {
            i++; j++;
            next[i] = j;
        }
        else {
            j = next[j];
        }
    }
    return next;
}

// KMP匹配过程
int KMPMatch(const vector<int>& text, const vector<int>& pattern) {
    if (pattern.empty()) return text.size();
    if (text.empty()) return 0;

    vector<int> next = buildNext(pattern);
    int n = text.size(), m = pattern.size();
    int i = 0, j = 0, ans = 0;

    while (i < n) {
        if (j == -1 || text[i] == pattern[j]) {
            i++; j++;
        }
        else {
            j = next[j];
        }
        if (j == m) {
            ans++;  // 找到一个匹配
            j = next[j];  // 继续寻找下一个匹配
        }
    }
    return ans;
}

// 分治处理序列
vector<int> processSequence(const vector<int>& seq, int left, int right) {
    if (right - left <= 1) {
        return vector<int>();
    }

    int mid = left + (right - left) / 2;

    // 递归处理左右两半
    auto leftDiff = processSequence(seq, left, mid);
    auto rightDiff = processSequence(seq, mid, right);

    // 贪心合并结果：直接计算差分
    vector<int> result;
    for (int i = left + 1; i < right; i++) {
        result.push_back(seq[i] - seq[i - 1]);
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, w;
    cin >> n >> w;

    // 如果模式长度为1，任何位置都是匹配的
    if (w == 1) {
        cout << n << "\n";
        return 0;
    }

    // 如果模式长度大于文本长度，直接返回0
    if (w > n) {
        cout << "0\n";
        return 0;
    }

    // 读入两个序列
    vector<int> wall(n), pattern(w);
    for (int i = 0; i < n; i++) {
        cin >> wall[i];
    }
    for (int i = 0; i < w; i++) {
        cin >> pattern[i];
    }

    // 分治处理序列，获得差分数组
    vector<int> wallDiff = processSequence(wall, 0, n);
    vector<int> patternDiff = processSequence(pattern, 0, w);

    // 使用KMP寻找匹配
    int result = KMPMatch(wallDiff, patternDiff);

    cout << result << "\n";

    return 0;
}