#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a[101], vis[1001] = { 0 }, n, ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if (!vis[a[i]])
		{
			vis[a[i]] = 1;
			ans++;
		}
	}
	printf("%d\n", ans);
	for (int i = 1; i <= 1000; i++)
	{
		if (vis[i])
			printf("%d ", i);
	}
	return 0;
}