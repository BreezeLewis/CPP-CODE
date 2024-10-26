/*
70 3
71 100
69 1
1 2
*/
#include <iostream>
#include <algorithm>
using namespace std;

struct herb
{
	int cost, value;
}hb[110];

int dp[110][1100];

int main()
{
	int T, M;
	cin >> T >> M;
	for (int i = 1; i <= M; i++)
		cin >> hb[i].cost >> hb[i].value;

	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= T; j++)
		{
			if (j >= hb[i].cost)
				dp[i][j] = max(dp[i - 1][j - hb[i].cost] + hb[i].value, dp[i - 1][j]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[M][T] << endl;

	return 0;
}