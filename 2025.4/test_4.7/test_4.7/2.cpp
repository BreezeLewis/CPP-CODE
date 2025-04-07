// 问题：最长回文子串
// 给定一个字符串 s，找到 s 中最长的回文子串。
// 回文字符串指正着读和倒着读都一样的字符串。

#include <iostream>
#include <string>
using namespace std;

string longestPalindrome(string s) {
    if (s.length() <= 1) return s;

    int start = 0, maxLength = 1;

    // 辅助函数：从中心向两边扩展，寻找最长回文子串
    auto expandAroundCenter = [&s](int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return make_pair(left + 1, right - left - 1);
        };

    for (int i = 0; i < s.length(); i++) {
        // 处理奇数长度的回文（如 "aba"）
        auto [oddStart, oddLength] = expandAroundCenter(i, i);
        if (oddLength > maxLength) {
            maxLength = oddLength;
            start = oddStart;
        }

        // 处理偶数长度的回文（如 "abba"）
        if (i < s.length() - 1 && s[i] == s[i + 1]) {
            auto [evenStart, evenLength] = expandAroundCenter(i, i + 1);
            if (evenLength > maxLength) {
                maxLength = evenLength;
                start = evenStart;
            }
        }
    }

    return s.substr(start, maxLength);
}

int main() {
    string s;
    cout << "请输入一个字符串: ";
    cin >> s;

    string result = longestPalindrome(s);
    cout << "最长回文子串是: " << result << endl;
    cout << "长度为: " << result.length() << endl;

    return 0;
}