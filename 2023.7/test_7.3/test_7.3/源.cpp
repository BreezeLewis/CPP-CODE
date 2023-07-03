#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;


void reverseStrToInt(string& s, int a[])
{
    for (size_t i = 0; i < s.size(); i++)
        a[i + 1] = s[s.size() - i - 1] - '0';
}
string BinaryMultiply(string& num1, string& num2)
{
    int a[10000] = { 0 };
    int b[10000] = { 0 };
    int c[10000] = { 0 };
    size_t size = num1.size() + num2.size();
    reverseStrToInt(num1, a);
    reverseStrToInt(num2, b);
    for (size_t i = 1; i <= num1.size(); i++)
    {
        for (size_t j = 1; j <= num2.size(); j++)
        {
            c[i + j - 1] += a[i] * b[j];
            c[i + j] += c[i + j - 1] / 2;
            c[i + j - 1] %= 2;
        }
    }
    string ret;
    int flag = 0;
    for (size_t i = size; i >= 1; i--)
    {
        if (flag == 0 && c[i] == 0)
            continue;
        else
        {
            flag = 1;
            ret += c[i] + '0';
        }
    }
    if (ret == "")
        return "0";
    return ret;
}
string triple(string& s)
{
    string ss = BinaryMultiply(s, s);
    string sss = BinaryMultiply(ss, s);
    return sss;
}
string BinaryAddStrings(string& num1, string& num2)
{
    int a[3000] = { 0 };
    int b[3000] = { 0 };
    int c[3000] = { 0 };
    size_t size = num1.size() > num2.size() ? num1.size() + 2 : num2.size() + 2;
    reverseStrToInt(num1, a);
    reverseStrToInt(num2, b);
    for (size_t i = 0; i <= size; i++)
    {
        c[i] += a[i] + b[i];
        c[i + 1] = c[i] / 2;
        c[i] %= 2;
    }
    string ret;
    int flag = 0;
    for (size_t i = size; i >= 1; i--)
    {
        if (flag == 0 && c[i] == 0)
            continue;
        else
        {
            flag = 1;
            ret += c[i] + '0';
        }
    }

    return ret;
}
char BinaryToDecimal_char(string& s)
{
    int ret = 0;
    for (int i = 0; s.size(); i++)
    {
        ret += (int)pow(2, i) * (int)(s.back() - '0');
        s.pop_back();
    }
    return (char)ret;
}

int mycmp(const string& s1, const string& s2)
{
    size_t len1 = s1.size(), len2 = s2.size();
    if (len1 > len2) return 1;
    if (len1 < len2)return 0;
    for (size_t i = 0; i < len1; i++)
        if (s1[i] > s2[i])
            return 1;
        else if (s1[i] < s2[i])
            return 0;
    return 1;
}

int left_right(string& s1, string& s2)
{
    size_t len1 = s1.size(), len2 = s2.size();
    if (len1 < len2) return 1;
    if (len1 > len2)return 0;
    for (size_t i = 0; i < len1; i++)
        if (s1[i] < s2[i])
            return 1;
        else if (s1[i] > s2[i])
            return 0;
    return 0;
}
//string sysu = "010010010010000001001100010011110101011001000101001000000101001101011001010100110101010100100001";
string secret;
string ans;
int main()
{
    cin >> secret;
    string left = "1";
    string ret = "1";
    string right = secret;
    //二分

    for (; left.size() + 10 < secret.size() / 3;)
    {
        left += "0000000000";
    }
    for (; left.size() + 1 < secret.size() / 3;)
    {
        left += "0";
    }
    left += "0";
    //left += "0";
    while (left_right(left, right))
    {
        string mid = BinaryAddStrings(left, right);
        mid.pop_back();
        if (mycmp(triple(mid), secret))
            right = mid;
        else
            left = BinaryAddStrings(mid, ret);
    }
    /*while (left != right)
    {
        string mid = BinaryAddStrings(left, right);
        mid.pop_back();
        if (mycmp(triple(mid), secret))
            right = mid;
        else
            left = BinaryAddStrings(mid, ret);
    }*/
    ans = left;

    //得出ans之后
    string tmp;
    string plain;
    while (ans.size())
    {
        while (tmp.size() != 8)
        {
            if (ans.size() == 0)break;
            tmp += ans[ans.size() - 1];
            ans.pop_back();
        }
        reverse(tmp.begin(), tmp.end());
        plain += BinaryToDecimal_char(tmp);
        tmp.clear();
    }
    reverse(plain.begin(), plain.end());

    cout << plain << endl;


    return 0;
}



