#include <iostream>
#include <string>

using namespace std;

const int N = (int)1e5 + 10;

int a[N], b[N], c[N];
string add_str(string x, string y)
{
    int len1 = 0, len2 = 0;
    for (int i = (int)x.size() - 1; i >= 0; i--)
        a[len1++] = x[i] - '0';
    for (int i = (int)y.size() - 1; i >= 0; i--)
        b[len2++] = y[i] - '0';

    int len = (int)max(x.size(), y.size());

    for (int i = 0; i < len; i++)
    {
        c[i] += a[i] + b[i];
        c[i + 1] = c[i] / 10;
        c[i] %= 10;
    }

    while (c[len]) len++;

    string ret;
    for (int i = len - 1; i >= 0; i--)
        ret += c[i] + '0';

    return ret;
}


int main()
{
    string x, y;
    cin >> x >> y;

    string ret = add_str(x, y);

    cout << ret << endl;

    return 0;
}