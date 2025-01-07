#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<pair<int, int>> moves;

    // Bubble sort implementation with tracking moves
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[j] > a[j + 1] || (a[j] == a[j + 1] && b[j] > b[j + 1])) {
                swap(a[j], a[j + 1]);
                swap(b[j], b[j + 1]);
                moves.push_back({ j + 1, j + 2 });
            }
        }
    }

    // Check if both arrays are sorted
    bool sorted = true;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1] || b[i] < b[i - 1]) {
            sorted = false;
            break;
        }
    }

    if (!sorted) {
        cout << -1 << "\n";
        return;
    }

    cout << moves.size() << "\n";
    for (auto move : moves) {
        cout << move.first << " " << move.second << "\n";
    }
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