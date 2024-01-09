#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct cow
{
	int begin, end, id;
}c[100000];

bool cmp(cow x, cow y)
{
	return x.begin < y.begin;
}

struct Greater
{
	bool operator()(pair<int, int> x, pair<int, int> y)
	{
		if (x.first == y.first)
			return x.second > y.second;
		return x.first > y.first;
	}
};

int res[100000];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		c[i].id = i;
		cin >> c[i].begin >> c[i].end;
	}

	sort(c + 1, c + 1 + n, cmp);

	priority_queue<pair<int, int>, vector<pair<int, int>>, Greater> pq;


	for (int i = 1; i <= n; i++)
	{
		if (pq.empty() || pq.top().first >= c[i].begin)
		{
			res[c[i].id] = (int)pq.size() + 1;
			pq.push(make_pair(c[i].end, (int)pq.size() + 1));
		}
		else
		{
			auto ret = pq.top();
			pq.pop();
			ret.first = c[i].end;
			res[c[i].id] = ret.second;
			pq.push(ret);
		}
	}

	cout << pq.size() << endl;
	
	for (int i = 1; i <= n; i++)
		cout << res[i] << endl;

	return 0;
}