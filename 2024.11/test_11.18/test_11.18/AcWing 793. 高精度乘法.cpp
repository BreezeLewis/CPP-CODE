#include <iostream>
#include <string>

using namespace std;

const int N = (int)1e5 + 10;

int a[N], b[N], c[N + N];

string s1, s2;

void reverseStrToInt(string s, int a[])
{
    for (int i = (int)s.size() - 1; i >= 0; i--)
        a[s.size() - i] = s[i] - '0';
}

string mul_str(string s1, string s2)
{
    reverseStrToInt(s1, a);
    reverseStrToInt(s2, b);

    for (int i = 1; i <= s1.size(); i++)
        for (int j = 1; j <= s2.size(); j++)
        {
            c[i + j - 1] += a[i] * b[j];
            c[i + j] += c[i + j - 1] / 10;
            c[i + j - 1] %= 10;
        }

    int size = (int)(s1.size() + s2.size());
    while (size > 1 && c[size] == 0) size--;

    string ret;
    for (int i = size; i > 0; i--) ret += c[i] + '0';

    return ret;
}

int main()
{
    cin >> s1 >> s2;

    string ret = mul_str(s1, s2);

    cout << ret << endl;

    return 0;
}

