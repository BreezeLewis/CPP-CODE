//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//
//const int N = 10;
//
//int n, k, res;
//
//char a[N][N];
//
//int vis[N];//标记列
//
//int ans[N];
//void dfs(int dep, int pre)
//{
//	if (dep == k)
//	{
//		res++;
//		return;
//	}
//	for (int i = pre + 1; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (a[i][j] == '#' && !vis[j])
//			{
//				if (i == 3 && j == 0)
//				{
//					int x = 0;
//				}
//				vis[j] = 1;
//				dfs(dep + 1, i);
//				vis[j] = 0;
//			}
//		}
//	}
//}
//int main()
//{
//	while (cin >> n >> k && n != -1 && k != -1)
//	{
//		for (int i = 0; i < n; i++)
//			for (int j = 0; j < n; j++)
//				cin >> a[i][j];
//		res = 0;
//		memset(vis, 0, sizeof(vis));
//		dfs(0, -1);
//		cout << res << endl;
//	}
//	return 0;
//}
////class Test
////{
////public:
////
////
////private:
////	int a = 0;
////};
////int main()
////{
////	Test* t = new Test();
////	Test* p = t;
////	cout << t << endl;  // 输出0xe12590
////	delete t;
////	delete p;
////	cout << p << endl;
////	return 0;
////}