#include <iostream>
#include <vector>

using namespace std;

// 比较两个非负高精度数字：返回 1(A>B), 0(A==B), -1(A<B)
int cmp(const vector<int>& A, const vector<int>& B) {
    if (A.size() != B.size()) return A.size() > B.size() ? 1 : -1;
    for (int i = A.size() - 1; i >= 0; --i)
        if (A[i] != B[i]) return A[i] > B[i] ? 1 : -1;
    return 0;
}

// C = A - B  (要求 A >= B)
vector<int> sub(vector<int> A, const vector<int>& B) {
    int t = 0;                          // 借位
    for (size_t i = 0; i < A.size(); ++i) {
        A[i] -= t + (i < B.size() ? B[i] : 0);
        if (A[i] < 0) { A[i] += 10; t = 1; }
        else t = 0;
    }
    while (A.size() > 1 && A.back() == 0) A.pop_back();
    return A;
}

// C = B * k   (0 <= k <= 9)   —— 用于猜商
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

// 商 Q，余数 R ；均“低位在前”
vector<int> div_big(vector<int> A, const vector<int>& B, vector<int>& R) {
    vector<int> Q;          // 商
    R.clear(); R.push_back(0);

    for (int i = A.size() - 1; i >= 0; --i) {
        // 1. 余数左移一位并加上新数字 A[i]
        R.insert(R.begin(), A[i]);
        while (R.size() > 1 && R.back() == 0) R.pop_back();   // 去前导 0

        // 2. 在 0~9 里找最大 q，使 B*q <= R
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

        Q.push_back(q);      // 本位商
    }

    // 4. 处理商的前导 0
    while (Q.size() > 1 && Q.back() == 0) Q.pop_back();
    reverse(Q.begin(), Q.end());      // 最后改成高位在前的输出顺序
    return Q;
}

int main() {
    string sa, sb;                     // 读入两个非负整数
    while (cin >> sa >> sb) {
        vector<int> A, B;
        for (int i = sa.size() - 1; i >= 0; --i) A.push_back(sa[i] - '0');
        for (int i = sb.size() - 1; i >= 0; --i) B.push_back(sb[i] - '0');

        if (sb == "0") { cout << "Error: divide by zero\n"; continue; }

        vector<int> R;
        auto Q = div_big(A, B, R);

        // 输出商
        for (int i = Q.size() - 1; i >= 0; --i) cout << Q[i];
        cout << '\n';
        // 输出余数
        for (int i = R.size() - 1; i >= 0; --i) cout << R[i];
        cout << '\n';
    }
    return 0;
}
