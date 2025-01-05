#include <iostream>
#include <vector>
using namespace std;
#define ll long long

void solve() {
    int n, u, v;
    cin >> n >> u >> v;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Check if array elements differ by more than 1
    bool diff_more_than_one = false;
    bool has_diff_one = false;

    for (int i = 1; i < n; i++) {
        if (abs(a[i] - a[i - 1]) > 1) {
            diff_more_than_one = true;
        }
        if (abs(a[i] - a[i - 1]) == 1) {
            has_diff_one = true;
        }
    }

    if (diff_more_than_one) {
        cout << 0 << "\n";
        return;
    }

    if (has_diff_one) {
        cout << min(u, v) << "\n";
        return;
    }

    cout << min(u + v, 2 * v) << "\n";
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