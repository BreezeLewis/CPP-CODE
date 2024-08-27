#include <iostream>
using namespace std;

// ���������жϸ����� N �Ƿ���Ա�ʾΪ 2^x * 3^y
bool check(int64_t N) {
    // ���ϳ���2
    while (N % 2 == 0) {
        N /= 2;
    }
    // ���ϳ���3
    while (N % 3 == 0) {
        N /= 3;
    }
    // ������ս����1������true
    return N == 1;
}

int main() {
    int64_t N;
    cin >> N; // ����N
    if (check(N)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}
