#include<iostream>
using namespace std;

bool check(int n) {
    // Check if the number is a multiple of 7
    if (n % 7 == 0) return false;

    // Check if the number contains the digit 7
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        if (digit == 7) return false; // Check for digit 7
        sum += digit; // Sum the digits
        n /= 10;
    }

    // Check if the sum of digits is a multiple of 7
    if (sum % 7 == 0) return false;

    return true;
}

int main() {
    for (int i = 1; i <= 100; ++i) {
        if (check(i)) {
            cout << i << " ";
        }
    }
    return 0;
}