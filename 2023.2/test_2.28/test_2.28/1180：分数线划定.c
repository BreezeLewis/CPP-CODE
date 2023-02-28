#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//struct node
//{
//	int id;
//	int score;
//}a[5001];
//int cmp(const void* e1, const void* e2)
//{
//	struct node* a = (struct node*)e1;
//	struct node* b = (struct node*)e2;
//	if (a->score == b->score)
//		return a->id - b->id;
//	return b->score - a->score;
//}
//int main()
//{
//	int n, m, rank, line, ans = 0;
//	scanf("%d%d", &n, &m);
//	rank = (int)(m * 1.5);
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%d%d", &a[i].id, &a[i].score);
//	}
//	qsort(a + 1, n, sizeof(struct node), cmp);
//	line = a[rank].score;
//	for (int i = 1; i <= n; i++)
//	{
//		if (a[i].score >= line)
//			ans++;
//	}
//	printf("%d %d\n", line, ans);
//	for (int i = 1; i <= ans; i++)
//		printf("%d %d\n", a[i].id, a[i].score);
//	return 0;
//}