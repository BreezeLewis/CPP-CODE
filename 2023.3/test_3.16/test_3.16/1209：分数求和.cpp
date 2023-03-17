//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//int gcd(int a, int b)
//{
//	if (b == 0)
//		return a;
//	return gcd(b, a % b);
//}
//int main()
//{
//	int n, a, b;
//	cin >> n;
//	scanf("%d/%d", &a, &b);
//	int c = a, d = b;
//	while (--n)
//	{
//		scanf("%d/%d", &a, &b);
//		c = a * d + b * c;
//		d = b * d;
//		int tmp = gcd(c, d);
//		c /= tmp, d /= tmp;
//	}
//	if (d == 1)
//		cout << c << endl;
//	else
//		cout << c << "/" << d << endl;
//
//	return 0;
//}