#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;
        string currentString = "";
        int k = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                k = k * 10 + (ch - '0');
            }
            else if (ch == '[') {
                // 保存当前的重复次数和字符串
                countStack.push(k);
                stringStack.push(currentString);
                // 重置计数器和当前字符串
                k = 0;
                currentString = "";
            }
            else if (ch == ']') {
                // 获取重复次数和之前的字符串
                int repeatTimes = countStack.top();
                countStack.pop();

                string temp = stringStack.top();
                stringStack.pop();

                // 重复当前字符串并添加到之前的字符串
                for (int i = 0; i < repeatTimes; i++) {
                    temp += currentString;
                }

                // 更新当前字符串
                currentString = temp;
            }
            else {
                // 普通字符直接添加
                currentString += ch;
            }
        }

        return currentString;
    }
};

int main() {
    Solution solution;

    // 测试用例
    cout << solution.decodeString("3[a]2[bc]") << endl;       // 输出: "aaabcbc"
    cout << solution.decodeString("3[a2[c]]") << endl;        // 输出: "accaccacc"
    cout << solution.decodeString("2[abc]3[cd]ef") << endl;   // 输出: "abcabccdcdcdef"
    cout << solution.decodeString("abc3[cd]xyz") << endl;     // 输出: "abccdcdcdxyz"

    return 0;
}