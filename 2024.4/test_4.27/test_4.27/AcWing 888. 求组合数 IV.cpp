//把C(a, b)分解质因数，先把1~a的素数筛出来
//然后求每个质数在C(a, b)中出现的次数
//最后用高精度乘法把因数相乘

#include <iostream>
#include <vector>

using namespace std;

const int N = 5010;

bool vis[N];
int primes[N], cnt;
int sum[N];//每个质数在C(a, b)中出现的次数

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

int get(int n, int p)//求n！的分解质因数有多少个p相乘
{
    int res = 0;
    while (n)
    {
        res += n / p;
        n /= p;
    }
    return res;
}

vector<int> mul(vector<int>& a, int b)
{
    vector<int> ret;
    int t = 0;
    for (int i = 0; i < a.size(); i++)
    {
        t += a[i] * b;
        ret.push_back(t % 10);
        t /= 10;
    }

    while (t)
    {
        ret.push_back(t % 10);
        t /= 10;
    }

    return ret;
}

int main()
{
    int a, b;
    cin >> a >> b;
    get_primes(a);//求出2~a的所有质数，共cnt个

    for (int i = 0; i < cnt; i++)
        sum[i] = get(a, primes[i]) - get(b, primes[i]) - get(a - b, primes[i]);

    vector<int> res;
    res.push_back(1);

    for (int i = 0; i < cnt; i++)
        for (int j = 0; j < sum[i]; j++)
            res = mul(res, primes[i]);

    for (int i = res.size() - 1; i >= 0; i--)
        cout << res[i];
    puts("");

    return 0;
}