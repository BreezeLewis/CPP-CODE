#include <iostream>
#include <vector>
#include <string>

// KMP�㷨 - ��������ƥ���(next����)
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

// KMP�㷨 - ִ���ַ���ƥ��
std::vector<int> kmpSearch(const std::string& text, const std::string& pattern) {
    int n = text.length();
    int m = pattern.length();
    std::vector<int> positions;

    // ���ģʽ��Ϊ�ջ򳤶�Ϊ�㣬���ؿս��
    if (m == 0) {
        return positions;
    }

    // ���㲿��ƥ���
    std::vector<int> lps = computeLPS(pattern);

    int i = 0; // text������
    int j = 0; // pattern������

    while (i < n) {
        // �ַ�ƥ��ɹ�
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        // ģʽ����ȫƥ��
        if (j == m) {
            positions.push_back(i - j); // ��¼ƥ��λ��
            j = lps[j - 1]; // ������һ��ƥ��
        }
        // �ַ���ƥ��
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
        std::cout << "δ�ҵ�ƥ��" << std::endl;
    }
    else {
        std::cout << "ģʽ������������λ��: ";
        for (int pos : positions) {
            std::cout << pos << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}