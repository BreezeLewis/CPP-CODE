#include <iostream>
#include <vector>

using namespace std;

const int N = 11;

int f[N][10];

void init()
{
    for (int j = 0; j <= 9; j++)
        if (j != 4)
            f[1][j] = 1;

    for (int i = 2; i < N; i++)
        for (int j = 0; j <= 9; j++)
        {
            if (j == 4) continue;
            for (int k = 0; k <= 9; k++)
            {
                if (k == 4 || j == 6 && k == 2) continue;
                f[i][j] += f[i - 1][k];
            }
        }
}

int dp(int n)
{
    if (n == 0) return 1;

    vector<int> nums;
    while (n) nums.push_back(n % 10), n /= 10;

    int res = 0, last = 0;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        int x = nums[i];
        for (int j = 0; j < x; j++)
        {
            if (j == 4 || last == 6 && j == 2) continue;
            res += f[i + 1][j];
        }

        if (x == 4 || last == 6 && x == 2) break;

        last = x;

        if (i == 0) res++;
    }

    return res;
}

int main()
{
    init();
    int l, r;
    while (cin >> l >> r, l, r)
    {
        cout << dp(r) - dp(l - 1) << endl;
    }

    return 0;
}