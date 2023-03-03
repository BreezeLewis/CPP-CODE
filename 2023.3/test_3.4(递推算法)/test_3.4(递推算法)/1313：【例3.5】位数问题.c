#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int n, odd[1001], even[1001];
int main()
{
	scanf("%d", &n);
	odd[1] = 1; even[1] = 9;
	int tmp = 9;
	for (int i = 2; i <= n; i++)
	{
		if (i == n)
			tmp--;
		even[i] = (even[i - 1] * tmp + odd[i - 1]) % 12345;
		odd[i] = (even[i - 1] + odd[i - 1] * tmp) % 12345;
	}
	printf("%d\n", even[n]);
	return 0;
}