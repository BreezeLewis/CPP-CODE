#include <iostream>

using namespace std;

const int N = 100010;

int a[N];

int main()
{
    int n, x;
    int res = 0;
    cin >> n;
    while (n--)
    {
        cin >> x;
        res ^= x;
    }

    if (res) puts("Yes");
    else puts("No");

    return 0;

}