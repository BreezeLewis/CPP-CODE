#include <iostream>
#include <algorithm>

using namespace std;

const int N = 9, M = 1 << N;

int ones[M], map[M];
int row[N], col[N], cell[3][3];
char str[100];

void init()
{
    for (int i = 0; i < N; i++)
        row[i] = col[i] = (1 << N) - 1;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cell[i][j] = (1 << N) - 1;
}

void draw(int i, int j, int t, bool is_set)
{
    if (is_set) str[i * N + j] = '1' + t;
    else str[i * N + j] = '.';

    int v = 1 << t;
    if (!is_set) v = -v;

    row[i] -= v;
    col[j] -= v;
    cell[i / 3][j / 3] -= v;
}

int get(int i, int j)
{
    return row[i] & col[j] & cell[i / 3][j / 3];
}

int lowbit(int x)
{
    return x & -x;
}

bool dfs(int cnt)
{
    if (cnt == 0) return true;

    int minv = 10;
    int x, y;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (str[i * N + j] == '.')
            {
                int state = get(i, j);
                if (ones[state] < minv)
                {
                    minv = ones[state];
                    x = i, y = j;
                }
            }

    int state = get(x, y);

    for (int i = state; i; i -= lowbit(i))
    {
        int t = map[lowbit(i)];
        draw(x, y, t, true);
        if (dfs(cnt - 1)) return true;
        draw(x, y, t, false);
    }

    return false;
}

int main()
{
    for (int i = 0; i < N; i++) map[1 << i] = i;//对2^0~2^8求以2为底的对数，即这些数第几位有1

    for (int i = 0; i < 1 << N; i++)
        for (int j = 0; j < N; j++)
            ones[i] += i >> j & 1;//预处理每个数有多少个1，这些数为000000000~111111111

    while (cin >> str, str[0] != 'e')
    {
        init();

        int cnt = 0;
        for (int i = 0, k = 0; i < N; i++)
            for (int j = 0; j < N; j++, k++)
                if (str[k] != '.')
                {
                    int t = str[k] - '1';
                    draw(i, j, t, true);
                }
                else cnt++;
        dfs(cnt);

        puts(str);
    }

    return 0;
}