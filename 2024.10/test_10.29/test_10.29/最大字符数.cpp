#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int solve(string& a, string& b)
{
    int res = 0;

    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            if (a[i] < b[j])
            {
                res = max(res, (int)a.size() - i + (int)b.size() - j);
                break;
            }
        }
    }

    res = max(res, (int)b.size());

    return res;
}

int main()
{
    string a, b;
    cin >> a >> b;

    int q;
    cin >> q;
    while (q--)
    {
        int i, j;
        cin >> i >> j;

        string sa = a.substr(i - 1), sb = b.substr(j - 1);

        int res = solve(sa, sb);

        cout << res << endl;
    }

    return 0;
}
// 64 Î»Êä³öÇëÓÃ printf("%lld")







