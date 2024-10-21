#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = (int)5e4 + 10;

struct cow
{
	int begin, end, index;
}cows[N];

bool cmp(cow x, cow y)
{
	return x.begin < y.begin;
}

int res[N];

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> cows[i].begin >> cows[i].end;
		cows[i].index = i;
	}

	priority_queue<PII, vector<PII>, greater<PII>> heap;
	sort(cows, cows + n, cmp);

	for (int i = 0; i < n; i++)
	{
		cow tmp = cows[i];
		if (heap.empty() || heap.top().first >= tmp.begin)
		{
			PII stall;
			stall.first = tmp.end;
			stall.second = (int)heap.size() + 1;
			res[cows[i].index] = stall.second;
			heap.push(stall);
		}
		else
		{
			PII stall = heap.top();
			heap.pop();
			stall.first = tmp.end;
			res[cows[i].index] = stall.second;
			heap.push(stall);
		}
	}

	cout << heap.size() << endl;

	for (int i = 0; i < n; i++)
		cout << res[i] << endl;

	return 0;
}