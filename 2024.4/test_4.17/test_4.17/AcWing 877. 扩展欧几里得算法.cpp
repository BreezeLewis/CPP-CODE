#include <iostream>

using namespace std;

int gcd(int a, int b, int& x, int& y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }

    int d = gcd(b, a % b, y, x);

    y -= a / b * x;

    return d;
}

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        int a, b, x, y;
        cin >> a >> b;
        gcd(a, b, x, y);
        cout << x << " " << y << endl;
    }

    return 0;
}