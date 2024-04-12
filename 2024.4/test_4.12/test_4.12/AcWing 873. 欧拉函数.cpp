#include <iostream>
#include <algorithm>

using namespace std;

int n;

int main()
{
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;

        int res = x;
        for (int i = 2; i <= x / i; i++)
            if (x % i == 0)
            {
                while (x % i == 0) x /= i;
                res = res * (1 - 1.0 / i);
            }

        if (x > 1) res = res * (1 - 1.0 / x);

        cout << res << endl;
    }

    return 0;
}