#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int N = 11, M = 110;

int P;
int f[N][10][M];

int mod(int x, int y)
{
    return (x % y + y) % y;
}

void init()
{
    memset(f, 0, sizeof f);
    for (int j = 0; j <= 9; j++) f[1][j][j % P]++;

    for (int i = 2; i < N; i++)
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k < P; k++)
                for (int x = 0; x <= 9; x++)
                    f[i][j][k] += f[i - 1][x][mod(k - j, P)];
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
            res += f[i + 1][j][mod(-last, P)];

        last += x;

        if (i == 0 && last % P == 0) res++;
    }

    return res;
}

int main()
{
    int l, r;
    while (cin >> l >> r >> P)
    {
        init();

        cout << dp(r) - dp(l - 1) << endl;
    }

    return 0;
}