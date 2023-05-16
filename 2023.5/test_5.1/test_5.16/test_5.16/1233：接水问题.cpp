//#include <iostream>
//using namespace std;
//int n, m;
//int a[10010];
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//		cin >> a[i];
//	for (int i = m + 1; i <= n; i++)
//	{
//		int minIndex = 1;
//		for (int j = 1; j <= m; j++)
//		{
//			if (a[j] < a[minIndex])
//				minIndex = j;
//		}
//		a[minIndex] += a[i];
//	}
//	int maxx = a[1];
//	for (int i = 1; i <= n; i++)
//		maxx = max(maxx, a[i]);
//	cout << maxx << endl;
//	return 0;
//}