#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//计算n的阶乘   //计算从1到n的阶乘之和
//int main()
//{
//	int n = 0, f = 1, i = 0, sum = 0;
//	scanf("%d", &n);
//	for (i= n-1;i >= 0; i-- )
//	{
//		f = 1;
//		for (; n > 0; n--)
//		{
//			f *= n;
//		}
//		sum += f;
//		n = i;
//	}
//	
//	printf("%d", sum);
//	return 0;
//}
//int main()
//{
//	int i = 0, n = 0, ret = 1, sum = 0;
//	for (n = 1; n <= 10; n++)
//	{
//		ret = 1;
//		for (i = 1; i <= n; i++)
//		{
//			ret *= i;
//		}
//		sum += ret;
//	}
//	printf("%d", sum);
//	return 0;
//}
//int main()
//{
//	int ret = 1, sum = 0, n = 0;
//		for (n = 1; n <= 10; n++)
//		{
//			ret *= n;
//			sum += ret;
//		}
//		printf("%d", sum);
//	return 0;
//}
//int main()//有序数组中具体查找某个数据k
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	           // 0 1 2 3 4 5 6 7 8 9  
//	int k = 7;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;
//	int right = sz-1;
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			printf("找到了，下标：%d\n", mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("找不到\n");
//	}
//
//	return 0;
//}
//#include<string.h>
//#include<windows.h>
//int main()
//{
//	char arr1[] = "welcome to ikun's world";
//	char arr2[] = "#######################";
//	int left = 0;
//	int right = strlen(arr1) - 1;
//	while(left<=right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		Sleep(1000);
//		system("cls");
//		left++; right--;
//		
//	}
//	printf("%s\n", arr2);
//	return 0;
//}
//#include<string.h>
//int main()
//{
//	char password[20] = { 0 };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("请输入密码：");
//		scanf("%s", password);
//		if (strcmp(password, "123456") == 0)
//		{
//			printf("登录成功\n");
//			break;
//		}
//		else
//		{
//			printf("密码错误，重新输入\n");
//		}
//		if (i == 3)
//			printf("三次密码均错误，退出程序\n");
//	}
//	return 0;
//}
//#include<math.h>
//int main()  //dotcpp 1013
//{
//	int s = 0, n = 0, a = 0;
//	int i = 0;
//	int ret = 0;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++)
//	{
//		ret = 2 * pow(10, i);
//		a += ret;
//		s += a;
//	}
//	printf("%d", s);
//
//	return 0;
//}
//int main()
//{
//	int m = 0;
//	int n = 0;
//	int i = 0;
//	long long int sum = 0;
//	long long int ret = 1;
//	scanf("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		ret = 1;
//		for (m = 1; m <= i; m++)
//		{
//			ret *= m;
//			
//			}
//		sum += ret;
//	}
//	printf("%lld", sum);
//	return 0;
//}
