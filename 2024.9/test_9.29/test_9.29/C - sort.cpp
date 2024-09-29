#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

int a[1000001];
int n, m;
int main()
{
	while (~scanf("%d%d", &n, &m)) 
	{
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

		sort(a + 1, a + n + 1);

		for (int i = n; i >= n - m + 1; i--)
			if (i == n - m + 1) printf("%d\n", a[i]);
			else printf("%d ", a[i]);
	}

	return 0;
}