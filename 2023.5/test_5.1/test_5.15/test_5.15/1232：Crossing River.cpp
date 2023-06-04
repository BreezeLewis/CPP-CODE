//#include <iostream>
//#include <algorithm>
//using namespace std;
//const int N = 1010;
//int t, n;
//int a[N];
//int main()
//{
//	cin >> t;
//	while (t--)
//	{
//		int res = 0;
//		cin >> n;
//		for (int i = 1; i <= n; i++)
//			cin >> a[i];
//		sort(a + 1, a + n + 1);
//		while (n > 3)
//		{
//			res += min(2 * a[1] + a[n - 1] + a[n], a[1] + 2 * a[2] + a[n]);
//			n -= 2;
//		}
//		if (n == 3)
//			res += a[1] + a[2] + a[3];
//		else if (n == 2)
//			res += a[2];
//		cout << res << endl;
//	}
//	return 0;
//}