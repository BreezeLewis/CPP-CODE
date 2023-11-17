#include <iostream>
#include <algorithm>
using namespace std;

int N, M, R;
struct node
{
	int begin, end;
	int gallon;
};
node cow[1001];

int dp[1001];
int p[1001];

bool cmp(node x, node y)
{
	return x.end < y.end;
}

int main()
{
	cin >> N >> M >> R;
	for (int i = 1; i <= M; i++)
		cin >> cow[i].begin >> cow[i].end >> cow[i].gallon, cow[i].end += R;

	sort(cow + 1, cow + M + 1, cmp);

	
	//for (int i = 1; i <= M; i++)
	//{
	//	int left = 1, right = i;
	//	while (left < right)
	//	{
	//		int mid = (left + right) >> 1;

	//		if (cow[mid].end <= cow[right].begin && cow[mid + 1].end > cow[right].begin)//ур╣╫ак
	//		{
	//			p[i] = mid;
	//			break;
	//		}
	//		else
	//			left = mid + 1;
	//	}
	//	//if (p[i] == 0) p[i] = left;
	//}

	for (int i = M; i >= 1; i--)
	{
		for (int j = i - 1; j > 0; j--)
		{
			if (cow[j].end <= cow[i].begin)
			{
				p[i] = j;
				break;
			}
		}
	}

	for (int i = 1; i <= M; i++)
	{
		dp[i] = max(dp[p[i]] + cow[i].gallon, dp[i - 1]);
	}

	cout << dp[M] << endl;

	return 0;
}