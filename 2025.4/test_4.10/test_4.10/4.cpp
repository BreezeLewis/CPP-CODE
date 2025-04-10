#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> findAnagrams(string s, string p) {
    vector<int> res;
    if (s.size() < p.size()) return res;

    vector<int> target(26, 0), window(26, 0);

    // ��ͳ�� p ��ÿ���ַ����ֵĴ���
    for (char c : p) {
        target[c - 'a']++;
    }

    int left = 0, right = 0;
    int pLen = p.size();

    // ��������
    while (right < s.size()) {
        window[s[right] - 'a']++;
        if (right - left + 1 == pLen) {
            if (window == target) {
                res.push_back(left);
            }
            window[s[left] - 'a']--; // �Ƴ�����ߵ��ַ�
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

    cout << "��λ����ʼ����Ϊ: ";
    for (int idx : result) {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}
