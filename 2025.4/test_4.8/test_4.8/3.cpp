#include <iostream>
#include <vector>
#include <string>

// KMP算法 - 构建部分匹配表(next数组)
std::vector<int> computeLPS(const std::string& pattern) {
    int m = pattern.length();
    std::vector<int> lps(m, 0);

    int len = 0;
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

// KMP算法 - 执行字符串匹配
std::vector<int> kmpSearch(const std::string& text, const std::string& pattern) {
    int n = text.length();
    int m = pattern.length();
    std::vector<int> positions;

    // 如果模式串为空或长度为零，返回空结果
    if (m == 0) {
        return positions;
    }

    // 计算部分匹配表
    std::vector<int> lps = computeLPS(pattern);

    int i = 0; // text的索引
    int j = 0; // pattern的索引

    while (i < n) {
        // 字符匹配成功
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        // 模式串完全匹配
        if (j == m) {
            positions.push_back(i - j); // 记录匹配位置
            j = lps[j - 1]; // 查找下一个匹配
        }
        // 字符不匹配
        else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            }
            else {
                i++;
            }
        }
    }

    return positions;
}

int main() {
    std::string text = "ABABDABACDABABCABAB";
    std::string pattern = "ABABCABAB";

    std::vector<int> positions = kmpSearch(text, pattern);

    if (positions.empty()) {
        std::cout << "未找到匹配" << std::endl;
    }
    else {
        std::cout << "模式串出现在以下位置: ";
        for (int pos : positions) {
            std::cout << pos << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}