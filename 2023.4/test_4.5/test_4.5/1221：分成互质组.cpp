//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//int n, ans;
//int a[11];
//int gcd(int a, int b)
//{
//	return b == 0 ? a : gcd(b, a % b);
//}
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//		cin >> a[i];
//	for (int i = 1; i <= n; i++)
//		for (int j = i + 1; j <= n; j++)
//			if (a[j] && gcd(a[i], a[j]) == 1)
//				a[i] *= a[j], a[j] = 0;
//	for (int i = 1; i <= n; i++)
//		if (a[i])
//			ans++;
//	cout << ans << endl;
//	return 0;
//}