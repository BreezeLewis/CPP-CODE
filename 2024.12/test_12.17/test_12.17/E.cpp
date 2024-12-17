#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, D;
    cin >> n >> D;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;

    sort(a.begin(), a.end(), [&](const ll& x, const ll& y) -> bool {
        return x > y;
        });

    vector<ll> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + a[i];

    ll m1 = 0;
    while (m1 < n && a[m1] > D) {
        m1++;
    }
    ll sum1 = prefix[m1];
    ll damage_k1 = sum1 - m1 * D;

    cout << max(damage_k1, (ll)0) << "\n";

    for (ll k = 2; k <= n; k++) {
        ll m = n / k;
        if (m == 0) {
            cout << "0\n";
            continue;
        }
        if (m * k > n) {
            m = n / k;
        }
        ll sum_k = prefix[m * k];
        ll damage = sum_k - m * D;
        if (damage > 0) {
            cout << damage << "\n";
        }
        else {
            cout << "0\n";
        }
    }
}
