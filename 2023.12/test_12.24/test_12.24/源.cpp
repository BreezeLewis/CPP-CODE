#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
3 4
1
2
1
3
0 5 1
5 0 2
1 2 0
*/

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> path(m, 0);
	for (int i = 0; i < m; i++)
		cin >> path[i];

	vector<vector<int>> dp(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> dp[i][j];

	for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)			
				dp[i][j] = min(dp[i][k] + dp[k][j], dp[i][j]);
			
	int ans = 0;

	for (int i = 1; i < m; i++)
		ans += dp[path[i - 1] - 1][path[i] - 1];

	cout << ans << endl;

	return 0;
}