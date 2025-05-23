#include <iostream>

using namespace std;

typedef long long LL;

int exgcd(int a, int b, int& x, int& y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;

    return d;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, b, m, x, y;
        cin >> a >> b >> m;
        int d = exgcd(a, m, x, y);

        if (b % d) puts("impossible");
        else cout << (LL)x * b / d % m << endl;
    }
}