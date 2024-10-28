#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
	int begin, end, value;
}n[1000010];
int p[1010];
int dp[1010];

bool cmp(node x, node y)
{
	return x.end < y.end;
}

int main()
{
	int N, M, R;
	cin >> N >> M >> R;
	for (int i = 1; i <= M; i++)
		cin >> n[i].begin >> n[i].end >> n[i].value, n[i].end += R;

	sort(n + 1, n + M + 1, cmp);

	for (int i = M; i >= 1; i--)
		for (int j = i - 1; j >= 1; j--)
			if (n[j].end <= n[i].begin)
			{
				p[i] = j;
				break;
			}

	for (int i = 1; i <= M; i++)
	{
		dp[i] = max(dp[p[i]] + n[i].value, dp[i - 1]);
	}

	cout << dp[M] << endl;

	return 0;
}

/*
12 4 2
1 2 8
10 12 19
3 6 24
7 10 31
*/