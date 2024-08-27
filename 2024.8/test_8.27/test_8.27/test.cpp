#include <iostream>
using namespace std;

// 函数用于判断给定的 N 是否可以表示为 2^x * 3^y
bool check(int64_t N) {
    // 不断除以2
    while (N % 2 == 0) {
        N /= 2;
    }
    // 不断除以3
    while (N % 3 == 0) {
        N /= 3;
    }
    // 如果最终结果是1，返回true
    return N == 1;
}

int main() {
    int64_t N;
    cin >> N; // 输入N
    if (check(N)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}
