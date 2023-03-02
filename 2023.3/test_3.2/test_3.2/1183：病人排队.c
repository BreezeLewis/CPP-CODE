#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//struct node
//{
//	int age;
//	char ID[20];
//	int sequence;
//}a[101];
//int cmp1(const void* e1, const void* e2)
//{
//	int a = ((struct node*)e1)->age;
//	int b = ((struct node*)e2)->age;
//	return b - a;
//}
//int cmp2(const void* e1, const void* e2)
//{
//	int a = ((struct node*)e1)->sequence;
//	int b = ((struct node*)e2)->sequence;
//	return a - b;
//}
//int main()
//{
//	int n, old = 0;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		scanf("%s%d", a[i].ID, &a[i].age);
//		if (a[i].age >= 60)
//			old++;
//		a[i].sequence = i;
//	}
//	qsort(a + 1, n, sizeof(struct node), cmp1);//按年龄从大到小排
//	qsort(a + old + 1, n - old, sizeof(struct node), cmp2);//非老年人按登记顺序从小到大排
//	for (int i = 1; i <= n; i++)
//		printf("%s\n", a[i].ID);
//	return 0;
//}