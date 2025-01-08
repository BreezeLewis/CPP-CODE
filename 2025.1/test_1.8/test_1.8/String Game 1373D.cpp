#include <iostream>
#include <vector>
using namespace std;
#define ll long long

ll kadane(vector<ll>& arr) {
    ll curr_sum = 0, max_sum = 0;
    for (ll num : arr) {
        curr_sum = max(0LL, curr_sum + num);
        max_sum = max(max_sum, curr_sum);
    }
    return max_sum;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Calculate base score (sum of even-indexed elements)
    ll base_score = 0;
    for (int i = 0; i < n; i += 2) {
        base_score += a[i];
    }

    // Try to maximize score by reversing some segment
    vector<ll> diff1, diff2;  // differences when starting from even/odd index

    for (int i = 1; i < n; i += 2) {
        if (i + 1 < n) {
            diff1.push_back(a[i] - a[i - 1]);  // gain when reversing i-1,i
        }
    }

    for (int i = 1; i < n - 1; i += 2) {
        diff2.push_back(a[i + 1] - a[i]);  // gain when reversing i,i+1
    }

    ll max_gain = max(kadane(diff1), kadane(diff2));
    cout << base_score + max_gain << "\n";
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