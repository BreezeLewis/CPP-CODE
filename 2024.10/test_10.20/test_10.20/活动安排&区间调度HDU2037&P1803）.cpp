#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

struct TV
{
	int begin, end;
}tv[N];

bool cmp(TV x, TV y)
{
	return x.end < y.end;
}

int main()
{
	int n;

	while (cin >> n && n)
	{
		for (int i = 0; i < n; i++) cin >> tv[i].begin >> tv[i].end;

		sort(tv, tv + n, cmp);

		int res = 1;
		int tmp = 0;

		for (int i = 1; i < n; i++)
			if (tv[i].begin >= tv[tmp].end) res++, tmp = i;

		cout << res << endl;
	}
}