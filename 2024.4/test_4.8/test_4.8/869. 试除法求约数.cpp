#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, x;

void get_divisor(vector<int>& v, int x)
{
    for (int i = 1; i <= x / i; i++)
    {
        if (x % i == 0)
        {
            v.push_back(i);
            if (x / i != i) v.push_back(x / i);
        }
    }

    sort(v.begin(), v.end());
}

int main()
{
    cin >> n;
    while (n--)
    {
        cin >> x;
        vector<int> res;
        get_divisor(res, x);

        for (auto e : res) cout << e << ' ';
        puts("");
    }

    return 0;
}