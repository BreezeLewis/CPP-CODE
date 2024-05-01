#include <iostream>

using namespace std;

int main()
{
    int n, res = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (i % 2 == 1) res ^= x;
    }

    if (res) puts("Yes");
    else puts("No");

    return 0;
}