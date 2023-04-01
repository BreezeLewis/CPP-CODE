//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//
//int r, c, res, vis[26];//标记数组
//
//char a[21][21];
//
//int dx[] = { 0, 0, 1, -1 };
//int dy[] = { 1, -1, 0, 0 };
//
//void dfs(int x, int y, int dep)
//{
//	res = max(res, dep);
//	for (int i = 0; i < 4; i++)
//	{
//		int bx = x + dx[i];
//		int by = y + dy[i];
//		if (bx<1 || by<1 || bx>r || by>c)
//			continue;
//		if (vis[a[bx][by] - 'A'])
//			continue;
//		vis[a[bx][by] - 'A'] = 1;
//		dfs(bx, by, dep + 1);
//		vis[a[bx][by] - 'A'] = 0;
//	}
//}
//
//int main()
//{
//	cin >> r >> c;
//	for (int i = 1; i <= r; i++)
//		for (int j = 1; j <= c; j++)
//			cin >> a[i][j];
//	vis[a[1][1] - 'A'] = 1;
//	dfs(1, 1, 1);
//	cout << res << endl;
//	return 0;
//}