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
                // ���浱ǰ���ظ��������ַ���
                countStack.push(k);
                stringStack.push(currentString);
                // ���ü������͵�ǰ�ַ���
                k = 0;
                currentString = "";
            }
            else if (ch == ']') {
                // ��ȡ�ظ�������֮ǰ���ַ���
                int repeatTimes = countStack.top();
                countStack.pop();

                string temp = stringStack.top();
                stringStack.pop();

                // �ظ���ǰ�ַ�������ӵ�֮ǰ���ַ���
                for (int i = 0; i < repeatTimes; i++) {
                    temp += currentString;
                }

                // ���µ�ǰ�ַ���
                currentString = temp;
            }
            else {
                // ��ͨ�ַ�ֱ�����
                currentString += ch;
            }
        }

        return currentString;
    }
};

int main() {
    Solution solution;

    // ��������
    cout << solution.decodeString("3[a]2[bc]") << endl;       // ���: "aaabcbc"
    cout << solution.decodeString("3[a2[c]]") << endl;        // ���: "accaccacc"
    cout << solution.decodeString("2[abc]3[cd]ef") << endl;   // ���: "abcabccdcdcdef"
    cout << solution.decodeString("abc3[cd]xyz") << endl;     // ���: "abccdcdcdxyz"

    return 0;
}