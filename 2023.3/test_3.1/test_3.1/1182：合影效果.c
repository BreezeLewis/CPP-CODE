#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp1(const void* e1, const void* e2)
{
	double a = *(double*)e1;
	double b = *(double*)e2;
	if (a > b)
		return 1;
	else if (a == b)
		return 0;
	else
		return -1;
}
int cmp2(const void* e1, const void* e2)
{
	double a = *(double*)e1;
	double b = *(double*)e2;
	if (a > b)
		return -1;
	else if (a == b)
		return 0;
	else
		return 1;
}
int main()
{
	int n;
	scanf("%d", &n);
	double male[40] = { 0 };
	double female[40] = { 0 };
	int len1 = 0, len2 = 0;
	double height;
	char sex[20];
	for (int i = 1; i <= n; i++)
	{
		scanf("%s%lf", sex, &height);
		if (strcmp(sex, "male") == 0)
		{
			male[len1++] = height;
		}
		else
		{
			female[len2++] = height;
		}
	}
	qsort(male, len1, sizeof(double), cmp1);
	qsort(female, len2, sizeof(double), cmp2);
	for (int i = 0; i < len1; i++)
		printf("%.2lf ", male[i]);
	for (int i = 0; i < len2; i++)
		printf("%.2lf ", female[i]);
	return 0;
}