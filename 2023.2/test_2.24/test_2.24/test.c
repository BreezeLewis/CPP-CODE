#define _CRT_SECURE_NO_WARNINGS
//1310
//#include <stdio.h>
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr[10000] = { 0 };
//	for (int i = 0; i < n; i++)
//		scanf("%d", &arr[i]);
//	int count = 0;
//	for (int i = 0; i < n - 1; i++)
//	{
//		for (int j = 0; j < n - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				count++;
//			}
//		}
//	}
//	printf("%d\n", count);
//	return 0;
//}

//1311
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//void _MergeSort(int* a, int left, int right, int* tmp, int* count)
//{
//	if (left >= right)
//		return;
//	int mid = (left + right) / 2;
//	//[left,mid][mid+1,right]
//	_MergeSort(a, left, mid, tmp, count);
//	_MergeSort(a, mid + 1, right, tmp, count);
//	int begin1 = left, end1 = mid;
//	int begin2 = mid + 1, end2 = right;
//	int i = left;
//	while (begin1 <= end1 && begin2 <= end2)
//	{
//		if (a[begin1] <= a[begin2])
//			tmp[i++] = a[begin1++];
//		else
//		{
//			tmp[i++] = a[begin2++];
//			*count += (mid - begin1 + 1);
//		}
//	}
//	while (begin1 <= end1)
//		tmp[i++] = a[begin1++];
//	while (begin2 <= end2)
//		tmp[i++] = a[begin2++];
//	memcpy(a + left, tmp + left, sizeof(int) * (right - left + 1));
//}
//void MergeSort(int* a, int n, int* count)
//{
//	int* tmp = (int*)malloc(sizeof(int) * n);
//	if (tmp == NULL)
//	{
//		perror("malloc fail");
//		exit(-1);
//	}
//	_MergeSort(a, 0, n - 1, tmp, count);
//
//	free(tmp);
//	tmp = NULL;
//}
void _MergeSort(int* a, int left, int right, int* tmp, long long* count)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	//[left,mid][mid+1,right]
	_MergeSort(a, left, mid, tmp, count);
	_MergeSort(a, mid + 1, right, tmp, count);
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int i = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] <= a[begin2])
			tmp[i++] = a[begin1++];
		else
		{
			tmp[i++] = a[begin2++];
			*count += (mid - begin1 + 1);
		}
	}
	while (begin1 <= end1)
		tmp[i++] = a[begin1++];
	while (begin2 <= end2)
		tmp[i++] = a[begin2++];
	memcpy(a + left, tmp + left, sizeof(int) * (right - left + 1));
}
long long reversePairs(int* nums, int numsSize) {
	long long count = 0;
	int n = numsSize;
	int* a = nums;
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	_MergeSort(a, 0, n - 1, tmp, &count);

	free(tmp);
	tmp = NULL;
	return count;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int arr[100000] = { 0 };
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	//¹é²¢ÅÅÐò
	long long count = reversePairs(arr, n);
	printf("%lld\n", count);
	return 0;
}