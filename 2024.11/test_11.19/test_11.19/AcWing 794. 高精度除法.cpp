#include <iostream>
#include <string>

using namespace std;

const int N = (int)1e5 + 10;

int a[N], c[N];
string A;
int B;

string div(string s, int b, int& r)
{
    for (int i = 0; i < s.size(); i++) a[i] = s[i] - '0';

    int len = 0;
    for (int i = 0; i < s.size(); i++)
    {
        r = r * 10 + a[i];
        c[len++] = r / b;
        r %= b;
    }

    int start = 0;
    while (start < len - 1 && c[start] == 0) start++;

    string ret;
    for (int i = start; i < len; i++) ret += c[i] + '0';

    return ret;
}

int main()
{
    cin >> A >> B;

    int r = 0;
    string ret = div(A, B, r);

    cout << ret << endl << r << endl;

    return 0;
}