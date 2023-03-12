#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int n, x;
int a[1000010];
int pell(int x)
{
	if (a[x])
		return a[x];
	
	a[x] = (2 * pell(x - 1) + pell(x - 2)) % 32767;
	
	return a[x];
}
int main()
{
	scanf("%d", &n);
	a[1] = 1, a[2] = 2;
	while (n--)
	{
		scanf("%d", &x);
		printf("%d\n", pell(x));
	}
	return 0;
}