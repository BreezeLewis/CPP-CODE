#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int cx, cy, n, m, vis[21][21];
//long long a[21][21];
//int dx[] = { 1,1,-1,-1,2,2,-2,-2 };
//int dy[] = { 2,-2,2,-2,1,-1,1,-1 };
//int main()
//{
//	scanf("%d%d%d%d", &n, &m, &cx, &cy);
//	for (int i = 0; i < 8; i++)
//	{
//		int bx = cx + dx[i];
//		int by = cy + dy[i];
//		if (bx >= 0 && bx <= n && by >= 0 && by <= m)
//			vis[bx][by] = 1;
//	}
//	vis[cx][cy] = 1, a[0][0] = 1;
//	for (int i = 1; i <= n; i++)
//		if (!vis[i][0])
//			a[i][0] = a[i - 1][0];
//	for (int i = 1; i <= m; i++)
//		if (!vis[0][i])
//			a[0][i] = a[0][i - 1];
//	for(int i=1;i<=n;i++)
//		for (int j = 1; j <= m; j++)
//			if (!vis[i][j])
//				a[i][j] = a[i - 1][j] + a[i][j - 1];
//	printf("%lld\n", a[n][m]);
//	return 0;
//}