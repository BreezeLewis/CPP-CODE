#include <iostream>
#include <vector>
#include <string>
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
    sort(a.begin(), a.end(), [](const ll& x, const ll& y)->bool {
        return x > y;
        });
    vector<ll> prefix_sum(n + 1, 0);
    for (int i = 1; i <= n; i++) prefix_sum[i] = prefix_sum[i - 1] + a[i - 1];
    string res;
    res.reserve(n * 20);
    for (ll k = 1; k <= n; k++) {
        ll m = n / k;
        ll sum_S = m > 0 ? prefix_sum[m * k] : 0;
        if (sum_S > m * D) {
            res += to_string(sum_S - m * D) + "\n";
        }
        else {
            res += "0\n";
        }
    }
    cout << res;
}
