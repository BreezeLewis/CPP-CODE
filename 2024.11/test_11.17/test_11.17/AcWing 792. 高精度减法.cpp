#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int N = (int)1e5 + 10;

int s1[N], s2[N], s3[N];

bool operator<(string a, string b)
{
    if (a.size() < b.size()) return true;
    else if (a.size() > b.size()) return false;

    for (int i = 0; i < a.size(); i++)
        if (a[i] < b[i]) return true;
        else if (a[i] > b[i]) return false;

    return false;
}

string sub_str(string a, string b)
{
    string prefix;
    if (a < b)
        swap(a, b), prefix = "-";

    int len1 = 0, len2 = 0;

    for (int i = a.size() - 1; i >= 0; i--)
        s1[len1++] = a[i] - '0';

    for (int i = b.size() - 1; i >= 0; i--)
        s2[len2++] = b[i] - '0';

    for (int i = 0; i < a.size(); i++)
    {
        s3[i] = s1[i] - s2[i];
        if (s3[i] < 0)
        {
            s1[i + 1] -= 1;
            s3[i] += 10;
        }
    }

    string ret;
    int size = a.size();
    while (s3[size] == 0 && size > 0) size--;

    for (int i = size; i >= 0; i--) ret += s3[i] + '0';

    return prefix + ret;
}

int main()
{
    string a, b;

    cin >> a >> b;

    string ret = sub_str(a, b);

    cout << ret << endl;

    return 0;
}