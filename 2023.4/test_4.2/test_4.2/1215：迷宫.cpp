//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//
//const int N = 110;
//int k, n, sx, sy, fx, fy;
//char a[N][N];
//int vis[N][N];
//int dx[]{ 0,0,1,-1 };
//int dy[]{ 1,-1,0,0 };
//
//void dfs(int x, int y, int& flag)
//{
//	if (x == fx && y == fy)
//	{
//		flag = 1;
//		return;
//	}
//	for (int i = 0; i < 4; i++)
//	{
//		int bx = x + dx[i];
//		int by = y + dy[i];
//		if (bx < 0 || bx >= n || by < 0 || by >= n)
//			continue;
//		if (a[bx][by] == '#')
//			continue;
//		if (vis[bx][by])
//			continue;
//		vis[bx][by] = 1;
//		dfs(bx, by, flag);
//		//vis[bx][by] = 0;不能回溯，回溯会导致超时
//	}
//}
//int main()
//{
//	cin >> k;
//	while (k--)
//	{
//		cin >> n;
//		for (int i = 0; i < n; i++)
//			for (int j = 0; j < n; j++)
//				cin >> a[i][j];
//		cin >> sx >> sy >> fx >> fy; //判断能否从(x1,y1)到(x2,y2)
//		memset(vis, 0, sizeof(vis));
//		vis[sx][sy] = 1;
//		int flag = 0;
//		dfs(sx, sy, flag);
//		cout << (flag ? "YES" : "NO") << endl;
//	}
//	return 0;
//}