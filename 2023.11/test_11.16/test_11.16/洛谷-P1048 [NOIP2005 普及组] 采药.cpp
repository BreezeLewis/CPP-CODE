#include <iostream>
#include <algorithm>
using namespace std;

int dp[101][1001];//
int T, M;
int cost[101];
int value[101];
int main()
{
	cin >> T >> M;

	for (int i = 1; i <= M; i++)
		cin >> cost[i] >> value[i];

	for (int i = 1; i <= M; i++)
		for (int j = 0; j <= T; j++)
		{
			if (j >= cost[i])
				dp[i][j] = max(dp[i - 1][j - cost[i]] + value[i], dp[i - 1][j]);
			else
				dp[i][j] = dp[i - 1][j];
		}

	cout << dp[M][T] << endl;

	return 0;
}