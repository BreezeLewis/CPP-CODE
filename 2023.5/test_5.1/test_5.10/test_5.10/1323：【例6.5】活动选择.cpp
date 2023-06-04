//#include <iostream>
//#include <algorithm>
//using namespace std;
//const int N = 1010;
//struct node
//{
//	int begin, end;
//}a[N];
//int n, res;
//bool cmp(node x, node y)
//{
//	return x.end < y.end;
//}
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//		cin >> a[i].begin >> a[i].end;
//	sort(a + 1, a + n + 1, cmp);
//	int time = 0;
//	for (int i = 1; i <= n; i++)
//	{
//		if (a[i].begin >= time)
//		{
//			res++;
//			time = a[i].end;
//		}
//	}
//	cout << res << endl;
//	return 0;
//}