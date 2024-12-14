#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    ll D;
    cin >> n >> D;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    // Compute prefix sums
    vector<ll> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + a[i];
    // Iterate over each k
    for (int k = 1; k <= n; k++) {
        ll damage = 0;
        int m = (n + k - 1) / k;
        for (int i = 0; i < m; i++) {
            int start = i * k;
            int end = min((i + 1) * k, n);
            ll S = prefix[end] - prefix[start];
            if (S > D) {
                damage += S - D;
            }
        }
        cout << damage << "\n";
    }
}
