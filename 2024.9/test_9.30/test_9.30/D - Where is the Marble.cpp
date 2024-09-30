#include <iostream>
#include <algorithm>

using namespace std;

const int N = (int)1e4 + 10;

int a[N];

int main()
{
	int n, q, cnt = 0;

	while (scanf("%d%d", &n, &q) && n && q)
	{
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);

		cnt++;

		printf("CASE# %d:\n", cnt);
		while (q--)
		{
			int tmp; 
			scanf("%d", &tmp);

			int pos = lower_bound(a, a + n, tmp) - a;
			if (a[pos] == tmp) printf("%d found at %d\n", tmp, pos + 1);
			else printf("%d not found\n", tmp);
		}
	}

	return 0;
}