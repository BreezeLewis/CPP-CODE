//C(2n, n) - C(2n, n - 1) = C(2n, n) / n + 1;
#include <iostream>

using namespace std;

typedef long long LL;

const int mod = 1e9 + 7;

int qmi(int a, int k, int p)
{
    int res = 1;
    while (k)
    {
        if (k & 1) res = (LL)res * a % p;
        a = (LL)a * a % p;
        k >>= 1;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    int a = 2 * n, b = n;
    int res = 1;
    for (int i = a; i > a - b; i--) res = (LL)res * i % mod;
    for (int i = 1; i <= b; i++) res = (LL)res * qmi(i, mod - 2, mod) % mod;

    res = (LL)res * qmi(n + 1, mod - 2, mod) % mod;

    cout << res << endl;

    return 0;
}