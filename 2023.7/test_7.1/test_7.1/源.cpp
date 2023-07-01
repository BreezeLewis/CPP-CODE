#include <iostream>
using namespace std;
class Solution
{
public:
    void reverseStrToInt(string& s, int a[])
    {
        for (int i = 0; i < s.size(); i++)
            a[i + 1] = s[s.size() - i - 1] - '0';
    }
    string multiply(string num1, string num2)
    {
        int a[300] = { 0 };
        int b[300] = { 0 };
        int c[300] = { 0 };
        int size = num1.size() + num2.size();
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
        for (int i = size; i >= 1; i--)
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
};
int main()
{
    string s1 = "2";
    string s2 = "3";
    cout << Solution().multiply(s1, s2) << endl;

    return 0;
}