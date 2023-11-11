#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;

const int N = (int)1e6 + 10;

struct node
{
	int begin;
	int end;
	int id;
	int place;
};
node cow[50010];

int n;

struct Greater
{
	bool operator()(node x, node y)
	{
		return x.end > y.end;
	}
};

//bool cmp(node x, node y)
//{
//	return x.begin < y.begin;
//}
//
//bool cmp_id(node x, node y)
//{
//	return x.id < y.id;
//}

int main()
{
	priority_queue<node, vector<node>, Greater> pq;

	int cnt = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		//cin >> cow[i].begin >> cow[i].end;
		scanf("%d%d", &cow[i].begin, &cow[i].end);
		cow[i].id = i;
	}

	sort(cow + 1, cow + n + 1, cmp);

	for (int i = 1; i <= n; i++)
	{
		if (pq.empty() || pq.top().end >= cow[i].begin)
		{//自立门户
			cnt++;
			cow[i].place = cnt;
			pq.push(cow[i]);
		}
		else
		{
			cow[i].place = pq.top().place;
			pq.pop();
			pq.push(cow[i]);
		}
	}

	cout << cnt << endl;

	sort(cow + 1, cow + n + 1, cmp_id);
	for (int i = 1; i <= n; i++)
	{
		//cout << cow[i].place << endl;
		printf("%d\n", cow[i].place);
	}

	return 0;
}


/*
5
1 10
2 4
3 6
5 8
4 7
*/