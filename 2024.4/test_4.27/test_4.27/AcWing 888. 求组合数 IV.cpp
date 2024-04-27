//��C(a, b)�ֽ����������Ȱ�1~a������ɸ����
//Ȼ����ÿ��������C(a, b)�г��ֵĴ���
//����ø߾��ȳ˷����������

#include <iostream>
#include <vector>

using namespace std;

const int N = 5010;

bool vis[N];
int primes[N], cnt;
int sum[N];//ÿ��������C(a, b)�г��ֵĴ���

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

int get(int n, int p)//��n���ķֽ��������ж��ٸ�p���
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
    get_primes(a);//���2~a��������������cnt��

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