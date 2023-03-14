//#include <iostream>
//using namespace std;
//int f(int m, int n)
//{
//	if (m == 1 || n == 1 || m == 0 || n == 0)
//		return 1;
//	if (m < n)
//		return f(m, m);
//	else//m>=n
//		return f(m, n - 1) + f(m - n, n);
//}
//int main()
//{
//	int t, m, n;
//	cin >> t;
//	while (t--)
//	{
//		cin >> m >> n;
//		cout << f(m, n) << endl;
//	}
//	return 0;
//}