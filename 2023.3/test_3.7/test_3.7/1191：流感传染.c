#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int vis[110][110];
//char a[110][110];
//int n, m, res;
//int dx[] = { 1,-1,0,0 };
//int dy[] = { 0,0,1,-1 };
//int main()
//{
//	scanf("%d", &n);
//	getchar();
//	for (int i = 1;i <= n;i++)
//	{
//		for (int j = 1;j <= n;j++)
//			scanf("%c", &a[i][j]);
//		getchar();
//	}
//	scanf("%d", &m);
//	//  . 表示健康的人   
//	//  # 表示房间为空
//	//  @ 表示得流感的人  相邻的若为 . 则被感染
//	while (--m)
//	{
//		for (int i = 1;i <= n;i++)
//			for (int j = 1;j <= n;j++)
//				if (a[i][j] == '@')
//				{
//					for (int k = 0;k < 4;k++)
//					{
//						int bx = dx[k] + i;
//						int by = dy[k] + j;
//						//判断越界
//						if (bx<1 || bx >n || by<1 || by>n)
//							continue;
//						//如果是健康的人就标记
//						if (a[bx][by] == '.')
//							vis[bx][by] = 1;
//					}
//				}
//		for (int i = 1;i <= n;i++)
//			for (int j = 1;j <= n;j++)
//				if (vis[i][j])
//					a[i][j] = '@';
//
//	}
//	for (int i = 1;i <= n;i++)
//		for (int j = 1;j <= n;j++)
//			if (a[i][j] == '@')
//				res++;
//	printf("%d\n", res);
//	return 0;
//}