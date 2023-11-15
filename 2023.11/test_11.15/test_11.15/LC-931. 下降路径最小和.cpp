#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        int n = (int)matrix.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1));

        for (int j = 1; j <= n; j++)
            dp[1][j] = matrix[0][j - 1];

        for (int i = 2; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (j == 1)
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + 1]) + matrix[i - 1][j - 1];
                else if (j == n)
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + matrix[i - 1][j - 1];
                else
                    dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i - 1][j + 1]) + matrix[i - 1][j - 1];

        int minx = 120;
        for (int j = 1; j <= n; j++)
            minx = min(minx, dp[n][j]);

        return minx;
    }
};

int main()
{
    vector<vector<int>> matrix = { {2, 1, 3} ,{6, 5, 4},{7, 8, 9} };

    Solution().minFallingPathSum(matrix);

    return 0;
}