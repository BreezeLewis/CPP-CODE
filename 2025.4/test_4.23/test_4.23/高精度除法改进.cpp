#include <iostream>
#include <vector>

using namespace std;

// �Ƚ������Ǹ��߾������֣����� 1(A>B), 0(A==B), -1(A<B)
int cmp(const vector<int>& A, const vector<int>& B) {
    if (A.size() != B.size()) return A.size() > B.size() ? 1 : -1;
    for (int i = A.size() - 1; i >= 0; --i)
        if (A[i] != B[i]) return A[i] > B[i] ? 1 : -1;
    return 0;
}

// C = A - B  (Ҫ�� A >= B)
vector<int> sub(vector<int> A, const vector<int>& B) {
    int t = 0;                          // ��λ
    for (size_t i = 0; i < A.size(); ++i) {
        A[i] -= t + (i < B.size() ? B[i] : 0);
        if (A[i] < 0) { A[i] += 10; t = 1; }
        else t = 0;
    }
    while (A.size() > 1 && A.back() == 0) A.pop_back();
    return A;
}

// C = B * k   (0 <= k <= 9)   ���� ���ڲ���
vector<int> mul_small(const vector<int>& B, int k) {
    if (k == 0) return { 0 };
    vector<int> C;  long long carry = 0;
    for (size_t i = 0; i < B.size() || carry; ++i) {
        long long cur = carry + 1LL * (i < B.size() ? B[i] : 0) * k;
        C.push_back(cur % 10);
        carry = cur / 10;
    }
    return C;
}

// �� Q������ R ��������λ��ǰ��
vector<int> div_big(vector<int> A, const vector<int>& B, vector<int>& R) {
    vector<int> Q;          // ��
    R.clear(); R.push_back(0);

    for (int i = A.size() - 1; i >= 0; --i) {
        // 1. ��������һλ������������ A[i]
        R.insert(R.begin(), A[i]);
        while (R.size() > 1 && R.back() == 0) R.pop_back();   // ȥǰ�� 0

        // 2. �� 0~9 ������� q��ʹ B*q <= R
        int q = 0, l = 0, r = 9;
        while (l <= r) {
            int mid = (l + r) >> 1;
            auto prod = mul_small(B, mid);
            if (cmp(prod, R) <= 0) { q = mid; l = mid + 1; }
            else r = mid - 1;
        }

        // 3. R -= B*q
        if (q) {
            auto prod = mul_small(B, q);
            R = sub(R, prod);
        }

        Q.push_back(q);      // ��λ��
    }

    // 4. �����̵�ǰ�� 0
    while (Q.size() > 1 && Q.back() == 0) Q.pop_back();
    reverse(Q.begin(), Q.end());      // ���ĳɸ�λ��ǰ�����˳��
    return Q;
}

int main() {
    string sa, sb;                     // ���������Ǹ�����
    while (cin >> sa >> sb) {
        vector<int> A, B;
        for (int i = sa.size() - 1; i >= 0; --i) A.push_back(sa[i] - '0');
        for (int i = sb.size() - 1; i >= 0; --i) B.push_back(sb[i] - '0');

        if (sb == "0") { cout << "Error: divide by zero\n"; continue; }

        vector<int> R;
        auto Q = div_big(A, B, R);

        // �����
        for (int i = Q.size() - 1; i >= 0; --i) cout << Q[i];
        cout << '\n';
        // �������
        for (int i = R.size() - 1; i >= 0; --i) cout << R[i];
        cout << '\n';
    }
    return 0;
}
