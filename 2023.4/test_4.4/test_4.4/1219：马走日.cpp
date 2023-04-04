//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//int k, n, m, sx, sy, res;
//int vis[11][11];
//int dx[]{ 1,1,-1,-1,2,2,-2,-2 };
//int dy[]{ 2,-2,2,-2,1,-1,1,-1 };
//void dfs(int x, int y, int dep)
//{
//	if (dep == n * m)
//	{
//		res++;
//		return;
//	}
//	for (int i = 0; i < 8; i++)
//	{
//		int bx = x + dx[i], by = y + dy[i];
//		if (bx < 0 || by < 0 || bx >= n || by >= m)
//			continue;
//		if (vis[bx][by])
//			continue;
//		vis[bx][by] = 1;
//		dfs(bx, by, dep + 1);
//		vis[bx][by] = 0;
//	}
//}
//int main()
//{
//	cin >> k;
//	while (k--)
//	{
//		cin >> n >> m >> sx >> sy;
//		res = 0;
//		memset(vis, 0, sizeof(vis));
//		vis[sx][sy] = 1;
//		dfs(sx, sy, 1);
//		cout << res << endl;
//	}
//	return 0;
//}