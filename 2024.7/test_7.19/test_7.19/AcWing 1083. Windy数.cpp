#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

const int N = 11;

int f[N][10];//f[i][j]表示填i位数，最高位是j的方法数

void init()
{
    for (int i = 0; i <= 9; i++) f[1][i] = 1;

    for (int i = 2; i <= N; i++)
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k <= 9; k++)
                if (abs(j - k) >= 2)
                    f[i][j] += f[i - 1][k];
}

int dp(int n)
{
    if (n == 0) return 0;

    vector<int> nums;
    while (n) nums.push_back(n % 10), n /= 10;

    int res = 0, last = -2;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        int x = nums[i];

        for (int j = i == nums.size() - 1; j < x; j++)
            if (abs(last - j) >= 2)
                res += f[i + 1][j];

        if (abs(x - last) < 2) break;

        last = x;

        if (!i) res++;
    }

    for (int i = 1; i < nums.size(); i++)
        for (int j = 1; j <= 9; j++)
            res += f[i][j];

    return res;
}

int main()
{
    init();
    int l, r;
    cin >> l >> r;

    cout << dp(r) - dp(l - 1) << endl;

    return 0;
}