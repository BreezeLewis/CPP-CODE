#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// KMP���֣�����next����
vector<int> buildNext(const vector<int>& pattern) {
    int m = pattern.size();
    vector<int> next(m + 1);
    next[0] = -1;
    int i = 0, j = -1;

    while (i < m) {
        // ̰�Ĳ��ԣ�������������֪��Ϣ
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

// KMPƥ�����
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
            ans++;  // �ҵ�һ��ƥ��
            j = next[j];  // ����Ѱ����һ��ƥ��
        }
    }
    return ans;
}

// ���δ�������
vector<int> processSequence(const vector<int>& seq, int left, int right) {
    if (right - left <= 1) {
        return vector<int>();
    }

    int mid = left + (right - left) / 2;

    // �ݹ鴦����������
    auto leftDiff = processSequence(seq, left, mid);
    auto rightDiff = processSequence(seq, mid, right);

    // ̰�ĺϲ������ֱ�Ӽ�����
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

    // ���ģʽ����Ϊ1���κ�λ�ö���ƥ���
    if (w == 1) {
        cout << n << "\n";
        return 0;
    }

    // ���ģʽ���ȴ����ı����ȣ�ֱ�ӷ���0
    if (w > n) {
        cout << "0\n";
        return 0;
    }

    // ������������
    vector<int> wall(n), pattern(w);
    for (int i = 0; i < n; i++) {
        cin >> wall[i];
    }
    for (int i = 0; i < w; i++) {
        cin >> pattern[i];
    }

    // ���δ������У���ò������
    vector<int> wallDiff = processSequence(wall, 0, n);
    vector<int> patternDiff = processSequence(pattern, 0, w);

    // ʹ��KMPѰ��ƥ��
    int result = KMPMatch(wallDiff, patternDiff);

    cout << result << "\n";

    return 0;
}