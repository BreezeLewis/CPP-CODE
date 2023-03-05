#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int fib[1000001], n, k;
int main()
{
	fib[1] = 1, fib[2] = 1;
	for (int i = 3; i <= 1000000; i++)
		fib[i] = (fib[i - 1] + fib[i - 2]) % 1000;
	scanf("%d", &k);
	while (k--)
	{
		scanf("%d", &n);
		printf("%d\n", fib[n]);
	}
	return 0;
}