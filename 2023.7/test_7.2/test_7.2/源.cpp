#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;


void reverseStrToInt(string& s, int a[])
{
    for (int i = 0; i < s.size(); i++)
        a[i + 1] = s[s.size() - i - 1] - '0';
}
string multiply(string num1, string num2)
{
    int a[3000] = { 0 };
    int b[3000] = { 0 };
    int c[3000] = { 0 };
    size_t size = num1.size() + num2.size();
    reverseStrToInt(num1, a);
    reverseStrToInt(num2, b);
    for (int i = 1; i <= num1.size(); i++)
    {
        for (int j = 1; j <= num2.size(); j++)
        {
            c[i + j - 1] += a[i] * b[j];
            c[i + j] += c[i + j - 1] / 10;
            c[i + j - 1] %= 10;
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


string BinaryMultiply(string num1, string num2)
{
    int a[3000] = { 0 };
    int b[3000] = { 0 };
    int c[3000] = { 0 };
    size_t size = num1.size() + num2.size();
    reverseStrToInt(num1, a);
    reverseStrToInt(num2, b);
    for (int i = 1; i <= num1.size(); i++)
    {
        for (int j = 1; j <= num2.size(); j++)
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

string llToStr(long long n)
{
    string res;
    for (auto i = n; i; i /= 10)
    {
        res.insert(0, 1, (i % 10) + '0');
    }
    return res;
}





string triple(string& s)
{
    string ss = BinaryMultiply(s, s);
    string sss = BinaryMultiply(ss, s);
    return sss;
}

string IntToBinary(long long n)
{
    if (n == 0)
        return "0";
    string ret;
    for (auto i = n; i; i /= 2)
    {
        ret += ((i % 2) + '0');
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

string addStrings(string num1, string num2)
{
    int a[3000] = { 0 };
    int b[3000] = { 0 };
    int c[3000] = { 0 };
    size_t size = num1.size() > num2.size() ? num1.size() + 2 : num2.size() + 2;
    reverseStrToInt(num1, a);
    reverseStrToInt(num2, b);
    for (size_t i = 1; i <= size; i++)
    {
        c[i] += a[i] + b[i];
        c[i + 1] = c[i] / 10;
        c[i] %= 10;
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

string BinaryAddStrings(string num1, string num2)
{
    int a[3000] = { 0 };
    int b[3000] = { 0 };
    int c[3000] = { 0 };
    size_t size = num1.size() > num2.size() ? num1.size() + 2 : num2.size() + 2;
    reverseStrToInt(num1, a);
    reverseStrToInt(num2, b);
    for (size_t i = 1; i <= size; i++)
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




string sysu = "010010010010000001001100010011110101011001000101001000000101001101011001010100110101010100100001";
string secret;
string ans;
int main() 
{
    string s = "1011111011101111101011110100110011110010010000010100000001101000111010010111010101011100011110111111010011010101111011110001011101110011000101011001110100110100111100111111110101001101010101010111001011000111110111110010111100010110110111000110000000101100011100000010100101101100001";
             //"1011111011101111101011110100110011110010010000010100000001101000111010010111010101011100011110111111010011010101111011110001011101110011000101011001110100110100111100111111110101001101010101010111001011000111110111110010111100010110110111000110000000101100011100000010100101101100001"
    secret = s;
    string ret = "1";
    for (string i = "010010010010000001001100010011110101011001000101001000000101001101011001010100110101010100100001";; i = BinaryAddStrings(i, ret))                   
    {
        if (triple(i) == secret)
        {
            ans = i;
            break;
        }
    }
    string tmp;
    string plain;
    while (ans.size())
    {
        while (tmp.size() != 8)
        {
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
