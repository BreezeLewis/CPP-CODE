#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	char s[2000] = { 0 };
	int a[26] = { 0 };
	scanf("%s", s);
	for (int i = 0; s[i]; i++)
	{
		a[s[i] - 'a']++;
	}
	int maxi = 0;
	for (int i = 1; i < 26; i++)
	{
		if (a[i] > a[maxi])
			maxi = i;
	}
	printf("%c %d", maxi + 'a', a[maxi]);
	return 0;
}