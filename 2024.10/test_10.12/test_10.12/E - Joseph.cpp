#include <iostream>
#include <vector>
using namespace std;

// 判断给定的 m 是否能保证所有坏人被执行在好人之前
bool is_valid_m(int k, int m) {
    int total = 2 * k;  // 总人数
    int pos = 0;  // 当前执行位置
    for (int i = 0; i < k; ++i) {
        pos = (pos + m - 1) % (total - i);  // 找到下一次执行的位置
        if (pos < k) return false;  // 如果执行的是好人，m不合适
    }
    return true;  // 如果所有坏人都先被执行，返回true
}

int find_min_m(int k) {
    int m = k + 1;  // m最小为k+1，因为m=k时，坏人不可能先被执行
    while (!is_valid_m(k, m)) {
        ++m;
    }
    return m;  // 返回找到的最小m
}

int main() {
    int k;
    while (cin >> k && k != 0) {
        cout << find_min_m(k) << endl;;;
    }
    return 0;
}
