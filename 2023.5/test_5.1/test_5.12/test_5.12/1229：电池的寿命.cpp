//#include <iostream>
//using namespace std;
//const int N = 1010;
//int n;
//int a[N];
//int main()
//{
//	while (cin >> n)
//	{
//		int maxx = -0x3f3f3f3f;
//		int sum = 0;
//		double res = 0;
//		for (int i = 1; i <= n; i++)
//			cin >> a[i], maxx = max(maxx, a[i]), sum += a[i];
//		if (sum - maxx >= maxx)
//			res = (sum - maxx - maxx) / 2.0 + maxx;
//		else
//			res = sum - maxx;
//		printf("%.1lf\n", res);
//	}
//	return 0;
//}