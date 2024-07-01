#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

const int N = 12, M = 1 << 10, K = 110;

int n, m;
vector<int> state;
int cnt[M];
vector<int> head[M];
LL f[N][K][M];

bool check(int state)
{
    for (int i = 0; i < n; i++)
        if ((state >> i & 1) && (state >> i + 1 & 1))
            return false;
    return true;
}

int count(int state)
{
    int res = 0;
    for (int i = 0; i < n; i++)
        if (state >> i & 1) res++;
    return res;
}

int main()
{
    cin >> n >> m;

    //先预处理出所有的合法状态到state中
    for (int i = 0; i < 1 << n; i++)
        if (check(i))
        {
            state.push_back(i);
            cnt[i] = count(i);
        }

    //把每个状态能够相邻的状态处理出来
    for (int i = 0; i < state.size(); i++)
        for (int j = 0; j < state.size(); j++)
        {
            int a = state[i], b = state[j];
            if ((a & b) == 0 && check(a | b))
                head[i].push_back(j);
        }

    f[0][0][0] = 1;//没有国王没有状态，只有一种方案，就是什么都不放

    for (int i = 1; i <= n + 1; i++)
        for (int j = 0; j <= m; j++)
            for (int a = 0; a < state.size(); a++)
                for (int b = 0; b < head[a].size(); b++)
                {
                    int c = cnt[state[a]];
                    if (j >= c)
                        f[i][j][state[a]] += f[i - 1][j - c][state[head[a][b]]];
                }

    cout << f[n + 1][m][0] << endl;

    return 0;
}