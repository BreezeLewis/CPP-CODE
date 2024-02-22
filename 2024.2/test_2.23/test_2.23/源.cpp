#include<iostream>
using namespace std;
long long n, h, p, a[10100], b[10100], m, x[5100];
bool r;
int main()
{
    scanf("%lld%lld%lld%lld", &n, &p, &h, &m);
    //for(long long i=1;i<=n;i++) x[i]=h;
    for (long long i = 1; i <= m; i++)
    {
        scanf("%lld%lld", &a[i], &b[i]);
        if (a[i] > b[i]) swap(a[i], b[i]);
        r = true;
        for (long long j = 1; j < i; j++)
        {
            if (a[i] == a[j] && b[i] == b[j])
            {
                r = false;
                break;
            }
        }
        if (r == true)
        {
            x[a[i] + 1]--;
            x[b[i]]++;
        }
    }
    for (long long i = 1; i <= n; i++) x[i] += x[i - 1];
    for (long long i = 1; i <= n; i++)
    {
        x[i] += h;
        printf("%lld\n", x[i]);
    }
    return 0;
}
