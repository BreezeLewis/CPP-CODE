#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//char s[10], vis[10], ans[10];
//int len;
//void dfs(int dep)
//{
//	if (dep == len)
//	{
//		printf("%s\n", ans);
//		return;
//	}
//	for (int i = 0; i < len; i++)
//	{
//		if (!vis[i])
//		{
//			vis[i] = 1;
//			ans[dep] = s[i];
//			dfs(dep + 1);
//			vis[i] = 0;
//		}
//	}
//}
//int main()
//{
//	scanf("%s", s);
//	len = (int)strlen(s);
//	dfs(0);
//	return 0;
//}