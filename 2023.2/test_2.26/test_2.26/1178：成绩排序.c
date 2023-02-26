#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stu
{
	char name[20];
	int score;
}a[20];
int cmp(const void* e1, const void* e2)
{
	struct stu* a = (struct stu*)e1;
	struct stu* b = (struct stu*)e2;
	if (a->score == b->score)
		return strcmp(a->name, b->name);
	return b->score - a->score;
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%s%d", a[i].name, &a[i].score);
	qsort(a + 1, n, sizeof(struct stu), cmp);
	for (int i = 1; i <= n; i++)
		printf("%s %d\n", a[i].name, a[i].score);
	return 0;
}