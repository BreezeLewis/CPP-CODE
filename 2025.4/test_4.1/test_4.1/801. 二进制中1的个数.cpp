#include <iostream>

using namespace std;

const int N = (int)1e5 + 10;

int a[N];

int count1(int x)
{
    int res = 0;
    while (x)
    {
        if (x & 1) res++;
        x >>= 1;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i], cout << count1(a[i]) << ' ';
}