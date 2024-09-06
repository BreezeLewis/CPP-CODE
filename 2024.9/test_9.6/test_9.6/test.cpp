#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10010;

int dp[N];
int n, m;

int main()
{
	cin >> n >> m;

	while (m--)
	{
		int v, w, z;
		cin >> v >> w >> z;

		if (z == 0)
			for (int i = v; i <= n; i++)
				dp[i] = max(dp[i], dp[i - v] + w);
		else
			for (int i = n; i >= v; i--)
				dp[i] = max(dp[i], dp[i - v] + w);
	}

	cout << dp[n] << endl;

	return 0;
}