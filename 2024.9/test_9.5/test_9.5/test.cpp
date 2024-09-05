#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 510;

int a[N][N];
int dp[N][N];

int main()
{
	int n, m;
	cin >> n >> m;

	memset(dp, -0x3f, sizeof dp);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];

	if (a[1][1] == 1) dp[1][1] = -1;
	else if (a[1][1] == 2) dp[1][1] = 1;
	else dp[1][1] = 0;

	for (int i = 2; i <= m; i++)
	{
		int v = a[1][i];
		if (v == 0) dp[1][i] = dp[1][i - 1];
		else if (v == 1) dp[1][i] = dp[1][i - 1] - 1;
		else dp[1][i] = dp[1][i - 1] + 1;
	}

	for (int i = 2; i <= n; i++)
	{
		int v = a[i][1];
		if (v == 0) dp[i][1] = dp[i - 1][1];
		else if (v == 1) dp[i][1] = dp[i - 1][1] - 1;
		else dp[i][1] = dp[i - 1][1] + 1;
	}

	for (int i = 2; i <= n; i++)
		for (int j = 2; j <= m; j++)
		{
			int v = a[i][j];
			if (v == 0) dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			else if (v == 1) dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) - 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + 1;
		}

	cout << dp[n][m] << endl;

	return 0;
}