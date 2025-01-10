#include <iostream>

#include <string>


using namespace std;

bool check(string& s, int x) {
    int n = s.length();
    int ones = count(s.begin(), s.end(), '1');

    // Try all possible segments to keep ones
    int curr_ones = 0;
    int curr_zeros = 0;
    int min_outside_zeros = n;  // zeros outside the segment

    // Use sliding window of size (ones - x)
    int need = ones - x;  // number of ones we need to keep
    if (need == 0) return true;

    for (int i = 0, j = 0; j < n; j++) {
        if (s[j] == '1') curr_ones++;
        else curr_zeros++;

        // Shrink window while maintaining needed ones
        while (curr_ones > need && i <= j) {
            if (s[i] == '1') curr_ones--;
            else curr_zeros--;
            i++;
        }

        if (curr_ones == need) {
            // Calculate zeros outside current segment
            int outside_zeros = count(s.begin(), s.begin() + i, '0') +
                count(s.begin() + j + 1, s.end(), '0');
            min_outside_zeros = min(min_outside_zeros, outside_zeros);
        }
    }

    return min_outside_zeros <= x;
}

void solve() {
    string s;
    cin >> s;

    // Binary search on answer
    int left = 0, right = s.length();
    while (left < right) {
        int mid = (left + right) / 2;
        if (check(s, mid)) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }

    cout << left << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}