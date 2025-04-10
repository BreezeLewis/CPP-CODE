#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> findAnagrams(string s, string p) {
    vector<int> res;
    if (s.size() < p.size()) return res;

    vector<int> target(26, 0), window(26, 0);

    // 先统计 p 中每个字符出现的次数
    for (char c : p) {
        target[c - 'a']++;
    }

    int left = 0, right = 0;
    int pLen = p.size();

    // 滑动窗口
    while (right < s.size()) {
        window[s[right] - 'a']++;
        if (right - left + 1 == pLen) {
            if (window == target) {
                res.push_back(left);
            }
            window[s[left] - 'a']--; // 移出最左边的字符
            left++;
        }
        right++;
    }

    return res;
}

int main() {
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> result = findAnagrams(s, p);

    cout << "异位词起始索引为: ";
    for (int idx : result) {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}
