#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
	int start;
	int end;
};

bool cmp(node x, node y)
{
	return x.end < y.end;
}

const int N = (int)1e6 + 10;

node a[N];

int n;

int main()
{
	cin >> n;
	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i].start >> a[i].end;
	}

	sort(a, a + n, cmp);

	int time = 0;

	for (int i = 0; i < n; i++)
	{
		if (time <= a[i].start)
		{
			time = a[i].end;
			cnt++;
		}
		else
		{
			continue;
		}
	}

	cout << cnt << endl;

	return 0;
}