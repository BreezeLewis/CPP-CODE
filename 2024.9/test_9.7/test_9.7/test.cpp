#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010, M = 10010 * 2;
int h[N], e[M], w[M], ne[M], idx;
int dp[N][M];

void add(int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int main()
{
	int n, m, t; // 点，花费时间，边
	cin >> n >> m >> t;

	memset(h, -1, sizeof h);
	memset(dp, -0x3f, sizeof dp);

	dp[1][0] = 1;

	while (t--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
		add(b, a, c);
	}

	for (int i = 0; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if (dp[j][i] != -0x3f3f3f3f)
				for (int k = h[j]; k != -1; k = ne[k])
				{
					int to = e[k], time = w[k];

					if (i + time <= m)
						dp[to][i + time] = max(dp[to][i + time], dp[j][i] + 1);
				}

	int ans = dp[n][m];
	if (ans == -0x3f3f3f3f) puts("-1");
	else cout << ans << endl;


	return 0;

}