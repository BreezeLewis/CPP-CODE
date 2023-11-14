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
        //�ȶ�s[1]��������
        int num = s[1] - '0';
        if (num != 0)//��������ɹ�
            dp[1] += dp[0];
        //��s[0],s[1]һ�����
        num = (s[0] - '0') * 10 + num;
        if (num >= 10 && num <= 26)//һ�����ɹ�
            dp[1]++;

        for (int i = 2; i < n; i++)
        {
            //��s[i]��������
            num = s[i] - '0';
            if (num != 0)//s[i]��������ɹ�
                dp[i] += dp[i - 1];
            //��s[i - 1]s[i]һ�����
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