#include <iostream>
#include <vector>
#include <map>

using namespace std;
#define ll long long

void solve() {
    int n;
    string s;
    cin >> n >> s;

    // Convert string to array of integers
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = s[i] - '0';
    }

    // Calculate prefix sum with offset
    // Sum[i,j] = j-i+1 means a[i...j] is good
    // (pref[j] - pref[i-1]) = (j+1) - i
    // pref[j] - j = pref[i-1] - (i-1)
    vector<ll> pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + a[i];
    }

    // Count frequencies of (pref[i] - i)
    map<ll, ll> count;
    ll ans = 0;

    for (int i = 0; i <= n; i++) {
        ans += count[pref[i] - i];
        count[pref[i] - i]++;
    }

    cout << ans << "\n";
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