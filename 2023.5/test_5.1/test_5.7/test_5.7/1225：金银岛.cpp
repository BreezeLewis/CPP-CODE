//#include <iostream>
//#include <algorithm>
//using namespace std;
//const int N = 110;
//int k, w, s;
//struct node
//{
//	int n, v;
//	double ratio;//cost performance
//}a[N];
//bool cmp(node x, node y)
//{
//	return x.ratio > y.ratio;
//}
//int main()
//{
//	cin >> k;
//	while (k--)
//	{
//		double res = 0;
//		cin >> w >> s;
//		for (int i = 1; i <= s; i++)
//		{
//			cin >> a[i].n >> a[i].v;
//			a[i].ratio = (double)a[i].v / a[i].n;
//		}
//		sort(a + 1, a + s + 1, cmp);
//		for (int i = 1; i <= s; i++)
//		{
//			if (w == 0)
//				break;
//			if (w >= a[i].n)
//				w -= a[i].n, res += a[i].v;
//			else
//				res += w * a[i].ratio, w = 0;
//		}
//		printf("%.2lf\n", res);
//	}
//	return 0;
//}