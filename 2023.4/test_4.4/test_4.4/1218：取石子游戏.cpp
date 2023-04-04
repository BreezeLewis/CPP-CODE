//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//int a, b, flag;
//bool dfs(int a, int b)
//{
//	if (a < b)
//		swap(a, b);
//	if (a % b == 0)
//		return true;
//	for (int i = a / b; i >= 1; i--)
//		if (dfs(a - i * b, b) == false)
//			return true;
//	return false;
//}
//int main()
//{
//	while (cin >> a >> b && a && b)
//	{
//		flag = dfs(a, b);
//		cout << (flag ? "win" : "lose") << endl;
//	}
//	return 0;
//}