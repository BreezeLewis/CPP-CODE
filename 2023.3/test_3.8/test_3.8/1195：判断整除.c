#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int n, mod, sum;
//int a[10010];
//int main()
//{
//	scanf("%d%d", &n, &mod);
//	for (int i = 1;i <= n;i++)
//	{
//		scanf("%d", &a[i]);
//		sum += a[i];
//	}
//	if (sum % mod == 0)
//	{
//		printf("YES\n");
//		return 0;
//	}
//	for (int i = 1;i <= n;i++)
//	{
//		sum -= 2 * a[i];
//		if (sum % mod == 0)
//		{
//			printf("YES\n");
//			return 0;
//		}
//		if (sum < 0)
//			break;
//	}
//	printf("NO\n");
//	return 0;
//}