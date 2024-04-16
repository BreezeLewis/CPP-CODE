#include <iostream>

using namespace std;

typedef long long LL;

int qmi(int a, int k, int p)
{
    int res = 1;
    while (k)
    {
        if (k & 1) res = (LL)res * a % p;
        k >>= 1;
        a = (LL)a * a % p;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, p;
        cin >> a >> p;
        if (a % p != 0)
            cout << qmi(a, p - 2, p) << endl;
        else puts("impossible");
    }

    return 0;
}