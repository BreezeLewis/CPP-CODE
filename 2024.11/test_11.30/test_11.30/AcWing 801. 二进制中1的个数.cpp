#include <iostream>

using namespace std;

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
    while (n--)
    {
        int x;
        cin >> x;
        cout << count1(x) << ' ';
    }

    return 0;
}