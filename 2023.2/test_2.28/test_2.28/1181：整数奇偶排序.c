#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int cmp1(const void* e1, const void* e2)
{
	int a = *(int*)e1;
	int b = *(int*)e2;
	return b - a;
}
int cmp2(const void* e1, const void* e2)
{
	int a = *(int*)e1;
	int b = *(int*)e2;
	return a - b;
}
int main()
{
	int odd[10] = { 0 }, even[10] = { 0 };
	int len1 = 0, len2 = 0;
	int x;
	for (int i = 1; i <= 10; i++)
	{
		scanf("%d", &x);
		if (x % 2 == 1)
			odd[len1++] = x;
		else
			even[len2++] = x;
	}
	qsort(odd, len1, sizeof(int), cmp1);
	qsort(even, len2, sizeof(int), cmp2);
	for (int i = 0; i < len1; i++)
		printf("%d ", odd[i]);
	for (int i = 0; i < len2; i++)
		printf("%d ", even[i]);
	return 0;
}