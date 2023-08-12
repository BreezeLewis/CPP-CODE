//#include <iostream>
////#include <algorithm>
//#include <cmath>
//using namespace std;
//const int N = 10010;
//int n;
//double v[N], t[N];
//int main()
//{
//	while (cin >> n && n)
//	{
//		int s = 4500;
//		double min_t = 0x3f3f3f3f;
//		for (int i = 1; i <= n; i++)
//			cin >> v[i] >> t[i], v[i] /= 3.6;
//		for (int i = 1; i <= n; i++)
//		{
//			if (t[i] < 0)
//				continue;
//			double cost_t = t[i] + 4500 / v[i];
//			min_t = min(min_t, cost_t);
//		}
//		cout << (int)ceil(min_t) << endl;
//	}
//	return 0;
//}