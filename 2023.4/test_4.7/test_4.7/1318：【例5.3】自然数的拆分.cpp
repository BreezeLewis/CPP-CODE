//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
////输入n，然后进行拆分
//int n, a[101];
//void dfs(int dep, int sum)
//{
//	if (sum == n)
//	{
//		cout << sum << "=";
//		for (int i = 1; i < dep - 1; i++)
//			cout << a[i] << "+";
//		cout << a[dep - 1] << endl;
//	}
//	if (sum > n)
//		return;
//	for (int i = a[dep - 1]; i < n; i++)
//	{
//		a[dep] = i;
//		dfs(dep + 1, sum + i);
//	}
//}
//int main()
//{
//	a[0] = 1;
//	cin >> n;
//	dfs(1, 0);
//	return 0;
//}