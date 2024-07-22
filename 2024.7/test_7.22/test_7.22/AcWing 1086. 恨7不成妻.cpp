#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;

const int N = 20, P = 1e9 + 7;

struct F//预处理出i位，最高位为j，%7余a，和%7为b的数的个数、和、平方和
{
    int s0, s1, s2;
}f[N][10][7][7];

int mod(LL x, int y)
{
    return (x % y + y) % y;
}

int power7[N], power9[N];//10的i次方%7和10的i次方%P

void init()
{
    for (int j = 0; j <= 9; j++)//一位数的情况下符合条件的数
        if (j != 7)
        {
            auto& v = f[1][j][j % 7][j % 7];
            v.s0++;
            v.s1 += j;
            v.s2 += j * j;
        }

    LL power = 10;
    for (int i = 2; i < N; i++, power *= 10)
        for (int j = 0; j <= 9; j++)
        {
            if (j == 7) continue;
            for (int a = 0; a < 7; a++)
                for (int b = 0; b < 7; b++)
                    for (int k = 0; k <= 9; k++)
                    {
                        if (k == 7) continue;
                        auto& v1 = f[i][j][a][b], & v2 = f[i - 1][k][mod(a - j * power, 7)][mod(b - j, 7)];

                        v1.s0 = mod(v1.s0 + v2.s0, P);
                        v1.s1 = mod(v1.s1 + j * (power % P) % P * v2.s0 % P + v2.s1, P);
                        v1.s2 = mod(v1.s2 +
                            j * j * (power % P) % P * (power % P) % P * v2.s0 % P +
                            2 * j * power % P * v2.s1 % P +
                            v2.s2
                            , P);
                    }
        }

    power7[0] = power9[0] = 1;
    for (int i = 1; i < N; i++)
    {
        power7[i] = power7[i - 1] * 10 % 7;
        power9[i] = power9[i - 1] * 10ll % P;
    }
}

F get(int i, int j, int a, int b)
{
    int s0 = 0, s1 = 0, s2 = 0;
    for (int x = 0; x < 7; x++)
        for (int y = 0; y < 7; y++)
        {
            if (x == a || y == b) continue;
            auto& v = f[i][j][x][y];
            s0 = (s0 + v.s0) % P;
            s1 = (s1 + v.s1) % P;
            s2 = (s2 + v.s2) % P;
        }
    return { s0, s1, s2 };
}

int dp(LL n)
{
    if (n == 0) return 0;

    LL backup_n = n % P;
    vector<int> nums;
    while (n) nums.push_back(n % 10), n /= 10;

    LL last_a = 0, last_b = 0;
    int res = 0;

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        int x = nums[i];
        for (int j = 0; j < x; j++)
        {
            if (j == 7) continue;
            int a = mod(-last_a * power7[i + 1], 7);
            int b = mod(-last_b, 7);

            auto v = get(i + 1, j, a, b);
            res = (res +
                (last_a % P) * (last_a % P) % P * (power9[i + 1] % P) % P * (power9[i + 1] % P) % P * v.s0 % P +
                2 * (last_a % P) % P * (power9[i + 1] % P) % P * v.s1 % P +
                v.s2
                ) % P;
        }

        if (x == 7) break;

        last_a = last_a * 10 + x;
        last_b += x;

        if (i == 0 && last_a % 7 && last_b % 7) res = (res + backup_n * backup_n) % P;
    }

    return res;
}

int main()
{
    init();
    int T;
    cin >> T;
    while (T--)
    {
        LL l, r;
        cin >> l >> r;
        cout << mod(dp(r) - dp(l - 1), P) << endl;
    }

    return 0;
}