//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//int t, m, n, res;
//int a[20], vis[11];
//void dfs(int sum, int dep)
//{
//	if (sum > m || dep > n + 1)
//		return;
//	if (sum == m && dep <= n + 1)
//	{
//		res++;
//		return;
//	}
//	for (int i = a[dep - 1]; i <= m; i++)
//	{
//		a[dep] = i;
//		dfs(sum + i, dep + 1);
//	}
//}
//int main()
//{
//	cin >> t;
//	while (t--)
//	{
//		cin >> m >> n;
//		res = 0;
//		a[0] = 1;
//		dfs(0, 1);
//		cout << res << endl;
//	}
//
//	return 0;
//}