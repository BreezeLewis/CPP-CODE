#include <iostream>

using namespace std;

const int N = 1000010;

typedef long long LL;

int n;
int phi[N], primes[N], cnt;
bool vis[N];

LL get_eulers(int n)
{
    phi[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            primes[cnt++] = i;
            phi[i] = i - 1;
        }

        for (int j = 0; primes[j] <= n / i; j++)
        {
            vis[primes[j] * i] = true;

            if (i % primes[j] == 0)
            {
                phi[i * primes[j]] = phi[i] * primes[j];
                break;
            }

            phi[i * primes[j]] = phi[i] * (primes[j] - 1);
        }
    }

    LL res = 0;
    for (int i = 1; i <= n; i++) res += phi[i];
    return res;
}

int main()
{
    cin >> n;

    cout << get_eulers(n) << endl;

    return 0;
}