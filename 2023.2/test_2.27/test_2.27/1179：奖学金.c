#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
struct stu
{
	int id;
	int chinese;
	int math;
	int english;
	int sum;
}a[301];
int cmp(const void* e1, const void* e2)
{
	struct stu* a = (struct stu*)e1;
	struct stu* b = (struct stu*)e2;
	if (a->sum != b->sum)
	{
		return -(a->sum - b->sum);
	}
	else if (a->chinese != b->chinese)
	{
		return -(a->chinese - b->chinese);
	}
	else
	{
		return a->id - b->id;
	}

}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		a[i].id = i;
		scanf("%d%d%d", &a[i].chinese, &a[i].math, &a[i].english);
		a[i].sum = a[i].chinese + a[i].math + a[i].english;
	}
	qsort(a + 1, n, sizeof(struct stu), cmp);
	if (n < 5)
		for (int i = 1; i <= n; i++)
			printf("%d %d\n", a[i].id, a[i].sum);
	else
		for (int i = 1; i <= 5; i++)
			printf("%d %d\n", a[i].id, a[i].sum);
	return 0;
}