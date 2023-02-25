#define _CRT_SECURE_NO_WARNINGS
//1176
#include <stdio.h>
#include <stdlib.h>
typedef struct stu
{
	int num;
	double grade;
	struct stu* next;
}stu;
stu* Init(int n)
{
	stu* obj = NULL;
	stu* tail = obj;
	for (int i = 0; i < n; i++)
	{
		stu* node = (stu*)malloc(sizeof(stu) * n);
		node->next = NULL;
		scanf("%d%lf", &(node->num), &(node->grade));
		if (obj == NULL)
		{
			obj = tail = node;
		}
		else
		{
			tail->next = node;
			tail = node;
		}
	}
	return obj;
}
void nodeSwap(stu* a, stu* b)
{
	int ret = a->num; double tmp = a->grade;
	a->num = b->num; a->grade = b->grade;
	b->num = ret; b->grade = tmp;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int k = 0;
	scanf("%d", &k);
	stu* obj = Init(n);
	stu* list = obj;
	stu** arr = (stu**)malloc(sizeof(stu*) * n);
	for (int i = 0; i < n; i++)
	{
		arr[i] = list;
		list = list->next;
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j]->grade < arr[j + 1]->grade)
			{
				nodeSwap(arr[j], arr[j + 1]);
			}
		}
	}
	list = obj;
	for (int i = 0; i < k - 1; i++)
	{
		list = list->next;
	}
	printf("%d %g\n", list->num, list->grade);
	return 0;
}