#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int l[30], r[30], u[30];
//int n;
//int main()
//{
//	scanf("%d", &n);
//	l[1] = r[1] = u[1] = 1;
//	for (int i = 2;i <= n;i++)
//	{
//		l[i] = l[i - 1] + u[i - 1];
//		r[i] = r[i - 1] + u[i - 1];
//		u[i] = u[i - 1] + l[i - 1] + r[i - 1];
//	}
//	printf("%d\n", u[n] + l[n] + r[n]);
//	return 0;
//}