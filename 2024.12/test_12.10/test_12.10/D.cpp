#include <iostream>
using namespace std;

typedef long long ll;

const int MOD = 1000000007;
const int MAX = 100005;

ll power_mod(ll x, ll y, ll mod) {
    ll res = 1;
    x %= mod;
    while (y > 0) {
        if (y & 1) {
            res = res * x % mod;
        }
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}

ll fact[MAX];
ll inv_fact_arr[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    fact[0] = 1;
    for (int i = 1; i <= N; i++) 
        fact[i] = fact[i - 1] * i % MOD;

    inv_fact_arr[N] = power_mod(fact[N], MOD - 2, MOD);
    for (int i = N - 1; i >= 0; i--) {
        inv_fact_arr[i] = inv_fact_arr[i + 1] * (i + 1) % MOD;
    }

    ll sum = 0;
    for (int i = 0; i <= K; i++) {

        ll Cki = fact[K] * inv_fact_arr[i] % MOD;
        Cki = Cki * inv_fact_arr[K - i] % MOD;

        ll f = fact[N - i];

        ll term = Cki * f % MOD;
        if (i % 2) {
            sum = (sum - term) % MOD;
            if (sum < 0) sum += MOD;
        }
        else {
            sum = (sum + term) % MOD;
        }
    }

    ll result = sum * inv_fact_arr[N - K] % MOD;
    cout << result;
}
