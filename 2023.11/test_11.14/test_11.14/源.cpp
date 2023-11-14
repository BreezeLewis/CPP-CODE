#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution
{
public:
    int numDecodings(string s)
    {
        if (s.size() == 1)
            return (s[0] - '0') == 0 ? 0 : 1;
        int n = s.size();
        vector<int> dp(n, 0);
        if (s[0] != '0')
            dp[0] = 1;
        //先对s[1]单独解码
        int num = s[1] - '0';
        if (num != 0)//单独解码成功
            dp[1] += dp[0];
        //对s[0],s[1]一起解码
        num = (s[0] - '0') * 10 + num;
        if (num >= 10 && num <= 26)//一起解码成功
            dp[1]++;

        for (int i = 2; i < n; i++)
        {
            //对s[i]单独解码
            num = s[i] - '0';
            if (num != 0)//s[i]单独解码成功
                dp[i] += dp[i - 1];
            //对s[i - 1]s[i]一起解码
            num = (s[i - 1] - '0') * 10 + num;
            if (num >= 10 && num <= 26)
                dp[i] += dp[i - 2];
        }
        return dp[n - 1];
    }
};


int main()
{
    cout << Solution().numDecodings("2101") << endl;

    return 0;
}