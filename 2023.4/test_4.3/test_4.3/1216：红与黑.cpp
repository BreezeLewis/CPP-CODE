//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//
//const int N = 25;
//
//int c, r, sx, sy, ans;
//
//char a[N][N];
//
//int vis[N][N];
//
//int dx[]{ 0,0,1,-1 }, dy[]{ 1,-1,0,0 };
//void dfs(int x, int y)
//{
//	for (int i = 0; i < 4; i++)
//	{
//		int bx = x + dx[i], by = y + dy[i];
//		if (bx < 0 || by < 0 || bx >= r || by >= c)
//			continue;
//		if (a[bx][by] != '.')
//			continue;
//		a[bx][by] = '@';
//		ans++;
//		dfs(bx, by);
//	}
//}
//int main()
//{
//	while (cin >> c >> r && c && r)
//	{
//		for (int i = 0; i < r; i++)
//			for (int j = 0; j < c; j++)
//			{
//				cin >> a[i][j];
//				if (a[i][j] == '@')
//					sx = i, sy = j;
//			}
//		ans = 1;
//		dfs(sx, sy);
//		cout << ans << endl;
//	}
//	return 0;
//}