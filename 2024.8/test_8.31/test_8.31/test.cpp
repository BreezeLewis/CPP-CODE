#include <iostream>
using namespace std;

// Function to calculate the last digit of n^m
int lastDigit(long long n, long long m) {
    // If m is 0, n^0 is 1
    if (m == 0) return 1;

    // Get the last digit of n
    n = n % 10;

    // Calculate cycle of last digits
    int cycle[4];
    cycle[0] = n;
    for (int i = 1; i < 4; i++) {
        cycle[i] = (cycle[i - 1] * n) % 10;
    }

    // Find the position in the cycle
    int position = (m - 1) % 4;

    return cycle[position];
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long n, m;
        cin >> n >> m;
        cout << lastDigit(n, m) << endl;
    }
    return 0;
}
