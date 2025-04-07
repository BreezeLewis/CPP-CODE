// ���⣺������Ӵ�
// ����һ���ַ��� s���ҵ� s ����Ļ����Ӵ���
// �����ַ���ָ���Ŷ��͵��Ŷ���һ�����ַ�����

#include <iostream>
#include <string>
using namespace std;

string longestPalindrome(string s) {
    if (s.length() <= 1) return s;

    int start = 0, maxLength = 1;

    // ������������������������չ��Ѱ��������Ӵ�
    auto expandAroundCenter = [&s](int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return make_pair(left + 1, right - left - 1);
        };

    for (int i = 0; i < s.length(); i++) {
        // �����������ȵĻ��ģ��� "aba"��
        auto [oddStart, oddLength] = expandAroundCenter(i, i);
        if (oddLength > maxLength) {
            maxLength = oddLength;
            start = oddStart;
        }

        // ����ż�����ȵĻ��ģ��� "abba"��
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
    cout << "������һ���ַ���: ";
    cin >> s;

    string result = longestPalindrome(s);
    cout << "������Ӵ���: " << result << endl;
    cout << "����Ϊ: " << result.length() << endl;

    return 0;
}