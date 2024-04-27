#include <iostream>

using namespace std;

const int N = 1000010;

int primes[N], cnt;
bool vis[N];
int sum[N];

void get_primes(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i]) primes[cnt++] = i;

        for (int j = 0; primes[j] <= n / i; j++)
        {
            vis[primes[j] * i] = true;

            if (i % primes[j] == 0) break;
        }
    }
}

int get(int n, int p)//计算n的阶乘有几个p
{
    int res = 0;
    while (n)
    {
        res += n / p;
        n /= p;
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    get_primes(n);

    for (int i = 0; i < cnt; i++)
        sum[i] = get(n, primes[i]);

    for (int i = 0; i < cnt; i++)
        cout << primes[i] << " " << sum[i] << endl;

    return 0;
}