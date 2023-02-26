#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//int a[501], n, vis[501];
//int cmp(const void* e1, const void* e2)
//{
//	int a = *(int*)e1, b = *(int*)e2;
//	return a - b;
//}
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//		cin >> a[i];
//	qsort(a + 1, n, sizeof(int), cmp);
//	int flag = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		if (a[i] % 2 == 1)
//		{
//			if (flag)
//			{
//				cout << "," << a[i];
//			}
//			else
//			{
//				flag = 1;
//				cout << a[i];
//			}
//		}
//	}
//
//	return 0;
//}