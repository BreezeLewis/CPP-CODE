//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//int n, r;//  n个数取r个进行组合
//int a[21];
//void dfs(int dep)
//{
//	if (dep == r + 1)
//	{//  1  2  3
//		for (int i = 1; i < dep; i++)
//			cout << "  " << a[i];
//		cout << endl;
//	}
//	for (int i = a[dep - 1] + 1; i <= n; i++)
//	{
//		a[dep] = i;
//		dfs(dep + 1);
//		//a[dep] = 0;
//	}
//}
//int main()
//{
//	cin >> n >> r;
//	dfs(1);
//	return 0;
//}