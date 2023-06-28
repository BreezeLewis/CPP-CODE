#include <iostream>
using namespace std;

class Solution {
public:
    void reverseStrToInt(int a[], string& s)
    {
        for (int i = 0; i < s.size(); i++)
            a[i] = s[s.size() - i - 1] - '0';
    }
    string addStrings(string num1, string num2)
    {
        int a[10010] = { 0 };
        int b[10010] = { 0 };
        int c[10010] = { 0 };
        reverseStrToInt(a, num1);
        reverseStrToInt(b, num2);

        int size = num1.size() + num2.size() + 1;
        for (int i = 0; i < size; i++)
        {
            c[i] += a[i] + b[i];
            c[i + 1] = c[i] / 10;
            c[i] %= 10;
        }
        string ret;
        int flag = 0;
        for (int i = size; i >= 0; i--)
        {
            if (flag == 0 && c[i] == 0)
            {
                continue;
            }
            else
            {
                flag = 1;
                ret += c[i] + '0';
            }
        }
        return ret;
    }
};

int main()
{
    string num1, num2;
    cin >> num1 >> num2;
    cout << Solution().addStrings(num1, num2) << endl;
    return 0;
}